// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�쳡");
        set("long", @LONG
һ�˼��ɸߵ�ľ������ε�����·���У���˵Ķ�����һ��СС������̨����
����������Ĺ�ģ�������ϣ�ȴҲ�����������������ķ��ˣ���ɽ�ĺ��˸��ǹ�
������ͷ�󻼡��t��̨����Ϊ�˶�����ÿ����ͽ��Ϯ�ŵ�ʱ�����������Ĺٱ���
�����Ӹ澯��
ʾ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs3",
  "west" : __DIR__"yam",
  "east" : __DIR__"fac",
  "south" : __DIR__"cxs5",
  "up" : __DIR__"gding",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	room = find_object(__DIR__"gding");
	if(objectp(room))
	tell_object(room,me->name()+"�뿪���쳡��\n");
                return 1;
}

int valid_enter(object me, string dir)
{
        object room;
        room = find_object(__DIR__"gding");
        if(objectp(room))
        tell_object(room,me->name()+"�������쳡��\n");
	return 1;
}

