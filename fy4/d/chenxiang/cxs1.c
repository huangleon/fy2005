// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������Ͻ�");
        set("long", @LONG
������ɽ�������������Ƿ羰������[33m��ɽ[32m�����д󲿷־������Ը���ˮ��Ϊ����
ÿ������ũ�������ų��صĲ�������������ĺ�ˮ�����л������ص�����һ����
ð��ŨŨ�Ĵ��̣�ɢ�������˵ĵ��������ļҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter",
  "south" : __DIR__"cxcenter1",
  "west" : AREA_HUANGSHAN"shanmen",
]));
        set("objects", ([
	__DIR__"npc/farmer": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
