// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ѿ��ǳ���ǵ���ߡ���������������ĵ�·�����･��������Ӱ���١�
é��Խ��Խ�񣬾�ɫԽ��Խ�������������������ޱ߼ʵ�ç�֡�����һ�����˽���
ç���м���ɱ���ķ������壬Ҳ�����书������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : AREA_MANGLIN"edge1",
  "west" : __DIR__"cxe2",
  "south" : __DIR__"dangpu",
]));
        set("objects", ([
        __DIR__"npc/girl": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
