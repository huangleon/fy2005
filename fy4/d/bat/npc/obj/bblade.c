#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(RED "��Ѫ��" NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "iron");
		set("long", "����һ�ѳ���а����ɱ���ĸֵ���\n");
		set("wield_msg", "$N���һ�Ѱ���ɫ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	::init_blade(15);
}
