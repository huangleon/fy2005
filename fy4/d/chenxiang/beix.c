// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������֨֨��������������Ĵ�ֽ�Ѿ���������ˡ����������������Ҳ
�����䣬���ұ�ľ�������˿ס�������ǽ�Ѿ����绯�ò����ٱ��ˣ���������ĵ�
�ݶ��ƺ����紵���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"cxw2",
]));
        set("objects", ([
        __DIR__"npc/wang": 1,
                        ]) );
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
