#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIG"С¥һҹ������"NOR, ({ "springrain blade", "blade" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "��С¥һҹ�����꣢������С¥���꣢�����������������������֮һ��\n"
                        "�˵���а�����������ࡣ\n");
                set("value", 35000);
                set("material", "sapphire");
		set("rigidity", 50000);
		set("no_get",1);
		set("no_drop",1);
                set("wield_msg", "$N��ˢ����һ�����һ�����������$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        ::init_blade(10);
}

void owner_is_killed(object killer)
{
	message_vision(HIR"\n \n С¥һҹ������ "NOR +"���ڵ��ϣ��ֵ���$N�Ļ��У�\n\n",killer);
	this_object()->move(killer);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	me->add("bellicosity",10+random(30));
        return RED "$N������ӳ�ţ�С¥һҹ�����꣢�����Ĺ����⡣\n"NOR;
}

