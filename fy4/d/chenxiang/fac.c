// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����Ļ����Ѿ����ǻ�ɫ�ˣ�����Ψһ��һ��ľ׮Ҳ��������������ɫ�ˡ���
����������Ѫ�Ѿ��㹻������ϴˢ����ġ�������ľ׮��Χ�����������Ѿ���ѪȾ
�ɰ���ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs4",
]));
        set("objects", ([
        __DIR__"npc/poorghost": 1,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
