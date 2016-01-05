
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(BLK"ն��"NOR, ({ "ghost blade","blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ���������ڵĺ�������˸�Żް���Ѫ�⡣\n");
                set("value", 800);
                set("material", "steel");
        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_blade(20);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        if( victim->is_zombie())
        {
                victim->receive_wound("gin",random(me->query("mana")*50));
                return HIR "��Ȼ��ն��ͻȻ���������⻪,������ת,��������...\n"NOR;        
        }
        if( victim->is_ghost() ) {
                if( random(me->query("max_mana")) > (int)victim->query("mana")/5 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage*10);
                        victim->receive_wound("sen", damage*10);
                        me->receive_heal("kee", damage*5);
                        me->receive_heal("sen", damage*5);
                        victim->receive_wound("kee", damage*10);
                        return HIY "ն����Ȼ�����������,������ת,��������,ȴʹ$N���ػ������崺��,��̩���...\n"NOR;
                }
                return random(me->query_spi());
        }
}

