// go.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#pragma optimize all
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"±±",
	"south":		"ÄÏ",
	"east":			"¶«",
	"west":			"Î÷",
	"northup":		"±±±ß¸ß´¦",
	"southup":		"ÄÏ±ß¸ß´¦",
	"eastup":		"¶«±ß¸ß´¦",
	"westup":		"Î÷±ß¸ß´¦",
	"northdown":		"±±±ßµÍ´¦",
	"southdown":		"ÄÏ±ßµÍ´¦",
	"eastdown":		"¶«±ßµÍ´¦",
	"westdown":		"Î÷±ßµÍ´¦",
	"northeast":		"¶«±±",
	"northwest":		"Î÷±±",
	"southeast":		"¶«ÄÏ",
	"southwest":		"Î÷ÄÏ",
	"up":			"ÉÏ",
	"down":			"ÏÂ",
	"out":			"Íâ",
	"enter":		"Àï",
]);

void create() {
	seteuid(getuid());
}

int drop_things(object me) {
	int i, result;
	object *inv;
	object env;

	env = environment(me);
	inv = all_inventory(me);
	result = 0;
	for(i=0;i<sizeof(inv);i++){
		if(inv[i]->query("no_drop") || inv[i]->query("equipped") || inv[i]->query("owner")
				|| random(me->query_max_encumbrance()) > inv[i]->weight()) {
			continue;
		}
		result = me->ccommand("drop "+inv[i]->query("id")) ? 1 : result;
	}
	if(result) {
		message_vision("»ÅÂÒ¶øÈ¥¡£", me);
		return 1;
	}
	return 0;
}


int check_flee(object me, string arg)  {
   	mapping 	my, your;
   	object 	*enemy;
   	int	num, fp, bp, i, level;
   	
   	fp = me->query_agi();
	
	enemy = me->query_enemy();
   	i = sizeof(enemy);
   	while (i--) {
		if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) 
		{
			if (enemy[i]->query("possessed"))		continue;
			if (enemy[i]->query_temp("is_unconcious"))	continue;
			// Since x5 can usually kill 1, Let it not blocking x5.
			if (enemy[i]->query("combat_exp")< me->query("combat_exp")/5) 	continue;
			bp = enemy[i]->query_agi();
			if (fp > bp*2)	continue;	
			if (enemy[i]->is_busy())
				bp = bp * 3/5;
			level = F_LEVEL->get_level(me->query("combat_exp"));
			if ( level <30) fp = fp*3;
			else if (level < 40) fp = fp*2;		
			if((random(fp + bp) < bp)
				|| enemy[i]->query_temp("block_all_escape")) 
			{
				message_vision(YEL "$NÏò" + arg + "ÌÓÈ¥£¡\n" NOR, me);
				message_vision(RED "$NÉíÓ°Ò»ÉÁ£¬µ²ÔÚÁË$nµÄÃæÇ°£¡\n" NOR, enemy[i], me);
				return 0;
		 	}
	  	}
   	}
   	return 1;
}


int main(object me, string arg) {
	string dest, mout, min, dir, blk;
	object env, obj, blocker;
	mapping exit;
	mapping block;
	int water_lvl;
	
	if( !arg ) return notify_fail("ÄãÒªÍùÄÄ¸ö·½Ïò×ß£¿\n");

	if( me->over_encumbranced() )
		return notify_fail("ÄãµÄ¸ººÉ¹ıÖØ£¬¶¯µ¯²»µÃ¡£\n");

	if( me->is_busy() )
		return notify_fail("ÄãÏÖÔÚÃ¦µÃºÜ£¬²»ÄÜÒÆ¶¯¡£\n");

	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));
				
	env = environment(me);
	if(!env) return notify_fail("ÄãÄÄÀïÒ²È¥²»ÁË¡£\n");
	if(env->query_temp("lock_scene"))
	{
		if(time()<env->query_temp("lock_scene")+120)//·ÀÖ¹ÍòÒ»Ã»ÓĞÈ¥µôÄÇ¸ötemp mark£¬³öÎÊÌâ¡£
			return notify_fail("Äã¸Ğ¾õµ½ÖÜÎ§±»Ò»ÕóÆø³¡½ô½ôËõ×¡£¬ÎŞ·¨¶¯µ¯¡£\n");
	}
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("Õâ¸ö·½ÏòÃ»ÓĞ³öÂ·¡£\n");
		else
			return 0;
	}

	
