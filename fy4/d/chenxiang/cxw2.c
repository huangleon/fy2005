// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����ĵ�·�Ѿ����������ĵط����ˣ��ӿ����ݵģ���Щש�Ѿ��ɶ�������ȥ
�λε�����������ͻᷢ�������ڡ�������������η�Ļ�����Ʒ���ʹÿ��
·�˶���ͷ�����ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beix",
  "south" : __DIR__"nanx",
  "west" : __DIR__"cxw3",
  "east" : __DIR__"cxw1",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
