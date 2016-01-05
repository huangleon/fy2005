#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"���¶̵�"NOR, ({ "newmoon blade", "blade"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ������Ķ̵��������������£��˵���˵����ѩ�ı�����Щ����Ч����20%���ʶ����˺���\n");
		set("material", "iron");
		set("value",10);
		set("lore", 1);
	}
	::init_blade(20);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	mixed c;
	int badint=0;
	if(damage_bonus < 300 ) return 0;
	
	if (!random(5)) return 0;
			
	if(victim->query_temp("weapon") && victim->query_skill_mapped("blade") == "shortsong-blade")
	{
		if ((victim->query_temp("weapon"))->query("skill_type") == "blade")
		{
			badint = victim->query_skill("blade");
			victim->receive_wound("kee",badint*2,me);
			c = HIW"���¶̵�"HIC"����һ����������Ļ��ߣ�������$n������֮�С�\n" NOR;
		}
	}
	if(victim->query_temp("weapon") && victim->query_skill_mapped("sword") == "diesword")
	{
		if ((victim->query_temp("weapon"))->query("skill_type") == "sword")
		{
			badint = victim->query_skill("sword");
			c = HIW"���¶̵�"HIC"����һ����������Ļ��ߣ�������$n������֮�С�\n" NOR;
			victim->receive_wound("kee",badint*2,me);
		}
	}
	
	return c;
}
