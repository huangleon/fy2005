// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
	set("short", "�����Ϲ�");
	set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ
֮һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ�Ҳ
���������Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
[31m
                	�Ϲ�Ǯׯ
[37m
LONG
	);
	
	set("exits", ([
		"east"    	: __DIR__"cxcenter",
	]) );
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��
TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/bankowner" : 1,

			]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
