// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��������Ժ");
        set("long", @LONG
��ǽ���������˶�ߣ�����û���κζ������������֡�Ժ����Ψһ��һ����Ҳ
��һ�ɶ�ߵ�դ��Χ���������ƺ��������˻��������ϡ���Ժ����һ�ڿݾ����
���ס�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"jdi",
  "west" : __DIR__"wol",
]));
        set("objects", ([
        __DIR__"npc/dau": 1,
                        ]) );
	set("no_magic",1);
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
 	if( dir=="down" ) 
 	{	
 		if(me->query_temp("marks/asked_jianu") && present("jianu"))
 		{
 			tell_object(me,"��ץס��Ů���µ������������½�ȥ��\n");
 			return 1;
 		}
 	 	else
 			return notify_fail("��̫���ˣ���ȥ��ˤ���ġ�\n");
 	}else 
 		return 1;
}
