// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "½£¸ó");
        set("long", @LONG
½£¸ó
LONG
        );
	set("exits",([
  		"northeast" : __DIR__"shudao3",
  		"southwest" : __DIR__"shudao2",
  		"up" : __DIR__"jiange2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}