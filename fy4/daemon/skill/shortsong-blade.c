#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","�̸赶��");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("practice_limit",100);
	set("difficulty",200);
	set("eff_parry_level",150);
	set("skill_class","legend");
	set("parry_msg", ({
		"$nʹ��һ�С�Ψ�жſ����������е�$v����$N����ָ��\n",
		"$n���̤ǰһ����һ�С��������ơ������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
		"$n���е�$vһ�������һƬ������һ�С��������ġ�������$N��ȫ��\n",
		"$n΢��һ�������е�$v����һ���⻡��һ�С���Ϊ���ʡ�����$N��ȫ��Χס��\n",
	}) );
	set("unarmed_parry_msg", ({
		"$nʹ��һ�С��������񡹣������е�$v����$N��\n",
		"$n���̤ǰ̤��һ�С�����¹���������е�$v����$N֮�ؾȡ�\n",
		"$n���е�$vһ����һ�С�ɽ����ߡ�������$N��\n",
		"$n���е�$v����һ�С����¹��ġ�����$N��ȫ��Χס��\n",
	}) );	
	action = ({
		([	"action":		"$Nʹһ�С��ԾƵ��衹������$w���Ƶ���$n��$lնȥ��",
			"damage":		150,
			"dodge":		70,
			"damage_type":	"����"
		]),
		([	"action":		"$N�䵶���£�$w����һ�С��������Ρ����¶�������$n��$l",
			"damage":		250,
			"damage_type":	"����"
		]),
		([	"action":		"$N����һת��һ�С�Ʃ�糯¶��$w�糯¶��˸��ն��$n��$l",
			"damage":		90,
			"damage_type":	"����"
		]),
		([	"action":		"$N�趯$w��һ�С�ȥ�տ�ࡹ��$n��$lбб����һ��",
			"damage":		50,
			"damage_type":	"����"
		]),
		([	"action":		"$N����$wһ�Σ�һ�С������Կ���Ѹ�����׵�����$n��$l",
			"damage":		150,
			"damage_type":	"����"
		]),
		([	"action":		"$N�����������զչ��һ�С���˼������ֱ��$n$l",
			"damage":		110,
			"damage_type":	"����"
		]),
		([	"action":		"$N�Ʋ�����ʹһ�С����Խ��ǡ��������ն��$n��$l",
			"damage":		130,
			"damage_type":	"����"
		]),
	});
}


int valid_learn(object me)
{
	if( (string)me->query_skill_mapped("force")!= "qidaoforce" ) {
		return notify_fail("�̸赶�����������ѩ�ڹ���������\n");
	}
	if( me->query_skill("qidaoforce",1) <= me->query_skill("shortsong-blade",1) && me->query_skill("qidaoforce",1) < 150 ) {
		return notify_fail("�̸赶���������൱����ѩ�ڹ���������\n");
	}
	if( !::valid_learn(me) ) {
		return 0;
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	if( random(damage_bonus) < 300 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "sword" ) {
			if( victim->query_skill_mapped("sword") == "deisword" ) {
				if( me->query_skill("blade") > victim->query_skill("sword") ) {
					switch( random(3) ) {
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
					return random(me->query_skill("blade")) * 2;
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
	if (me) {
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
		skill = me ->query_skill("shortsong-blade", 1);
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
�̸赶�������������±�������ͬ�ȼ�������ķ�Ϊ����
�̸赶�������������ϣ�ѧϰϵ�����ӵ���������

���������Ρ���daojianruomeng��
���˺ϻ�֮����������Ҫ30����������������̸赶������	
����æ�����غ�
���⹥�����������˺�������Ӧ�̸���������ȼ�
����߲�����������

���̸賤�Ρ���duangechangmeng��
�����ؼ�����Ҫ����ķ���ϣ�����æ��2�غ�
�����˺������̸赶���ȼ�
�̣���	��������
�̣�������ÿ�������ӱؿ�������һ�Σ����У���������
������������ʹ����ɱ��������������������������

���̸衻��duange��
�����ֳɹ������ˡ��̸賤�Ρ������һ��������غ���ʹ��
���пɹ�����������Ķ���һ����������æ�ҡ�
���⹥�������̸赶���ȼ�����
�����˺������̸赶���ȼ�����
��û��ץסʱ���������ֻ����ͨһ��������æ�����֡�
�裱�������̸赶��

�����Ρ���changmeng��
�����ֳɹ��м��ˡ��̸賤�Ρ������һ��������غ���ʹ��
���пɹ�����������Ķ���һ����������æ�ҡ�
���⹥�������̸赶���ȼ�����
�����˺������̸赶���ȼ�����
��û��ץסʱ���������ֻ����ͨһ��������æ�����֡�
�裱�������̸赶��

HELP
    );
    return 1;
}
