#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("������֦", ({ "shuzhi" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����߳��İ�����֦������ϸϸ�ġ�\n");
		set("value", 200);
		set("material", "wood");
		set("rigidity", 200);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_sword(2);
}



