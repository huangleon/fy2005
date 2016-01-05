// fumostaff.c

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","Τ�ӷ�ħ�ȷ�");
	set("skill_class","shaolin");
	set("effective_level",150);
	set("type","staff");
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);

	set("parry_msg", ({
        	"$n������������ֳ��Ȼ���Ȧ��������һ�С���ͷ�ǰ���������$N��$w��\n",
        	"$n���һ��������$v�������ϣ�����һ������$N��$w�ϡ�\n",
        	"$n˫�ֳ�ס$v�����������Ƴ���$Nֻ������$w����ǧ�����ݲ�����ȥ��\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n������������ֳ��Ȼ���Ȧ��������һ�С���ͷ�ǰ�������ȥ��$N�Ĺ��ơ�\n",
        	"$n���һ��������$v�������ϣ�����һ������$N�����ϡ�\n",
        	"$n˫�ֳ�ס$v�����������Ƴ���$Nֻ��ǰ�澢���𵴣��ݲ�����ȥ��\n",
	}) );
	action = ({
        ([      "action":               
"$Nʹһ�С��������������$w�趯��ɣ�ɨ��$n���̣�",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "damage_type":  	"����"
        ]),
        ([      "action":               
"$N����$w��һ�С���Ŀ������������$wֻ�����أ�����$n$l��",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "damage_type":  	"����"
        ]),
        ([      "action":               
"$N�������$w��ʹ�������Ӻ�ա�������$w���ն��£�����$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "damage_type":  	"����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��ຣ�Ⱥ�����$w�󿪴�ϣ�ײ��$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "damage_type":  	"����"
        ]),
	});
}

int valid_learn(object me) {
	
	if (	me->query_skill("fumostaff",1)>=150
		&& me->query_skill("fumostaff",1) >= me->query_skill("staff",1)
		)
		return notify_fail("150�����ϵķ�ħ�ȷ���Ҫ����ͬ�ȼ��Ļ����ȷ�Ϊ������\n");
	return ::valid_learn(me);
}


void skill_improved(object me)
{
        int s;
        s = me->query_skill("fumostaff", 1);
		if (s == 170 && me->query("class") == "shaolin" ) 
        {
        	tell_object(me, WHT"������������Τ�ӷ�ħ�ȷ�����ԡ���ȥ�δӡ�����������ˡ�\n" NOR);
        	me->set("pfm/fumo_improve",1);
        }
}

int effective_level(object me)
{
	int skill,n;
	if (me) {
		skill=me->query_skill("fumostaff",1);
		if (skill<=150 || (me->query("class")!="shaolin" && userp(me))) return 150;
		if (skill>=170) return 200;
		n= (skill-150) /4*10 + 150;
		return n;
	}
	return 200;
}


int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill = me ->query_skill("fumostaff",1);
		if (skill < 150)
			return 200;
		else
			return 700;
	}
	return 200;
}


int help(object me)
{
	write(@HELP   
Τ�ӷ�ħ�ȷ���ϵ����150����ʼ�𲽴�150��ߵ�200��L170��
��ѧϰϵ�����ӵ�700
150�����ϵķ�ħ�ȷ���Ҫ����ͬ�ȼ��Ļ����ȷ�Ϊ����

����ȥ�δӣɡ���hequhecong��
��Ҫ150����Τ�ӷ�ħ�ȷ��ͻ����ȷ�
ʹ����æ�����У����ʧ������æ�����У��ɹ�����æ��һ��

����ȥ�δӣɣɡ���hequhecong��
��Ҫ170����Τ�ӷ�ħ�ȷ��ͻ����ȷ�
ʹ����æ�����У����ʧ������æ�����У��ɹ���������æ��

HELP
    );
    return 1;
}
