// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ľ��");
        set("long", @LONG
����΢΢����ת�����ĵ������Ȼ������·ҲԽ��Խ��խ���ܿ�͵���������
�����д��ε�ľ�Σ��Ĵ�ʯ����ÿ��һ�α��и�����ʯ���ϵĻ�棬��ⲻͣ����
����һ�ж������ڻ谵�ĺ�ɫ��â֮�¡����з�����������ľ����ľ��޼��������
Ť�����̾����ƺ�����ʳ�Ż��˵���Ѫ����ҫ�ŻҰ���Ѫɫ��
LONG
        );
   	set("exits", ([ /* sizeof() == 4 */
  		"northwest" : __DIR__"ztdd",
	]));
        set("indoors", "cave");
	set("coor/x",12);
	set("coor/y",-8);
	set("coor/z",0);
        set("objects", ([
        __DIR__"npc/guard4": 1,
                        ]) );
	setup();
}


