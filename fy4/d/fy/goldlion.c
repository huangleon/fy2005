inherit ROOM;

void create()
{
    set("short", "½ðÊ¨ïÚ¾Ö´óÔº");
    set("long", @LONG
ÕâÀï¼¸Ê®ÄêÀ´¼¸ºõÃ»ÓÐÊ²Ã´±ä»¯£¬[33mºÚÊ¯[32mÆÌµØ£¬´óÔºÓÒ±ßÁãÂÒµÄ·Å×ÅÒ»Ð©´óÐ¡²»
Ò»µÄ[37mÊ¯Ëø[32m£¬Ïë±ØÊÇïÚ¾ÖÖÐµÄÌË×ÓÊÖÓÃÀ´Á·±ÛÁ¦µÄ¡£×ó²àÔòÊÇÍë¿Ú´ÖÏ¸Ò»ÈË¶à¸ßµÄ[37mÃ·
»¨×®[32m¡£×ÜïÚÍ·²éÃÍÊÇÉÙÁÖË×¼ÒµÜ×Ó³öÉí£¬ËäÈ»½Ì³öµÄÍ½µÜ²»ÔõÃ´Ñù£¬µ«ÊÇËûµÄÇá¹¦
ºÍÕÆ·¨¶¼ÒÑ¾­Â¯»ð´¿ÇàÁË¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ecloud3",
	"east"  : __DIR__"ghall", 
	"northwest" : __DIR__"gcang",
	"southwest" : __DIR__"gkitchen",
      ]));
    set("objects", ([
	__DIR__"npc/biaoshi" : 1,
	__DIR__"npc/biaoshi1": 1,
      ]) );
    set("outdoors", "fengyun");

    set("coor/x",160);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init(){
    add_action("do_look","look");
    add_action("do_lift","lift");
    add_action("do_lian","lian");
}


int do_lift(string arg)
{
    object me;
    int	s, amount, da;

    if(!arg) 
	return notify_fail("ÄãÏë¾ÙÊ²Ã´£¿\n");

    if (arg != "Ê¯Ëø" && arg != "stonehammer") 
	return notify_fail("ÄãÃ»·¨¾ÙÕâ¸ö¡£\n");

    me = this_player();
    if( me->is_fighting() )
		return notify_fail("ÔÚÕ½¶·ÖÐÁ·Ï°£¬ÏëÕÒËÀÂð£¡\n");
    if( me->is_busy() )
		return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓÐÍê³É£¬²»ÄÜÁ·Ï°¡£\n");
    
    me->start_busy(2);
    s = (int)me->query_skill("unarmed", 1);
    
    if(random(30) && me->query("kar")>10 && s>= 10) {
		if(s >= 40) {
		    message_vision("\n$NÄÃÆðÒ»¸ö×î´ó×îÖØµÄÊ¯Ëø£¬Ò²²»¼û·ÑÁËÊ²Ã´¾¢¾Í°ÑËüÈÓµ½ÁË¼¸³ß¸ß¡£\n", me);
		    tell_object(me, "ÕâÐ©Ê¯Ëø¶ÔÄãÀ´ËµÒÑ¾­Ì«ÇáÁË¡£\n");
	
		    if (QUESTS_D->verify_quest(me,"½ðÊ¨Ê¯Ëø")) {
				if (!me->query_temp("marks/js_lift_start")) {
				    me->set_temp("marks/js_lift_start",1);
				    me->delete_temp("marks/js_lift");
				}
				me->add_temp("marks/js_lift",1);
				if (me->query_temp("marks/js_lift")>=10) {
				    QUESTS_D->special_reward(me,"½ðÊ¨Ê¯Ëø");
				    me->delete_temp("marks/js_lift");
				    me->set_temp("marks/js_lift_start",1);
				}
		    }
	
		    return 1;
		} 
		if(s >= 20) 
		    message_vision("\n$NºÙµÄÒ»Éù£¬Õ¾²½¶××®£¬°Ñ¸öÎåÊ®½ïµÄÊ¯ËøÎèµÄÏñ¸ö³µÂÖ×ÓËÆµÄ¡£\n", me);
		else 
		    message_vision("\n$NÒ§½ôÑÀ¹Ø£¬Ð¡Á³ÕÇµÃÍ¨ºì£¬²ü²üÎ¡Î¡µØ°Ñ¸ö¶þÊ®½ïµÄÊ¯Ëø¾Ù¹ýÍ·¶¥¡£\n", me);
	
		tell_object(me, "ÄãµÄ²«¶·Ö®¼¼ºÃÏó³¤½øÁËÒ»Ð©¡£\n");
		amount =  me->query("int") + me->query("str") + me->query_skill("unarmed",1)*25;;
		
		if(amount < 1) amount = 1;
		me->improve_skill("unarmed", amount);
		
		da = 20;
		me->set_temp("last_damage_from","Á·¾ÙÖØ²»Ð¡ÐÄ±»Ê¯ËøµôÏÂÀ´ÔÒËÀÁË¡£");
		me->receive_damage("kee", da);
	
		if (QUESTS_D->verify_quest(me,"½ðÊ¨Ê¯Ëø")) {
		    if (!me->query_temp("marks/js_lift_start")) {
			me->set_temp("marks/js_lift_start",1);
			me->delete_temp("marks/js_lift");
		    }
		    me->add_temp("marks/js_lift",1);
		    if (me->query_temp("marks/js_lift")>=10) {
			QUESTS_D->special_reward(me,"½ðÊ¨Ê¯Ëø");
			me->delete_temp("marks/js_lift");
			me->delete_temp("marks/js_lift_start");
		    }
		}

    } else {
		message_vision("\n$NºÙµÄÒ»Éù£¬Ò»Ò§ÑÀ¾ÙÆðÊ¯Ëø£¬\n", me);
		message_vision("\n»¹Ã»µ½°ëÑü¸ß£¬$NÊÖÒ»ÈíÊ¯ËøµôÏÂÀ´ÕýÔÒÔÚ×Ô¼º½Å±³ÉÏ£¬ÕæÍ´£¡\n", me);
		da = 100;
		me->set_temp("last_damage_from","Á·¾ÙÖØ²»Ð¡ÐÄ±»Ê¯ËøµôÏÂÀ´ÔÒËÀÁË¡£");
		me->receive_damage("kee", da);


		if (QUESTS_D->verify_quest(me,"½ðÊ¨Ê¯Ëø")) {
			if (!me->query_temp("marks/js_lift_start")) {
			    me->set_temp("marks/js_lift_start",1);
			    me->delete_temp("marks/js_lift");
			}
			me->add_temp("marks/js_lift",1);
			if (me->query_temp("marks/js_lift")>=10) {
			    QUESTS_D->special_reward(me,"½ðÊ¨Ê¯Ëø");
			    me->delete_temp("marks/js_lift");
			    me->set_temp("marks/js_lift_start",1);
			}
	    }

    }
    return 1;
}

int do_lian(string arg)
{
    object me;
    int	s, amount, da;

    if(!arg) 
	return notify_fail("ÄãÏëÁ·Ê²Ã´£¿\n");

    if (arg != "Ã·»¨×®" && arg!= "zhuang") 
	return notify_fail("ÄãÃ»·¨Á·Õâ¸ö¡£\n");


    me = this_player();
    if( me->is_fighting() )
	return notify_fail("ÔÚÕ½¶·ÖÐÁ·Ï°£¬ÏëÕÒËÀÂð£¡\n");
    if( me->is_busy() )
	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓÐÍê³É£¬²»ÄÜÁ·Ï°¡£\n");
    me->start_busy(2);
    s = (int)me->query_skill("move", 1);
    if(random(30) && me->query("kar")>10 && s>=10) {
	if(s >= 40) {
	    message_vision("\n$N°ÎÉí¶øÆð£¬·É¿ìµØÔÚÃ·»¨×®ÉÏ×ßÁËÒ»È¦£¬ÓÖäìÈ÷µØÌøÁËÏÂÀ´¡£\n", me);
	    tell_object(me, "ÄãµÄÇá¹¦ºÃÏóÃ»ÓÐÊ²Ã´³¤½ø¡£\n");

	    if (QUESTS_D->verify_quest(me,"½ðÊ¨Ã·»¨×®")) {
		if (!me->query_temp("marks/js_lian_start")) {
		    me->set_temp("marks/js_lian_start",1);
		    me->delete_temp("marks/js_lian");
		}
		me->add_temp("marks/js_lian",1);
		if (me->query_temp("marks/js_lian")>=10) {
		    QUESTS_D->special_reward(me,"½ðÊ¨Ã·»¨×®");
		    me->delete_temp("marks/js_lian");
		    me->delete_temp("marks/js_lian_start");
		}
	    }
	    return 1;
	} 
	if(s >= 20) {
	    message_vision("\n$N°ÎÉí¶øÆð£¬·É¿ìµØÔÚÃ·»¨×®ÉÏ×ßÁËÒ»È¦£¬ÓÖäìÈ÷µØÌøÁËÏÂÀ´¡£\n", me);	
	}
	else 
	    message_vision("\n$NÐ¡ÐÄµØÌøÉÏÁËÃ·»¨×®£¬µ¨Õ½ÐÄ¾ªµØ×ßÁËÒ»È¦£¬¸Ï¿ìÓÖÌøÁËÏÂÀ´¡£\n", me);

	tell_object(me, "ÄãµÄÇá¹¦ºÃÏó³¤½øÁËÒ»Ð©¡£\n");
	amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*25;
	if(amount < 1) amount = 1;
	me->improve_skill("move", amount);
	me->set_temp("last_damage_from","¿àÁ·Ã·»¨×®£¬²»Ð¡ÐÄµôÏÂÀ´Ë¤ËÀÁË¡£");
	da = 20;
	me->receive_damage("kee", da);

	if (QUESTS_D->verify_quest(me,"½ðÊ¨Ã·»¨×®")) {
	    if (!me->query_temp("marks/js_lian_start")) {
		me->set_temp("marks/js_lian_start",1);
		me->delete_temp("marks/js_lian");
	    }
	    me->add_temp("marks/js_lian",1);
	    if (me->query_temp("marks/js_lian")>=10) {
		QUESTS_D->special_reward(me,"½ðÊ¨Ã·»¨×®");
		me->delete_temp("marks/js_lian");
		me->delete_temp("marks/js_lian_start");
	    }
	}

    } else {
		message_vision("\n$N°ÎÉí¶øÆð£¬äìÈ÷µØÔÚÃ·»¨×®ÉÏ×ßÁËÒ»È¦¡£\n", me);
		message_vision("\n$N°¥Ñ½Ò»Éù´ÓÃ·»¨×®ÉÏµôÁËÏÂÀ´¡£\n", me);
		da = 100;
		me->set_temp("last_damage_from","¿àÁ·Ã·»¨×®£¬²»Ð¡ÐÄµôÏÂÀ´Ë¤ËÀÁË¡£");
		me->receive_damage("kee", da);

		    if (QUESTS_D->verify_quest(me,"½ðÊ¨Ã·»¨×®")) {
		if (!me->query_temp("marks/js_lian_start")) {
		    me->set_temp("marks/js_lian_start",1);
		    me->delete_temp("marks/js_lian");
		}
		me->add_temp("marks/js_lian",1);
		if (me->query_temp("marks/js_lian")>=10) {
		    QUESTS_D->special_reward(me,"½ðÊ¨Ã·»¨×®");
		    me->delete_temp("marks/js_lian");
		    me->delete_temp("marks/js_lian_start");
		}
	    }

    }
    return 1;
}


int do_look(string arg){
    object me;

    me = this_player();

    if (arg == "Ê¯Ëø") {
	tell_object(me, "´ó´óÐ¡Ð¡µÄÊ¯ËøÊÇÓÃÀ´¶ÍÁ¶±ÛÁ¦µÄ£¬Äã¿ÉÒÔÊÔ×Å¾Ù¾Ù¿´£¨lift Ê¯Ëø£©¡£
²»¹ý£¬ÒªÏëÓÐËùµÃÒæ£¬ÒªÓÐµã²«»÷µÄ»ù´¡£¨10£©£¬ÔËÆøÒ²²»ÄÜÌ«»µ£¨11£©¡£\n");
	return 1;
    }

    if (arg == "Ã·»¨×®") {
	tell_object(me, "Íë¿Ú´ÖÏ¸Ò»ÈË¶à¸ßµÄÃ·»¨×®£¬ÊÇÓÃÀ´Á·Ï°Çá¹¦µÄ£¨lian Ã·»¨×®£©¡£
²»¹ý£¬ÒªÏëÓÐËùµÃÒæ£¬ÒªÓÐµãÇá¹¦µÄ»ù´¡£¨10£©£¬ÔËÆøÒ²²»ÄÜÌ«»µ£¨11£©¡£\n");
	return 1;
    }

    if (arg == "ºÚÊ¯") {
	if (this_player()->query_temp("marks/js_cook_mice") < 2) {
	    tell_object(this_player(),"Ôº×ÓµÄµØÃæÊÇÓÃºÚÊ¯ÆÌ³ÉµÄ¡£\n");
	    return 1;
	}
	tell_object(this_player(),"Ôº×ÓµÄµØÃæÊÇÓÃºÚÊ¯ÆÌ³ÉµÄ£¬ÉÏÃæÁãÁãÂäÂäµô×ÅÐ©Ã×Á££¬Ò»Ö±Í¨Ïò´óÌü¡£\n");
	this_player()->set_temp("marks/js_cook_mice",3);
	return 1;
    }

    return 0;
}
