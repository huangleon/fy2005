// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "������·");
        set("long", @LONG
·�ߵİ����Ѿ����Կ����ˣ����ڱ����ϵͣ������Ȼ�γ�һ��СС���ٲ���
�ٲ�����ˮ�ܼ��������������������ٲ����󣬰�����������治���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btxm",
  "south" : __DIR__"tzdx",
]));
        set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}
