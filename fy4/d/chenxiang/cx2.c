// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�������ʯ��");
        set("long", @LONG
�����ֵ���ʾ�Ž���С�����ֶ��ؽ��еķ��԰���ε�С�ź��һ������
��С���������µ���ˮ����ƼȾ�ɰ��˵Ĵ��̡�ż��һ��ֻ���ۻ����������źӱ�
����ź��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx1",
  "southwest" : __DIR__"cx3",
]));
        set("objects", ([
        __DIR__"npc/boy": 2,
                        ]) );
        set("outdoors", "chenxiang");
        set("resource/water",1);
        set("liquid/container","�����С����");
        set("liquid/name","С����ˮ");
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}
