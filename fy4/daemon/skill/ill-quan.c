// ill-quan.c
#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","��άĦȭ");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("effective_level",200);
	set("practice_limit",100);
	set("skill_class","tieflag");
	set("parry_msg", ({
        	"$n���һָ������һ��$N��$w��$w��תͷȥ����$N���ɹ�ȥ��\n",
		"$nһ��$N��$w���������Ѿ���$N��ͷ����Խ������������������$N���\n",
		"$n����һ����������ճ��$N��$w��һ����\n",
        	"$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
        	"$N��ǰһ�������е�$w����������鴦����ϸһ����$nվ��ԭ��û�ж�����\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
        	"$nһ�С�Χκ���ԡ������˷���������$N���Ƶ�$N�����Ա���\n",
		"$n˫ȭ���䣬��סȫ��Ҫ����\n",
        	"$N��ǰһ�������е���ʽ����������鴦����ϸһ����$nվ��ԭ��û�ж�����\n",
	}) );
	action = ({
        ([      "action":               
"$Nһʽ���½�����������£�ʤ�����£�˫ȭ����$n��$l",
                "dodge":                230,
                "parry":                150,
                "force":                700,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һת����ȭ���¶�������$n��$l",
                "dodge":                140,
                "parry":                100,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ�٣����˴�ȭ����$n��ǰ����Ѹ�ײ����ڶ�֮�ƻ���$n��$l",
                "dodge":                130,
                "parry":                120,
                "force":                190,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��һת������$n��������$n��$l�ͻ�",
                "dodge":                150,
                "parry":                200,
                "force":                290,
                "damage_type":  "����"
        ]),
	});
}

 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( random(damage_bonus) < 350 ) {
    	return 0;
    }
    if(!victim->query_temp("weapon"))
    if(victim->query_skill_mapped("unarmed") == "changquan")
    if(me->query_skill("unarmed") > victim->query_skill("unarmed")) {
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
    	return random(me->query_skill("unarmed")) * 5;
    }
    return 0;
}

