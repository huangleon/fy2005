#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name( GRN"̤��Ʈ����"NOR , ({ "pxshan" }) );
    	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "���Ǳ��൱���µ����ȣ��ȹ����������������д�š�̤�¶�����\n���ֿ�ݣ���Լɢ������翵������㡣\n");
        set("value", 0);
		set("material", "steel");
        set("wield_msg", "$N��ৡ���һ����$nչ���������У������������¡�\n");
		set("unwield_msg", "$N�����е�$n�����������С�\n");
	}
        ::init_dagger(20);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
		int dam;
    	dam = (int) me->query("max_sen");
    	victim->receive_damage("sen",dam/100,me);
        return HIG "̤��Ʈ��������ɢ����һ˿�������޵������㣬�����ͣ���Զ������\n" NOR;
}
