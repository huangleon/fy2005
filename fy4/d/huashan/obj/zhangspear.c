// spear.c
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("�ɰ���ì", ({ "zhang spear", "spear" }) );
	set_weight(10000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��һ�ɰ˳ߣ��ĳ�ǹͷ���������ѡ������ǹӧӳ����ڵ�ǹ��
����һ����֪֮�ȴҲ����������");
		set("value", 800);
		set("rigidity", 2000);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(25);
}
