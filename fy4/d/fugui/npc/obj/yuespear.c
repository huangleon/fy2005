#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name(HIR"��Ȫ��ǹ"NOR, ({ "yue spear","spear" }) );
        set_weight(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                      
"һ�˳�Լһ�����ߵ�պ���ǹ,ǹ���Ϻ�Ȼ���š���Ȫ��ǹ���ĸ��֣�
���ǵ���ŭ�����,̤�ƺ���ɽ�ڣ�һ����˧�����Ǳ��޵����µ������\n\n"
);
                set("value", 0);
                set("no_stack",1);
                set("no_drop",1);
                set("material", "steel");
                set("level_required",30);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n�һ�����\n");
        }
        ::init_spear(40);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	dam = (int) me->query("max_force")/40;
	dam = COMBAT_D->magic_modifier(me, victim, "gin", dam);
	victim->receive_damage("gin",dam,me);
    return HIR"��Ȫ��ǹ�ƾ����������·���������Ѫâʹ$n�����ɢ����ƣ������\n"NOR;
}

