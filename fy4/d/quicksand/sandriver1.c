#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɳ�ӵ�");
	set("long", @LONG
ԭ��������һ�����ӣ������ˮ������ȴ������ɳĮ����ΧһƬ�谵��������
�����ɵ�ɳˮ������Ըо���ˮ�е�ɳ�������Ħ���������գ���סһ��������
΢΢������������ȥ��͸��΢΢���Ķ��ڸ�������ˣ�����������Ϸ��� 
LONG
	);
	set("exits", ([ 
  		"up" : __DIR__"shaxue",
	]));

	set("indoors", "quicksand");

	set("coor/x",-1060);
	set("coor/y",-20);
	set("coor/z",-20);
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

int valid_leave() {
	message_vision(HIB"$N��ס�������δ������˶��ڡ�\n"NOR, this_player()); 
	return 1;
}
