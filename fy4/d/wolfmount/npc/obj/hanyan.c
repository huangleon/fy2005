#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(HIW"����ǹ"NOR, ({ "hanyan" }) );
    set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ����������ǹ���˳����ߣ��̶�˶������ͭ����\n");
		set("value", 5);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
        set("unwield_msg", "$N�����е�$n����������\n");
	}
    ::init_hammer(10);
}
