// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit __DIR__"bush_base.c";

void create()
{
	set("short", "�����");
	set("long", @LONG
��ɫԽ���谵�����������Ű���ɫ���������������¼��ߣ����е�ֲ�ﶼ����
��һ�ֽ��Ƶ���ɫ�����µ�������������ÿһ����������ȥ��Σ�ա�
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"zhaoze5",
]));

        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"

        ]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
	set("route","south");
        set("route_room",__DIR__"zhaoze7");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}