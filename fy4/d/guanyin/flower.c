// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ҳ��֪��ã�����ͻȻ����һ�������۵Ļ��㡣�⻨�㲻��ĵ��������õ
�壬Ҳ����÷�����Ǿ�......�⻨�����۵þ����������У������������ϡ�
LONG
        );
        set("exits", ([ 
 		 "south" : __DIR__"sand",
  		  "north" : __DIR__"valley",
	]));
	set("no_force",1);
	set("no_fly",1);
        set("outdoors", "guanyin");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();

}



int valid_leave(object who, string dir){
	if (dir=="north"){
		if (userp(who))
			who->apply_condition("no_force",10);
	}
	return 1;
}