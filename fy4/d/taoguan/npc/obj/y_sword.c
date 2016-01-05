#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    	set_name("��ľ��", ({ "sword" }) );
    	set_weight(1000);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
	        set("unit", "��");
	        set("long","����һ�ѻ���ľ��ɵĽ�����������һ����ζ���������������δ���������ġ�\n");
	        set("value", 800);
	        set("material", "wood");
	        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	        set("weapon_prop/spirituality", 1);
	        set("for_taoist",1);
    }
    ::init_sword(15);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        if(query("exorcising"))
        	return ;

        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > (int)victim->query("atman")/2 ) {
                        damage = me->query_spi()/2;
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY "��ľ������һ����ɫ�����������$N��ȫ��\n"NOR;
                }
                return random(me->query_spi());
        }
}
 
