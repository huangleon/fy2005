// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit __DIR__"bush_base.c";

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ܲ��ľ����������̣�����ͨ��������ķ��򡣵Ͱ���С���Ե�ס���ߣ�
ʹ�˱治�巽�򡣵��²������õĿ�Ҷ����������ġ�ż����һ�������ݴӵ��ϵ�
��ˮ��ӿ��������������Ż�Ĵ̱���ζ��
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"zhaoze3",
]));

        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"

        ]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
        set("route","west");
        set("route_room",__DIR__"zhaoze5");
	set("coor/x",1020);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
