#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name( HIR "���泤��" NOR, ({ "fireblade" }) );
	set_weight(7000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long",	"һ�ѷǽ��ľ��ͨ�尵��ĳ�����\n");
	    set("red_dragon_bane",1);
	    set("value", 0);
	    set("material", "steel");
	    set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	    set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	
	::init_blade(15);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	
	dam = (int) me->query("force");
	if(!userp(me))
	{
		victim->receive_wound("kee",100, me);
		return HIR "���泤�����һ���ɺ�Ļ��棬�ǿ���$n��ȫ��\n" NOR;
	}
}
 
