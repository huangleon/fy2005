
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name( "ߡ��" , ({ "zheshan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱���µ�ߡ��\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$nչ�����������������¡�\n");
		set("unwield_msg", "$N�����е�$n�����������С�\n");
	}
	init_dagger(5);
}
