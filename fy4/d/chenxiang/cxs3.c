// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ʵ��ֻ�ǳ����������ٽ������Ŵ���һ���Ʒ������ϵĸ����Ǻô�ϲ����
��ԭ���ĳ�ǽ�Ƶ��ؽ�������ͨ��[33m���Ƶ�[32m��������Ǻ����������[33m��ɽ[32m�������ŷ�
����ש����ϧ�����οͣ�ֻ��ż����С�ɵ�����ڴ�פ�㡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs2",
  "west" : __DIR__"mw",
  "east" : __DIR__"me",
  "south" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
