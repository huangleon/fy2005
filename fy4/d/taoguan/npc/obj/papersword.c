// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("��ֽ��" , ({ "papersword","paper sword","sword","seal sword" }) );	
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",                      
"һ�ѷ�ֽ���ɵĽ�������������������\n");
                set("value", 10000);
                set("material", "paper");
	        set("for_taoist",1);
	        set("ex_eff",110);
	        set("combat_exp",6400000);
        }
        ::init_sword(25);
}


mixed hit_ob(object me, object victim)
{
	object weapon;
	string result;
	int extra;
	
	weapon=me->query_temp("weapon");
	
	if (!userp(me) && me->query("id")=="xin wang")
		extra = 200;
	
	if(!extra )	return ;
		
	result=HIR"��ֽ���ϵ�Ѫɫ�ƺ��ּ�����һ�֣�����\n";
	if(victim->is_ghost())
	{
		victim->set("eff_sen",-100);
		victim->receive_wound("sen",100,me);
		result+=HIR+victim->name()+"�����Ĳҽ���һ������Ϊ�˻ҽ���\n"NOR;
	}
	else if(victim->is_zombie())
	{
		victim->set("eff_sen",-100);
		victim->receive_wound("sen",100,me);
		result+=HIR+victim->name()+"�����Ĳҽ���һ������Ϊ��һ̲Ѫˮ��\n"NOR;
	}
	else
	{
		victim->receive_wound("sen",extra,me);
		victim->receive_damage("sen",extra/2,me);
		result+=HIY"$n�����������ݣ���Ϊ֮�ᡣ\n"NOR;
		// 300 damage,geese@main hv 6k sen,��סӦ�ò���...*snicker
		// point master ding,2250 damage per hit! rascal ding
	}
	return result;
}

