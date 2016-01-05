// learn.c
/*	-- Modified by Silencer for FY4.1

(1)	Using Difficulty instead of learn_bonus to describe skill learning.
(2)	Removed Randomness in learning .

*/

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "ËµµÀ£ºÄúÌ«¿ÍÆøÁË£¬ÕâÔõ÷á¸Òµ±£¿\n",
        "ÏñÊÇÊÜ³èÈô¾ªÒ»Ñù£¬ËµµÀ£ºÇë½Ì£¿ÕâÔõ÷á¸Òµ±£¿\n",
        "Ğ¦ÖøËµµÀ£ºÄú¼ûĞ¦ÁË£¬ÎÒÕâµãµñ³æĞ¡¼¼Ôõ¹»×Ê¸ñ¡¸Ö¸µã¡¹ÄúÊ²÷á£¿\n",
});

int couple_learn(object me, object couple, string skill);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    	string skill, teacher, master;
    	string target, cardname;
    	object ob, *list, marry_card;
    	int master_skill, my_skill, gin_cost;
    	int i,marry_flag, level;
    	int amount=0, pot;
    	
		string *att_skill = ({ "literate", "unarmed", "force", 
							"foreknowledge", "chanting", "move" });

    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 )
        	return notify_fail("Ö¸Áî¸ñÊ½£ºlearn <¼¼ÄÜ> from <Ä³ÈË> with <Ç±ÄÜµã>\n");

    	if( me->is_fighting() )
        	return notify_fail("ÁÙÕóÄ¥Ç¹£¿À´²»¼°À²¡£\n");
    
    	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
        	return notify_fail("ÄãÒªÏòË­Çó½Ì£¿\n");
    
    	if( !living(ob) )
        	return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + ob->name() + "ÅªĞÑÔÙËµ¡£\n");
    	if ( pot <=0 )
        	return notify_fail("Ç±ÄÜµã×îÉÙÊÇÒ»£¡\n");
		
		if (userp(ob))
        	return notify_fail("ÏÖÏÂÍ¬´²ÒìÃÎÖ®ÊÂ±È±È½ÔÊÇ£®£®£®\n»¹ÊÇ²»ÒªÖ¸ÍûÄãÕæÄÜÑ§µ½Ê²Ã´ÁË°Õ¡£\n");
        	
    	target = (string)me->query("marry");
    
    	if( !me->is_apprentice_of(ob) && !me->is_couple_of(ob)){
	        // 	Basically, if you are not his apprentice, you can't learn  
	        //   from NPC unless he returns   recognize_apprentice = 1
	        if( !(ob->recognize_apprentice(me)) && ob->query("race") == "ÈËÀà") {
	            return notify_fail( ob ->name() + 
					reject_msg[random(sizeof(reject_msg))] );
			} else if(ob->query("race") != "ÈËÀà"){
				return notify_fail(ob->name() + "ÏÔÈ»Ìı²»¶®ÄãµÄ»°¡£\n");
			}
		}
// until here we deicde that me can learn from ob!
   	
    	if(!me->is_couple_of(ob)){ 
    		// Prevent_learn can be either from inheritance from F_MASTER
    		// Or a function in npc files. it allows you to set individual skills.
    		// But, if you override it to in a F_MASTER to play tricks 
    		// 		it will override the betrayal in F_MASTER
    		if(ob->prevent_learn(me, skill)) 
        	return notify_fail(ob->name() + "²»Ô¸Òâ½ÌÄãÕâÏî¼¼ÄÜ¡£\n");
    	}
    	
    	if( ob->is_couple_of(me) )    		
//		if( couple_learn(me,ob,skill))
            	return notify_fail(ob->name() + "²»Ô¸Òâ½ÌÄãÕâÏî¼¼ÄÜ¡£\n");
    
    	if( !master_skill = ob->query_skill(skill,1) )
        	return notify_fail("ÕâÏî¼¼ÄÜÄã¿ÖÅÂ±ØĞëÕÒ±ğÈËÑ§ÁË¡£\n");

    	my_skill = me->query_skill(skill, 1);
    	if( my_skill >= master_skill )
        	return notify_fail("ÕâÏî¼¼ÄÜÄãµÄ³Ì¶ÈÒÑ¾­²»ÊäÓÚÄãÊ¦¸¸ÁË¡£\n");
    	
    	// Áù´ó»ù±¾ÊôĞÔËù¶ÔÓ¦µÄ»ù±¾¼¼ÄÜÔÚÑ§Ï°Ê±ÏµÊıÒÔ1.5¼ÆËã¡£
    	if ( member_array(skill, att_skill) == -1)
    		my_skill = my_skill * SKILL_D(skill)->effective_level(me)/100;
    	else
    		my_skill = my_skill * 150 /100;
    
    	notify_fail("ÒÀÄãÄ¿Ç°µÄÄÜÁ¦£¬Ã»ÓĞ°ì·¨Ñ§Ï°ÕâÖÖ¼¼ÄÜ¡£\n");
    	if( !SKILL_D(skill)->valid_learn(me) )  return 0;

