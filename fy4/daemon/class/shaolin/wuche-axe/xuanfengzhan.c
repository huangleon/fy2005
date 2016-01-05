// Silencer@fengyun	June.2005
// AE Attack, good for getting NPCs' attention when start fighting.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill, extra_attack, extra_damage, timer, duration, i, chance;
	object weapon;
	object* enemy;

	if( me->query("class") != "shaolin" ) {
		return notify_fail("������ն��Ϊ�����ؼ���\n");
	}
	skill = me->query_skill("wuche-axe",1);
	if( skill < 170 || me->query_skill("axe",1) < 170 ) {
		return notify_fail("������ն����Ҫ170�����򳹲��縫����170���Ļ���������\n");
	}
	timer = 60 - F_ABILITY->check_ability(me,"xuanfeng_add")*2;	
	duration = me->query("timer/pfm/sl_xfz") + timer - time();
	if( duration > 0 ) {
    	return notify_fail("������ն����Ҫ"+chinese_number(duration)+"�������ٴ�ʹ�á�\n");
	}
	enemy = me->query_enemy();
	if( !sizeof(enemy) ) {
		return notify_fail("������ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	weapon = me->query_temp("weapon");
	msg = BBLU+HIY"$N"HIY"˫���ո�����������Ϊ���ģ�������Ȼ��ת��ת���ó��滺����
Ȼ��ͻȻ�䣬�����Х����֪���أ����ѻ���һƬ��Ļ������������
������һ���ǻ�����һ����λ��˭Ҳ�Ʋ�����"NOR"

	"HIR"��		��		ն"NOR+YEL"

	��Ӱһ������ֻ��һ�������硢��Ӱ�������漣����ȫͣ�١�\n" NOR;

	message_vision(msg, me);
	msg = "";
	extra_attack = skill;
	extra_damage = skill * 3;

	me->add_temp("apply/attack", extra_attack);	
	me->add_temp("apply/damage", extra_damage);

	for( i = 0; i < sizeof(enemy); i++ ) {
		if( me->is_busy() ) {
			continue;
		}
		COMBAT_D->do_attack(me, enemy[i], TYPE_PERFORM, msg);
		if( enemy[i] ) {
			if( enemy[i]->query_temp("damaged_during_attack") ) {
				enemy[i]->add_hate(me, skill*6);
			}
		}
	}

	me->add_temp("apply/attack", -extra_attack);
	me->add_temp("apply/damage", -extra_damage);
	me->set("timer/pfm/sl_xfz", time());    
	me->perform_busy(1);
	return 1;
}