//	ÔÚfy4ÀïÉĞÎ´ÓÃµ½´Ë¹¦ÄÜ£¬ĞèÒªÊ±ÔÙËµ¡£        
/*      if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
		if( objectp(blocker = present(blk, env)) &&  living(blocker))
		return notify_fail("Õâ¸ö·½ÏòµÄÂ·±»"+ blocker->name() + "µ²×¡ÁË ¡£\n");
        }*/

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
	{
		if (!load_object(dest))
		{
			tell_object(me,"Õâ¼äÎİ×ÓÒÑÏûÊ§ÔÚĞé¿ÕÖĞ£®£®£®\n");
			if (wizardp(me) && me->query("env/yesiknow"))
				call_other(dest, "???");
			return 1;
		}
//		call_other(dest, "???");
	}
	
	if( !(obj = find_object(dest)) )
		return notify_fail("ÎŞ·¨ÒÆ¶¯¡£\n");

/*	if (userp(me) && ANNIE_D->check_buff(me,"fugitive")>0
		 && (obj->query("no_fight") || obj->query("no_death_penalty")))
		return notify_fail("ÄãÉí¸ºÖØ°¸£¬ÄÇĞ©µØ·½²»¸ÒÊÕÁôÄãÑ½£¡\n");*/
	
	if (env)
	if (!env->valid_leave(me, arg) ) {
		return 0;
	}
	 
	if( !undefinedp(default_dirs[arg]) )
			dir = default_dirs[arg];
		else if (dest->query("short")) dir=dest->query("short");
		else dir = arg;

	if( me->is_fighting() ) {

		if (ANNIE_D->check_buff(me,"lockfield") >= 1)
		{
			tell_object(me,YEL"ÄãÑÛÇ°µÄ¾°ÎïËÆÕæËÆ»Ã£¬ÓÎÒÆ²»¶¨£¬ÄÑÒÔÈ·¶¨µÀÂ·¾¿¾¹ÊÇÔÚºÎ·½¡£\n"NOR);
			return 0;
		}

		if (me->query_temp("timer/no_escape") > time()) 
			return notify_fail("ÄãÏÖÔÚ²»ÄÜÌÓÅÜ£¡\n");

		// Ã¿3¸öheart_beatÀïÖ»ÓĞÒ»´ÎÌÓÅÜµÄ³¢ÊÔ¿ÉÄÜ³É¹¦¡£
		if (me->query_temp("marks/escape") + 6 > time()) {
			return notify_fail("Äã±»µ²ÁË»ØÀ´¡£\n");
		}
		if(check_flee(me, dir) == 0) {
			me->set_temp("marks/escape",time());
			return notify_fail("Äã±»µ²ÁË»ØÀ´¡£\n");
		}
		if (me->query("timer/insurance") + 259200 < time())
			drop_things(me);
		
		if (me->query("fleeout_message")) {
		    mout = replace_string( me->query("fleeout_message"), "$d", dir );
		    mout = mout + "¡£\n";
		 }
         else 
         	mout = "Íù" + dir + "Âä»Ä¶øÌÓÁË¡£\n";
         if (me->query("fleein_message")) 
         	min  = me->query("fleein_message") + "¡£\n";
         else  
         	min = "µøµø×²×²µØÅÜÁË¹ıÀ´£¬Ä£ÑùÓĞĞ©ÀÇ±·¡£\n";

	} else {
// Let's add this messages here to make go and come more interesting...
		if( mout = me->query("leave_msg"))
			mout = "Íù" + dir + mout +"¡£\n";
		else 
			mout = "Íù" + dir + "Àë¿ª¡£\n";
		if( min = me->query("arrive_msg") )
			min = min + "¡£\n";
		else
			min = "×ßÁË¹ıÀ´¡£\n";
	}
	
	if (userp(me))
	if (obj->query("underwater") > me->query_skill("swimming",1))
		return notify_fail("ÄãµÄÓÎÓ¾¼¼ÄÜÌ«²î£¬Ã»·¨¹ıÈ¥Ñ½£¨ĞèÒª¼¼ÄÜ"+obj->query("underwater")+"¼¶£©\n");
		
	if (!userp(me) && obj->query("NONPC"))
		return notify_fail("Äã²»¿ÉÈ¥ÄÇÀï¡£\n");
	else if( function_exists("valid_enter", obj) && !obj->valid_enter(me))
		return notify_fail("Äã²»¿ÉÈ¥±ğÈËµÄË½Õ¬¡£\n");
		
	if(!me->is_ghost())
		if( me->query("self_go_msg") )		// this is for ×Ô¶¨ÒåµÄ²»´øÖ÷ÓïµÄÀë¿ª
			message( "vision", me->query("leave_msg")+"\n", environment(me), ({me}) );
		else if (me->query("env/invisibility"))
			message("vision","ËÆºõÓĞÊ²Ã´¶«Î÷Ò»ÉÁºó²»ÖªÏòÊ²Ã´·½ÏòÈ¥ÁË¡£\n",environment(me),({me}));
		else  message( "vision", me->name() + mout, environment(me), ({me}) );

	if( me->move(obj) ) {
		me->remove_all_enemy();
		if(!me->is_ghost())
			if( me->query("self_go_msg") )	// this is for ×Ô¶¨ÒåµÄ²»´øÖ÷ÓïµÄ½øÈë
				message( "vision", me->query("arrive_msg")+"\n", environment(me), ({me}) );
			else if(me->query("env/invisibility"))
				message("vision","ËÆºõÓĞÊ²Ã´¶«Î÷ÉÁÁË½øÀ´¡£\n",environment(me),({me}));
			else	
				message( "vision", me->name()+ min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		
		if(env)
		if(environment(me) != env) {
			all_inventory(env)->follow_me(me, arg);
		}
		
		return 1;
	}

	return 0;
}


