// annie. ������;.
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","���ɽ���");
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",180);
	set("practice_limit",100);
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
                "force":		120,
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
                "force":		100,
                "damage_type":  "����"
        ]),
	});
}


int valid_learn(object me)
{
	return 0;
}

mixed parry_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chessism",1);
	
	if (me->query_busy())
	{
		message_vision(HIG"$N������ת�����˾�Ȼ���ĵ�������ƪ��������Ŀ��������Ȼ����������\n"NOR, me);	
		if (me->query_busy()==1) me->stop_busy();
			else me->start_busy(me->query_busy()-1);
	}
	
	return 0;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

