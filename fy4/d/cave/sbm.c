// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
һ��ʯ���ţ����泤������̦���������֡����ŵ��ұ���һ������ʯ��������
̼��д��һЩ��ֵķ��š��Ų����ܸߣ���΢��һЩ������Ҫ�����ſ���ͨ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"tsbd",
  "west" : __DIR__"sbj",
]));
        set("objects", ([
     __DIR__"obj/stone": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",-15);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
