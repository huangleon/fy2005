#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","���ŵ��书");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",70);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","npc");
	
 	set("unarmed_parry_msg", 		({
        "$nָ�ⷢ��˿˿����ץ��$N����$N��æ����ܿ���\n",
        "Ȼ��$n��ָ��㣬������ָ�罫$N���ˡ�\n",
        "$n����������Ӱ��һ�С�����ˮ�¡�����Գ�һָ��һ�����$N��\n",
        "$n˫ȭ����ӳ���������ң��ȵ�$N�������ˡ� \n",
        "$n����ץ$N˫Ŀ������������ȵ�$NһԾ�˿��� \n",
        "$n�������ǣ�һ�С��ͻ���ɽ������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
        "$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
        "$nһ�С�����Ʊա���˫�Ʋ���Բת������$N����������ת��һȦ��\n",
        "$n����Ϊָ��һ�С����ŭХ������$N������ҪѨ��\n",
        "$n��ָ΢����һ�С��޿ײ��롹��һ����ɭɭ��ָ��ֱ��$N�����š�\n",

        
							})
	);

					   
 	action = ({
        ([      "action":               
"$N����ָ�ױ�ͻ�������Ƴ���һ�С����������󡹣�ץ��$n$l",
                "dodge":                250,
                "parry":                350,
                "force":                470,
                "damage_type":  "ץ��"
        ]),

        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����ɨҶ������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),

         ([ "action":
"$N����������������ʹ��һ�С��ֻ����á���˫��������$n��$l��£",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"����"
                ]),
 		
         ([      "action":               
"$N���Զ٣�����һ��ʹ������ͤ��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),

        ([      "action":               
"$N�ز�б�����ֳ�צ����һ��Բ����һʽ�����ӷ�������$n$l",
                "dodge":                310,
                "parry":                200,
                "force":                290,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N��ָ��ǰһ�࣬һ��������ָ���佫��ȥ������$n$l ",
                "dodge":                380,
                "parry":                360,
                "force":                390,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":          	
"$Nһ�С����ļ��ԡ���������ָ��ָ���ƿգ���$n��$l��ȥ",
                "dodge":                30,
                "parry":                180,
                "force":                140,
                "damage_type":  "����",
                "weapon":               "һ��ָ��",
        ]),
        ([      "action":               
"$Nб��һת�����Ƴ�צ���$n���ţ���������б��$n��$l�� ",
                "dodge":                170,
                "parry":                170,
                "damage":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������צ������$n��ȫ����������������һ���ķ��۽���������ɱ�֣� ",
                "dodge":                70,
                "parry":                70,
                "damage":                140,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N����������һ�С������컢��˫�Ʋ����Ƴ�",
                "dodge":                170,
                "parry":                240,
                "force":                150,
                "damage_type":  "����"
        ]),

	});
}

mixed hit_ob(object me, object victim, int damage_bonus) {
	if(random(damage_bonus) < 350) {
		return 0;
	}
	if(!victim->query_temp("weapon") 
			&& victim->query_skill_mapped("unarmed") == "ill-quan"
			&& me->query_skill("unarmed") > victim->query_skill("unarmed")) {
		switch(random(3)) {
			case 0:
				message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
				break;
			case 1:
				message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
				break;
			case 2:
				message_vision(HIR "\n��ȭ����ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
				break;
		}
		return random(me->query_skill("unarmed")) * 10;
	}
	return 0;
}