//	casue problem under query-skill-eff-lvl
    	if( (int)me->query_skill(skill,1) == 0 ) {
        	me->set_skill(skill,0);
    	}

    	if(pot >10000)	
    		return notify_fail("Îª·ÀÖ¹Òç³ö£¬Ã¿´ÎÑ§Ï°µÄÇ±ÄÜµã²»ÄÜ³¬¹ı£±£°£°£°£°µã¡£\n");
    	
    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
        	return notify_fail("ÄãÃ»ÓĞÕâÃ´¶àµÄÇ±ÄÜ¡£\n");

    	if (me->query("gin")< 10)
    		return notify_fail("ÄãµÄ¾«Á¦²»¹»£¬»¹ÊÇÏÈĞİÏ¢ĞİÏ¢°É¡£\n");
    	
    	tell_object(me,"ÄãÏò"+ob->name()+"Çë½ÌÓĞ¹Ø¡¸"+ SKILL_D(skill)->name() +"¡¹µÄÒÉÎÊ¡£\n");
    
    	if( ob->query("env/no_teach") )
        	return notify_fail("µ«ÊÇ" + ob->name() +"ÏÖÔÚ²¢²»×¼±¸»Ø´ğÄãµÄÎÊÌâ¡£\n");
    
    	tell_object(ob, sprintf("%sÏòÄãÇë½ÌÓĞ¹Ø¡¸%s¡¹µÄÎÊÌâ¡£\n",me->name(), SKILL_D(skill)->name()));
    	    	
		if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") ) {
            	printf("Ò²ĞíÊÇÒòÎªÈ±·¦¾­Ñé£¬Äã¶Ô%sµÄ»Ø´ğ×ÜÊÇÎŞ·¨Áì»á¡£\n", ob->name() );
        } else {

// WARNING ON	Seperated set of variables so it won't mess up with the old thing =============

			mapping learned_skill_points;
			int leftover, j, a_cost,a_amount, a_total;
						
			learned_skill_points=me->query_learned();
			if (mapp(learned_skill_points))
				leftover = learned_skill_points[skill];
			else
				leftover = 0;
			j = me->query_skill(skill,1);
			
			if (me->query_int()<=40)
				a_amount = (400+30*me->query_int())*2*100;
			else
				a_amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
			
	        if (me->query("national")=="Ãç×å")	
	        	a_amount = a_amount + a_amount/20;	// Ãñ×åÌØĞÔ      	            	    	
	        a_amount = a_amount / SKILL_D(skill)->skill_difficulty();        	                 	
	       	if( a_amount < 1) a_amount = 1;		// ÖÁÉÙ1£º1 
	       	          
	        a_total = (j+1)*(j+1)+1 - leftover;
	        a_cost = a_total*100/a_amount+1;
			
			if (a_cost < 0)
				a_cost = 1;
				
			if (a_cost < pot) { 
				tell_object(me, HIR"·çÔÆÓÑºÃÌáÊ¾£ºÄúËùÊäÈëµÄÇ±ÄÜÊı£¨"+pot+"£©´óÓÚÉı¼¶ËùĞè£¨"+a_cost+"£©µã£¡\n"NOR);
				tell_object(me,HIR"ÏµÍ³×Ô¶¯µ÷ÕûËùÓÃÇ±ÄÜÊıÎª"+a_cost+"µã¡£\n"NOR);
				pot = a_cost;
			}
			
// WARNING OFF =================================================================================

            	printf("ÄãÌıÁË%sµÄÖ¸µ¼£¬ËÆºõÓĞĞ©ĞÄµÃ¡£\n", ob->name());
            	
            	me->add("learned_points", pot); 
				me->add("annie/skill_cost/"+skill,pot);
    	         
    	        if (me->query_int()<=40)
    	        	amount = (400+30* me->query_int()) *2 * pot;
    	        else
    	        	amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*pot) ;
                       		
            	if (me->query("national")=="Ãç×å")	
            		amount = amount + amount/20;	// Ãñ×åÌØĞÔ
            	            	    	
            	amount = amount / SKILL_D(skill)->skill_difficulty();
            	            	           	                 	
            	if( amount < 1) amount = 1;		// ÖÁÉÙ1£º1            	

