#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","����������");
	set("type","sword");
	set("effective_level",150);
	set("eff_parry_level",150);
	set("usage/sword",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","legend");
	
	set("parry_msg", ({
		"$nʹ��һ�С�������������е�$v������$N��$w��\n",
		"$nʹ������������ʡ�����$N��$w�������⡣\n",
		"$nʹ��һ�С�ǿ�ֻ���ζ�������е�$v����������գ�������$N��$w��\n",
		"$n���е�$vһ����һ�С��ԾƵ��衹����$N��$w��������ȥ��\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n�����е�$v����ܲ�͸�磬һ�С����ǿ��Ϊ����ס��$N�Ĺ��ơ�\n",
		"$n����һ�С����������ޡ�����������ʧ��һ�Ž���֮�С�\n",
		"$nʹ��һ�С��м���ɫ�ԡ���$vֱ��$N��˫�֡�\n",
		"$n�����е�$vһ����һ�С��Ѿ��ִ��������ȵ�$N�������ˡ�\n",
	}) );
	action = ({
		([	"action":		"$Nʹһ�С�����Σ¥��ϸϸ��������$w�����һ�����$n��$l",
			"dodge":		20,
			"damage" :		200,
			"damage_type":	"����"
		]),
		([	"action":		"$Nʹ�����������еġ���ɫ�̹���������������հ�����$n��$l",
			"dodge":		20,
			"damage":		200,
			"damage_type":	"����"
		]),
		([	"action":		"$Nһ�С�����˭��ƾ���⡹������$wĬĬ������$n��$l",
			"dodge":		30,
			"damage":		50,
			"damage_type":	"����"
		]),
		([	"action":		"$N����$wһʽ��������ͼһ����׼$n��$lһ���̳��߽�",
			"damage":		90,
			"damage_type":	"����"
		]),
		([	"action":		"$N��$wƾ��һָ��һ�С��´������ղ��ڡ�����$n��$l",
			"dodge":		20,
			"damage":		300,
			"damage_type":	"����"
		]),
		([	"action":		"$N����$w����һ�֣�ʹһ�С�Ϊ���������㲡����ֶ�׼$n$lһ����ȥ",
			"dodge":		20,
			"damage":		100,
			"damage_type":	"����"
		]),
	});
}


int valid_learn(object me)
{
	if( (string)me->query_skill_mapped("force")!= "qidaoforce")
        return notify_fail("�������������������ѩ�ڹ���������\n");
	if (me->query_skill("qidaoforce",1)<= me->query_skill("diesword",1)
		&& me->query_skill("qidaoforce",1)<150)
		return notify_fail("�����������������൱����ѩ�ڹ���������\n");
			
	if(!::valid_learn(me))
    		return 0;
    
    return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	if( random(damage_bonus) < 300 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "blade" ) {
			if( victim->query_skill_mapped("blade") == "shortsong-blade" ) {
				if( me->query_skill("sword") > victim->query_skill("blade") ) {
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
					return random(me->query_skill("sword")) * 2;
				}
			}
		}
	}
	return 0;
}


int damage_level(object me)
{
	int skill, n;
	if( me ) {
		if( !me->query_temp("pfm/legend_berserk") && userp(me) ) {
			return 0;
		}
		skill = me->query_skill("six-sense",1);
		if( skill <= 100 ) {
			return 0;
		}
		if( skill >= 300 ) {
			return 200;
		}
		n = skill-100;
		return n;
	}
	return 200;
}


int accuracy_level(object me)
{
	int skill,n;
	if( me ) {
		n = me->query_temp("pfm/legend_jushen")*200;
		return n;
	}
	return 0;
}

int effective_level(object me)
{
	int skill,n;
	if( me ) {
		n = 150 + me->query_temp("pfm/legend_berserk");
		return n;
	}
	return 150;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("diesword", 1);
		if( skill < 200 ) {
			return 200;
		} else {
			return 400;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP
���������������������±�������ͬ�ȼ�������ķ�Ϊ����
���������������������ϣ�ѧϰϵ�����ӵ���������

���������Ρ���daojianruomeng��
���˺ϻ�֮����������Ҫ30����������������̸赶������
����æ�����غ�
���⹥�����������˺�������Ӧ�̸���������ȼ�
����߲�����������

���ʵ����衻��caidiekuangwu��
�����ؼ�����Ҫ����ķ���ϣ�����æ��2�غ�
�����˺����������������ȼ�
�̣���	��������
�̣�������ÿ�������ӱؿ�������һ�Σ����У���������
������������ʹ����ɱ��������������������������

���ʵ�����caidie��
�����ֳɹ������ˡ��ʵ����衻�����һ��������غ���ʹ��
���пɹ�����������Ķ���һ����������æ�ҡ�
���⹥�����������������ȼ�����
�����˺����������������ȼ�����
��û��ץסʱ���������ֻ����ͨһ��������æ�����֡�
�裱����������������

�����衻��kuangwu��
�����ֳɹ��м��ˡ��ʵ����衻�����һ��������غ���ʹ��
���пɹ�����������Ķ���һ����������æ�ҡ�
���⹥�����������������ȼ�����
�����˺����������������ȼ�����
��û��ץסʱ���������ֻ����ͨһ��������æ�����֡�
�裱����������������
HELP
    );
    return 1;
}
