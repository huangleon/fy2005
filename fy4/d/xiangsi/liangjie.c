// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���籮");
        set("long", @LONG
ʯ���Ͽ������˲�����У�Լ�����ɳ��̣�����ʯͷ��Ȼһ�壬��֪����
����ɣ������湤�ɽ����컯֮��������(�����𡡣�����)��ʯ����
������һ����״ʯ�������ϵ������Ѿ�����ʱ������Ž���ģ����ʯ����
����һƬ�������������ȴ��Ȼ�����ƽ���ӵ�价ɽ���������£�ʯ��
�·���һ��ɽ��Ͽ�ȣ��������ˡ�
LONG
        );
	set("objects", ([
		__DIR__"obj/rock3" : 1,
	]));
	set("exits",([
  		"west" : __DIR__"wuzhang",
  		"east" : __DIR__"leidashi",
	]) );
	set("item_desc",([
		"ʯ��":	"һ��ʯ�������������˿��£����Ͽ������ˡ�\n",
		"ʯ��":	"ʯ������״������������Ѿ�����ʱ������Ž���ģ����\n",
	]));
		
	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_jump", ({"dash","jump" }));
}


int do_jump(string arg)
{
   
   	object me, room;
   	int m;

   	me = this_player();
   	m = me->query_skill("move",1);
      
      	if(!arg || (arg != "down" && arg != "��" && arg!= "bridge" && arg!="����" 
      		&& arg!="��" && arg != "����ʯ"  && arg != "ʯ��"  && arg != "����"
      		&& arg!="ridge" )) {
      		write("��û��������������\n");
      		return 1;
      	}
      	
      	if (m >= 70 && me->query("force") >= me->query("max_force"))
		{
			message_vision(CYN"$N��һ������������ʯ����Ծȥ��\n"NOR,me);
			room = load_object(__DIR__"huju");
         	me->move(room);
         	message("vision", me->name()+"��ʯ����Ծ��������\n", environment(me), me);
         	return 1;
      	}
      	else if (m <70)
		{
         	tell_object(me, "�����������С�ĵ���ͷ��Ѫ����\n");
        	return 1;
		} 
		else
		{
			tell_object(me, "�����������������������ȥ��\n");
        	return 1;
			
		}			
      return 1;
}
