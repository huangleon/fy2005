// silencer@fy4

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","׷�������");
	set("type","fork");
	set("difficulty",200);
	set("effective_level",150);
	set("usage/fork",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("parry_msg",			({
			"���$n�����е�$v����$N����ʽ��\n",
			"$n�Ӷ�$v������ǰ���˸���Բ�����õ���$N�Ĺ��ơ�\n",
			"$n˿����Ϊ���������赭д�ػӲ�һ�̣��Ƶ�$N�����Է���\n",
			"$n��$v��÷��겻͸��$N����֮��ֻ�û��С�\n",
			"$nһ������$v����$N������һ���������ݿ����ɡ�\n",
			})
	);
	set("unarmed_parry_msg",			({
			"���$n�����е�$v����$N����ʽ��\n",
			"$n�Ӷ�$v������ǰ���˸���Բ�����õ���$N�Ĺ��ơ�\n",
			"$n˿����Ϊ���������赭д�ػӲ�һ�̣��Ƶ�$N�����Է���\n",
			"$n��$v��÷��겻͸��$N����֮��ֻ�û��С�\n",
			"$nһ������$v����$N������һ���������ݿ����ɡ�\n",
			})
	);
	action = ({
			([      "action":               
					"$N������������$w��������$n",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$Nһ����Х�����������Ӱ����$n����ǵصش�ȥ",
			        "damage":               30,
			        "dodge":                -100,
			        "parry":                -100,
			        "damage_type":  "����"
			]),
			([      "action":           
					"$N�������$w��ʹ����ʮ��������ãã��������$n$l",
			        "damage":               40,
			        "dodge":                -10,
			        "parry":                -40,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$Nʹ��һ�С������ζϡ���$wһͦ����$n$l",
			        "damage":               50,
			        "dodge":                -10,
			        "parry":                -40,
			        "damage_type":  "����"
			]),
	});
}

int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	
	if((int)me->query("str") + (int)me->query("max_force") / 10 < 35) {
		return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
	}
	return 1;
}


int practice_skill(object me)
{
	
	if ((int)me->query("force") < 20) {
		return notify_fail("�������������׷������档\n");
	}
	if(!::practice_skill(me)) {
		return 0;
	}
	me->add("force", -10);
	return 1;
}
