

#include <weapon.h>
inherit STAFF;

void create() {
	set_name("��ħ��", ({ "staff" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ����൱��ͨ��ľ��");
		set("value", 200000);
		set("weapon_prop/attack",25);
		set("level_required",40);
		set("material", "iron");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_staff(50);
}
