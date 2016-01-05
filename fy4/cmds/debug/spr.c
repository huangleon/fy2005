
#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
    	int gin_cost,my_skill, limit;
    	int pot, amount;
    	string skill, check, myclass;
    	mapping level;
    	
    	if( me->is_fighting() )
        	return notify_fail("ÔÚÕ½¶·ÖĞ¸ãÑĞ¾¿£¿\n");
    	
    	if (!arg)
    		return notify_fail("Ö¸Áî¸ñÊ½: research <¼¼ÄÜ> with <Ç±ÄÜµãÊı>\n");
    	
    	if( sscanf(arg, "%s with %d", skill, pot)!=2 ) {
    	 	if (sscanf(arg, "%s with %s", skill, check) == 2)
    	 	if ( check == "limit") {
    	 		if( !(int)my_skill=me->query_skill(skill,1) )
        			return notify_fail("Äã¶Ô´ËÏî¼¼ÄÜÒ»ÎŞËùÖª£¬ÈçºÎ¸ãÑĞ¾¿£¿\n");
    	 		
    	 		myclass = me->query("class");
    	 		me->set("class",SKILL_D(skill)->skill_class());
    	 		limit = 450 * 100 / SKILL_D(skill)->effective_level();
    			limit = (limit /5 + 1) * 5;
    			if (myclass)	me->set("class",myclass);
    				else	me->delete("class");
    				
    			tell_object( me, "´ËÏî¼¼ÄÜÄÜ¹»×êÑĞµ½µÄ×î¸ßµÈ¼¶Îª"+ limit +"¡£\n");
    			return 1;
    		}
    	 	return notify_fail("Ö¸Áî¸ñÊ½: research <¼¼ÄÜ> with <Ç±ÄÜµãÊı>\n");
    	}
    	
    	if( !(int)my_skill=me->query_skill(skill,1) )
        	return notify_fail("Äã¶Ô´ËÏî¼¼ÄÜÒ»ÎŞËùÖª£¬ÈçºÎ¸ãÑĞ¾¿£¿\n");
    
    	if( !SKILL_D(skill)->valid_learn(me)) return 0;
    
    	myclass = me->query("class");
    	 	me->set("class",SKILL_D(skill)->skill_class());
    	limit = 450 * 100 / SKILL_D(skill)->effective_level();
    	limit = (limit /5 + 1) * 5;
    	if (myclass)	me->set("class",myclass);
    		else	me->delete("class");
    	
    	if (my_skill >= limit )
    		return notify_fail("ËäÈ»Äã¿àĞÄ×êÑĞ£¬µ«ÊÇÈô·ÇÁíÓĞÆæÓö£¬ÒÑ¾­ÎŞ·¨½øÒ»²½ÁìÎò´ËÏî¼¼ÄÜÁË¡£\n");
    	
    	if (pot <100)
    		 return notify_fail("ÕâµãÇ±ÄÜ²»¹»ÓÃÀ´×öÑĞ¾¿£¨ÖÁÉÙĞèÓÃ100µã£©\n");
    
    	if (pot > (int)me->query("potential") - (int) me->query("learned_points"))
    		 return notify_fail("ÄãµÄÇ±ÄÜµã²»¹»£¡\n");
    	
    	gin_cost = 10000 * 3 / ((int)me->query_int()*(int)me->query_kar());
    	if((int)me->query("gin") < gin_cost)
    	{
		me->set("gin",0);
		return notify_fail("ÄãÏÖÔÚÌ«ÀÛÁË£¬½á¹ûÊ²÷áÒ²Ã»ÓĞÑĞ¾¿³öÀ´¡£\n");
    	}
    	   	

            	if (me->query_int()<= 40)
            	       	amount = 200 + me->query_int() * me->query_int();                		
            	else
            		amount = 200 + 1600 + (me->query_int()-40) * 20;
            		
            	if (me->query("national")=="Ãç×å")	
            		amount = amount * 105/100;	// Ãñ×åÌØĞÔ
            	   	
            	amount = amount * pot * 2 / SKILL_D(skill)->skill_difficulty();
            	
	//	ÒÔÉÏÊµ¼ÊÉÏ¾ÍÊÇÖ±½ÓÑ§Ï°´ËÏî¼¼ÄÜµÄĞ§ÂÊ£¬¶ÔÓÚÑĞ¾¿À´Ëµ£¬/10
	amount = amount /10;	            	
    	write(sprintf("%d\n",amount));
    	
    	write("Äã¶Ô"+SKILL_D(skill)->name()+"×÷ÁËÒ»·¬³¹µ×µÄÑĞ¾¿£¡\n");
    	me->add("learned_points",pot);
    	me->receive_damage("gin", gin_cost );  	
    	me->research_skill(skill,amount);
    	
    	return 1;
}
            	
            	
int help(object me)
{
    write( @HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	research <¼¼ÄÜ> with <Ç±ÄÜµãÊı>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

·çÔÆÖĞ¹²ÓĞËÄÖÖ»ñÈ¡¼¼ÄÜµÄÍ¾¾¶£º	¶ÁÊé£¨study£©
				Ñ§Ï°£¨learn£©
				[1;31m×êÑĞ£¨research£©[0m
				Á·Ï°£¨practice£©

µ±Äã³É³¤µ½Ò»¶¨³Ì¶È£¬»á·¢ÏÖ×Ô¼ºÒÑ¾­Ñ§»áÁËËùÓĞÊ¦¸µÄÜ´«ÊÚµÄ¼¼ÄÜ£¬
µ±È»ÄãÈÔÈ»¿ÉÒÔ±éÀú¸÷µØ£¬Ñ°·ÃĞÂµÄÊ¦¸µ»òÕßÎä¹¦ÃØ¼®£¬·çÔÆÀïÓĞ×ã¹»
µÄ¶«Î÷¿ÉÑ§¡£µ«ÁíÒ»·½Ãæ£¬ÄãÒ²¿ÉÒÔÀûÓÃ×Ô¼ºµÄ²ÅÖÇÔÄÀú£¬¶ÔÒÑÑ§»áµÄ
¹¦·ò½øÒ»²½×êÑĞ¡£×êÑĞÊÇÒ»ÖÖ×ÔÎÒÁìÎòºÍ·ÉÔ¾µÄ¹ı³Ì£¬ÄÑ¶ÈÒª±ÈÏòÊ¦¸µ
Ñ§Òª´óµÃ¶à£¬²»¹ıÎ¨ÓĞÕâÑù£¬Äã²ÅÄÜ³¬Ô½Ç°ÈË£¬³ÉÎªÒ»´ú×ÚÊ¦¡£

ÕâÒ»Ö¸ÁîÈÃÄãÓÃÖ¸¶¨µÄÇ±ÄÜ¶ÔÄ³Ïî¼¼ÄÜ×÷ÉîÈëµÄÑĞ¾¿¡£
Ò»°ãÀ´Ëµ£¬ÑĞ¾¿µÄÄÑ¶ÈÊÇÍ¬Ñù´ÓÊ¦¸µÄÇ¶ùÑ§Ï°´ËÏîµÄ10±¶¡£
¸üÄÑµÄÊÇ£¬×êÑĞĞèÒªÉı¼¶µÄµãÊıÊÇÑ§Ï°µÄÁ½±¶£¬

¾ÙÀı£º
£ªµûÁµ»¨½£·¨ (diesword)                  - ´ÖÍ¨Æ¤Ã«  22/  530
Èç¹ûÄãÏòÊ¦¸µÑ§£¬»¨Ò»µãÇ±ÄÜÁ¢¼´ÄÜÉıÎª 23¼¶¡£
Èç¹ûÄãÊÇ×Ô¼º×êÑĞ£¬ĞèÒª³ÉÎª
£ªµûÁµ»¨½£·¨ (diesword)                  - ´ÖÍ¨Æ¤Ã«  22/  1060
ºó²ÅÄÜÉıµ½23¼¶¡£

×êÑĞµÄĞ§ÂÊÓëÒÔÏÂÒòËØÏà¹Ø£º
£¨1£©²ÅÖÇ£ºÔ½´ÏÃ÷µÄÈË£¬ÓÃÍ¬ÑùµÄÇ±ÄÜÁìÎòµ½µÄ¼¼ÄÜ¾Í¶à¡£
£¨2£©¼¼ÄÜÖÖÀà£º²»Í¬µÄÎä¹¦¼¼ÄÜÄÑ¶È²»Í¬£¬×îÈİÒ×µÄÊÇ´ò»ù´¡µÄ¹¦·ò¡£
£¨3£©Ãñ×åÌØĞÔ£¬Ãç×åµÄ×êÑĞĞ§ÂÊ±È½Ï¸ß¡£

×êÑĞµÄ¾ÖÏŞ£ºÈËÁ¦ÓĞÇî¾¡Ö®Ê±£¬µ±ÄãµÄ¼¼ÄÜ´ïµ½Ò»¶¨¼¶±ğÊ±£¬
£¨¼¼ÄÜµÈ¼¶xÏµÊı>= 450)
Èô·ÇÔÙÓĞÆæÔµ£¬¹â¿¿¸öÈËµÄ×êÑĞ¾ÍÎŞ·¨½øÒ»²½Ìá¸ßÁË¡£
Ê¹ÓÃÃüÁî Research <¼¼ÄÜ> with limit ¿ÉÒÔ²é¿´ÄãËùÓµÓĞ¼¼ÄÜ¿É´ïµ½
µÄ×î´óµÈ¼¶¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
   );
    return 1;
}

