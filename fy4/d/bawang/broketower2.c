#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��������");

	set("long", @LONG
���Ƕ����ڶ��㡣���������ҳ���һ��������ķ��⣬�����ƺ�ʲô��û�С�
���洰���Ϻ�����ֽ�Ѳ����ˣ����紵�á����������������졣Խ�ߵ����棬��Խ
������Խ�죬�����Ҳ����Խ�졣�����ߵ�ľ�ݸ����ưܣ��ƺ���ʱ�����䡣
LONG);

	//{{ --- by MapMaker
	set("type","street");
	set("exits",([
	"up":__DIR__"broketower3",
	"down":__DIR__"broketower",
	]) );
	//}}
	set("objects", ([
          __DIR__"npc/ghost": 3,
           ]));
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",-5);
	setup();
	//replace_program(ROOM);
}
void slipping(object me,object room)
{
	 message_vision(HIR"$Nһ��С�ģ���������ص��Դ�ˤ��������\n "NOR,me);
	 tell_room(room,HIR+me->query("name")+"һ��С�ģ���������ص��Դ�ˤ��������\n "NOR);
	 me->move(room);
	 me->receive_wound("kee",2);
}

int valid_leave(object me, string dir)
{
	mapping exits;
	object room;
	exits=query("exits");
	room=load_object(exits["down"]);
	if( dir == "up" && (int)me->query_skill("move")+random(140)<random(280))
    {
		message_vision(HIR"�����ɣ��������ľ�����Գ���$N֮�أ�һ���Ӷ��ѿ�����\n"NOR,me);
		message_vision(HIR"$Nһ��С�ģ���������ص��Դ�ˤ�����������磡��$N�Դ�
����˸����ľ�����档\n "NOR,me);
		tell_room(room,HIR+me->query("name")+"һ��С�ģ�ˤ��������\n "NOR);
		me->move(room);
		me->receive_wound("kee",2);
		return notify_fail(HIW" ����¥�ݿɲ�̫��ʵ���»������������Ṧ�ȡ�������\n"NOR);
	}
	return 1;
}
