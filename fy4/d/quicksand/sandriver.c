#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɳ�ӵ�");
	set("long", @LONG
ԭ��������һ�����ӣ������ˮ������ȴ������ɳĮ����ΧһƬ�谵��������
�����ɵ�ɳˮ������Ըо���ˮ�е�ɳ�������Ħ���������գ���סһ��������
΢΢������������ȥ��б�Ϸ������и����ڣ�͸��΢΢��⡣ 
LONG
	);
	set("exits", ([ 
  		"southup" : __DIR__"sandriver1",
	]));

	set("indoors", "quicksand");

	set("coor/x",-1060);
	set("coor/y",-10);
	set("coor/z",-50);
	set("underwater",150);
	set("water_damage",20);
	setup();
}

void init()
{
   	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}


int valid_enter(object me) {
	tell_object(me, "\nͻȻ�䣬ѹ�������ˣ����ܵ���ɳҲ�����ˣ���Ӹߴ����£���ͨһ��������ˮ�\n\n");
	message("vision", "\n��ͨһ����" + me->name() + "�����������Ե�ˮ�С�\n", this_object(), me);
	return 1;
}


int valid_leave(object me, string dir) {
	if (dir=="southup") {
		message_vision(HIB"\n$N��ס������������ǰ��ȥ��\n"NOR, me); 	
	} 
	return 1;
}

