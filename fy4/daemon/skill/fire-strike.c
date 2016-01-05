// silencer@fengyun4

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","������");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",200);
	set("practice_limit",100);
	set("damage_level",100);
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
		"$n��������ͻȻһ�Ż��潫$N�Ƶ����˼�����\n",
		"$n���ϵĻ�������һʢ��$N�Ĺ��ƴ��˻��ű�Ե����Ȼ�����ڲ�����\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n����һ��������$N��\n",
        	"$n��������ͻȻһ�Ż��潫$N�Ƶ����˼�����\n",
		"$n���ϵĻ�������һʢ��$N�Ĺ��ƴ��˻��ű�Ե����Ȼ�����ڲ�����\n",
	}) );
	action = ({
		([	"action":		"$NͻȻһ������������$n��$l��",
			"dodge":		100,
			"parry" :		100,
			"force":		400,
	                "damage":               200,
			"damage_type":	"����"
		]),
		([	"action":		"$N����һ�һ���һ�ӭ����$n��$l����",
	                "dodge":		30,
			"parry" :		100,
	                "damage":               200,
			"force":		300,
			"damage_type":	"����"
		]),
		([	"action":		"������$N�����е����ƣ����ۺ�ɢ���ƻ���$n��$l",
			"dodge":		120,
			"parry" :		80,
			"force":		100,
	                "damage":               200,
			"damage_type":	"����"
		]),
		([	"action":		"$Nһ���ֵ���$n���󣬴��һ����ɫ����",
			"dodge":		100,
			"parry" :		400,
			"force":		100,
	                "damage":               200,
			"damage_type":	"����"
		]),
		([	"action":		"$N����ȫ��Ĺ�����˫�ִ�����ŷ���$n",
			"dodge":		300,
			"parry" :		300,
			"force":		200,
			"damage":		200,
			"damage_type":	"����"
		]),
	});
}
int valid_learn(object me)
{
    if( (int)me->query_skill("force", 1) < 100 ) {
        return notify_fail("����ڹ��ķ�����㣬�޷��������Ʒ���\n");
	}
	return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
	int my_exp, your_exp, damage, lvl;
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	lvl= me->query_skill("fire-strike",1);
	damage = lvl*2;
	
	if( 10*random(my_exp)>your_exp) {
		victim->receive_wound("kee",damage+random(damage));
		victim->set_temp("last_damage_from",me);
		return RED "$n���һ����յý�ͷ�ö\n" NOR;
	}	
}
