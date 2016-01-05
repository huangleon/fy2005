#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","��צ");
	set("type","unarmed");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("usage/theorem",1);
	set("practice_limit",1);
	set("effective_level",170);
	set("difficulty",100);
	set("skill_class","npc");

	set("parry_msg", ({
        "$n˫צһ�棬��ס��$N�Ĺ�����\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n˫צһ�棬��ס��$N�Ĺ�����\n",
	}) );	

	action = ({
        ([      "action":               
"$N����΢����������ǰ�˳�����צֱ������"HIR"�ɺ�ժ��"NOR"����ץ��$n��˫�ۡ� ",
                "dodge":                10,
                "parry":                10,
                "damage":                70,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N������Σ��硸"HIG"�����֦"NOR"������ֱ��������$n�ļ羮��Ѩ�� ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nһ��ǰ�죬һ�ۺ�ָ��һ�С�"WHT"Գ������"NOR"��������$n������ ",
                "dodge":                50,
                "parry":                50,
                "damage":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N��Ȼ����һ�ţ�ʹһʽ��"MAG"�˷���Ӱ"NOR"����˫צ�����޶���һצץ��$n���ؿڡ� ",
                "dodge":                70,
                "parry":                70,
                "damage":                140,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N����һ������һ������ʹ����"CYN"ˮ������"NOR"����˫צ������$n��С���� ",
                "dodge":                30,
                "parry":                25,
                "damage":                77,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N�͵����ϸ߸�Ծ��һ�С�"HIC"���ժ"HIY"��"NOR"�����Ӹ����£�һצ����$n��ͷ�ǡ� ",
                "dodge":                50,
                "parry":                90,
                "damage":                30,
                "damage_type":  "ץ��"
        ]),
	});
}


void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("monkey-claw", 1);
	    	if (s == 50 || s == 100 || s == 150 || s == 200) 
	    		tell_object(me,WHT"����������צ����춸�������֮�ʵ�������С�ˡ�\n"NOR);
    	return;
}


int valid_learn(object me)
{

	if (me->query_skill("monkey-claw",1) >= me->query_skill("theorem",1)*2)
		return notify_fail("�������֮����򲻹���\n");

	return ::valid_learn(me);
}


int help(object me)
{
	write(@HELP   
������/2�ȼ�������֮����ѧ�ɺ�ɽ���ս���б任����������ķ�
�����½�����˾��ժ�Ǵ�ѧ�á��˼���Ϊ�������ܣ�����Enable����
�Զ���Ч��
ע��ս���б任������2�غ��������мܣ�parry������������ʱ�½�
L0�� �м���Ϊԭ����20%
L50���м���Ϊԭ����30%
L100���м���Ϊԭ����50%
L150���м���Ϊԭ����70%
L200���м���Ϊԭ����90%
HELP
);
    return 1;
}
