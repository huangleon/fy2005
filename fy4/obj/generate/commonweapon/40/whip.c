
#include <weapon.h>
inherit WHIP;

void create() {
	set_name( "��β��", ({ "whip" }) );
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100000);
		set("weapon_prop/attack",20);
		set("level_required",30);
		set("material", "skin");        
		set("wield_msg", "$N����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_whip(40);
}

