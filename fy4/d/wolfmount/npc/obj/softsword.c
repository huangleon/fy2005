#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIM"��˪��"NOR, ({ "soft sword", "sword" }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("value", 1000);
        set("long", "�����ĳߣ��鶯���ߣ�����һ��������\n");
        set("material", "steel");
        set("rigidity", 100);
        set("wield_msg", "$N��������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
    ::init_sword(20);
}
