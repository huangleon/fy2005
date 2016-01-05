//feidao.c
inherit SKILL;

void setup() {
	set("name","�ɵ�����");
	set("type","throwing");
	set("effective_level",150);
	set("difficulty",500);
	set("usage/throwing",1);
	set("skill_class","npc");
	
	action = ({
        ([      "action":               
"$N˫��һ�Σ����е�$w��һ�����߰����$n��$l",
                "dodge":                -20,
                "damage":               30,
		"post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����$w�����̶����ƿ���ֱ��$n��$l",
                "dodge":                -40,
                "damage":               30,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ָ΢����$wбб�ķ���$n��$l",
                "dodge":                -40,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������⣬����һ˦�����е�$w����һ����������$n��$l",
                "dodge":                20,
                "post_action":  "throw_weapon",
                "damage":               40,
                "damage_type":  "����"
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)) {
		return 0;
	}
	if( (int)me->query("max_force") < 500 ) {
		return notify_fail("�������������û�а취���ɵ�������\n");
	}
	return 1;
}

