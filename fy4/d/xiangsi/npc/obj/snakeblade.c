#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(MAG"������ϼ"NOR, ({ "twilight blade","blade"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", MAG"һ������ɫ���䵶�������Ͽ���һ���������ŵ�С�ߡ�\n"NOR);
		set("material", "iron");
		set("value",10);
		set("lore", 1);
	}
	::init_blade(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	return MAG"������ϼ�Ϸ���������ƣ���$n"MAG"�������С�\n"NOR;
}
