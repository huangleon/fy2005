#include <ansi.h>


#include <weapon.h>
inherit STAFF;

void create() {
	set_name(YEL"һ���Ժ�"NOR, ({ "staff" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ����൱��ͨ��ľ��");
		set("value", 800000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("material", "iron");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_staff(70);
}
