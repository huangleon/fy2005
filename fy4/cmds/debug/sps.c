// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    	object ob;
    	mapping skill;
    	string  book,liter;
    	int cost, sena, i;
    	int amount=0;
    	int my_skill, liter_level;
    	string *att_skill = ({ "literate", "unarmed", "force", "foreknowledge", "chanting", "move" });
    
    	if( me->is_fighting() )
        	return notify_fail("ÄãÎŞ·¨ÔÚÕ½¶·ÖĞ×¨ĞÄÏÂÀ´ÑĞ¶ÁĞÂÖª£¡\n");
    	if( me->is_busy() )
        	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÑĞ¶ÁĞÂÖª¡£\n");
    	
    	if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        	return notify_fail("Ö¸Áî¸ñÊ½£ºstudy <ÎïÆ·> <ÉñÊıÁ¿>\n");
    
    	if(!objectp(ob = present(book, me)) )
	if(!objectp(ob = present(book, environment(me))))
            	return notify_fail("ÄãÒª¶ÁÊ²÷á£¿\n");
    
    	if( !mapp(skill = ob->query("skill")) )
        	return notify_fail("ÄãÎŞ·¨´ÓÕâÑù¶«Î÷Ñ§µ½ÈÎºÎ¶«Î÷¡£\n");

// added by tie
    	if(stringp(skill["literate"])) liter = skill["literate"];
    		else liter = "literate";
    	if( !me->query_skill(liter, 1) )
        	return notify_fail("Äã¿´²»¶®Ò®£®£®£¬ÏÈÑ§Ñ§"+SKILL_D(liter)->name()+"°É¡£\n");

// added by silencer, require a certain level of basic skill to study certain skills.
    	if(skill["liter_level"]) {
    		liter_level = skill["liter_level"];
    		if (me->query_skill(liter,1) <liter_level)
    			return notify_fail("ÄãµÄ"+SKILL_D(liter)->name()+"Ì«²îÁË£¬Áì»á²»ÁËÒ®£¨ĞèÒª"+liter_level+"¼¶£©\n");	
	}
    
    	message("vision", me->name() + "Õı×¨ĞÄµØÑĞ¶Á" + ob->name()+ "¡£\n", environment(me), me);
    	if( (int)me->query("combat_exp") < skill["exp_required"] )
    	{
        	write("ÄãµÄÊµÕ½¾­Ñé²»×ã£¬ÔÙÔõ÷á¶ÁÒ²Ã»ÓÃ¡£\n");
        	return 1;
    	}
    	
    	notify_fail("ÒÔÄãÄ¿Ç°µÄÄÜÁ¦£¬»¹Ã»ÓĞ°ì·¨Ñ§Õâ¸ö¼¼ÄÜ¡£\n");
    
    	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;
    
    	cost = skill["sen_cost"] + skill["sen_cost"] 
        		* (skill["difficulty"] - (int)me->query_int())/20;
    	cost = cost /2;
    	if(cost < 1) cost = 1;
    	if( cost > sena)
		return notify_fail("ÒÔÄãÄ¿Ç°µÄÄÜÁ¦£¬ÄãÖÁÉÙÒª»¨"+chinese_number(cost)+"µãÉñ\n");
    
    	if( (int)me->query("sen") <= sena)
    	{
        	write("ÄãÏÖÔÚ¹ıì¶Æ£¾ë£¬ÎŞ·¨×¨ĞÄÏÂÀ´ÑĞ¶ÁĞÂÖª¡£\n");
        	return 1;
    	}

    	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
    	{
        	write("ÄãÑĞ¶ÁÁËÒ»»á¶ù£¬µ«ÊÇ·¢ÏÖÉÏÃæËùËµµÄ¶ÔÄã¶øÑÔ¶¼Ì«Ç³ÁË£¬Ã»ÓĞÑ§µ½ÈÎºÎ¶«Î÷¡£\n");
        	return 1;
    	}
    	
    	my_skill = me->query_skill(skill["name"], 1);
    	
    	if ( member_array(skill["name"], att_skill) == -1)
    		my_skill = my_skill * SKILL_D(skill["name"])->effective_level()/100;
    	else
    		my_skill = my_skill;
    	    	
    	if(my_skill * my_skill * my_skill  > (int)me->query("combat_exp")) {
        	write("ÒÔÄãÏÖÔÚµÄÊµÕ½¾­Ñé£¬ÔÙÔõ÷á¶ÁÒ²ÎŞ·¨Áì»á¡£\n");
        	return 1;
    	}
//    	me->receive_damage("sen", sena);
    
    	if( !me->query_skill(skill["name"], 1) )
        	me->set_skill(skill["name"], 0);
        		
    	for (i=1;i<200;i++){
    		reset_eval_cost();
    		me->improve_skill(skill["name"], 9999);
    		my_skill = me->query_skill(skill["name"], 1);
    		if ( member_array(skill["name"], att_skill) == -1)
    			my_skill = my_skill * SKILL_D(skill["name"])->effective_level()/100;
    		else
    			my_skill = my_skill;
    		if (my_skill * my_skill * my_skill > me->query("combat_exp"))	break;
    		if (me->query_skill(skill["name"], 1) > skill["max_skill"] )	break;
    	}
    	    	
//    	write("ÄãÑĞ¶ÁÓĞ¹Ø" + SKILL_D(skill["name"])->name() + "µÄ¼¼ÇÉ£¬ËÆºõÓĞµãĞÄµÃ¡£\n");
    	return 1;
}

int help(object me)
{
    write( @HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : sps <ÎïÆ·Ãû³Æ> <ºÄ·Ñ¡¸ĞÄÉñ¡¹µÄÁ¿>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

µ÷ÊÔÃüÁî£º¿ìËÙÑ§Ï°Ä³¼¼ÄÜµ½¾­ÑéµÈ¼¶µÄÉÏÏŞ

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
