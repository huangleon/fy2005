// mimicat@fy4

#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","��ʮ������");
	set("type","sword");
	set("skill_class","swordsman");
	set("effective_level",200);
	set("difficulty",400);
	set("usage/sword",1);
	set("usage/dodge",1);
	set("usage/parry",1);
	set("parry_msg",  ({
	        "$n�˽���ɣ���ʱ�ͽ�$N��$w���������⡣\n",
	        "$n������ע���⣬$Nֻ������һ��$w�����ɳ���\n",
	}) );
	set("unarmed_parry_msg", ({
	        "$n�Ľ��ƺ�����������$Nֻ�����޴����֡�\n",
	        "$n����������������������������ƫ��$N����ʽ�� \n",
	        "$n������ɣ��Ƶ�$N�������ˡ�\n",
	}) );
	set("dodge_msg",({
		"$n����Ʈ����������$N���԰��ա�\n",
		"$n�����ݿ�ȥ����$Nһʱ�޷�׷����\n",
		"$n������������$N������ǰʱȴ��һ��λ����ʹ$N���˸��ա�\n",
		"$n����һ�㣬ȫ���ڿգ���ʱ�㿪��$N־�ڱصõ���һ����\n",
	}) );
	action = ({
        ([      "action":               "$Nʹ����ʮ�������еġ���ʮ��ʽ�����������֣���ʱ��$n���˸����ֲ�����",
                "dodge":                400,
                "parry" :               300,
                "damage":               70,
                "force" :               0,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ʮ�������еġ�����ʽ�����߸�Ծ��$w�������£�����$n��$l��",
                "dodge":                100,
                "parry" :               0,
                "damage":               400,
                "force" :               400,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ʮ�������еġ���ʮһʽ��������$w����һ�����⣬����$n��$l��",
                "dodge":                0,
                "parry" :               300,
                "damage":               150,
                "force" :               350,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ʮ�������еġ�����ʽ��������һ��Ѹ���ޱȵĴ���$n��$l��",
                "dodge":                -100,
                "parry" :               300,
                "damage":               450,
                "force" :               0,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ʮ�������еġ�����ʽ�������е�$w�����ݳ���ָ��$n��$l��",
                "dodge":                0,
                "parry" :               0,
                "damage":               0,
                "force" :               120,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ʮ�������еġ�����ʽ��������Ϊ��������$n��$l��",
                "dodge":                20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ʮ�������еġ�����ʽ������Ȼ����$n���ԣ�$w�������ϣ�����$n��$l��",
                "dodge":                -200,
                "parry" :               300,
                "damage":               80,
                "force" :               60,
                "damage_type":  "����"
        ]),
		([      "action":               "$Nʹ����ʮ�������еġ�����ʽ�������λ�����ת��$n���������$w����$n�ĺ󱳣�",
                "dodge":                400,
                "parry" :               0,
                "damage":               0,
                "force" :               160,
                "damage_type":  "����"
        ]),
		([      "action":               "$Nʹ����ʮ�������еġ��ڶ�ʽ�������ⲻ�ϲ�������ʱ�ͽ�$n��ȫ���Ѩ�������У�",
                "dodge":                0,
                "parry" :               -100,
                "damage":               0,
                "force" :               960,
                "damage_type":  "����"
        ]),
		
		([      "action":               "$Nʹ����ʮ�������еġ���ʮ��ʽ����$nֻ����ǰһ����$w���������ţ�",
                "dodge":                500,
                "parry" :               300,
                "damage":               100,
                "force" :               100,
                "damage_type":  "����"
        ]),
		
		([      "action":               "$Nʹ����ʮ�������еġ��ھ�ʽ��������һ��ֱ��$n��$l��",
                "dodge":                100,
                "parry" :               300,
                "damage":               0,
                "force" :               90,
                "damage_type":  "����"
        ]),

		([      "action":               "$Nʹ����ʮ�������еġ���ʮʽ���������$w�����ѻ�����һ��磬�������$n���˹�����",
                "dodge":                600,
                "parry" :               -50,
                "damage":               0,
                "force" :               1000,
                "damage_type":  "����"
        ]),
		([      "action":               "$Nһ����ƮƮ�̳���ʹ����ʮ�������еġ��ڰ�ʽ�����������ޱ仯�����Ǳ仯��Ȼ������ˣ�\n���þ�������ˮ������Ȼ��$w�д���һ���������������$n$l��",
                "dodge":                300,
                "parry" :               350,
                "damage":               20,
                "force" :               90,
                "damage_type":  "����"
        ]),
});

}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 1000 )
                return notify_fail("�������������û�а취����ʮ��������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 350 ) return 0;
    	
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "sword")
    	if(victim->query_skill_mapped("sword") == "softsword")
    	if(me->query_skill("sword")+100 > victim->query_skill("sword")) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n$N�ϵл��ȣ�����ռ���Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N����һ��������$n���������ڣ�" NOR,me,victim);
                    break;
                    }
    		return random(me->query_skill("sword")) * 3;
    	}
    	return 0;
}
