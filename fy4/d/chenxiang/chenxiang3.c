// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�������ƺ������ŵ����꽭�ϵ�ζ��������С�����¿ɰ��ĳ������Ѿ���Ϊ��
ʢ���ٵĳ���ǣ��������Ӱ���Ǻ������ֵġ�������ǰ������ǻ�ɫ�ģ��Ʋ�
Ҳ�ǻ�ɫ�ģ������������ȫ����������һƬ���롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"road",
  "southwest" : __DIR__"cx0",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
