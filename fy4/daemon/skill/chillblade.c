// �����߾� - chillblade.c 
// annie 07.2003
// dancing_faery@hotmail.com
// desc: ��Ұ�䰵��ʽ.��

#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","�����߾�");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",140);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","moon");
	set("parry_msg", ({
		"$n�������������$v��չ����һ�������纮��������ס$N�Ĺ��ơ�\n",
		})
	);
	set("unarmed_parry_msg", ({
		"$n�������������$v��չ����һ�������纮��������ס$N�Ĺ��ơ�\n",
		})
	);
	action = ({
	([	"action":		"$N�鵶���裬һ�С�ĺ���վ����庮��������âһƬ�����¹������$n",
		"dodge":		50,
		"damage":		160,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ������$w��һʽ��������������ɫ�����������¹�����������$n",
		"dodge":		120,
		"damage":		180,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�ʮ��˪Ӱתͥ�ࡹ����Ӱ����һ��Բ��������ɫ��Ʈ��$n",
		"dodge":		180,
		"damage":		120,
		"damage_type":	"����"
	]),
	([	"action":		"$N���$w�����������������һ��������ҹ�ø����¡��������޵�����$n",
		"dodge":		160,
		"damage":		160,
		"damage_type":	"����"
	]),
	});
}

int valid_learn(object me)
{
	if( !::valid_learn(me) ) {
		return 0;
	}
	if( me->query_skill("snowforce", 1) < me->query_skill("chillblade",1)-20 ) {
		return notify_fail("��ѩ�ľ���Ϊδ����ǿ�������߾��к����档\n");
	}
	return 1;
}

int basic_armor(object victim){
	
	int armor, eff_ness, absorb_vic;
	string absorb_skill;
	if( victim->query_skill("iron-cloth") ) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if( absorb_skill ) {
			if( !(eff_ness = SKILL_D(absorb_skill)->ic_effect()) ) {
				eff_ness = 100;
			}
			absorb_vic = victim->query_skill("iron-cloth",1)/2 + victim->query_skill(absorb_skill)*eff_ness/200 + victim->query_temp("apply/iron-cloth");
		} else {
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1)/2 + victim->query_temp("apply/iron-cloth");
		}
	} else {
		absorb_vic = victim->query_temp("apply/iron-cloth");
	}
	return absorb_vic;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int skill, damage, mark, i, *hits, num, n;
	object weapon;

	weapon = me->query_temp("weapon");
	if( !weapon->query("ice_blade") ) {
		return 0;
	}
	if( userp(me) && me->query("class") != "moon" ) {
		return 0;
	}

	if( !userp(me) ) {
		// NPC �� binglunyingjing is just a fake buff, add 0 damage.
		if( !me->query_temp("annie/chillblade_extradamage") ) {
			me->set_temp("annie/chillblade_extradamage",to_int(pow(to_float(me->query("combat_exp")),0.40)));
		}
	}
	// Extra damage here.
	if( !me->query_temp("annie/chillblade_extradamage") ) {
		return 0;
	}
	if( ANNIE_D->check_buff(me,"enchantweapon") > 0 || !userp(me) ) {
		damage = me->query_temp("annie/chillblade_extradamage");
		damage = damage - victim->query_temp("apply/armor");
		if( damage < 0 ) {
			return 0;
		}
		damage = COMBAT_D->magic_modifier(me,victim,"sen",damage);
		if( me->query_skill("chillblade",1) >= 190 && me->query_skill("stormdance",1) >= 130 ) {
				n = 2;
		} else {
			n = 1;
		}
		hits = me->query_temp("marks/shine_hits");
		if( !hits ) {
			hits = ({});
		}
		for( i = 0;i < sizeof(hits); i++ ) {
			if( hits[i]+30 < time() ) {
				hits -= ({ hits[i] });
			}
		}
		hits -= ({ 0 });
		me->set_temp("marks/shine_hits",hits);
		num = sizeof(hits);
		if( num > 10*n ) {
			num = 10*n; // capped +damage to 50%
		}
		damage += COMBAT_D->magic_modifier(me, victim, "sen", damage*n*num/20);
		victim->receive_damage("sen", damage, me);
		mark = 1;
		COMBAT_D->win_lose_check(me, victim, damage);
	}

	// Extra busy here.
