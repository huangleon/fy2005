// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","���ľ�");
	set("type","force");
	set("usage/force",1);
	set("effective_level",100);
	set("difficulty",400);
	set("skill_class","yinshi");
}


// �ƽ�I II
mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage, rate;
	object weapon, *enemy;
	string msg;

	if( !(rate = me->query_temp("pfm/locustcurse")) ) {
		return;
	}
	// max 500*2
	extra = me->query_skill("cursism");
	extra = extra *2;
	extra = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	me->delete_temp("pfm/locustcurse");
	if( random(100) > rate ) {
		if( COMBAT_D->do_magic_attack(me, victim, "cursism", "kee", 400) ) {
			victim->receive_wound("kee", extra, me);
			msg= RED"$N���еĺ���Ȼ���ӳ�������û��Ϣ���䵽$n���ϡ�\n"NOR;
		} else {
			msg= YEL"$N���еĺ���Ȼ���ӳ�����$n����������һ�ƽ�����ɢ��\n"NOR;
		}
		return msg;
	} else {
		me->receive_wound("kee", extra, me);
		me->set_temp("last_damage_from","���ƽ�ʬ�淴�ɶ���\n");
		msg= HIR"$N���еĺ���ܾ����Ӷ���ֱ������$N��ʧɫ��\n"NOR;
		return msg;
	}
	return 0;
}


int help(object me)
{
	write(@HELP
�����ľ�����Heal�������ķ�

�����ľ�����Depoison���ⶾ
L0 		����һ����˷���ԵȲ�״
L75 	�����𶾡��߶�����Ѫ�ơ���Ѫ�Ƶ�
L150 	����������������
Ϊ���ˣ����ѣ�������Ҫ100�����ľ�

�����ľ�����Buffup) 
����Լ�����Ѫ���ֵ���軨��400������������15����
��		����50�����ľ���+300��Ѫ
�ɣ�	����110�����ľ����Ķ����ᣬ+900��Ѫ
�ɣɣ�	����150�����ľ����Ķ����ᣬ+1500��Ѫ
�ɣ�	������200��ͨ�콵���Ķ����ᣬ+2500��Ѫ
���ľ����Ծ�������ability��һ����ߣ����⻹�ɾ���TASK ability3ͬʱ
������/��/�񣬵������ӵĲ��������ڶ���ʱ�������롣
HELP
	);
	return 1;
}
