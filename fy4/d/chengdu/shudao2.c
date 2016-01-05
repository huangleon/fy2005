// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ÊñµÀ");
        set("long", @LONG
ÊñµÀ
LONG
        );
	set("exits",([
  		"northeast" : __DIR__"jiange1",
  		"southwest" : __DIR__"shudao1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}