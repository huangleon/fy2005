#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIC"��̳"NOR);
    set("long", 
"��̳��ʵ����ʲô��̳��ֻ�ǵ���һ���ܼ򵥵���ͤ����̳��Ҳ�Ӳ��������
���飬ֻ�����м����뷢�԰׵�����������Ȳ衣���󷲳�����Ƶ��ˣ���ϲ����
����ЪϢ���������ǽ�һЩ�������ţ���һЩ������Ѫ���ڵĹ��£������ª�Ĳ�
ͤ�ƺ�Ҳ�������ǳ��ֿ�ȭ����ص���㡣
"+HIC"
                   ��            ̳

"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"swind2",
  		"north" : __DIR__"fysquare",
  		"east" : __DIR__"yitea",
//  		"west" : __DIR__"jiulou",
  		"west" : __DIR__"station",
]));
        set("outdoors", "fengyun");
        set("objects", ([
	        __DIR__"npc/mei": 1,
                        ]) );

	set("coor/x",0);
  set("coor/y",-40);
	set("coor/z",0);
 set("map","fysouth");
	setup();
}

/*
int valid_leave(object me, string dir)
{
	object room;
	if (dir == "west")
	{
		room=find_object("/p/residence/train");
		if (!room)
			room=load_object("/p/residence/train");
		message_vision("$N�����뿪��\n"NOR,me);
		tell_object(me,CYN"\nһ�������������վ̨�л��죬���̵�ҡ������ε���\n����æ���ϵ��У���һȺ�ֺ����Ĺ�è������һ����λ���¡�\n\n"NOR);
		me->set_temp("annie/laputa_up",1);
		me->set_temp("annie/laputa_down",0);
		me->move(room);
		tell_object(me,HIG"\n���л�����ʻ����վ̨������"NOR);
//		message_vision("$N���˹�����\n"NOR,me);
		return notify_fail(" ");
	}
	return 1;
}
*/
