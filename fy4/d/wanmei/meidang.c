inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "��÷��");
        set("long", @LONG
���нྻ��ϴ��̴��Ʈ�졣�������Կ�÷������ȴʵΪ�Ϻ�̴��ľ���졣����
�ܸߣ��ϹҰ�յ�͵ƣ���о��˸ɢ�����������̡�����ӳ����̣�����������ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"frontyard",
  "east" : __DIR__"yard",
]));
        set("objects", ([
        __DIR__"npc/oldman": 1,
                        ]) );

	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
