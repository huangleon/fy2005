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
  		"west" : __DIR__"duchang",
  		"north" : __DIR__"beidajie2",
  		"south" : __DIR__"chengdu_center",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}