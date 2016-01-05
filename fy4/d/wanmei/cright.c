// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ƫԺ");
        set("long", @LONG
����һ���ɰ���С��ƺ����ƺ����һԲʯ����������ʯ�ʡ������Ǿ��´���ʯ��
ʯ�Ͽ���һ�����̡����ϻ�����һ��δ��Ĳ��塣���ϻ��������оƣ��������¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  	"north" : __DIR__"yard",
	]));
        set("outdoors", "wanmei");
        set("objects", ([
		BOOKS"skill/doomforce_31" : 1,
                        ]) );

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_look","look");
	add_action("do_study","study");
}

int do_look(string arg)
{
	if(!arg || (arg != "����" && arg != "canqi"))
	return 0;
	this_player()->add_temp("looked_canqi",1);
	if((int) this_player()->query_temp("looked_canqi") <= 15)
	{
		write("һ��δ��Ĳ��壬���ư����������\n");
		return 1;
	}
	else
	{
		write("���ƺ�������һЩ�����ѧϰһ�°ɣ���\n");
		return 1;
	}
}
 
int do_study(string arg)
{
	if(!arg || (arg != "����" && arg != "canqi"))
	return 0;
	if(this_player()->query_temp("looked_canqi") <= 15)
	{
		write("һ��δ��Ĳ��壬���ư����������\n");
		return 1;
	}
	else
		return 0;
	
}