// DEBUG on
		if (wizardp(me) && me->query("env/debug")) {
			write("skill difficulty is "+ SKILL_D(skill)->skill_difficulty() + "\n");
			write("learning efficiency is: 1 point Ç±ÄÜ == " + amount/pot + "\n");
		}
// DEBUG off

            	me->improve_skill(skill,amount);
        }
	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	learn <¼¼ÄÜ> from <Ä³ÈË> with <Ç±ÄÜµã>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

·çÔÆÖĞ¹²ÓĞËÄÖÖ»ñÈ¡¼¼ÄÜµÄÍ¾¾¶£º	¶ÁÊé£¨study£©
				[1;31mÑ§Ï°£¨learn£©[0m
				×êÑĞ£¨research£©
				Á·Ï°£¨practice£©

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄãÏò±ğÈËÇë½ÌÓĞ¹ØÄ³Ò»ÖÖ¼¼ÄÜµÄÒÉÄÑÎÊÌâ£¬µ±È»£¬ÄãÇë
½ÌµÄ¶ÔÏóÔÚÕâÏî¼¼ÄÜÉÏµÄÔìÒè±ØĞë±ÈÄã¸ß£¬¶øÄã¾­ÓÉÕâÖÖ·½Ê½Ñ§Ï°µÃÀ´
µÄ¼¼ÄÜÒ²²»¿ÉÄÜ¸ßì¶ÄãËùÇë½ÌµÄÈË£¬È»¶øÒòÎªÕâÖÖÑ§Ï°·½Ê½Ïàµ±ì¶Ò»ÖÖ
¾­ÑéµÄ´«³Ğ£¬Òò´ËÑ§Ï°¿ÉÒÔËµÊÇÊìÏ¤Ò»ÖÖĞÂ¼¼ÄÜ×î¿ìµÄ·½·¨¡£

Í¨³££¬Ò»¸öÈË¸ÕÑ§µ½Ò»ÖÖĞÂ¼¼ÄÜÊÇ²»»áÓĞÊ²÷áÒÉÄÑÎÊÌâµÄ£¬¶øÊÇ¾­ÓÉÊµ
¼ÊÉÏµÄÓ¦ÓÃÖĞÔâÓöÎÊÌâ£¬ÕâĞ©ÎÊÌâ¶Ôì¶Ñ§Ï°Ò»ÖÖĞÂ¼¼ÄÜµÄ¹ı³ÌÊÇºÜÖØÒª
µÄ£¬ÓÈÆäÊÇ¸÷ÖÖ×÷ÎªÆäËû¼¼ÄÜ»ù´¡µÄ»ù±¾¼¼ÄÜ£¬¸üĞèÒª¾­ÓÉ¡¸·¢ÏÖÎÊÌâ
¡ª½â¾öÎÊÌâ¡¹µÄ¹ı³Ì²ÅÄÜµÃµ½½ÏºÃµÄĞ§¹ûÒò´ËÎÒÃÇ½«ÕâÖÖ·¢ÏÖÎÊÌâµÄ¹ı
³ÌÓÃ¡¸Ç±ÄÜ¡¹µÄ¹ÛÄî±íÊ¾£¬Ò»¸öÈËÄÜ¹»×Ô¼º·¢ÏÖÄ³Ğ©ÎÊÌâ£¬±íÊ¾Ëû(Ëı)
ÓĞ½â¾öÕâÏîÎÊÌâµÄÇ±ÄÜ£¬µ±Äã¾ßÓĞÕâÑùµÄÇ±ÄÜÊ±¾Í¿ÉÒÔÀûÓÃÕâ¸öÖ¸ÁîÀ´
ÏòÆäËûÈËÇë½Ì£¬¶ø»ñµÃ½ø²½¡£

FY2005ÖĞÑ§Ï°²»ÔÙÏûºÄ¾«Á¦¡£

ÖÁì¶ÈçºÎÖªµÀÄãÄÜ´Ó¶Ô·½Ñ§µ½Ê²÷á¼¼ÄÜ£¬Èç¹û¶Ô·½ÊÇÄãµÄÊ¦¸¸£¬¿ÉÒÔÓÃ
 skills Ö¸ÁîÖ±½Ó²é¿´¡£

Ã¿NµãÇ±ÄÜ¶ÔÓ¦µÄ¼¼ÄÜÔö¼Ó¶ÔÓ¦µÄ¾ßÌå¹«Ê½Îª£º
£¨1£©²ÅÖÇ¡¶=40Ê±£¬
	= N *£¨400 + 30*²ÅÖÇ£©*2 /Ñ§Ï°ÄÑ¶È 
£¨2£©²ÅÖÇ¡µ40Ê±£¬ 
	= N*((£¨int*10£©^0.03)*871-950)*173/5/Ñ§Ï°ÄÑ¶È

ËùÑ§µÄÊıÖµÔÚ¼ÆËãµÄ×îºóÒ»²½È¡Õû¡£
´ó²¿·Ö¼¼ÄÜµÄÑ§Ï°ÄÑ¶ÈÔÚ£±£°£°ÖÁ£²£µ£°£¬

Ñ§Ï°µÄĞ§ÂÊÓëÒÔÏÂÒòËØÏà¹Ø£º
£¨1£©¼¼ÄÜÖÖÀà£º²»Í¬µÄÎä¹¦Ñ§Ï°ÄÑ¶È²»Í¬£¬¿ÉÓÃskillsÃüÁî²ì¿´¡£
£¨2£©Ãñ×åÌØĞÔ£¬Ãç×åµÄÑ§Ï°Ğ§ÂÊ±È½Ï¸ß£¨ÉÏÃæ¹«Ê½ÔÙ+5%£©

Ñ§Ï°¼¼ÄÜµÄÏŞÖÆ£º
£¨1£©Ã»ÓĞÊ¦¸µÏ²»¶ÈıĞÄ¶şÒâ¡¢³¯³şÄºÇØµÄµÜ×Ó£¬ÄãÃ¿ÅÑÊ¦Ò»´Î£¬ÏÂÒ»¸ö
Ê¦¸µÔ¸Òâ½ÌÄãµÄ¼¼ÄÜµÈ¼¶¾Í»á¼õÉÙ¶şÊ®¼¶¡£Í¬Ê±£¬Ê¦ÃÅ×¨ÓĞµÄÎä¹¦½ø½ç
£¨£á£â£é£ì£é£ô£ù£©ÔÚÅĞÊ¦ºóÒ²¾ÍÃ»ÓÃÁË¡£

Éı¼¶µÄÌõ¼ş
µ±ÄãµÄÑ§Ï°µãÊı´óÓÚÏÂÒ»¼¶µÄÆ½·½¼ÓÒ»Ê±Éı¼¶£¬
Ò²¾ÍÊÇËµ£¬Èç¹ûÄãµÄ¼¼ÄÜµÈ¼¶Îªn£¬ÔÚÑ§Ï°µãÊı£¨×¢Òâ£¬²»ÊÇÇ±ÄÜµãÊı£©
´óÓÚ(n+1)*(n+1)+1Ê±Éı¼¶¡£

¾ÙÀı
£ªµûÁµ»¨½£·¨ (diesword)                  - ´ÖÍ¨Æ¤Ã«  22/  530
´ËµØ 530 = 23*23 + 1£¬ µ±ÄãÔÙ»¨·ÑÒ»µãÇ±ÄÜÑ§Ï°Ê±Éı¼¶³ÉÎª
£ªµûÁµ»¨½£·¨ (diesword)                  - ´ÖÍ¨Æ¤Ã«  23/  0

** Áù´ó»ù±¾ÊôĞÔ¶ÔÓ¦µÄÏà¹Ø¼¼ÄÜ£¨¶ÁÊéÊ¶×Ö¡¢ËĞ¾­¡¢ÆË»÷¸ñ¶·¡¢»ù±¾
Çá¹¦¡¢Õ¼²·Ñ§¡¢»ù±¾ÄÚ¹¦£©ÔÚÑ§Ï°µÄÊ±ºòÏµÊı¼ÆËãÎª150¡£

ÆäËûÏà¹ØÖ¸Áî : practice¡¢study¡¢research

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
        );
    return 1;
}


int couple_learn(object me, object couple, string skill)
{
	int i, div,div1,mylvl, herlvl, ratio=0;
	if(!userp(couple)) return 0;
	mylvl = me->query_skill(skill,1);
	herlvl = couple->query_skill(skill,1);
	div = (int) me->query("divorced");
	div1 = (int) couple->query("divorced");
	for(i=1; i<=div1; i++) 
		ratio+=25;
	if(div1&&(mylvl>=herlvl-ratio)){
		message_vision("$NÏëÆğ$n´ÓÇ°Àë»éµÄÊÂ£¬ºöÈ»¾õµÃĞÄÀïºÜ²»Êæ·ş£¬Ò»Ê±É¥Ê§ÁËÑ§Ï°µÄĞËÈ¤¡£\n",me,couple);
		return 1;
	}
	if(div&& (mylvl >= herlvl / 2) ){
		message_vision("$NÉñÉ«¼äËÆºõ¶Ô$n²»ÊÇÊ®·ÖĞÅÈÎ£¬Ò²ĞíÊÇÏëÆğ$p´ÓÇ°Àë»éµÄÊÂÇé...¡£\n", couple, me );	
		return 1;	
	}
	return 0;
}
