// feixian-sword.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","���ɽ���");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("ignore_ic", 1);
	set("skill_class","baiyun");
	set("effective_level",180);
	set("difficulty",200);
	set("bypass_ic", 1);		// BYPASS iron-cloth.
	set("parry_msg", ({
	        "$nʹ��һ�С�������졹�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
	        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
	        "$nʹ��һ�С�������ѩ�������е�$v��������ѩӰ��������$N��$w��\n",
	        "$n���е�$vһ����һ�С����ش��ס�����$N��$w��������ȥ��\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
	        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
	        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
	        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
	}) );	
	action = ({
        ([      "action":               
"$Nʹһ�С����·ת��������$w��һ�����߰����$n��$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����ɽ����еġ���ɽ������������ն��$n��$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                30,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ�����ն�������׼$n��$l�̳�һ��",
                "dodge":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
                "dodge":                40,
                "damage":		120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�һ������������$n��$l",
                "dodge":                20,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С������ܲ�������һ���⻡����$n��$l",
                "dodge":                30,
                "damage":               50,
                "damage":		100,
                "damage_type":  "����"
        ]),
	});
}


int valid_learn(object me)
{
    	if( (string)me->query_skill_mapped("force")!= "chessism") {
            return notify_fail("���ɽ���������ϡ��ĵ���������ϰ��\n");
	}
	if(!::valid_learn(me)) {
		return 0;
	}
    return 1;
}


mixed hit_ob(object me, object victim)
{	
        int level, myexp, yourexp;
        object weapon;
        
		if (me->query("class") != "baiyun")	return ("");
	
		if (me->query_skill_mapped("force") != "chessism")
			return ("");
    	
    	if (!me->query_temp("in_feixian_pfm")) return ("");
    	
    	myexp = me->query("combat_exp");
    	yourexp = victim->query("combat_exp");
    	level = me->query_skill("chessism", 1);
    	
    	if (!victim->is_busy())
    	if (3* random(myexp) > yourexp ) 
        {
			if (random(3))	
				victim->start_busy(1);  
			else 
				victim->start_busy(2);
 	       	return (WHT "$N�Ľ���һ���ĵ�������ƪ���Ȼ����գ����Ʊ���޷���$n����ʱ������æ���ң�\n" NOR);
		}
	return ("");
		
}

mixed parry_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	if (me->query("class") != "baiyun")	return ("");
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chessism",1);
	
	if (me->query_busy()>1)
	if (random(skill) + skill/3 > 100 && me->is_busy()) {
		message_vision(HIG"$N������ת�����˾�Ȼ���ĵ�������ƪ��������Ŀ��������Ȼ����������\n"NOR, me);	
		if (me->query_busy()==1) me->stop_busy();
			else me->start_busy(me->query_busy()-1);
	}
	
	return 0;
}

int bypass_ironcloth(){
	return 1;
}
