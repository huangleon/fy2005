// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
�����س��а���ˮ�������ܲ�������˵���ˮһ��������ĳ�������������
�������������ĺ�ˮ����������ƾ���ط����ڽ������������������Ѫս��ȡ����
�磬���ڵس��������Ӷ���������ˮ�Σ����Ǳ������������ĸ��ɵ��ӵĹ��Źء���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"north" : __DIR__"ntxl",

		]));
        set("indoors", "cave");
		set("coor/x",-20);
		set("coor/y",-40);
		set("coor/z",0);
        set("objects", ([
        	__DIR__"npc/guard2": 1,
                        ]) );
		setup();
        replace_program(ROOM);
}
