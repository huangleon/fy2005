// libie-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","�֦��ʽ");
	set("type","sword");
	set("difficulty",230);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",230);
	set("unarmed_parry_msg",({
		"$n����$vһȦ��һ�С���÷����պ÷�ס$N�Ĺ��ơ�\n",
		"$nһ�С�է��÷�ࡱ���е�$v����$N�ؾ�֮����\n",	
		"$n���е�$vһ�������һƬ������һ�С�÷�ֻ��䡱��$Nȫ��Χס��\n",
					})	
	);
	action = ({
        ([      "action":               
"$N����$wһȦ��Ȼ����Ȼ����$n��$l�����ǡ��֦��ʽ���еġ���÷���",
                "dodge":                40,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ��������$wͻ��һ̽������ȴ��б�Ӷ��ϣ�����һ֦÷��էȻ�����
����$n��$l�����Ǿ�ѧ����÷���桱",
                "dodge":                42,
                "damage":               150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ɿ�ıȳ���ʽ��ȴ���֦�����е�����ɱ�֣�ֻ��$N������٣�һ��֮�£�
˫������һ��һѹ������$w����$n�����ǡ�է��÷�ࡱ����ʽ��",
                "dodge":                30,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"�ƽ�����$N$w͸��������һ�����糤�߳���������$n$l�����ǡ��֦��������
�����ѧ��÷ռ�ȴ���",
                "dodge":                37,
                "damage":		240,
                "damage_type":  "����"
        ]),

               
	});
}

int practice_skill(object me)
{

	return notify_fail("�֦��ʽֻ����ѧ�ġ�\n");
}

 

mixed hit_ob(object me,object victim)
{
	if(me->query_temp("hanmeiluo"))
	return HIR "���⻪��ɢ��ҫĿ�Ľ����Ѵ�����$nҪ����\n"NOR;

}

	      
