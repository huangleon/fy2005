
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIC"����ǹ"NOR, ({ "silver spear","spear" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "����һ��պ����ǹ���������ƺ��������ᡣ\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N��֪��ʲô�ط�����һ��$n,��ৡ���һ���������С�\n");
		set("unwield_msg", "$N�����е�$n����\n");
	}
    	::init_spear(15);
}
