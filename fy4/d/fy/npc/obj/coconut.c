#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"Ҭ��"NOR, ({"coconut" }) );
    set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������Ƥ������Ҭ�ӡ�\n");
		set("unit", "��");
		set("value", 0);
        set("food_remaining", 1);
		set("food_supply", 1);
	}
    ::init_item();
}

int finish_eat()
{
	object me;
	me = this_player();
	me->apply_condition("salt_drug",5+random(10));
	tell_object(me,"��һ��ҧ��Ҭ�ӣ�ֻ�������﷢�෢ɬ��ԭ�����Ҭ�����ѻ��ˡ�\n");
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

