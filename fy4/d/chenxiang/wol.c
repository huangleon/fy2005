// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����൱�ظߣ�������¥���ߣ�һյͭ���ø첲��ϸ�������ӷ���ֱ��������
������������򣬾������ɫ������ͬ��ÿ����ȼ��ʱ�򣬾����������ɫҲ��һ
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs6",
  "east" : __DIR__"wol2",
]));
        set("objects", ([
        __DIR__"npc/ywai": 1,
                        ]) );
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "east" &&  !me->query_temp("marks/cured_jia") 
	&& ob=present("jia", this_object())) 
                return notify_fail("��������·��"+ob->name()+"��ס�� ��\n");
	else
                return 1;
}

