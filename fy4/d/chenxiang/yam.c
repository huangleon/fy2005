// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ǰ����������צ��ʯʨ��������ڷ����Ļ��ڣ�һ�ȿ���͸�����ţ��ټ���
ǽ�ϵ�һ�������񣬽���������������ǿ�ҵ�ɱ���С�����������ķ�ͽ��������
ҲҪ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxs4",
]));
        set("objects", ([
        __DIR__"npc/governor": 1,
        __DIR__"npc/yayi0": 1,
        __DIR__"npc/yayi": 2,
                        ]) );

	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
