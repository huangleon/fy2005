// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�ϵ���˪��");
        set("long", @LONG
��ʯ������ķ��Ӹ���ĸߴ����ڵƻ�ͨ���������̵��Ǻ��Ĳ�˹��̺��
���ܵİ���ʮ�ֵľ��£�ǽ�Ϲ���Щ����С�ɵĵ���������������ͯ����ߡ���
֮�����һ�и���������ո���롣
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"zx",
	]));
    set("objects", ([
        __DIR__"npc/weaponer": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

