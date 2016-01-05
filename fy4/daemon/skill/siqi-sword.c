//TIE@FY3
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","���潣��");
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","huangshan");
	set("effective_level",150);
	set("parry_msg", ({
       	 	"$nʹ������Դ̽�ġ�������$v�������ۣ���$N���е�$w��ƫ�˳�ȥ��\n",
		"$n$vƮ��������һ�С��ɷ���𽡹�������벻���ĽǶȼ�ס��$N���е�$w��\n",
		"$n���е�$v����������һ�С��Űؾ��ɡ�������$N��$w����ָ��\n",
		"$n���е�$v������ɣ�������������Ⱥɽ��һ�С�Ⱥ����䡹����ס��$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n����$vԲת������������һ�С���ɽ���ơ���ǿ���Ľ����Ƶ�$N�������ˡ�\n",
		"$n����$v�ĳ����ݽ�����һ�С�������ʤ��������$Nվ�����ȡ�\n",
		"$n$v��Σ����潣�ƣ��ڿ���������һ�С���ȥ���⡹����ʧ����Ӱ���١�\n",
		"$nת��$vһ�С�������塹������һƬ��â�����Լ�ȫ�����ܲ�͸�硣\n",
	}) );	
	action = ({
		([	
			"action":		
			"$Nʹһ�С�����ӭ�͡������α���������$wһ�ڣ���$n��$l��ȥ",
			"dodge":		50,
			"force":		170,
			"damage_type":	"����"
		]),
		([	
			"action":		
			"$N���ΰεض�������$w�趯�����콣��ɭɭ��һ�С�����Ư�졹����$n��$l",
			"dodge":		-70,
			"force":		200,
			"damage_type":	"����"
		]),
		([	
			"action":		
			"$N����$w��â������һ�С�������Ȫ����˲������$n��$l��������",
			"dodge":		-40,
			"damage":		90,
			"damage_type":	"����"
		]),
		([	
			"action":		
			"$N����$wһȦ����������ɳ����ͻȻ����һ���������������⣬һ�С���ʯ��ɡ���ס$n��$l",
			"dodge":		-40,
			"damage":		40,
			"damage_type":	"����"
		]),
		([	
			"action":		
			"$N$w�������ó����콣Ӱ�����Ŵشأ�һ�С��α���������$n$l��ȥ",
			"dodge":		60,
			"damage":		120,
			"damage_type":	"����"
		]),
		([	
			"action":		
			"$N����Ծ������$w�����佣����һ�С�ϲȵ��÷����ס$n��ȫ��",
			"dodge":		-60,
			"damage":		150,
			"damage_type":	"����"
		]),
	});
}
int valid_learn(object me)
{
    if( (string)me->query("gender") != "Ů��" )
                return notify_fail("���潣����ֻ��Ů�Ӳ��������书��\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����潣����\n");
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 300 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "three-sword" )
    if(me->query_skill("siqi-sword",1) > victim->query_skill("three-sword",1)) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n�򽣷���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("sword")) * 10;
    }
    return 0;
}

