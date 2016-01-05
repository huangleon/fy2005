// fengmo-staff.c by Silencer@fy4 workgroup

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","��ħ�ȷ�");
	set("type","staff");
	set("effective_level",200);
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",250);
	set("damage_level",200);
	set("practice_limit",100);
	set("skill_class","lama");
	set("parry_msg",		({
			"$nһ���֣���ӭͷһ���������������ǹ�����������ת��Ϊ����\n",
			"$n����б�������Ⱥ����һ�С���β���ơ��ֿ��ֳ�����ס$N��$w��\n",
			"$n���ұ�һ������������ӰٿȻ�϶�Ϊһ�������������麣��,��ס$N��$w��\n",
			"$n�趯���������������������Ӱ�ݺᣬ�û���һƬƬ��Ļ����ס��$N�Ĺ��ơ�\n",
			"$nһ���ȣ���ͷָ�죬��β��أ����ǡ���ħ�ȷ����еġ�����������,����$N��\n",
			})
	);

	set("unarmed_parry_msg",	({
			"$nһ���֣���ӭͷһ���������������ǹ�����������ת��Ϊ����\n",
			"$n����б�������Ⱥ����һ�С���β���ơ��ֿ��ֳ�����ס$N��������\n",
			"$n���ұ�һ������������ӰٿȻ�϶�Ϊһ�������������麣��,����$N���ھ���\n",
			"$n�趯���������������������Ӱ�ݺᣬ�û���һƬƬ��Ļ����ס��$n�Ĺ��ơ�\n",
			"$nһ���ȣ���ͷָ�죬��β��أ����ǡ���ħ�ȷ����еġ�����������,����$N��\n",
			})
	);
	
	action = ({
			([      "action":               
		"$N�ߺ�������Խ��Խ�ݣ����Ƿ��˿��Ұ��һ�㣬$w��ɨ�ͻ��������Ҵ�",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$Nһ��$w������������һ���������ȣ���Ӱ��ɽ������$n",
			        "damage":               40,
			        "dodge":                20,
			        "parry":                60,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":           
		"$Nʹ����������ɽ�����ݼ��ͼ������緢����ħ����$w�����Ҵ�",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$N˫�����ȣ�һ�С������ȡ������ͻ�",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$Nһ�����ʩ��һ�в����̴�֮�ƣ�§ͷ�Ƕ��ģ�ֱ����$nͷ�����ͻ�������",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$N���е�$wһ�С�������ʯ�����ӱ����Լ�Ϊ֧���������",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$N���������л���ʹһ�С������ߡ�������$w������������֮��",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			
			
	});
}

mapping query_action(object me, object weapon) {
	mapping act=([]);
	string msg;
	if(sizeof(action) > 0) {
		if (me->query_temp("pfm/fengmo_1")) {
			msg = HIB + action[random(sizeof(action))]["action"] + NOR;
			act["action"] = replace_string(msg,"$w","$w"+HIB);
			act["post_action"] = "bash_weapon";
			act["damage_type"] = "����";
			return act; 
		}
		else if (me->query_temp("pfm/fengmo_2")) {
			msg = HIY + action[random(sizeof(action))]["action"] + NOR;
			act["action"] = replace_string(msg,"$w","$w"+HIY);
			act["post_action"] = "bash_weapon";
			act["damage_type"] = "����";
			return act; 
		}else if (me->query_temp("pfm/fengmo_3")){
			msg = HIR + action[random(sizeof(action))]["action"] + NOR;
			act["action"] = replace_string(msg,"$w","$w"+HIR);
			act["post_action"] = "bash_weapon";
			act["damage_type"] = "����";
			return act; 
		}
			
		return action[random(sizeof(action))];
	}
}

int accuracy_level(object me){
	if (me){
		if (me->query_temp("pfm/fengmo_1")) {
			return 200; 
		} else if (me->query_temp("pfm/fengmo_2")|| me->query_temp("pfm/fengmo_3")) {
			return 200; 
		}
	}
	return 0;	
}

int damage_level(object me){
	
	if (me){
		if (me->query_temp("pfm/fengmo_1")) {
			return 300; 
		} else if (me->query_temp("pfm/fengmo_2")|| me->query_temp("pfm/fengmo_3")) {
			return 400; 
		}
	}
	return 200;	
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    
    	int damage;
		
		if (!me->query_temp("pfm/fengmo_1") && !me->query_temp("pfm/fengmo_2")
			&& !me->query_temp("pfm/fengmo_3"))
			return 0;
			    	
    	if (!userp(victim))
    		victim->add_hate(me,me->query_skill("lamaism",1)*2);
    		
        return 0;
}

int help(object me)
{
	write(@HELP   
��ħ�ȷ��������书�ؼ���ͬ��ʹ���ڼ���Ȼ����ͨ��ʽ�������֣�
��������æ�ң����ȷ��˺������еȼ�����Ϊ��ߡ�
��ħ�ȷ��������ؼ��ڼ�����ʱ�����������ޣ����ڷ𷨣�����

L40����������fuhu��
ÿ������ʹ��һ�Σ������ʣ����������˺��ʣ������������������غϡ�

L120����������xianglong��
ÿ������ʹ��һ�Σ������ʣ����������˺��ʣ������������������غϣ�
ÿ�غϹ������С�

L180����ħ����fengmo��
��������ʹ��һ�Σ����������غϣ�ÿ�غϹ������С������ʣ���������
�˺��ʣ������������ؼ�ֻ��������Ӧ�ľ�������ʹ�á�

�����ؼ�����ͨ����Ӧ��������߼����ٴ�ʹ��ʱ�䡣

HELP
    );
    return 1;
}
