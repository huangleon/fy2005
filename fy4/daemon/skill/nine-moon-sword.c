// nine-moon-sword.c
#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","������������");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","shenshui");
	set("effective_level",100);
	set("difficulty",200);
	set("practice_limit",100);
	set("parry_msg", ({
		"$nʹ�������������С������𡹣���$N���е�$w��ƫ�˳�ȥ��\n",
		"$n̤��λ�������ţ����е�$v����һ�ã���ס��$N���е�$w��\n",
		"$n��$N����һ�������е�$v˳��$N��$w���£�����$N��$w����ָ��\n",
		"$n���е�$vһ����һ�С��Ŷ��������$v�ó�������Ӱ����ס��$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n��͸���⣬һ�С�����̹ǡ���ǿ���Ľ���ֱȡ$N���ʺ�\n",
		"$n����һ����$v��һ��������ֱ��$N������\n",
		"$n�ҽź�̤һ����$v�����֣�������$N�鰴��һ�ɾ���ʹ$Ņ�����֡�\n",
		"$nת��$vͻȻ��Ҹ�´̳���һ�С�ɳ�س�Ы��������$N������$N��æ�����Ա���\n",
	}) ); 	
	action = ({
		([	"name":			"���겻ɢ",
			"action":		"$Nʹһ�С����겻ɢ��������$w���Ⱪ������$n��$l��ȥ",
			"dodge":		50,
 	  	         "parry":                240,
			"force":		170,
			"damage_type":	"����"
		]),
		([	"name":			"����ɭɭ",
			"action":		"$N������ת��һ�С�����ɭɭ������$n��$l",
			"dodge":		70,
			 "parry":                180,
			"force":		200,
			"damage_type":	"����"
		]),
		([	"name":			"���Ƶ���",
			"action":		"$N�趯$w��һ�С����Ƶ���Ю�������������$n��$l",
			"dodge":		40,
			 "parry":                150,
			"damage":		90,
			"damage_type":	"����"
		]),
		([	"name":			"���ܵظ�",
			"action":		"$N����$w����һ�������������ܵظ�����$n��$l�̳�����",
			"dodge":		40,
			 "parry":                160,
			"damage":		40,
			"damage_type":	"����"
		]),
		([	"name":			"��������",
			"action":		"$N����$w���Ⱪ����һ�С��������ǡ���$n$l��ȥ",
			"dodge":		60,
			 "parry":                150,
			"damage":		120,
			"damage_type":	"����"
		]),
		([	"name":			"��������",
			"action":		"$N����$w����һ���⻡��ֱָ$n$l��һ�С��������¡���������������ȥ",
			"dodge":		60,
			 "parry":                140,
			"damage":		150,
			"damage_type":	"����"
		]),
	});
}

int valid_learn(object me)
{

	if( (string)me->query_skill_mapped("force") != "nine-moon-force" ) {
        	return notify_fail("������������������Ͼ����ľ���������\n");
	}
/*	if (me->query_skill("nine-moon-sword",1) >= me->query_skill("nine-moon-force",1)){
			return notify_fail("��ľ����ľ���򲻹���\n");
	}		*/
	return ::valid_learn(me);
}


mixed parry_ob(object victim,object me)
{
	int mylvl, extra, damage;
	string msg;
	
	if( extra = me->query_temp("nine-moon-force_poison") ) {
		extra = extra/2;
		damage = COMBAT_D->magic_modifier( me, victim, "kee", extra);
		victim->receive_damage("kee", damage, me);
		victim->receive_wound("kee", damage, me);
		if( !victim->query_temp("weapon") ) {	
			return MAG"$Nֻ�����ִ�����һ������������׶�Ķ�����\n"NOR;
		} else {
			return MAG"$Nֻ��һ�㵭���������ӱ��������Ӷ������̹ǵĺ�������������ת�����顣\n"NOR;
		}
	}
}

int effective_level(object me)
{
	int skill,n;	
	if( me ) {
		skill = me->query_skill("qingpingsword", 1);
		if( skill < 109 ) {
			return 100;
		} if( skill > 200 )	{
			return 175;
		}
		if( skill <= 150 )	{
			return (skill/10*10);
		}
		return (150 + (skill-150)/10*5);
	}
	return 150;
}


int help(object me)
{
	write(@HELP   
��˪���ϼ��(shuanglengcanxia)
���⹥����=��������
�����˺���=��Ч����
�����ľ�180������ʱ�����ж�����һ��������ɶ�������
�˺�����������ٴ죬Ϊ����ץ����­�ڶ�������ʱ����

����ӳ�⺮��(biyingguanghan)
��170���ľ�������������30�룬ÿ2����ʹ��һ�Σ�ս���У�
ÿһ������Ϊ�������˺���*150%��
����ֿ���Ѫ�˺���������30%
����ֿ������˺���������30%

����ɺ�̶����yanduhantan��
��Ҫ150���ľ���������100����ƽ����
�����������æ�����֣�����æ��һ�֡�

����Ⱦ���ơ���yirancangyun��
��200���ľ���������200����ƽ��������ס���ֺ������е�һ��
���⹥����=����������+����ȼ���*2
�����˺���=����Ч����+����ȼ���*2
����æ��2�֣�ÿ3����ʹ��һ��
����������=250������æ�ҽ�Ϊ1��
����������=300����æ��

��ƽ�����ɴӰ����մ�ѧ�ã�����Ϊ115���Ů��
L100-L150���𲽣�ÿʮ����������������ϵ����100��ߵ�150
L150-L200���𲽣�ÿʮ����������������ϵ����150��ߵ�175
HELP
    );
    return 1;
}
