inherit ROOM;
#include <ansi.h>

string look_house();

void create()

{
        set("short", "С����");
        set("long", @LONG
΢���д���Ȫˮ�������������㲻֪�������߹�ȥ������ˮ������������ˮҲ
���ɿݣ�ȴ��Զ����ͣ����,�·���Զ��֪����룬�����ֻ��õ��������㲻�䡣
̸��������Ӻ�ˮ�����𣬿�������ô���ᣬ��ô���������������һԾԾ�����
��ķ��պ�ʹ�����Ҳ�ܿ�ؾͻ�������������ʧ��
LONG
        );
        set("exits", ([ 
		"eastup":  __DIR__"spring",
	]));
	set("item_desc",([
			"red house": 	(: look_house() :),
			"house": 	(: look_house() :),
			"С��¥": 	(: look_house() :),
			"��¥": 	(: look_house() :),
			"river":	"һ������������СϪ��ˮ��������������\n",
			"��ˮ":		"һ������������СϪ��ˮ��������������\n",
			"С��":		"һ������������СϪ��ˮ��������������\n",
			"��ˮ":		"һ������������СϪ��ˮ��������������\n",
			"stream":	"һ������������СϪ��ˮ��������������\n",
			"Ȫˮ":		"һ������������СϪ��ˮ��������������\n",
	]) );
        set("objects", ([
        	__DIR__"npc/xiaodie2": 1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1670);
        set("coor/y",640);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}


void init(){
	add_action("do_walk","walkto");
}


int do_walk(string arg){
	
	object me=this_player();
	object room;
	
	if ( REWARD_D->riddle_check(me,"��԰����")!=14
			&& !REWARD_D->check_m_success(me,"��԰����")) {
		tell_object(me,"������������û���߹�ȥ��\n");
		return 1;
	}
	if (arg == "building" || arg == "house" || arg == "С��¥" || arg == "��¥") {
		message_vision("$N��Ӷ԰�һԾ����Ӱ��ʧ�������С�\n",me);
		room=find_object(__DIR__"star_room2");
		if (!objectp(room)) room=load_object(__DIR__"star_room2");
		me->move(room);
		return 1;
	}
	tell_object(me,"�������Ķ��ߣ�\n");
	return 1;
}
		
		
		
string look_house(){
	
	object me=this_player();
	if ( REWARD_D->riddle_check(me,"��԰����")!=14
			&& !REWARD_D->check_m_success(me,"��԰����"))
		return "ˮ����������ʲôҲ���������\n";
	return "ˮ���У��԰���һ��С��¥�������֣�����������߹�ȥ(walkto)��\n";
}
