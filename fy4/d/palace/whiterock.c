inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "°×Ê¯");
        set("long", @LONG
ÕâÊÇÒ»¿é¾Þ´óµÄ°×É«É½Ê¯£¬´óÔ¼¿ÉÒÔÈÝÄÉÁùÆß¸öÈË¡£Ê¯Í·µÄ±íÃæÒì³£Æ½»¬£¬Áî
ÈË¾ªÆæµÄÊÇÊ¯ÃæÉÏµÄ¼¸¿é[30mºÚÉ«Ó¡ºÛ[32m£¬²»ÖªÊÇÌìÈ»¶ø³É£¬»òÊÇÈËÎªµÄºÛ¼£¡£ÏòÏÂÍû£¬
¿ÉÒÔ¿´µ½±ÌÀ¶µÄºþË®£»ÏòÉÏÍû£¬Ö»¼ûÉÏÃæÔÆÎíçÔÈÆ£¬²»Öª»¹ÓÐ¶à¸ß²Å»áµ½¶¥¡£
LONG
        );
    	set("item_desc", ([
        	"ºÚÉ«Ó¡ºÛ" : "ºÃÏñÊÇÈËµÄ×ãÓ¡°ã´óÐ¡£¬Ò²ÐíÄã¿ÉÒÔÊÔ×Å²ÈÒ»²È£¨step£©¡£\n",
     	]));

		set("outdoors","fengyun");
		set("coor/x",-50);
		set("coor/y",60);
		set("coor/z",20);
		setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}

int do_step(string arg)
{
	object me= this_player();
	if(!arg || arg != "ºÚÉ«Ó¡ºÛ" )
		return notify_fail("ÄãÒª²ÈÊ²Ã´£¿\n");
	message_vision(YEL"$NÒ»½Å²ÈÔÚÊ¯ÃæÉÏµÄºÚÉ«Ó¡ºÛ£¬Ö»Ìýµ½£¢Ö¨Ñ½£¢Ò»Éù£¬
ÑÂ±ÚÉÏÁÑ¿ªÁËÒ»µÀÃÅ»§£¡\n"NOR, this_player());
	set("exits/enter", __DIR__"holeopen2");
    REWARD_D->riddle_done(me,"ÇÉ¹ý°×Ê¯",10,1);
	if (QUESTS_D->verify_quest(me,"ÇÉ¹ý°×Ê¯"))
		QUESTS_D->special_reward(me,"ÇÉ¹ý°×Ê¯");
	return 1;
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("ÄãÒªÍùÉÏ»òÏÂÅÀ£¿\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$NÐ¡ÐÄÒíÒíµØÏòÉÏÅÀÈ¥£¬ÉíÐÎÂýÂý±»ÔÆÎíÕÚÑÚ¡£\n"NOR, me);
		message_vision(HIR "\n$NÊÖÉÏÒ»¸öÃ»×¥ÎÈ£¬´ÓÎ£ÑÂÉÏµôÁËÏÂÈ¥£¡\n"NOR, me);
		me->move(__DIR__"yadi");
                me->receive_damage("kee", 150);
                me->receive_damage("sen", 150);
                me->receive_damage("gin", 150);
		message_vision(HIR "\n$N´ÓÎ£ÑÂÉÏµôÁËÏÂÀ´£¬ÖØÖØµÄË¤ÔÚÁËµØÉÏ£¡\n"NOR, me);
		me->set_temp("last_damage_from","ÓÚµÛÍõ¹È×¹ÑÂÉíÍö¡£\n");
		
	}
	else {
		message_vision(HIY "$NÐ¡ÐÄÒíÒíµØÏòÏÂÅÀÈ¥£¬ÉíÐÎÂýÂý±»ÔÆÎíÕÚÑÚ¡£"NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}

int reset(){
	delete("exits/enter");
	::reset();
}