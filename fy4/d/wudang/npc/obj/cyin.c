#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(RED"ϦӰ��"NOR, ({ "cyin blade","blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "flex");	// :>>....flex blade
		set("no_get",1);
	}
	::init_blade(77);
}

mixed hit_ob()
{
	return RED"ϦӰ��ӳ��һƬ�������ʵĵ�ϼ���⣬����Ŀ������\n"NOR;
}
