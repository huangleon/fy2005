// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1


int main(object me, string arg)
{
	object soldier,*enemy;
	string where;
	int strategy,leadership, exp, title , cost, sen, yue,hate;
	int duration, i,timer;
	
	if ((string)me->query("class") != "official")
		return notify_fail("Äã²»ÊÇ³¯Í¢Ãü¹Ù£¬»¹ÊÇ×Ô¼ºÕÕ¹Ë×Ô¼º°É£¡\n");
	
	 if (userp(me))
     if (REWARD_D->check_m_success(me,"×İºáÌìÏÂ") || me->query("family/master_id")=="master yue")
        	return notify_fail("³Û³Ò½®³¡µÄÄÄ¶ù»¹ÓĞ´óÄÚ¸ßÊÖ±£»¤°¡¡£\n");
	
	if (ANNIE_D->check_buff(me,"lockfield") >= 1)
	{
		tell_object(me,YEL"ÄãÕÅ¿ÚÓûĞ¥£¬È´Í»È»·¢ÏÖ·¢²»³öÒ»µãÉùÒô¡£\n"NOR);
		return 0;
	}

	timer  = 6;
		
	strategy = (int)me->query_skill("strategy",1);
	leadership = (int)me->query_skill("leadership",1);
	if(strategy < 25 || leadership < 25)
		return notify_fail("Ğ¥¾¯ÖÁÉÙĞèÒª25¼¶±ø·¨ºÍ25¼¶ÓÃÈËÖ®¼¼!\n");	
	
	if( !me->is_fighting() )
    	return notify_fail("ºÃÏóÃ»ÓĞÈËÒªÉ±Äã£¡\n");
		
	duration = me->query("timer/pfm/alert")-time() + timer;
    if (duration >0)
		return notify_fail("Äã»¹ĞèÒªµÈ´ı"+(int)(duration)+"ÃëÖÓ×óÓÒ²ÅÄÜÔÙ´ÎĞ¥¾¯¡£\n");
	        	
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("ÒÔÄãÏÖÔÚµÄ¹ÙÎ»£¬ÄãÒÑ¾­ÊÜµ½×ã¹»µÄ±£»¤£¡\n");
		
	//	high cost for alert.	
	cost = me->query("max_sen")/5;
	cost = (cost> 800)? 800 : cost;
	if ( me->query("sen") < cost)
		return notify_fail("ĞèÒª" + cost + "µãĞÄÉñ£¡\n");
	me->receive_damage("sen",cost);
   
    me -> set("timer/pfm/alert",time());
    
    if (random(leadership+strategy)< 13 && leadership + strategy <=260) {
       	message_vision(HIB "\n$N·¢³öÒ»Éù³¤Ğ¥ÇóÔ®£¡µ«ÊÇÊ²÷áÒ²Ã»ÓĞ·¢Éú£¡\n" NOR, me);   
		return 1;
	}  	
    	
	if (leadership + strategy >260 && random(100)<5)  
		message_vision(HIB "\n$N·¢³öÒ»Éù³¤Ğ¥ÇóÔ®£¡µ«ÊÇÊ²÷áÒ²Ã»ÓĞ·¢Éú£¡\n" NOR, me); 
	else {
		seteuid(getuid());
		soldier= new("/obj/npc/danei_guard");
		message_vision(HIB "\n$N·¢³öÒ»Éù³¤Ğ¥ÇóÔ®£¡\n" NOR, me);   
        soldier->set("possessed", me);
        soldier->set_leader(me);
      	    
        title = leadership+ strategy;
        	
        if (title < 200)
			soldier->set_name("´óÄÚ¸ßÊÖ",({ "bodyguard" }));
		else if (title < 300)
			soldier->set_name(HIY"ÓùÇ°ÊÌÎÀ"NOR,({ "bodyguard" }));
		else 
			soldier->set_name(HIR"½õÒÂÎÀ"NOR,({ "bodyguard" }));

        me->add_temp("max_guard",1);			
		soldier->move(environment(me));	
		soldier->invocation(me, (leadership+strategy));

		if (soldier) {
	       	message_vision(HIB "\n$NÓ¦Éù¶øÀ´£¡\n" NOR, soldier);
	       	message_vision("$NºÈµÀ£º´óµ¨£¡¾¹¸ÒºÍ³¯Í¢Ãü¹Ù¹ı²»È¥£¡\n" NOR,soldier);
	       	enemy = me->query_enemy();
		    if (enemy)
	    	for (i=0;i<sizeof(enemy);i++)
	    	{
	       		hate = enemy[i]->query_hate(me);
	       		enemy[i]->add_hate(soldier, hate);     	
	    	}
	       	me->remove_all_killer();
	       	
	    }
	}
		
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½£ºalert[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
¹Ù¸®ÌØÓĞÖ¸Áî£ºÕâ¸öÖ¸ÁîÈÃ¹ÙÔ±ºô»½¸ßÊÖÀ´±£»¤×Ô¼º¡£
ÄÜ·ñÕĞºô³ö¸ßÊÖ£¬ºô³ö¸ßÊÖË®Æ½µÄ¸ßµÍÈ¡¾öÓÚ¹ÙÔ±ÓÃÈËÖ®¼¼ºÍ±ø·¨µÄµÈ¼¶¸ßµÍ¡£

¹Ù¸®µÜ×ÓĞ¥¾¯Ìõ¼ş£º25¼¶±ø·¨ºÍ25¼¶ÓÃÈËÖ®¼¼¡£
ÕÙ»½³öÀ´µÄ¸ßÊÖ·Ö±ğÎª£º
±ø·¨ + ÓÃÈËÖ®¼¼¡¶ 200£º	´óÄÚ¸ßÊÖ
±ø·¨ + ÓÃÈËÖ®¼¼¡¶ 300£º	ÓùÇ°ÊÌÎÀ
±ø·¨ + ÓÃÈËÖ®¼¼¡¶ 450£º	½õÒÂÎÀ	

×¢Òâ£º·çÔÆÂÒÊÀ£¬³¯Í¢ÈË²ÅµòÁã£¬Ğ¥¾¯/ÇóÔ®ÄÜ¹»ÕÙµ½µÄ¸ßÊÖÒàÓĞÒ»¶¨ÏŞÖÆ¡£
	¹Ù¸®µÜ×ÓÃ¿6Ãë²ÅÄÜĞ¥¾¯Ò»´Î£¬×î¶àÖ»ÄÜÍ¬Ê±ÓĞÁ½¸ö¸ßÊÖ¡£
	°İÔÀ·Éºó²»ÄÜÔÙĞ¥¾¯¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
