// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����������������������е�һ�����Σ����Ǳ�������׽�õ���ʿ�ٲ���
�����͵������ϼӿ���һ����������û�����ܳ��ܵ�ס������һ�����Ѷ������û
�У�����һ���ˣ����˾��Ǹձ�������ʮ�塻������������ȥ����������ͽ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"twt",
//  "south" : __DIR__"tbzl",
]));
        set("objects", ([
        __DIR__"npc/guard1": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",-5);
	set("coor/y",5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
