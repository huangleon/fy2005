// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ľ��");
        set("long", @LONG
����Ĺ�ľ�Ͷ����������е��̶���ɽ�紵������������ȳ���ʹ�˲���������
���ٴ��к�ɽ�²�ƺ�����㡣����ǰ�������ͱ��������������£�����������η��ֹ
����ǰ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lake",
  "south" : __DIR__"upriver",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/bihu" :1,
                        ]) );
	set("coor/x",20);
	set("coor/y",110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
