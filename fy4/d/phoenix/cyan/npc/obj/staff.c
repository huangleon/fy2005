// staff.c


#include <weapon.h>
inherit STAFF;

void create() {
	set_name("��ɽ��", ({ "staff" }) );
	set_weight(2000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ��ľ����");
		set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
		set("climb",1);
	}
    ::init_staff(15);
}
