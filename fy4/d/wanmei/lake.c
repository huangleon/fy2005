// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ɽ�о޺�");
        set("long", @LONG
��ˮ�峺���ף�����ɫ��ˮ���沨ҡ�ڡ�ββС�㻺���ζ���������ˮ��֮�䡣
һϯ�ٲ�к����У�����¡¡֮�����ص���Ⱥɽ�����������С���������������
��һ��СϪ������ɽ�¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jungle",
  "east" : __DIR__"waterfall",
]));
	set("outdoors","wanmei");
	set("coor/x",30);
	set("coor/y",110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
