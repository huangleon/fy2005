// staff.c : Gun zi

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name("׽�����⹳", ({ "zhuo hun gou" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѽ����������⹳�������ƺ������Ż��أ�");
                set("value", 30);
                set("material", "steel");
        }
        ::init_staff(23, TWO_HANDED);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (userp(me) || victim->query_condition("unknown"))	
		return;
	
	victim->apply_condition("unknown",random(5)+5);
        return HIR "$n�ƺ�Ⱦ����׽�����⹳�ϵĶ���\n"NOR;
}

