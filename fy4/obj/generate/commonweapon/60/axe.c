#include <weapon.h>
inherit AXE;

void create() {
	set_name("ͭ�Ÿ�", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 400000);
		set("weapon_prop/attack",30);
		set("level_required",50);
		set("material", "iron");
		set("wield_msg", "$N�ӱ�����$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_axe(60);
}
