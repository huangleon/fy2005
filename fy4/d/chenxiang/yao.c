// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��٢ҩ��");
        set("long", @LONG
���Ĵ��ţ���������Ľ��ң����в����İ��������Ĺ�Ʒ����������еı�
���ʢ�����Ҫ������ҩ����ʮ��������û�л������ˣ���˵���������
�����ú�����������š�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cx3",
  "west" : __DIR__"yao2",
]));
        set("objects", ([
        __DIR__"npc/huoji": 1,
                        ]) );
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
