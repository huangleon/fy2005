//By clone       6/2001
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("ϸ��С��" , ({ "short sword","sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѷ�С�Ľ�������խ��\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "����һ��---$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	::init_dagger(10);
}
