// kill.c
// Modified by justdoit at Dec 5,2001
// When player type kill,KILL_LOG file will add user id in it.

#include <ansi.h>
inherit F_CLEAN_UP;
int legitimate_kill(object attacker, object victim);

int main(object me, string arg)
{
	object obj;
	string *killer, callname;
	seteuid(getuid());

	if( environment(me)->query("no_fight") )
		return notify_fail("ÕâÀï²»×¼Õ½¶·¡£\n");

	if( !arg )
		return notify_fail("ÄãÏëÉ±Ë­£¿\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("ÕâÀïÃ»ÓÐÕâ¸öÈË¡£\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("¿´Çå³þÒ»µã£¬ÄÇ²¢²»ÊÇ»îÎï¡£\n");

	if(obj==me)
		return notify_fail("ÓÃ suicide Ö¸Áî»á±È½Ï¿ì:P¡£\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("ÄãÎÞ·¨¹¥»÷´ËÈË¡£\n");
	}
	
	callname = RANK_D->query_rude(obj);

        if( userp(obj) && environment(obj)->query("no_pk"))
		me->add("vendetta/pker",1);

	if (obj->query("race") != "ÔªËØ" && me->query("race") != "ÔªËØ")
		message_vision("\n$N¶ÔÖø$nºÈµÀ£º¡¸" 
		+ callname + "£¡½ñÈÕ²»ÊÇÄãËÀ¾ÍÊÇÎÒ»î£¡¡¹\n\n", me, obj);
	else
		message_vision(HIR"\n$N´óºÈÒ»Éù£¬¿ªÊ¼¶Ô$n·¢¶¯¹¥»÷£¡\n\n"NOR, me, obj);


	me->kill_ob(obj);
	if( !userp(obj) || !userp(me))
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "Èç¹ûÄãÒªºÍ" + me->name() 
			+ "ÐÔÃüÏà²«£¬ÇëÄãÒ²¶ÔÕâ¸öÈËÏÂÒ»´Î kill Ö¸Áî¡£\n" NOR);
	}

	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	kill <ÈËÎï>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÈÃÄãÖ÷¶¯¿ªÊ¼¹¥»÷Ò»¸öÈËÎï£¬²¢ÇÒ³¢ÊÔÉ±ËÀ¶Ô·½£¬kill ºÍ fight 
×î´óµÄ²»Í¬ÔÚì¶Ë«·½½«»áÕæµ¶ÊµÇ¹µØ´ò¶·£¬Ò²¾ÍÊÇËµ£¬»áÕæµÄËÀÉË¡£ÓÉì¶ 
kill Ö»Ðèµ¥·½ÃæÒ»ÏáÇéÔ¸¾Í¿ÉÒÔ³ÉÁ¢£¬Òò´ËÄã¶ÔÈÎºÎÈËÊ¹ÓÃ kill Ö¸Áî¶¼
»á¿ªÊ¼Õ½¶·£¬Í¨³£Èç¹û¶Ô·½ÊÇ NPC µÄ»°£¬ËûÃÇÒ²»áÍ¬Ñù¶ÔÄãÊ¹ÓÃ kill¡£

µ±ÓÐÈË¶ÔÄãÊ¹ÓÃ kill Ö¸ÁîÊ±»á³öÏÖºìÉ«µÄ×ÖÑù¾¯¸æÄã£¬¶Ôì¶Ò»¸öÍæ¼Ò¶ø
ÑÔ£¬Èç¹ûÄãÃ»ÓÐ¶ÔÒ»ÃûµÐÈËÊ¹ÓÃ¹ý kill Ö¸Áî£¬Ò»°ã²»»á½«¶Ô·½ÕæµÄ´òÉË
»òÉ±ËÀ¡£µ±È»£¬µ¶Ç¹ÎÞÑÛ£¬Å¼¶ûÒ²»áÓÐÀýÍâ£¬ËùÒÔÈç¹ûÊÇ±ÈÎä½¨Òéµ½ÑÅÈË
´¦¡£

ÆäËûÏà¹ØÖ¸Áî: fight

ÓÐ¹Ø fight ¸ú kill µÄÇø·ÖÇë¿´ 'help combat'.

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
 
