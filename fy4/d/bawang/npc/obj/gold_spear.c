
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIR"��ǹ"NOR, ({ "gold spear" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ͻ͵Ľ�ǹ��������Լ��ʮ�������ҡ�\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������¡�\n");
	}
	::init_spear(15);
}
