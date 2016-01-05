// practice.c ËùÓĞÎä¹¦µÄPractice²»³¬¹ı100¼¶¡£
//	Í³Ò»½µµÍÁËpracticeµÄÄÑ¶È£¬Ö»Óë»ù±¾¼¼ÄÜµÄ¸ßµÍÓĞ¹Ø
//	È¥³ıÁËµ¥Ò»µÄpractice£¬Ç¿ÆÈÍæ¼ÒÊ¹ÓÃ½ÚÊ¡ÏµÍ³×ÊÔ´µÄÍ¾¾¶¡£
//		--- by Silencer@fy

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string p_skill, skillname;
    	int skill, skill_basic, skill_level, skill_prac_limit;
    	int amount, times, num;
    	int o_kee, o_gin, o_sen, o_force, o_mana, o_atman;
    	int c_kee, c_gin, c_sen, c_force, c_mana, c_atman;    
    	int p_kee, p_gin, p_sen, p_force, p_mana, p_atman;
    
    	seteuid(getuid());
    	if(environment(me)->query("no_fight")||environment(me)->query("no_practice"))
        	return notify_fail("Äã²»¿ÉÒÔÔÚÕâÀïÁ·Ï°¡£\n");
    
    	if( me->is_fighting() )
        	return notify_fail("ÄãÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");
    
    	if(!arg)
        	return notify_fail("Ö¸Áî¸ñÊ½£ºpractice <¼¼ÄÜ> <Á·Ï°´ÎÊı>\n");    
    	
    	if (sscanf(arg, "%s %d", p_skill, times)!=2)
    	    		return notify_fail("Ö¸Áî¸ñÊ½£ºpractice <¼¼ÄÜ> <Á·Ï°´ÎÊı>\n");    
    	
    	if( !p_skill ) 
    		return (__DIR__"enable")->main(me, p_skill);
    
    	if( !stringp(skillname = me->query_skill_mapped(p_skill)) )
        	return notify_fail("ÄãÖ»ÄÜÁ·Ï°»ù±¾¼¼ÄÜ£¬Í¬Ê±±ØĞëÏÈÖ¸¶¨£¨enable£©
Ò»ÏîÌØÊâ¼¼ÄÜµ½ÒªÁ·Ï°µÄ»ù±¾¼¼ÄÜÉÏ¡£\n");

	if (times < 1)
		return notify_fail("Á·Ï°´ÎÊı±ØĞë´óÓÚµÈÓÚÒ»¡£\n");
		
    	skill_basic = me->query_skill(p_skill,1)/2 + 1;
    	skill = me->query_skill(skillname) + 1;
    	skill_prac_limit = SKILL_D(skillname)->practice_limit() > 99 ? 99 : SKILL_D(skillname)->practice_limit();

//      skill_prac_limit = SKILL_D(skillname)->practice_limit();
        	
    	if( skill < 1 )
        	return notify_fail("ÄãºÃÏñ»¹Ã»Ñ§»áÕâÏî¼¼ÄÜ°É£¿×îºÃÏÈÈ¥Çë½Ì±ğÈË¡£\n");
    	if( skill_basic < 1 )
        	return notify_fail("Äã¶ÔÕâ·½ÃæµÄ¼¼ÄÜ»¹ÊÇÒ»ÇÏ²»Í¨£¬×îºÃÏÈ´Ó»ù±¾Ñ§Æğ¡£\n");
        	
    	if( me->query_skill(skillname,1) > skill_prac_limit)
    		return notify_fail( SKILL_D(skillname)->name()+"ÔÙÍùºóÖ»ÄÜ¿¿Ñ§Ï°»òÑĞ¾¿À´Ìá¸ßÁË¡£\n");
  
    	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
    
    	skill_level= (int) me->query_skill(skillname, 1);

    	notify_fail("ÄãÊÔÖøÁ·Ï°" + SKILL_D(skillname)->name() + "£¬µ«ÊÇ²¢Ã»ÓĞÈÎºÎ½ø²½¡£\n");
    
//    	if ( times >1) {
    		o_kee = me->query("kee");
    		o_gin = me->query("gin");
    		o_sen = me->query("sen");
    		o_force = me->query("force");
    		o_mana = me->query("mana");
    		o_atman = me->query("atman");
    		//<- get status before 1 practicing
    	
    		//-> Start multi-practicing
	    	if(SKILL_D(skillname)->practice_skill(me)) {
		    	c_kee = me->query("kee");
	    		c_gin = me->query("gin");
	    		c_sen = me->query("sen");
	    		c_force = me->query("force");
	    		c_mana = me->query("mana");
	    		c_atman = me->query("atman");
	    		//<- immediately get current status after 1 practicing
		    	p_kee = o_kee - c_kee;
	    		p_gin = o_gin - c_gin;
	    		p_sen = o_sen - c_sen;
	    		p_force = o_force - c_force;
	    		p_mana = o_mana - c_mana;
	    		p_atman = o_atman - c_atman;
	    		//<- get the consumption
	    		if (p_kee) times = (times > c_kee/p_kee) ? c_kee/p_kee: times;
	    		if (p_gin) times = (times > c_gin/p_gin) ? c_gin/p_gin: times;
	    		if (p_sen) times = (times > c_sen/p_sen) ? c_sen/p_sen: times;
	    		if (p_force) times = (times > c_force/p_force) ? c_force/p_force: times;
	    		if (p_mana) times = (times > c_mana/p_mana) ? c_mana/p_mana: times;
	    		if (p_atman) times = (times > c_atman/p_atman) ? c_atman/p_atman: times;
			// <- get the least numbers allowed to practice
	    		if (p_kee) me->add("kee", -p_kee * (times-1));
	    		if (p_gin) me->add("gin", -p_gin * (times-1));
	    		if (p_sen) me->add("sen", -p_sen * (times-1));
	    		if (p_force) me->add("force", -p_force * (times-1));
	    		if (p_mana) me->add("mana", -p_mana * (times-1));
	    		if (p_atman) me->add("atman", -p_atman * (times-1));
	    		// <- receive the practice damage
			//write("times:" + (string) times + "|"+(string) p_kee + "|"+(string)p_gin + "|"+(string)p_sen + "|"+(string)p_force + "|"+(string)p_mana + "|"+(string)p_atman);
	    		if (times > 0) {
	        		amount = skill_basic*20 + 10; 
	        	//	write("amount is"+ amount + "\n");		
	        		// here changed by akuma on 2003-4-10
	        		// for those who have researched to pink :)
	        		if(me->query_learned()[skillname]<=(skill_level+1) * (skill_level+1)+1)
	        		{
	        			me->improve_skill(skillname, amount*times + random(1 + times/5), skill_basic > skill? 0: 1);
	        		}
	        		// <- random(1 + times/5) ***** giving a bit bonus for saving system resource
		        	write( HIY "ÄãµÄ" + SKILL_D(skillname)->name() + "½ø²½ÁË£¡\n" NOR);
	        		me->status_msg("all");
	        		me->force_status_msg("all");
	        		return 1;
	        	}
	        	else 
	        		return notify_fail("ÄãµÄÉíÌå×´¿öÎŞ·¨Ç¿»¯Á·Ï°" + SKILL_D(skillname)->name() + "¡£\n");
	    	}
/*    	}
    	else {
	    	if(SKILL_D(skillname)->practice_skill(me)) {
	        	amount = (skill - 75) * SKILL_D(skillname)->black_white_ness()/100;
	        	if((amount < -25) && (skill < 75)) amount = -25;
	        	amount +=SKILL_D(skillname)->practice_bonus() + skill_basic/5 + 1;
	        	if( amount < 1) amount = 1;
	       		
	       		if (skill_level <30 && amount <3) amount =3;	
	       		if (skill_level >100) amount = amount*2;
	       		else if (skill_level >75) amount = amount*5;
	       		else amount = amount*10;
	       		
			if(me->query_learned()[skillname]<=(skill_level+1) * (skill_level+1)+1)
			{
	        		me->improve_skill(skillname, amount, skill_basic > skill? 0: 1);
	        	}
	        	write( HIY "ÄãµÄ" + SKILL_D(skillname)->name() + "½ø²½ÁË£¡\n" NOR);
	        	return 1;
	    	}
    	}*/
    	return 0;    
}

