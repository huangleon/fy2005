// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С��������");
        set("long", @LONG
����ĺӴ��Ͽ�ˮ���������ӱߵ�«έ����������������ɳɳ��������ż
����������ҰѼ�ĸ¸������ӱ��м�����ϡ��С�����ѵ�����Զ����������᾵Ĺ�
ʯ������С���ԡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle",
  "south" : __DIR__"playground",
]));
	set("outdoors","wanmei");
	set("coor/x",20);
	set("coor/y",100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
