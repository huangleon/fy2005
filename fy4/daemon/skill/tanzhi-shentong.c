// tanzhi-shentong.c

inherit SKILL;
#include <ansi.h>
mapping* throwing_action;
void setup(){

	set("name","��ָ��ͨ");
	set("type","throwing");
	set("difficulty",200);
	set("usage/throwing",1);
	set("usage/parry",1);
	set("effective_level",180);
	set("practice_limit",100);
	set("skill_class","huashan");
	
	set("parry_msg", ({
	        "$n����ָ������һ��ָ�����$N����Ѩ��$N��æ�������С�\n",
		"$n�����ᵯ��ɭɭָ�����$N˫Ŀ��$N�����������۾���\n",
		"$nǳЦ���У�����ʳָ�ᵯ��һ�ư�������$N����Ѩ��$N���������������ˡ�\n", 
	}) );
	set("unarmed_parry_msg", ({
		"$n����ָ������һ��ָ�����$N����Ѩ��$N��æ�������С�\n",
		"$n�����ᵯ��ɭɭָ�����$N˫Ŀ��$N�����������۾���\n",
		"$nǳЦ���У�����ʳָ�ᵯ��һ�ư�������$N����Ѩ��$N���������������ˡ�\n", 
	}) );	
	action = ({
                ([      "action":               
"$Nʳָ΢�������ᵯ����$w���������$n��$l",
                "dodge":                30,
                "parry":                30,
                "force":                280,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N��ָ������ָ���絶��$w�ھ����з���$n��$l",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N����бչ��Сָ΢�̽�$w����б��$n��$l����̬����ɷ���",
                "dodge":                30,
                "parry":                30,
                "force":                340,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N����ָ���͡��ص�����$w�����������$n��$l",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N����������������ָ����������Ĵָ��������$w����$n��$l ",
                "dodge":                100,
                "parry":                100,
                "force":                290,
                "damage_type":  "����",
                "weapon":               "����",
        ]),	
	});
}

/*
int valid_enable(string usage) 
{ 
	object me;
		
	me = this_player();
	if(!me->query("marks/hs_tz_parry")){
		return usage=="throwing";	
	}
	else
		return usage=="throwing"||usage=="parry"; 
}*/

int accuracy_level(object me){
	if (me && me->query_skill("qingfeng-sword",1)>=100) 
		return (me->query_skill("qingfeng-sword",1)-100);
	return 0;
}

int damage_level(object me){
	if (me && me->query_skill("zhaixin-claw",1)>=100)
		return (me->query_skill("zhaixin-claw",1)-100);
	return 0;
}

int help(object me)
{
	write(@HELP   
L80	����ָ���꡻��tanzhijinghun��
��ͼæ�ҵ������֣����ɹ�����æ��һ�֣���ʧ������æ�����֡�
���ؼ��ɹ��ʽϸߣ�����9���ڣ�����ʹ��Ч�ܽ��͡�

L80	�����컨�꡻��mantianhuayu��
�������а��������Է���ÿ40������һö���������5ö��
δ���жԷ��İ�������ת���������ܵ������˺�ʱ�Զ�������
L120ǰ����æ��2�֣�L120������æ��3�֡�������Ҫ10ö������

L160������ǧ�᡻��xinyouqianjie��
����200���÷�Ʈ���裬������Ҫ12ö����������æ��2�֣�
����ɱ�ˡ������ʶ��ϸߣ��Ҳ��ܶԷ�������Ӱ�죬
��ÿʹһʽ������ͬʱ���Լ����һ������Ѫ���ˡ�

HELP
    );
    return 1;
}
