#include <weapon.h>
inherit AXE;

void create() {
	set_name("���ḫ", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200000);
		set("weapon_prop/attack",25);
		set("level_required",40);
		set("material", "iron");
		set("wield_msg", "$N�ӱ�����$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_axe(50);
}
