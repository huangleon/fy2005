#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void do_eatflower();

void create()
{
	set_name(HIY"Խ��"NOR, ({ "bilberry" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��С��Ҳ�Ƶ�Խ�١�\n");
		set("unit", "��");
		set("base_unit","��");
		set("base_value", 10);
		set("food_remaining", 3);
		set("food_supply", 10);
		set("wield_msg", "$N��$n�������е�������\n");
		set("material", "bone");
		set("eat_func", (: do_eatflower :) );
	}
	set_amount(1);
	::init_throwing(1);
}


void do_eatflower()
{
	object me;
	me = this_player();
	tell_object(me,HIB"΢���Խ��ҧ�������ֻ����Խ��Խ����\n"NOR);
	me->add("food",-100);

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
