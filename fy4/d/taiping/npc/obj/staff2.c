#include <weapon.h>
inherit STAFF;

void create() {
	set_name("û�����ߵĵ����", ({ "fishpole" }) );
	set_weight(2000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ϸϸ�ĵ���ͣ���ֵ���û�в����ߡ�\n");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_staff(10);
}
