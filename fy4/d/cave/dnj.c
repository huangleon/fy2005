// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���Ͻ�");
        set("long", @LONG
�����ܵͣ�����ʯ�൱�Ķ࣬�γ�һƬʯ�֡�ʯ���л��м�����Ģ����Ģ�Ա�
��Ȼ�м���ʯ�ʺ�һ��ʯ̨�����Թ�����Ϣ������һֱ�ڵ�ˮ��Ū�������ƺ�����
�����ꡣ
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"ntdm",
  		"west" : __DIR__"tdnd",
	]));
    set("objects", ([
        __DIR__"npc/dinggan": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",-14);
	set("coor/z",0);
	setup();
}