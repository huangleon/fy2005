// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���˾�");
        set("long", @LONG
���ǳ�����������������һ�����ݡ����ݵ���ǽ����һ����ɽˮ��������
�ľ�ɫ������Զ����ǳ���һ�����ǳ��Դ�ʦ֮�֡�������Ȼ�󣬵�ֻ��һ�㣬
���ҳ���ظɾ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs5",
]));
        set("objects", ([
        __DIR__"npc/xb": 1,
                        ]) );
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
