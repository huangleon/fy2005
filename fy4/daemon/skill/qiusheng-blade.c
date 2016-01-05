//TIE@FY3
// qiusheng-blade.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","��������");
	set("practice_limit",100);
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("skill_class","huangshan");
	set("parry_msg", ({
        "$nʹ��һ�С���ҡɽ�������������е�$vɢ��˿˿��������$N��$w��\n",
		"$n����$v���������һ�С����������б��������Ӱ��ͻȻ����һ�ƹ�â�Ӳ��滮��$N֮�ؾȡ�\n",
		"$n����΢�٣����е�$v����һ�����⣬һ�С����������һ�С�������$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
		"$nʹ��һ�С�˪���Ҷ����������е�$v����������$N�Ĺ����沨��ɢ��\n",
		"$n���μ��ˣ�����$v���·��裬һ�С������������󡹣���ס$N����ʽ��\n",
		"$n���е�$v�����䵶����һ�С�������Ӱ���������������ࡣ\n",
	}) );	
	action = ({
		([	"action":		"$Nʹһ�С�һҶ��Ƽ��󺣡�������$wһ�ڣ����μ�����ɣ����˺�һ������$n��$l��",
			"damage_type":	"����"
		]),
		([	"action":		"$N$w�����������⣬һ�С������δ�����꡹����������$n��$l��",
			"damage_type":	"����"
		]),
		([	"action":		"$N����$w����������ˮ��һ�С�˥��б�������֡���бб����$n��$l",
			"damage_type":	"����"
		]),
		([	"action":		"$N����$w���⼤����һ�С�����Ӱ�հ����̡���ն��$n��",
			"damage_type":	"����"
		]),
		([	"action":		"$N����$w���裬�������Ŵشأ�һ�С����ܻ���֪��ɫ����ƮƮ������$n��ȥ",
			"damage_type":	"����"
		]),
		([	"action":		"$N����$w����ɭȻ��һ�С���Ƽ��Զ��������ֱ��$n$l",
			"damage_type":	"����"
		]),
		([	"action":		"$Nʹһ�С��ͷ������仨�졹������$w�ڶ����������ն��$n��$l",
			"damage_type":	"����"
		]),
	});
}
int valid_learn(object me)
{
	if( (string)me->query("gender") != "����" ){
	    return notify_fail("����������ֻ�����Բ��������书��\n");
	}
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
    if(victim->query_skill_mapped("sword") == "siqi-sword" )
    if(me->query_skill("blade") > victim->query_skill("sword")) {
		switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n�򵶽���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
        }
    return random(me->query_skill("blade")) * 10;
    }
    return 0;
}

