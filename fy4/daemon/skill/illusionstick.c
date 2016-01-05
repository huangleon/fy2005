inherit SKILL;
void setup(){
	set("name","�������������Ϲ�");
	set("type","staff");
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("effective_level",100);
	set("skill_class","demon");
	set("parry_msg", ({
        	"$nʹ��һ�С�����ҡͷ������$v�ڿ�������$N��$w��\n",
		"$n����$v��ڣ�һ�С��׻�̽צ����������$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n����������ˣ�����$v�ն�����ס��$N�Ĺ��ơ�\n",
		"$n����ֱͦͦ�˵��ڵأ�����$v����ɨ��$N��\n",
	}) );	
	action = ({
        ([      "action":               
"$Nʹ��һ�С�ӥ�����ա��������ڿն�������$w�Ҷ���������$n��$l�ݺ���ȥ",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$Nʹ��һ�С��������֡�������$w�������ѩ�����������֣���������$n��$l",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ��һ�С����ﳯ��������������$w������ֱָ$n��$l",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�ն���������������Х����һ�С���Х��������ֱ��$n��$l��ȥ",
                "damage":               200,
                "dodge":                110,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�Σ�����ȻΪ˫��һ�С��ʷ�˫�������ֱ�Ϯ��$n������Ҫ��",
                "damage":               10,
                "dodge":                100,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ת������$wһ�С�����������������$n��$lɨȥ",
                "damage":               20,
                "dodge":                10,
                "parry":                20,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���δ�������$wһ�С�һ�׳��졹��ֱ��ֱ�µش���$n��$l",
                "damage":               100,
                "dodge":                -10,
                "parry":                20,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�٣�����$wб��һ�С���Գ���١�������$n��$l",
                "damage":               50,
                "dodge":                10,
                "parry":                20,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�趯�����������Ӱ��һ�С����񳯷���Ӹ����Ƕ�ͬʱ����$n��$l",
                "damage":               50,
                "dodge":                200,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��ͻ���ɽ������Ծ������$w���϶��£���������$n��$l",
                "damage":               90,
                "dodge":                30,
                "parry":                50,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
	});
}

int valid_learn(object me)
{
	if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 ) {
	    return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
	}
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}


int help(object me)
{
	write(@HELP   
���λ����ޡ���menghuantianluo��
����������˪�쾹���ɵ�һ������������

HELP
    );
    return 1;
}
