#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", CYN"������"NOR);
	set("long", @LONG
СС�������ţ����Ǽ��ϳǵ�һ�󾰹ۡ����۵�С������ĵ���ˮͤ����
��ȥ��ȴ��û�п������˵����棬ֻ��һƬƬ��ҶƮ��ˮ�棬����񻨵ķ���
�Գ�������С�������̤����Ҷ�������ϣ����������ٵĲ��⣬���Ƶĵ�Ӱ��
ӭ�����˵ĺ���Ҳ�Եø������
LONG
	);
	set("exits", ([ 
  "southwest" : __DIR__"bridge2",
  "north" : __DIR__"bridge4",
]));
        set("objects", ([
//        __DIR__"npc/surong" : 1,
						]) );
    set("outdoors", "jinan");
	set("coor/x",100);
	set("coor/y",90);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
	object room;

	if (userp(me))
		if (me->query_temp("timer/jinan_bridge") + 1 > time())
		{
			room=find_object(__DIR__"bottom");
			if (!room)
				room=load_object(__DIR__"bottom");
			message_vision(CYN"$N���µĺ�Ҷ΢΢һ����һ��������ͨһ������˺��С�\n\n"NOR,me);
			me->move(room);
			return notify_fail("\n");
		}

		me->set_temp("timer/jinan_bridge",time());
       	return ::valid_leave(me,dir);
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
