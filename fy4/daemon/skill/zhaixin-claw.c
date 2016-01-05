//	ժ���ֵ���Ч
//  ��ɽ���书���˺�����ߣ�������ÿ��������ߣ�������
// 	��ɽ���书: qingfeng-sword, tanzhishentong, zhaixin-claw


#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","ժ����");
	set("usage/unarmed",1);
	set("effective_level",190);
	set("damage_level",200);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","huashan");
	set("unarmed_parry_msg", ({
       	"$nָ�ⷢ��˿˿����ץ��$N����$N��æ����ܿ���\n",
		"$n����һ��������������$Nֻ������һ�գ���ʽ��ƫ�� \n",
	}) );
	action = ({
        ([      "action":               
"$N����ֱץ������б�ӣ�һ�С�ժ�����¡�ץ��$n$l",
                "dodge":                100,
                "parry":                140,
                "force":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nһ�С�������÷�������ֺ��أ����ֳ�צ��ֱ��$n$l",
                "dodge":                150,
                "parry":                100,
                "force":                170,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ�������������������������䣬צӰɭɭ����$n$l",
                "dodge":                50,
                "parry":                120,
                "force":                140,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N�ز�б�����ֳ�צ����һ��Բ����һʽ�����ӷ�������$n$l",
                "dodge":                310,
                "parry":                200,
                "force":                290,
                "damage_type":  "ץ��"
        ]),
	});
}


int accuracy_level(object me){
	if (me && me->query_skill("qingfeng-sword",1)>=100) 
		return (me->query_skill("qingfeng-sword",1)-100);
	return 0;
}

int damage_level(object me){
	if (me && me->query_skill("zhaixin-claw",1)>=100)
		return (100+ me->query_skill("zhaixin-claw",1));
	return 200;
}

int help(object me)
{
	write(@HELP   
ժ����100�����ϣ�ÿ10����߻�ɽ�书��ժ���֡���罣����ָ��ͨ��
�˺��ȼ�+10��

L100	��ժ�ġ���zhaixin��
�Ե��˵�������ɼ����˺���ÿ30����ʹ��һ�Ρ�
�˺���=500 + ����ȼ� * ժ���ֵȼ�/5
HELP
    );
    return 1;
}