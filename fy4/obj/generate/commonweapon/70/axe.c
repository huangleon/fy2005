#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create() {
	set_name(HIR"�һ��޾�"NOR, ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 800000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("material", "iron");
		set("wield_msg", "$N�ӱ�����$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_axe(70);
}
