#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
#include <command.h>

void create()
{
        set_name(HIY"������"NOR, ({ "abacus","gold abacus" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ���Ӳӵ����̣�������������ġ�\n");
                set("value", 1);
                set("material", "steel");
                set("wield_msg", "$N��ž����һ���ó�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��Ū�˼��£��һ�����\n");
        }
        ::init_hammer(10);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	dam = (int) me->query("force_factor");  //*2; //add by ldb *2 ����ɱ���۹� 
	victim->receive_damage("gin",dam,me);

	return HIR"�����̻������죬$n�ķ����ң�������ս��\n"NOR;
}

