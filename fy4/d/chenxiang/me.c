// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����Ŷ�");
        set("long", @LONG
һ���һ�߼�������ש��ש���ﳤ���������͵��۲ݡ����ر���룬һ������
�����ھ��ĵش����������ڵ��ϣ������Ǹ��޴��Χ���̡���ֻС��ߴߴ������
�ڵ���Ѱʳ��ż���˹����������ڵط���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs3",
  "east" : __DIR__"fydao1",
]));
        set("objects", ([
        __DIR__"npc/yj": 1,
        __DIR__"npc/taijian": 1,
                        ]) );

        set("outdoors", "chenxiang");
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