void do_flee(object me) {
	mapping exits;
	string *directions;

	if(!environment(me) || !living(me)) {
		return;
	}
	exits = environment(me)->query("exits");
	if(!mapp(exits) || !sizeof(exits)) {
		return;
	}
	directions = keys(exits);
	if (!me->query_temp("no_flee_msg"))
		tell_object(me, "¿´À´¸ÃÕÒ»ú»áÌÓÅÜÁË...\n");
	main(me, directions[random(sizeof(directions))]);
}




int help(object me) {
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	go <·½Ïò>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÈÃÄãÍùÖ¸¶¨µÄ·½ÏòÒÆ¶¯¡£

Äã¿ÉÒÔÔÚÕ½¶·ÖĞÓÃ´ËÖ¸Áî³¢ÊÔÌÓÀëµ±Ç°·¿¼ä£¬
£±¡£ÌÓÀëµÄ¼¸ÂÊÖ±½ÓÈ¡¾öÓÚÕ½¶·Ë«·½µÄÏà¶ÔÃô½İ¶È
£²¡£ÔÚ¶ÔÊÖÃ¦ÂÒ£¨£â£õ£ó£ù£©Ê±ÄãµÄÌÓÅÜ¼¸ÂÊÔö´ó£´£°£¥
£³¡£Ã¿Èı¸öÕ½¶·»ØºÏÖ»ÄÜÓĞÒ»´ÎÌÓÅÜ³¢ÊÔ¿ÉÄÜ³É¹¦
£¨Ò²¾ÍÊÇËµ£¬¼´Ê¹ÄãÔÚÁùÃëÖÓÄÚÁ¬×ÅÊäÈë100¸ögo£¬ÏµÍ³Ö»¸ù¾İµÚÒ»¸öÀ´ÅĞ¶Ï£©
£´¡£ÔÚµÍµÈ¼¶Ê±£¨£Ì£´£°Ç°£©Ôö¼ÓÌÓÅÜ¼¸ÂÊ£±£°£¥£­£²£µ£¥

ÊıÖµ¼ÆËã¼°ËµÃ÷£ºa = ÌÓÅÜÕßËÙ¶È£»b = µĞÈËËÙ¶È
µ±£ò£á£î£ä£ï£í(a + b ) < b Ê±£¬ÌÓÅÜÊ§°Ü

£±£®Èç¹ûµĞÈË´¦ÔÚ»èÃÔ×´Ì¬£¬ÌÓÅÜ±ØÈ»³É¹¦
£²£®Èç¹ûµĞÈË¾­ÑéÖµµÍÓÚÌÓÅÜÕßµÄ£²£°£¥£¬ÌÓÅÜ±ØÈ»³É¹¦
£³£®Èç¹û£á£¾£²£â£¬ÌÓÅÜ±ØÈ»³É¹¦
£´£®Èç¹ûµĞÈË´¦ÔÚÃ¦ÂÒ×´Ì¬£¬£â*£¶£°£¥
£µ£®Èç¹ûÌÓÅÜÕßµÈ¼¶µÍÓÚ£³£°£¬£á*£²
£¶£®Èç¹ûÌÓÅÜÕßµÈ¼¶µÍÓÚ£´£°£¬£á*£²

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
	);
	return 1;
}