int help(object me)
{
    write(@TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	practice <¼¼ÄÜ> <Á·Ï°´ÎÊı>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

·çÔÆÖĞ¹²ÓĞËÄÖÖ»ñÈ¡¼¼ÄÜµÄÍ¾¾¶£º	¶ÁÊé£¨study£©
				Ñ§Ï°£¨learn£©
				×êÑĞ£¨research£©
				[1;31mÁ·Ï°£¨practice£©[0m
				
´ËÖ¸ÁîÈÃÄãÁ·Ï°Ä³¸öÖÖÀàµÄ¼¼ÄÜ£¬Á·Ï°Ê±²»»¨·ÑÇ±ÄÜ£¬Ö»ºÄ·ÑÒ»¶¨Êı
Á¿µÄ¾«ÆøÉñÖµ£¬Õâ¸ö¼¼ÄÜ±ØĞëÊÇ¾­¹ı enable µÄ×¨Òµ¼¼ÄÜ¡£

Ã¿Ò»´ÎÁ·Ï°µÄµÃÒæ = »ù±¾¼¼ÄÜµÈ¼¶*10 + 10

Èç¹ûÄãÕâ·½ÃæµÄ»ù±¾¼¼ÄÜ¹»¸ß£¬¿ÉÒÔ¾­ÓÉÁ·Ï°Ö±½ÓÉı¼¶£¬Éı¼¶µÄÉÏÏŞ
Ö»¸úÄã»ù±¾¼¼ÄÜµÄµÈ¼¶ÓĞ¹Ø£¬µ±È»£¬ÔÚÕâÖ®Ç°Äã±ØĞë´ÓÊµ¼ÊÔËÓÃÖĞ»ñ
µÃ×ã¹»µÄ¾­ÑéÒÔÌáÉıÄãµÄ»ù±¾¼¼ÄÜ¡£

¿ÉÒÔÖ±½ÓÉı¼¶µÄ×î¸ßµÈ¼¶ = »ù±¾¼¼ÄÜµÈ¼¶/2/ÌØÊâ¼¼ÄÜµÄÏµÊı

¾ÙÀı£º

£¨1£©ĞùÔ¯¸«Îä¹¦ÏµÊı = 2
Èç¹ûÄãµÄ»ù±¾¸«·¨Îª100¼¶£¬ÄãÄÜÁ·Ï°ĞùÔ¯¸«·¨ÖÁ100/2/2 = 25
ÔÙÍùÏÂÄã¾Í»á·¢ÏÖ¼¼ÄÜÎª
[35m£ªĞùÔ¯¸«·¨ (xuanyuan-axe)[0m     - ´ÖÍ¨Æ¤Ã«  25/  677
ÕâÊ±ºòÄãĞèÒªÏòÊ¦¸µ»¨·ÑÒ»µãÇ±ÄÜÑ§Ï°²ÅÄÜÉı¼¶¡£

£¨2£©µûÁµ»¨½£·¨ÏµÊıÎª2.3£¬
Èç¹ûÄãÓĞ100¼¶»ù±¾½£·¨£¬ËùÄÜÁ·Ï°µ½µÄ×î¸ß¼¶±ğÎª100/2/2.3 = 22

·çÔÆËÄÌá³«¼õÉÙ²»±ØÒªµÄ»úÆ÷ÈËÁ·¹¦£¬ËùÓĞÎä¹¦µÄÁ·Ï°ÄÑ¶È´ó·ù¶ÈÏÂ
½µ£¬ÌØÊâ¼¼ÄÜÔÚµÈ¼¶100ÒÔÇ°¿ÉÒÔºÜ¿ìµÄÁ·Ï°µ½ÉÏÏŞ£¬µ«ÊÇÔÚ100¼¶ºó
½«²»ÔÙÄÜ¿¿Á·Ï°Ìá¸ß£¬±ØĞëÊ¹ÓÃÊµÕ½ÖĞµÃµ½µÄÇ±ÄÜÀ´ÏòÊ¦¸µÑ§Ï°»ò×Ô
¼ºÑĞ¾¿¡£

Ïà¹ØÃüÁî£º	learn  study  research

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
TEXT
	);
    return 1;
}
