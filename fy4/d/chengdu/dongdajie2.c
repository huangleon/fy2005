// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
�����
LONG
        );
	set("exits",([
  		"west" : __DIR__"dongdajie1",
  		"east" : __DIR__"dongmen",
  		"northeast" : __DIR__"tulu",
  		"southeast" : __DIR__"chaotinghuoqiyingdamen",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}