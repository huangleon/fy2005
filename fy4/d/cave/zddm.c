// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǽ������Ľ��Σ�����Щ���ָ��������ĵ����ѵ��̾ߣ�ա������ǩ����
���Σ��������ᡣ������ɱ�˵�����������ȫ�����ζ��ϸ߸����Ÿ���۴�ϸ��ţ
�ͺ��򣬻��ҡҷ��˸��ӳ�ڲ�ס�����ķ���Ť��ʹ������ϡ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"zd",
  "east" : __DIR__"ztdd",
]));
        set("objects", ([
        __DIR__"npc/guard3": 1,
                        ]) );

        set("indoors", "cave");
	set("coor/x",5);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
