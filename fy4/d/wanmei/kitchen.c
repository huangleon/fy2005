inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "�����");
        set("long", @LONG
һյ�谵���͵��ڳ¾ɵ���̨�Ϸ��������Ĺ⡣���»��м����뽹�ĸɲ񣬻�
����ȼ���š����Ϲ��ڵ�ɽ��Ұ�����������˵���ζ��˿˿�����ӹ��ڵķ���Ʈ����
���˴������Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"backyard",
]));
        set("resource/water",1);
        set("liquid", ([
            "name": "ɽ��Ұ����",
            "container":"���",
            ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
