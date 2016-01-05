// silencer@fy4.com
//�򹷰������а˾���

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","�򹷰���");
	set("type","staff");
	set("usage/staff",1);
	set("usage/parry",1);
	set("skill_class","beggar");
	set("effective_level",210);
	set("practice_limit",100);
	set("difficulty",250);
	set("parry_msg", ({
			"$nʹ���������־�����$n����һ�������͵�ϸ�٣�ճ��$N��$w�ϡ�\n",
			"$n���ܲ�����һ�С�˫�����须������$vֱȡ$N��˫Ŀ��\n",
			"$n$v����������$w������˳������ǣ����\n",
			"$n$v���أ�ʹ�����־�������ס$w����˦����\n",
	})
	);
	set("unarmed_parry_msg", ({
			"$n���$v��һ�С��������졻����ס��$N�Ĺ��ơ�\n",
			"$n���ܲ�����һ�С�˫�����须������$vֱȡ$N��˫Ŀ��\n",
			"$n�ӳ�$v����ص���$N�����š�\n",
	})	
	);	
	action = ({
([      "action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
        "dodge": 10,
        "parry": 70,
        "damage": 90,
        "damage_type": "����"
]),
([      "action": "$N����$w���һζ���ٿȻ�й�ֱ��������$nǰ�ء��Ϲ�Ѩ��",
        "dodge": 20,
        "parry": 100,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$Nһ����Х��Ʈ�����������$w���𣬻��������Ӱ����$n����ɨȥ",
        "dodge": 20,
        "parry": 50,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$Nʹ���򹷰����С�մ����������Ĩ�����衱��㷨��������Ҳ�����в���$n��Ҫ��",
        "dodge": 20,
        "parry": 270,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$N����$w��һ�С�����ͷ������$nͷ����ȥ�����ֺ���������Ѹ��",
        "dodge": 20,
        "parry": 110,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$Nʹ�����������졻��$w����������$n��ȥ",
        "dodge": 120,
        "parry": 70,
        "damage": 180,
        "damage_type": "����"
]),
([      "action": "$Nʹ�������Ŵ򹷡�������$w������һ�ű�Ӱ���͵�$n���ĸ���ҪѨ",
        "dodge": 120,
        "parry": 300,
        "damage": 150,
        "damage_type": "����"
]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob, weapon;
	int myexp, urexp, skill, chance1, chance2, chance;
	    
	if( me->query("class") != "beggar" ) {
		return 0;
	}
	weapon = me->query_temp("weapon");
	skill = me->query_skill("dagou-stick",1);
	if( !victim->is_busy() && !me->query_temp("marks/pfm_dagou") ) {
		if( skill >= 180 && me->query_skill_mapped("force") == "huntunforce" ) {
			chance1 = F_ABILITY->check_ability(me, "3_pizi_add", 3)/2;
			chance2 = 20;
			if( random(100) < chance1 || ( COMBAT_D->do_busy_attack( me, victim, "dagou-stick/chanzijue", "unarmed", 100, 10) && random(100) < chance2 ) ) {
				message_vision(HIW "\n$Nʹ�����־�������"+weapon->name()+HIW"����һ�������͵�ϸ�٣���ס��$n��\n"NOR, me, victim);
				victim->force_busy(1);
			}
		}
	}

	if( skill >=180 && me->query_skill("begging",1) >= 200 && me->query_skill_mapped("force") == "huntunforce" ) {
		chance = 6 + (F_ABILITY->check_ability(me,"pizi_add")+F_ABILITY->check_ability(me, "3_pizi_add", 3))/2;
	//	tell_object(me,"chance is " + chance + "\n");
		if( chance >16 ) {
			chance = 16;
		}	        
		if( random(100) < chance ) {
			message_vision(HIR"\n$N�������־�������"+weapon->name()+HIR"�������磬�����쳣��\n"NOR, me, victim);
			return damage_bonus;
		}
	}
	 
	if( random(damage_bonus) < 250 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "whip" ) {
			if( victim->query_skill_mapped("whip") == "thunderwhip" ) {
				if( me->query_skill("staff") > victim->query_skill("whip") ) {
					switch( random(3) ) {
						case 0:
							message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
							break;
						case 1:
							message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
							break;
						case 2:
							message_vision(HIR "\n����޷���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
							break;
					}
					return random(me->query_skill("staff")) * 2;
				}
			}
		}
	}
	return 0;
}


mixed parry_ob(object victim, object me)
{	
	int skill, my_exp, your_exp;
	string msg;
	mapping buff;

	my_exp = me->query("combat_exp");
	your_exp = victim->query("combat_exp");
	skill = me->query_skill("dagou-stick",1);

	if( !ANNIE_D->check_buff(me, "parryup") && me->query_skill("dagou-stick",1) >= 130 && me->query("class") == "beggar" ) {
		msg=CYN"\n$N"+CYN"ʹ���򹷰����еķ��־������������Ӱ����ʱ���Լ���ǰ����֮�ؾ�����ס��\n"NOR;
		buff =
		([
			"caster":me,
			"who":me,
			"type":"parryup",
			"att":"bless",
			"name":"�򹷰��������־�",
			"buff1":"apply/parry",
			"buff1_c":skill/3,
			"time":20,
			"buff_msg":msg,
		]);
		ANNIE_D->buffup(buff);
		return;
	}

	if( me->is_busy() ) {
		return 0;
	}
	if( victim->query("race") == "Ұ��" ) {
		return 0;
	}
	if( random(3*my_exp) > your_exp && me->query_skill("dagou-stick",1) >= 170 && me->query("class") == "beggar" && random(2) ) {
		me->set_temp("counter_action", 1);
		me->set_temp("counter_msg", HIY"$Nʹ���򹷰���ת�־������а������������\n"NOR);
		return 0;
	}
}	


int help(object me)
{
	write(@HELP  
�򹷰������ؼ���Ҫ�����ķ������
�򹷰������Կ������ױ޷�
	 
L20	�������E����chuozijue��
�����������֣�����æ��2��
���⹥�������򹷰����ȼ�
�����˺������򹷰����ȼ�����

L60	���O���E����banzijue��
������3�֣����ʧ����������������һ�У�����ɹ�����æ��2-3�֡�
���ؼ��ڳɹ�ʱ��һ���ĸ����˺����ķ�50������

L100	�������E����tiaozijue��
���ɶ���������������30�����޷���װ�����Ա�����˵��Ҳ����Զ�Ͳ�
����װ�������ķ�50������������æ��2�֡�
ע�⣺�����������ؼ�ÿ������ÿ60�������Ч����һ�Ρ�

L110	�������E����yinzijue��
�Ѷ��ֵĹ���������������æ��1��
���ָ��ӹ��������򹷰����ȼ�
���ָ����˺������򹷰����ȼ�����
ÿ������ʹ��һ�Σ���������ǣ£ϣӣ������ÿ������ʹ��һ��

L125	�������޹�����tianxiawugou��
ͬʱ�����������е��ˣ�����æ��2��
���ӹ��������򹷰����ȼ�
�����˺������򹷰����ȼ�����

L130	�������E�� 
�ɹ��мܵ���ʱ�Զ�ʹ�ã������Ч�мܣ����򹷰����ȼ�������
����20��

L170	��ת���E�� 
�Զ�ʹ�ã��ڶ��ֹ���ʱ����������æ��״̬���п��ܷ������� 

L180	�������E�� 
�Զ�ʹ�ã����ж���ʱ��20%������ͼ��ס����ʹ��æ��һ�֣���ЧӦ
ֻ������ͨ������β������ʱ����֡��ü��ʿ�ͨ��ABILITY3��һ��
��ߵ�25%

L180	�������E�� 
����200������֮�����Զ�ʹ�ã�ÿһ����6%�ļ����˺����ӱ�����
���ʿ�ͨ��ABILITY��1��3����һ����ߵ�16%
HELP
    );
    return 1;
}
