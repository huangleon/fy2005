#include <ansi.h>

#include <weapon.h>
inherit WHIP;

void create() {
	set_name( HIC"��Ӱ����"NOR, ({ "whip" }) );
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 800000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("material", "skin");        
		set("wield_msg", "$N����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_whip(70);
}

