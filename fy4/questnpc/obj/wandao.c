//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIC "Բ���䵶" NOR, ({ "moonblade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����״�����صĵ�������·��е�������\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��$nͻȻ���ʣ��������û�п���$N�ε���\n");
		set("unwield_msg", "$N��$n�����ʡ�\n");
		set("for_modao",1);
	}
	init_blade(25);
	setup();
}
