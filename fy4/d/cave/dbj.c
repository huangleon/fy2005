// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
һ������ʯ���������������һ�˶�֣��ͺ�����һ�����������ӡ������ϸ
���Ļ��������Է���һ����ϸϸ����ˮ�������������£�û�����Ͳ����ˡ�
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"dbm",
  		"south" : __DIR__"btdm",
	]));
    set("objects", ([
        __DIR__"npc/tangye": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}