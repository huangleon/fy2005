// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"�Ͻ�֮��"NOR);
        set("long", @LONG
��Բ֮ҹ���Ͻ�֮�ۣ�����˵��������������ͣ������Ƴ�����Ҷ�³��롺����
���Ŵ�ѩ��Ҫ�ڴ˴����������µ�һ���ͣ����ʵ������µ����ָ��ֺ��˲����ڴ˾�
սΪ������ҫ����
LONG
        );
    set("exits", ([ 
  		"east" : __DIR__"zijin2",
  		"southeast" : __DIR__"zijin4",
  		"south" : __DIR__"zijin3",
		"northwest" : __DIR__"zijin_n",
	]));
	set("viewer", ({ __DIR__"zijin_e", __DIR__"zijin_w",__DIR__"zijin_s", __DIR__"zijin_n"
		}) );
	set("no_death_penalty",1);
	
    set("outdoors", "fengyun");
	set("coor/x",150);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}

int valid_leave(object ob, string dir){
	if(dir == "northwest" && ob->is_fighting()){
		return notify_fail(HIY"�㻹�ھ�ս�У��������˳���\n"NOR);
	}
	return 1;
}
