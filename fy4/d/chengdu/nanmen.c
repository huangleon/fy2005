// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����
LONG
        );
	set("exits",([
  		"north" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}