// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ͥ");
        set("long", @LONG
����������룬��һ����ʮ���ɷ�Բ�Ĺ㳡���㳡���м���һ�ɷ�Բ����أ�
�����ǲ�����ӿ�ĵ��ºӡ���ϸ��ȥ����ˮ���������һ����˿���޷��ж�������
��ż����ˮ���������棬�������ΧȾ��һƬ��̦�������и��󶴣�ÿ�춼��һ
���������룬��ҫ�ڰ����ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tbzm",
  "south" : __DIR__"tnzm",
  "east" : __DIR__ "zd",
//  "west" : __DIR__"zx",
]));
        set("objects", ([
        __DIR__"npc/ximenyu": 1,
        __DIR__"npc/gaoli": 1,
        __DIR__"npc/shuang": 1,
                        ]) ); 
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-4);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
