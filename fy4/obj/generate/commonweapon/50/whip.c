
#include <weapon.h>
inherit WHIP;

void create() {
	set_name( "�������ı�", ({ "whip" }) );
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200000);
		set("weapon_prop/attack",25);
		set("level_required",40);
		set("material", "skin");        
		set("wield_msg", "$N����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_whip(50);
}

