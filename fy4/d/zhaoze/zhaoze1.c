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
  		"north" : __DIR__"edge",
	]));

        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"

        ]) );
        set("objects", ([
                __DIR__"npc/monster1" : 1,
       	]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
        set("route","east");
        set("route_room",__DIR__"zhaoze2");
        
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}

