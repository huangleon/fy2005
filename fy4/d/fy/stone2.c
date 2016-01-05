// Tie@fengyun
#include <room.h>

inherit ROOM;
void create()
{
    set("short", "Ê¯Ïï¾¡Í·");
    set("long", @LONG
Ê¯Ïï²»Éî£¬ºÜ¿ìµ½ÁË¾¡Í·£¬Ò»¶Â¸ßÇ½µ²×¡È¥Â·¡£Ç½ÉÏÓÐµÀÕ­ÃÅ£¬Ç½½ÇÓÐÒ»[33m¹·¶´[32m£¬
Ò»ÌõÔàÏ¡Ï¡µÄÐ¡ºÓ¹µ´Ó¹·¶´ÖÐÁ÷³ö£¬Ê±¶ø²»Ê±µÄ£¬Ò»ÌõÌõ½þÂúÑªË®µÄ±Á´ø´Ó¹·¶´ÖÐ
Á÷³ö£¬É¢·¢³ö¸¯³ôµÄÆøÎ¶¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"stone1",
	"northeast" : __DIR__"sroom",
	"east" : __DIR__"ansheng",
      ]));
	set("item_desc", ([
	"¹·¶´":"Ò»¸ö·ÏÆúÒÑ¾ÃµÄ¹·¶´£¬ÔçÒÑ¾­Ê§È¥ÁË×ê(enter)¹·µÄÓÃÍ¾±ä×÷Òõ¹µ¡£\n",
	]) );
    set("objects", ([
		//__DIR__"npc/newsman" : 1,
      ]));
    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}

void init()
{
	add_action("do_north", "enter");
}



int do_north(string arg)
{
    object room, me;
		me = this_player();
		if (!room= find_object("/d/fycycle/road6"))
			room=load_object("/d/fycycle/road6");
		tell_object(me,"\nÄãÏëÆðº«ÐÅËûÄêÇÒÊÜ¿èÏÂÖ®Èè£¬Ïà½ÏÏÂÄãÕâÌÃÌÃ´óÏÀ×ê¸ö°Ñ¶ù¹·¶´ÓÖËãÊ²Ã´¡£\n");
		me->ccommand("emote ºÙºÙÒ»Ð¦£¬Ò»µÍÉí±ãÑØÖøÒõ¹µÏò¹·¶´×êÈ¥¡£\n");
		me->move(room);
		me->ccommand("emote ´Ó³ÇÇ½ÉÏÒ»¸öÐ¡¶´ÖÐ×ê³ö£¬Ð¡ÐÄÒíÒíµØ°Ï¹ý»¤³ÇºÓÐÐÁË¹ýÀ´¡£");
		if (!REWARD_D->check_m_success(me,"¹·¶´´óÏÀ"))
				REWARD_D->riddle_done(me,"¹·¶´´óÏÀ",1,1);
		me->set_temp("body_print", "ÕâÈËÉíÉÏÕ´ÂúÁËºÚÄà»ÒË®£¬»¹µÎµÎ´ð´ðµØÕýÏòÏÂÂä£¬\n¿´ÆðÀ´ºÃ¶ñÐÄ°¡¡£");

		return 1;
}


/*

// this code work only if npc cannot be arrested.
int invalid_leave(object me)
{
    object ob;
    if(  me->query_temp("answer_questions") <= 3 ) 
    {
	me->delete_temp("score");
	me->delete_temp("answer_questions");
	me->delete_temp("num_question");
	me->delete_temp("in_ask");
	if(ob=present("news man", this_object()))
	{
	    ob->set("in_test",0);
	}
    }
    return 0;
}
*/