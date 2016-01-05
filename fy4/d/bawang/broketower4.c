#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����Ĳ�");

	set("long", @LONG
���Ƕ������Ĳ㡣���������ҳ���һ��������ķ��⣬�����ƺ�ʲô��û�С�
���洰���Ϻ�����ֽ�Ѳ����ˣ����紵�á����������������졣Խ�ߵ����棬��Խ
������Խ�죬�����Ҳ����Խ�졣�����ߵ�ľ�ݸ����ưܣ��ƺ���ʱ�����䡣
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"broketower5",
		"down":__DIR__"broketower3",
	]) );
	set("objects", ([
		__DIR__"npc/ghost": 2,
	]));
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string dir)
{	object *inv;
	int t_weight;
	int i;
	mapping exits;
	object room;
	exits=query("exits");
	room=load_object(exits["down"]);
	inv = all_inventory(me);
	t_weight = 0;
	for(i=0; i<sizeof(inv); i++)
	{
		t_weight = t_weight + inv[i]->weight();
	}
	if( dir == "up" && t_weight > 140000)
	{
		message_vision(HIR"�����ɣ��������ľ�����Գ���$N֮�أ�һ���Ӷ��ѿ�����\n\n"NOR,me);
		message_vision(HIR"$Nһ��С�ģ���������ص��Դ�ˤ������......\n���磡��$N�Դ�����˸����ľ�����档\n "NOR,me);
		tell_room(room,HIR+me->query("name")+"һ��С�ģ�ˤ��������\n "NOR);
		me->move(room);
		me->receive_wound("kee",2);
		return notify_fail(HIW" ����¥�ݿɲ�̫��ʵ�������÷���Щ��������......��\n"NOR);
	}
//	if(!NATURE_D->is_day_time()){
		tell_object(me,HIM "\n
		
�������ͷ���ϵĶԻ���Խ��Խ������

������Ϊ�Ҳ���������
������������֮�У�����һ���ǲ������ġ���
����������������֮�У����Ʊ�ֻ��һ���ܻ��Ż�ȥ����
\n\n"NOR);
//	}
	return 1;
}

/*void init() {
	if(NATURE_D->is_day_time()){
		return;
	} else {
		call_out("greeting", 1, this_player());
	}
}

void greeting(object me){

}
*/