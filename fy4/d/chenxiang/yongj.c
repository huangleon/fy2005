// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����ӻ�");
        set("long", @LONG
����С�������ң�˭Ҳ�����������ʲô����ʲô��ʲô������ʲô������
������ĳ���ʱ����ʱ��Ʈ������������Ż���ӻ����ǽ�ϻ����˸��ָ����ļ�
�ţ����������������ص����ա�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxw3",
]));
        set("objects", ([
        __DIR__"npc/tianpeng": 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
