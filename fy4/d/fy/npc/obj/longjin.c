inherit ITEM;
inherit F_FOOD;

#include <ansi.h>
void create()
{
    set_name( YEL"������"NOR, ({ "longjing tea", "tea" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "�����պ�һ����������Ҷ,ʮ���ռ���\n");
		set("unit", "��");
        set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
