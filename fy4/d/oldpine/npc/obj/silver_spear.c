
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIW"����ɫ�ĳ�ǹ"NOR, ({ "silver spear" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������ĳ�ǹ��������Լ��ʮ�������ҡ�\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������¡�\n");
	}
	::init_spear(15);
}
