// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "Σ��һ��");
    set("long", @LONG
�ո�̤�ϴ��ţ�����ľ��ᵽ��ɤ���ۡ�������ɵ�ʯ������û�л�����
����һ�磬�����ڷ�ͷ֮�ϣ�������Ԩ����Χ���������ѱ�Զ�����������
ʱһ��С�ĵ�����ȥ��ֻ����ʱ��Ҫʬ���޴棬ˤ��������������ɿڵ�һ
̲��
LONG
        );
	set("objects", ([

	]));
	set("item_desc", ([
		"west":"���صĴ����赲ס������ߡ�\n",
		"east":"���صĴ����赲ס������ߡ�\n"

	]) );
	set("exits",([
  		"west" : "hotel5",
  		"east" : "rock",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}

void init()
{
	object me = this_player();
	// not 
	::init();
	if (random(me->query_skill("move")) < 2)	// well.. 
	{
		message_vision(CYN"\n��Ȼһ����Ϯ���������$N����ҡҡ�λΣ�����\n"NOR,me);
		if (random(me->query_skill("move")) < 2)	// again? sorry then, you are really bad bad luck.
		{
			message_vision(HIY"\nֻ����һ����У�$N����һ�����ȣ���ʯ����ֱֱ׹����ȥ��\n\n"NOR,me);
			me->die();	
		}
	}
}

int valid_leave(object obj, string dir){
	if (userp(obj) && random(5)) {
		obj->move(this_object());
		message_vision(CYN"$N����ʯ���ϣ�С���������ǰ�����ȥ��\n"NOR,obj);
		obj->perform_busy(1);
		return notify_fail("");
		}
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


