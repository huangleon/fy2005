// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����Ǿɽ�");
        set("long", @LONG
�����ǵ�������򱱽֣��ֵ��ɰ���ɫ��ʯש�̳ɣ��Ѿ��൱���ƾɡ��ֵ���
Ȼ�Ѿ��ӿ�������ֻ����һ��������ͨ�������������������ԼԼ�ŵ��ոճ�
�����������ζ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx0",
  "southeast" : __DIR__"cx2",
  "west" : __DIR__"mian",
]));
        set("objects", ([
        __DIR__"npc/moo": 1,
        __DIR__"npc/ditou" : 2,
//        __DIR__"npc/linshouou" : 1,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
