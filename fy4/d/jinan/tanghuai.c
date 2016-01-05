// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ÌÆ»±Í¤");
  set("long",@LONG
É½ĞĞ´Ó´ËÏò¶«¿ªÊ¼¶¸ÇÍ£¬Ò»×ùÁ¹Í¤Ç°ÓĞÒ»¿Ã´ó»±Ê÷£¬¾İ³ÆÌÆ´úÃû½«ÇØÇíÔøÔÚ´Ë
Ë¨ÂíĞªÏ¢£¬´ËÊ÷´Ó´ËËÄ¼¾³£ÂÌ£¬³¤µÃÓôÓô´Ğ´Ğ£¬ÕÚÌì±ÎÈÕ¡£Ğí¶àµÇÉ½Õß¶¼ÔÚ´ËĞª½Å¡£
½»²æÂ·¿Ú£¬Ïò¶«ÊÇÁ½ÌõÉ½µÀ£¬Ò»ÌõÍ¨ÏòÖøÃûµÄ[33m¡ºĞË¹úìøËÂ¡»[32m£¬ÁíÒ»ÌõÊÇÉ½ÏÂµÄ[33m¼¯ÊĞ[32m£¬
ÍùÄÏÇ°ĞĞ£¬±ãÊÇÈª³Ç[33m¡º¼ÃÄÏ¡»[32m¡£
LONG
  );
  set("exits",([
         "west"  :__DIR__"shanjiao.c",
         "eastup":AREA_QIANFO"qiyan.c",
         "east" : AREA_QIANFO"road",
	 "south" : __DIR__"gate"
               ]));
        set("objects", ([
                AREA_QIANFO"npc/horse" : 1,
		AREA_QIANFO"npc/climber" : 2,
       ]) );
        set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "ÍùÊ÷ÏÂ×ßÁË¹ıÀ´¡£\n");
        }
}

int do_climb(string arg)
{
        if( arg!="tree" ) return 0;

        message_vision("$NÊÖ½Å²¢ÓÃ£¬Ãô½İµØÅÀÉÏÁËÁ¹Í¤Ç°µÄ´ó»±Ê÷¡£\n",
                this_player());

        tell_room(__DIR__"tree1", this_player()->name() + "´ÓÊ÷ÏÂÅÀÁËÉÏÀ´¡£\n");
        this_player()->move(__DIR__"tree1");

        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir=="eastup") dir="east";
        tell_room(__DIR__"tree1",
                "Ê÷ÏÂµÄ" + me->name() + "Íù" + to_chinese(dir) + "Àë¿ªÁË¡£\n");
        if (dir=="east") dir ="eastup";
        return 1;
}

