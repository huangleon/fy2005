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
  		"down" : __DIR__"jiange1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}