// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���ҵ���");
        set("long", @LONG
�˼䵱�̺�С����ȴ��һ��ܴ�Ĵ����ҡ����̵����ܶ����˶���������ǽ��
Ҳ������ֻҪ���ܹ������Ķ�����ÿ�������϶���һ�ŵ�Ʊ�����жѻ��Ķ�������
���˻ҳ�����Ȼ�Ǻܶ��˽������䵱�ڴˣ�ȴ��Ҳû�л���ȡ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxe3",
]));
        set("objects", ([
        __DIR__"npc/pawnowner": 1,
                        ]) );
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
