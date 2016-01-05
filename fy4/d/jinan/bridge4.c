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
  "south" : __DIR__"bridge3",
  "enter" : __DIR__"pavilion",
]));
	set("item_desc", ([
	"��ˮͤ":"�������ѵ���ͷ������ǰ�����������£��ⶥ��ϼ�ĺ�����ˮͤ��\n",
	"pavalion":"�������ѵ���ͷ������ǰ�����������£��ⶥ��ϼ�ĺ�����ˮͤ��\n",
	]) );
		set("objects", ([
//        __DIR__"npc/surong" : 1,
        __DIR__"npc/thief" : 1,
                        ]) );
    set("outdoors", "jinan");
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_jump", "jump");
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


int do_jump(string arg)
{
   object me, room;
   int ml;

   me = this_player();
   ml = me->query_skill("move",1);

      if(!arg || (arg != "up" && arg != "pavalion" && arg != "��ˮͤ" && arg != "��ˮͤ��")) {
			tell_object(me,"��Ҫ����������\n");
			return 1;
	}

      if (ml >= 170)
	  {
		 message_vision(CYN"$Nһ������̬��ӯ������ˮͤ��Ծȥ������\n"NOR,me);
         room = find_object(__DIR__"pavtop");
         if(!objectp(room)) room = load_object(__DIR__"pavtop");
         me->move(room);
         message("vision", me->name()+"�����������������\n", environment(me), me);
         return 1;
      }

	message_vision(CYN"$N����������ˮͤ����ȥ������ȴ���˽����Ǻ�Ҷ�������޴�������\n"NOR,me);
	room=find_object(__DIR__"bottom");
	if (!room)
		room=load_object(__DIR__"bottom");
	message_vision(CYN"$N�����㵸�ش��˸�ת�������Ծ�����磬���������ص����˺��\n"NOR,me);
	me->move(room);
    return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
