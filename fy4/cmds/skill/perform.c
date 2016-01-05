/*	Modifications
		
	-- 7/22/2004 by Silencer
		** ËùÓĞperformÖÁÉÙĞèÒªÏûºÄ50µãÄÚÁ¦£¬L51¼¶ÒÔÏÂÃâ·Ñ¡£	
*/

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	object weapon;
    	string martial, skill;
    	string *skill_list = ({ "axe","blade","dagger","fork","hammer","parry","staff",
    				"sword","throwing","spear","unarmed","whip","musket"});
   		int force, mylevel, force2;
 	    string *freepass = ({ "chunxin","hengxie","jingpo", "juesha", "qianhuan", 
 	    					"yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"});       
    	string *freeforce = ({ "chunxin","hengxie","jingpo", "juesha", "qianhuan" });
//		string *freepass = ({});
//		string *freeforce = ({});
    	int chance;
    	
    	seteuid(getuid());
		
		
    	if( environment(me)->query("no_fight"))
		return notify_fail("ÕâÀïÎŞ·¨Ê¹ÓÃÌØÊâÕĞÊ½¡£\n");
    	if( me->is_busy() )
        	return notify_fail("£¨ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÊ©ÓÃÌØÊâÕĞÊ½¡££© \n");
        
    	if( !arg ) 
    		return notify_fail("ÄãÒªÊ¹ÓÃÄÄÒ»ÏîÌØÊâÕĞÊ½£¿\n");

    	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
	        if( weapon = me->query_temp("weapon") )
	            	martial = weapon->query("skill_type");
	        else if( weapon = me->query_temp("secondary_weapon"))
	            	martial = weapon->query("skill_type");
	        else
	            	martial = "unarmed";
    	} 
    	else{
			if( member_array(martial,skill_list) != -1)
            		return notify_fail("ÕâÖÖÌØÊâÕĞÊ½²»ĞèÖ¸¶¨Îä¹¦ÖÖÀà£¡\n");
        	if( martial == "move")
        		return notify_fail("´ËÀàÌØÊâÕĞÊ½Ó¦¸ÃÊ¹ÓÃÉÁ¶ãÊõ(dodge)µÄÍâ¹¦¡£\n");    
    	}
    	
    	mylevel = F_LEVEL->get_level(me->query("combat_exp"));
    	force = me->query("force");
    	if (userp(me) && mylevel > 50 && force < 50)
    		return notify_fail("Ê¹ÓÃÌØÊâÕĞÊ½ÖÁÉÙĞèÒª50µãµÄÄÚÁ¦¡£\n");	
    	
    	if( userp(me) && ANNIE_D->check_buff(me,"forceshield") && force < 300)
    		return notify_fail("ÔÚÔËĞĞ»¤¶ÜÀàÎä¹¦Ê±Ê¹ÓÃÌØÊâÕĞÊ½ÖÁÉÙĞèÒª300µãµÄÄÚÁ¦¡£\n");	
    		
    	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
    	
    	if( stringp(skill = me->query_skill_mapped(martial)) ) {
	        if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time()
        		&& member_array(arg,freepass)== -1 )// ÔÚÕ½¶·ÖĞ¡¡%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"Ò»ÕĞ²»É÷£¬Â¶³öÁËºÃ´óµÄÒ»¸öÆÆÕÀ£¡£¡£¡\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\nÄãÔËÁ¦²»É÷£¬Ã»ÓÃ³ö¾øÕĞ·´¶øÂ¶³öÁË¿ÕÃÅ£¡\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
	        	
	        if( SKILL_D(skill)->perform_action(me, arg) ) {	        	       	
				if (userp(me) && member_array(arg,freeforce)== -1 && me->query_temp("pfm/free_perform")<1) {
					if (mylevel>50)
		        	{	  		
		        		force2 = me->query("force");
		        		if( ANNIE_D->check_buff(me,"forceshield")) {
		        			if (force - force2 < 300)
		        				me->set("force", force - 300);
		        		} else
		        		{		        			
		        			if (force - force2 < 50)
		        				me->set("force",force-50);
		        		}		        	
		        	}
	        	}
	        	// Give a mark for zeor force perform
	        	if (me->query_temp("pfm/free_perform")>0) {
					me->add_temp("pfm/free_perform",-1);
					if (me->query_temp("pfm/free_perform")<1)
						me->delete_temp("pfm/free_perform");
				}
	        	me->force_status_msg("force");
	            return 1;
	        
	        } else 
	        	return 0;
    	}
    	return notify_fail("ÄãÇëÏÈÓÃ enable Ö¸ÁîÑ¡ÔñÄãÒªÊ¹ÓÃµÄÍâ¹¦¡£\n");
}



