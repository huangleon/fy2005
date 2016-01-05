// steal.c


#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim, guard;
        int sp, dp;

	if(me->query_skill("stealing",1) < 25 )
		return notify_fail("ĞĞÇÔÖÁÉÙĞèÒª£²£µ¼¶µÄÃîÊÖ¿Õ¿ÕÖ®¼¼¡£\n");

        if( environment(me)->query("no_fight"))
                return notify_fail("ÕâÀï½ûÖ¹ĞĞÇÔ¡£\n");
                
	if (guard=present("police",environment(me))) {
		message_vision(guard->query("name")+"¶Ô$NËµ£º¹í¹íËîËîµØÏë¸ÉÊ²Ã´£¿\n",me);
		return 1;
	}
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕıÃ¦£¬µÈ»á¶ùÔÙÏÂÊÖ°É¡£\n");
		
	if( me->query_temp("stealing") )
    	return notify_fail("ÄãÒÑ¾­ÔÚÕÒ»ú»áÏÂÊÖÁË£¡\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("Ö¸Áî¸ñÊ½£ºsteal <ÎïÆ·> from <ÈËÎï>\n");

        victim = present(who, environment(me));
        if( !victim || victim==me) return 
		notify_fail("ÄãÏëĞĞÇÔµÄ¶ÔÏó²»ÔÚÕâÀï¡£\n");
	if( !victim->is_character())
		return notify_fail("Äã¿ÉÓÃ£ç£å£ô¡¡£¼¶«Î÷£¾¡¡£æ£ò£ï£í¡¡£¼ÈİÆ÷£¾¡£\n");
	if (victim->is_corpse())
		return notify_fail("²»±ØÍµÁË£¬Ö±½ÓÄÃ¾ÍĞĞ¡£\n");
	if( !wizardp(me) && wizardp(victim) )
                return notify_fail("Íæ¼Ò²»ÄÜÍµÌìÉñÉíÉÏµÄ¶«Î÷¡£\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("ÄãÎŞ·¨Íµ´ËÈËÉíÉÏµÄ¶«Î÷¡£\n");
	}
		
        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail(victim->name() + "ÉíÉÏ¿´ÆğÀ´Ã»ÓĞÊ²÷áÖµÇ®µÄ¶«Î÷ºÃÍµ¡£\n");
                ob = inv[random(sizeof(inv))];
        }
        
        sp = (me->query_skill("stealing") + me->query_kar())*100/360;
        	if( sp < 1 ) sp = 1;
        	if (sp > 100) sp=100;
        	if( me->is_fighting() ) {
                	sp /= 2;
                	me->start_busy(3);
        	}
        
        dp = (victim->query("sen")+ ob->weight()/10)*100/(me->query("sen")+1);
        	if (dp<100) dp = 100;
                if( victim->is_fighting() ) dp *= 3;
        	if( ob->query("equipped") ) dp *= 5;

        write("Äã²»¶¯ÉùÉ«µØÂıÂı¿¿½ü" + victim->name() + "£¬µÈ´ı»ú»áÏÂÊÖ\n¡­¡­\n\n");
		if (wizardp(me)) tell_object(me,"sp="+(string)(sp)+", dp="+(string)(dp)+"\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp);
        return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
  
    	if (!me)	return;
    	
    	me->delete_temp("stealing");

//		if (me->query("class")!= "beggar") 
//			me->add("score",-1);
	
		if(!victim) {
        	tell_object(me, "Ì«¿ÉÏ§ÁË£¬ÄãÏÂÊÖµÄÄ¿±êÒÑ¾­²»¼ûÁË¡£\n");
            return;
        }
        
        if (!ob) {
        	tell_object(me, "Ì«¿ÉÏ§ÁË£¬ÄãÏëÍµµÄ¶«Î÷ÒÑ¾­ÏûÊ§ÁË¡£\n");
            return;
        }
        
        if (environment(ob)!= victim) {
        	tell_object(me,"¹ÖÁË£¬ÕâÑù¶«Î÷ÒÑ¾­²»ÔÚ´ËÈËÉíÉÏÁË¡£\n");
        	return;
        }
        	
        
        if(environment(victim) != environment(me) ) {
            tell_object(me, "Ì«¿ÉÏ§ÁË£¬ÄãÏÂÊÖµÄÄ¿±êÒÑ¾­×ßÁË¡£\n");
            return;
        }
        
		if((int)ob->query("no_get")||(int)ob->query("lore")) {
			tell_object(me,"ÄãËÆºõÃşµ½ÁËÊ²Ã´£¬²»¹ıÃ»·¨ÌÍ³öÀ´¡£\n");
			return;
		}
        
        if( victim->query_temp("is_unconcious") || (random(sp+dp) > dp) ) {
                if( !ob->move(me) ) {
        	        tell_object(me, sprintf("ÄãÃşµ½Ò»%s%s£¬¿ÉÊÇ¶ÔÄã¶øÑÔÌ«ÖØÁË£¬²»µÃ²»·ÅÆú¡£\n",ob->query("unit"),ob->name()));
                    return;
                }
                tell_object(me, HIW "µÃÊÖÁË£¡\n\n" NOR);
                tell_object(me, sprintf("Äã³É¹¦µØÍµµ½Ò»%s%s£¡\n",ob->query("unit"),ob->name()));
                if( living(victim) )
                if( random(sp) < dp/4 )
                        message("vision", sprintf("Äã¿´µ½%s¹í¹íËîËîµØ´Ó%sÉíÉÏÍµ×ßÁËÒ»%s%s£¡\n",
                        			 me->name(),victim->name(),ob->query("unit"),ob->name()),
                        	environment(me), ({ me, victim }) );
                return;
        } else if( random(sp) > dp/4 ) {
                        tell_object(me, victim->name() + "²»¾­ÒâµØÒ»×ªÍ·£¬Äã¼±Ã¦½«ÊÖËõÁË»ØÈ¥£¡\n»¹ºÃ£¬Ã»ÓĞ±»·¢ÏÖ¡£\n");
                        return;
        } 
        tell_object(me, HIR "Ôã¸â£¡ÄãÊ§ÊÖÁË£¡\n\n" NOR);
        message_vision("$NÒ»»ØÍ·£¬ÕıºÃ·¢ÏÖ$nµÄÊÖÕı×¥Öø$PÉíÉÏµÄ" + ob->name() + "£¡\n\n"+ "$NºÈµÀ£º¡¸¸ÉÊ²÷á£¡¡¹\n\n", victim, me);

        if( userp(victim)) 
        	victim->fight_ob(me);
        else 
        	victim->kill_ob(me);
        
        me->fight_ob(victim);
                        
        me->perform_busy(5 - me->query_skill("stealing",1)/100);
	                         
//        me->add("thief", 1);
}



int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	steal <Ä³Îï> from <Ä³ÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÈÃÄãÓĞ»ú»áÍµµ½ËûÈËÉíÉÏµÄ¶«Î÷¡£³É¹¦ÁË, µ±È»Äã¾ÍÄÜ»ñµÃ
¸ÃÑùÎïÆ·¡£¿ÉÊÇ, ÂíÓĞÊ§Ìã, ÈË×ÜÓĞÊ§·çµÄÊ±ºò, µ±ÄãÊ§°ÜÊ±µ±È»¾Í
µÃ¸¶³ö´ú¼Û, ÊÜº¦Õß¶ÔÇî½Ğ»¨×ÓÒ²Ğí»¹»áÍø¿ªÒ»Ãæ£¬¶ÔÆäËûÈË¿É¾Í²»
»áÁôÇéÁË¡£¡£¡£¡£


[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

HELP
    );
    return 1;
}
 
