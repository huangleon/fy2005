#include <ansi.h>
inherit F_CLEAN_UP;
int do_recover(object me,object target);

int main(object me, string arg)
{
		object target;
			
		if (!arg)
        	return notify_fail("ÁËÎò±ØÐëÖ¸¶¨¶ÔÏó¡£\n");
        
       	if(!objectp(target = present(arg, environment(me))))
				return notify_fail("ÕâÀïÃ»ÓÐÕâ¸ö¶«Î÷¡£\n");
        	
    	if( !target->is_corpse())
			return notify_fail("ÁËÎò±ØÐëÖ¸¶¨ÓÐÐ§¶ÔÏó£¨ÒÅÌå£©¡£\n");
	
		if (!target->query("victim_player"))
			return notify_fail("ÁËÎòÖ»ÄÜÊ¹ÓÃÔÚ×Ô¼ºµÄÒÅÌåÉÏ¡£\n");
	
		if ( target->query("victim_id")!= me->query("id"))	
			return notify_fail("ÁËÎòÖ»ÄÜÔÚ×Ô¼ºµÄÊ¬ÌåÉÏÊ¹ÓÃ¡£\n");

		if (!mapp(me->query("death")) || me->query("death/half_quest")>=0)
			return notify_fail("ÄãÏÖÔÚÎÞÐëÊ¹ÓÃÁËÎò¡£\n");
		
		if (me->query("score") < 10)
			return notify_fail("ÁËÎòÏûºÄÊ®µãÆÀ¼Û£¬ÄãµÄÆÀ¼Û²»×ã¡£\n");
	
		if (me->is_fighting() || me->is_busy())
			return notify_fail("ÄãÏÖÔÚÕýÃ¦×Å£¬ÈçºÎÄÜ¾²ÏÂÐÄÀ´ÁËÎò£¿\n");
		
		if (target->query_temp("in_reviving"))
			return notify_fail("ÄãÏÖÔÚ²»ÄÜÁËÎòÕâ¾ßÊ¬Ìå¡£\n");
		
		if (target->query("already_revived")|| !target->query("real_death")
			|| me->query("death/revived"))
			return notify_fail("ÄãÒÑ¾­ÎÞ·¨´ÓÕâ´Î×ªÊÀ¾­ÀúÖÐÁìÎòÊ²Ã´ÁË¡£\n");
		
		me->start_busy(10);
		target->set_temp("in_reviving",1);
		
		message_vision(HIW"$N»º»º×ø¶¨£¬×óÊÖ·­×ªÖ¸¶¨$n£¬ÓÒÊÖÐéÍÐÓÚ¸¹Ç°£¬´¹Ê×²»Óï¡£
Á³ÉÏºöÇàºöºì£¬ºö¶øÉí×ÓÎ¢²ü£¬Èç¶éº®±ù£»ºö¶ø¶îÍ·º¹ÈçÓêÏÂ£¬ÈçÂÄÁÒÑæ¡£\n"NOR,me,target);
		call_out("do_recover",20,me,target);
    	return 1;
}

int do_recover(object me,object target){
	
		mapping buff;
		
		if (!me )	return	1;
		
		me->stop_busy();
		
		if (!target) {
			tell_object(me,"ÄãµÄÊ¬ÌåÏûÊ§ÁË£¬ÎÞ·¨ÁËÎò¡£\n");
			return 1;
		}
		target->delete_temp("in_reviving");
		
		if (environment(target)!= environment(me)) {
			tell_object(me,"ÄãµÄÁËÎò±»´ò¶ÏÁË¡£\n");
			return 1;
		}
		
		if (me->query("score") < 10) {
			tell_object(me,"ÁËÎòÐèÏûºÄÊ®µãÆÀ¼Û£¬ÄãµÄÆÀ¼Û²»×ã¡£\n");
			return 1;
		}
		
		if (me->is_fighting() || me->is_busy()){
			tell_object(me,"ÄãÏÖÔÚÕýÃ¦×Å£¬ÈçºÎÄÜ¾²ÏÂÐÄÀ´ÁËÎò£¿\n");
			return 1;
		}
		
		if (target->query("already_revived")) {
			tell_object(me,"ÄãÒÑ¾­ÎÞ·¨´ÓÕâ´Î×ªÊÀ¾­ÀúÖÐÁìÎòÊ²Ã´ÁË¡£\n");
			return 1;
		}
		
		message_vision(WHT"$N³¤ÍÂÒ»¿ÚÆø£¬ÂýÂýÕ¾ÆðÉíÀ´£¬ËÆÓÐËùµÃ¡£\n"NOR, me);
		tell_object(me,"£¨ÄãÎò³öÁËÒ»Ð©ÉúËÀÖ®µÀ£¬ÄãµÄËÀÍöËðÊ§½µµÍÁË£©\n");
						
		
		me->add("score",-10);
		target->set("already_revived",1);

		me->add("death/half_quest",me->query("death/exp_lost")*50/100);
		
		if (me->query("death/half_quest")>=0) {
			me->delete("death/half_quest");		// º±¼ûÇé¿ö
			me->delete("death/exp_lost");
		}	

/*		me->set("force",0);
		me->set("atman",0);
		me->set("mana",0);
		me->set("death_revive",time());
		me->force_status_msg("all");
		
		// THis just serves as a timer, all checks use query(death_time), so even relogin can't bypass
		buff =
		([
			"caster":me,
			"who":me,
			"type":"revive-sickness",
			"att":"curse",
			"name":"»¹»ê¡¤ÐéÈõ²»¿°",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$NÉí×ÓÐéÈõµ½ÁË¼«µã£¬Á¬Õ¾¶¼Õ¾²»ÎÈÁË¡£\n"NOR,
		]);
		ANNIE_D->buffup(buff);*/
				
		
		me->set("death/revived",1);
		me->add("marks/self_revive",1);
		me->add("marks/revived",1);
		
		
		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) Ê¹ÓÃmeditate»Ö¸´ÁË×ÔÉí %d µÄËðÊ§¡£\n",
	    		ctime(time()),me->name(1), geteuid(me),
	    		me->query("death/exp_lost")/2));
	    		
		return 1;
}		
			


int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : ÁËÎò	meditate [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 

·çÔÆÀïÎ£»úÖØÖØ£¬ËÀÍöÅ¼ÓÐ·¢Éú£¬²»¹ý£¬Ö»ÒªÄãÄÜ¹»´Ó´ìÕÛÖÐÎò³öµã
Ê²Ã´À´£¬±ãÄÜ¹»½µµÍËÀÍöµÄËðÊ§¡£¸ÃÃüÁîµÄ¾ßÌå¹¦Ð§Çë²Î¿´
£è£å£ì£ð¡¡£ç£á£í£åÖÐµÄËÀÍöÉè¶¨Æª¡£

´ËÃüÁî²»ÄÜÔÚÕ½¶·ÖÐÊ¹ÓÃ£¬×ÔÎÒÃ¦ÂÒ£±£°ÂÖ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
