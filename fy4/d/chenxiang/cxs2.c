// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�������·");
        set("long", @LONG
���������̨�ܽ��������Կ������ֵ�Ӱ�ӡ����ܶ���ո�µģ�һ�����Ǹո�
���������ĵط����������ϳ��������������½��������õĵش���·�Եĳ�������
Ψһ����ԭ����Ϣ�Ľ������Ͷ����¿��ŵĲ˸���С���γ��������ա�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter1",
  "west" : __DIR__"ch",
  "east" : __DIR__"cag",
  "south" : __DIR__"cxs3",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
