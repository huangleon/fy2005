#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
    set_name( HIG "��絶" NOR, ({ "windblade" }) );
    set_weight(70000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long","һ�������񣬵���һ����ֻ��ı���������ʮ�����������֮һ\n");
        set("for_bandit",1);
        set("material", "steel");
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("value", 100);

    }
    
    ::init_blade(15);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam;
    dam = (int) me->query("force");
    if( victim->query("sen") > victim->query("max_sen")*3/4) {
	    victim->receive_damage("sen",dam/20);	// 100-150 maximum
    	return HIG "��絶�����ĺ�Х���ŵ�$n��������\n" NOR;
	}
	return 0;
}
