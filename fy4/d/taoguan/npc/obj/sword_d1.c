// sword.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(  "�佣����" , ({ "sword" }) );		// ���˷�
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",                      
"����һ����ľ��ɵĹŽ�����������һ����ζ���������������δ��������
�ģ�ֻ�н���������������ϡ���Ա��ϵ�׭�֣��� �� �� ��
��ն���Ч��x1.2��\n");
                set("value", 18000);
                set("material", "wood");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	        set("weapon_prop/spirituality", 10);
	        set("for_taoist",1);
	        set("ex_eff",120);
	        set("combat_exp",6400000);
        }
        ::init_sword(25);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
	if(query("exorcising"))
        	return ;
        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > (int)victim->query("atman")/2 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY "���򽣷���һ�ɽ�ɫ�����������$N��ȫ��\n"NOR;
                }
                return random(me->query_spi());
        }
}
 
