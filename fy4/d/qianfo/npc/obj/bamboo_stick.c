// bamboo_stick.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("����", ({"stick", "bamboo stick"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ŵ����������ȡ�\n");
		set("value", 100);
		set("material", "bamboo");
		set("wield_msg", "$N���һ����������������������С�\n");
		set("unwield_msg", "$N�����е����Ȳ�����С�\n");
	}
	::init_staff(15);
}	
