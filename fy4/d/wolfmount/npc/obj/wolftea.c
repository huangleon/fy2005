inherit ITEM;
inherit F_FOOD;

#include <ansi.h>
void create()
{
	set_name(GRN"��ɽ��"NOR, ({ "wolf tea", "wolftea" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ֲ�����ɽ�Ĳ�Ҷ�������͵ĺܿɰ���\n");
        	set("unit", "��");
		set("value", 400);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
   	::init_item();
}
