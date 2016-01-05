// ����˪������remedy����Heal over time
//  L150: 200 ������amount = skill ����ʮ��every 8 sec��max; 300*10 = 3000


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount1)
{
	int level,i, skill, amount, ability;
	object *enemy, *mem;

	if( me->query("class") != "huashan" ) {
		return notify_fail("ֻ�л�ɽ���Ӳ����ô��ķ���\n");
	}
	level = me->query_skill("hanmei-force",1);
	if( level < 150 ) {
		return notify_fail("��Ҫ150���ĺ�÷�ķ���\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target,mem) == -1 ) {
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
		}
	}
	if( userp(me) && !COMBAT_D->legitimate_heal(me,target) ) {
		return notify_fail("�㲻�������ʹ�ô������ľ���\n");
	}
	if( target->query_temp("pfm/hanmei_remedy") ) {
		return notify_fail("�����Ѿ��ڻָ����ˡ�\n");
	}
	if( me->query_skill("hanmei-force",1) >= 200 ) {
		skill = 300;
	} else if( me->query_skill("hanmei-force",1) >= 170) {
		skill = 250;
	} else {
		skill = 200;
	}
	if( me->query("force") < skill ) {
		return notify_fail("��Ҫ"+skill+"���������\n");
	}
	if( target != me ) {
		message_vision(HIG "$N"HIG"����˪�ķ���ʳָĴָ�������������ԴԴ��������$n"HIG"���ڡ�\n\n"NOR,me,target);
	} else {
		message_vision(HIG "$N"HIG"����˪����ʳָĴָ�������������ԴԴ���ϵ�������ѭ����\n\n"NOR,me);
	}
	if( userp(me) ) {
		if( F_ABILITY->check_ability(me,"heal_add") > random(100) ) {
			tell_object(me,YEL"������Ϣ��ͨ�����������ʹ������һ�У�\n"NOR);
		} else {
			me->add("force", -skill);
		}
	}
	if( target->is_fighting() ) {
		enemy = target->query_enemy();
		for( i = 0; i < sizeof(enemy); i++ ) {
			if( !enemy[i]->is_fighting(me) ) {
				enemy[i]->kill_ob(me);
				me->kill_ob(enemy[i]);
			}
		}
	}
	ability = F_ABILITY->check_ability(me, "huashang_add");
	amount = skill*(100+ability*3)/100;
	amount = COMBAT_D->magic_modifier(me, target, "kee",amount);
	target->set_temp("pfm/hanmei_remedy", 1);
	call_out("fillup", 8, target, 10, 0, amount);
	me->start_busy(1);
	return 1;
}

void fillup(object me, int total, int count, int amount)
{
	if( !me ) {
		return;
	}
	if( me->query_temp("pfm/hanmei_remedy") < 1 ) {
		me->delete_temp("pfm/hanmei_remedy");
		return;
	}
	if( ++count > total ) {
		tell_object(me,YEL"����������ת���ǹ�����������ʧ�ˡ�\n"NOR);
		me->delete_temp("pfm/hanmei_remedy");
		return;
	} else {
		// only heals when necessary, otherwise it's unnecessary hate.
		if( me->query("kee") < me->query("max_kee") ) {
			me->receive_fulling("kee", amount, me);
		}
		tell_object(me,WHT"�����𵴣�˳�����澭����Ѹ���������˿��������ϡ�\n"NOR);
		call_out("fillup", 8, me, total, count, amount);
	}
	return ;
}