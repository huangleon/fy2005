

#include <weapon.h>
inherit STAFF;

void create() {
	set_name("���ع�", ({ "staff" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ����൱��ͨ��ľ��");
		set("value", 20000);
		set("weapon_prop/attack",15);
		set("level_required",20);
		set("material", "iron");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_staff(30);
}