int help (object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	perform [<Îä¹¦ÖÖÀà>]<ÕĞÊ½Ãû³Æ> [<Ê©ÓÃ¶ÔÏó>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

·çÔÆÖĞµÄÎä¹¦¿É¹éÎªËÄ´óÀà£º£¨·Ö±ğ¶ÔÓ¦µÄÊ¹ÓÃÃüÁîÎª£©
£¨1£©´«Í³Îä¼¼£¨ÈçÉñ»úµ¶·¨¡¢ÆåµÀĞÄ·¨£©£º£¨perform/exert£©
£¨2£©·¨Êõ£º£¨ÈçĞË¹úìøËÂµÄ°ËÊ¶ÉñÍ¨£©£º(conjure)
£¨3) ÖäÊõ£º£¨ÈçÈıÇåµÄÈıÇåµÀÊõ¡¢´óÕÑµÄ¹ÛÒôÁù×ÖÃ÷Öä£©£º(cast)
£¨4£©½µÍ·Êõ£º£¨ÈçµÛÍõ¹ÈµÄÍ¨Ìì½µ£¬ÀÇÉ½µÄÑªÀÇÖä£©£º£¨curse£©

ËùÎ½´«Í³Îä¼¼¶àÖ¸È­½Å¡¢½£·¨¡¢µ¶·¨µÈ£¬ÕâĞ©¹¦·òÍ¨³£ÓĞÒ»Ğ©ÌØ
ÊâµÄ¹¥»÷ÕĞÊ½£¬¿ÉÒÔÓÃÕâ¸öÖ¸ÁîÀ´Ê¹ÓÃ¡£

ÏÈÓÃ enable Ö¸ÁîÖ¸¶¨ÄãËùÊ¹ÓÃµÄÎä¹¦£¬±ÈÈçËµ
	enable sword diesword ºó£¬¾ÍÄÜÊ¹ÓÃÆäÕĞÊ½¡°²Êµû¿ñÎè¡±
	perform caidiekuangwu

²»Êôì¶È­½Å¸úÎäÆ÷¼¼ÄÜµÄÎä¹¦±ØĞëÖ¸Ã÷ËùÓÃµÄ»ù±¾Îä¹¦£¬ÀıÈç
	perform iron-cloth.daoqiangburu
	perform dodge.yexuechuji
	perform herb.canyunbi

¶øÈ­½Å¹¦·ò»òÕß±øÆ÷¹¦·òÔò¿ÉÒÔÊ¡ÂÔµô»ù±¾Îä¹¦ÕâÒ»Ïî£¬ÀıÈç
	perform duangechangmeng
	perform tianxiawugou

ÔÚÍ¨³£Çé¿öÏÂ£¬ÔÚÓĞ¶à¸ö¶ÔÊÖÊ±£¬Ğí¶àÌØÊâÕĞÊ½¿ÉÒÔÖÆ¶¨¶ÔÊÖ£¬
±ÈÈçËµÄãÔÚÓë oldman, waiter, badguy Èı¸öÈËØËÉ±£¬
Ê¹ÓÃ
	perform dodge.luoyeqiufeng waiter
¾Í¿ÉÒÔ½«¡°ÂäÒ¶Çï·ç¡±µÄÌØ¼¼Ê¹ÓÃµ½waiterÉÏ¡£	

ÔÚÕ½¶·ÖĞÊ¹ÓÃÌØÊâ¼¼ÄÜÓĞ2%µÄ¿ÉÄÜ»áÊ§°Ü£¬Ôì³É×Ô¼ºÃ¦ÂÒ£¬ĞŞÏ°Ä³Ğ©
ÌØ¶¨µÄÎä¹¦¿ÉÒÔ½µµÍ´Ë¸ÅÂÊ¡£

Ê¹ÓÃÒ»´ÎÌØÊâÕĞÊ½ÖÁÉÙĞèÒªÏûºÄ50µãÄÚÁ¦¡£
£¨µÈ¼¶51ÒÔÏÂ¿ÉÃâÈ¥´ËÒªÇó£©

×¢:
	·çÔÆÖĞÓĞµÄÎä¹¦ĞèÒªÁ½ÈË»ò¶àÈË²ÅÄÜÊ¹³ö£¬Æä¸ñÊ½Îª£º
perform [<Îä¹¦ÖÖÀà>]<ÕĞÊ½Ãû³Æ> [<Ê©ÓÃ¶ÔÏó>] with Í¬°éÃû×Ö

±ÈÈçËµ£¬ÉÙÁÖµÄÁ«ĞÄµ¶·¨£¬ÆäÊ¹ÓÃµÄ¸ñÊ½Îª£º

perform yipianlianxin µĞÈËÃû×Ö with Í¬°éÃû×Ö
perform yipianlianxin with Í¬°éÃû×Ö

Í¬Àí£¬ÌúÑ©µÄµ¶½£ÈôÃÎ£¬ÆäÊ¹ÓÃµÄ¸ñÊ½Îª£º

perform daojianruomeng µĞÈËÃû×Ö with Í¬°éÃû×Ö
perform daojianruomeng with Í¬°éÃû×Ö

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
        );
    return 1;
}
 
