#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( CYN "��罣" NOR, ({ "wind sword","sword" }) );
    set_weight(7000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long","һ��������ˮ�ı�����\n");
        set("for_bandit",1);
        set("material", "steel");
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unequip_msg", "$N�����е�$n�������佣�ʡ�\n");
	set("value", 200);

    }
    
    ::init_sword(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam;
    dam = (int) me->query("force");
    if((int)victim->query("sen") > (int)victim->query("max_sen")*3/4)
    victim->receive_damage("sen",dam/20);
    return CYN "��罣�·�����紵����$n�����񲻽�һ����\n" NOR;
}
 