/*	skill = me->query_skill("chillblade",1);
	if (!userp(me))
		skill += 100;
	if (random(skill) > 100 && random(me->query("force"))>random(victim->query("max_force")))
	{
		if (userp(victim))
			victim->perform_busy(random(weapon->query("ice_blade"))+1);	// 1 | 2*
		else
			victim->perform_busy(1);
		mark=1;
	}*/

	if( mark == 1 ) {
		return WHT+weapon->name()+WHT"�ϴ���˿˿������ֱ͸��$n"NOR+WHT"���裮��\n"NOR;
	} else {
		return 0;
	}
}


int effective_level(object me)
{
	int skill, add;
	if( me && me->query_temp("annie/chillblade_skillup") ) {
		skill = me->query_temp("annie/chillblade_skillup");
		add = F_ABILITY->check_ability(me,"chillblade_add");
		if( skill >= 190 ) {
			return (190 + add);
		}
		if( skill >= 170 ) {
			return (180 + add);
		}
		if( skill >= 150) {
			return (170 + add);
		}
		if( skill >= 120 ) {
			return (160 + add);
		}
	}
	return 140 + add;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("chillblade", 1);
		if( skill < 190 ) {
			return 200;
		} else {
			return 300;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP   
�����߾���������ѩ�ľ�Ϊ����������Ϊ��ѩ�ľ�+20��
�����߾�����190���ϣ�ѧϰϵ�����ӵ�300��

L20�������硻(yuhouchuhong) Ů��
L20���׵罻�䡻(leidianjiaohong) ����
���⹥�����������߾��ȼ�
�����˺�������Ч�����ȼ�

����Ů�ϻ����������ʼӱ���

���±����߾����ؼ�����Ҫʹ�ô��к������������ܷ�������
����˼ɽ��������������ҵ���������������Ƶ�����Ҳ�ɾ�
�����Ϻ�Ȫ�Ĵ�������ɾ��д���Ч��

L80������ӯ����(binglunyinjing)
�����߾�ÿ������ʱ���������˺����˺�����ȼ���߶����
�������˺����Զ��ֻ������������ı���������30���ӡ�
����ӯ���ڼ䣬���ż��ʽ���1%
����֮�£���һ����������˺���ֵ

������Ʒѩ��(Kunlun)
L120�������߾�ϵ�������160
L150�������߾����ϵ����170
L170�������߾����ϵ����180
L190�������߾����ϵ����190
����30����

L150�������ࡻ(liuguang)
�����˶�����˺���ʱת��Ϊ������ӯ�����Ĺ�Ч��ÿ�ܵ�һ��
�˺��������5%����಻����50%�����ۼ�Ч������30�롣
L190ʱЧ����ǿһ��������130��������衣

������ʽ��Ҫ�ҵ���Ӧ�ľ������ʩչ��ͬʱ��Ҫ1000�����
Ϊ������

L190�����¡�(mingyue)
���ӿ��ã�ͬһ������ֻ��ʹ��һ�Σ������޷����ܡ��޷��мܣ�
�˺�ֵΪ������ֵ��
�����˺���=�������߾�*�����߾�/36��
�ϲ᣺ÿ4����ʹ��һ�Σ�����æ��2�غ�
�в᣺ÿ4����ʹ��һ�Σ�����æ��1�غ�
�²᣺ÿ3����ʹ��һ�Σ�������æ��

L190����ԡ�(qinghui)
Ů�ӿ��ã����м���Է�������ʱ����������æ��״̬��
����æ�����֣�ÿ�����ٺķ�250�㷨����
������е��������з��������Ե��˵���Ѫ�˺���
�ϲ᣺������Ѫ�˺�=����/2
�в᣺������Ѫ�˺�=����
�²᣺������Ѫ�˺�=��������������һ�غ�æ��

HELP
    );
    return 1;
}
