// ���һ���μƻ������˹�������--- by silencer

inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(WHT"�һ����"NOR, ({ "drop","luzhu"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", WHT"����һ���һ������ľ������ɵ�¶ˮ����˵�����˺��ܹ��������ϡ�\n"NOR);
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	object me;
	me = this_player();
	message_vision(MAG"$N��������͸��һ������Ĺ�ɣ���\n"NOR, me);
	tell_object(me,MAG"������Լ�������Խ��Խ�ᣬԽ��ԽԶ���ƺ�Ʈ���ڿ��У��ò��ǿ�����˰ɣ���\n"NOR);
	me->unconcious();
	destruct(this_object());
        return 1;
}
