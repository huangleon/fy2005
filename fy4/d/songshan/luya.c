// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "¬���ٲ�");
        set("long", @LONG
��ɫ��ɣ�����Ȼ���������κ��ܹ��ɽ������󼰵ģ��ٲ����󣬵���������
��͸������һ˿ˮ�⣬��һĨ�ʺ�ȴ����ƣ��������������ó�������΢�е��
����ˮ�����������ǵ��ģ�����ͯ��ң���Ӧ������ɽ��û���̻���Ϣ�ĵط���
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"zhongyue", 
  "north" : __DIR__"qingtong",
]));
        set("objects", ([
                __DIR__"npc/wuhua" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",20);
	set("coor/y",12);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "north" && ob=present("tian feng 14 lang", this_object()))
		if(!me->query_temp("marks/okey_to_see"))
		{
		ob->do_test(me);
		return notify_fail("");
		}
		return 1;
}

