// Silencer@fengyun	June.2005
// �����������������

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, duration;
	mapping buff;
	int mod;
	
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	extra = me->query_skill("eagle-claw", 1);
	if( extra < 150 ) {
		return notify_fail("���������Ҫ150����ӥצ����\n");	
	}
	if( target->query("race") != "����" ) {
		return notify_fail("�������ֻ���ڡ��ˡ�����ʹ�á�\n");
	}
	duration = me->query("timer/pfm/fg_cunjin") - time() + 600;
    if( duration > 0 ) {
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ�ô����\n");
	}
	if( target->query_temp("timer/lockup") + 60 > time() ) {
		return notify_fail("�����Ѿ��з����ˣ����²��ܵ��֣�����һ����˵�ɡ�\n"); 
	}
	if( ANNIE_D->check_buff(target, "lockup") ) {
		return notify_fail("�����Ѿ��ܵ������书ǣ���ˡ�\n");
	}
	mod = COMBAT_D->can_busy(me, target, "eagle-claw");	
	if( !mod ) {
		return notify_fail("���˹�����񣬴����޷����֡�\n");
	}
	msg = BCYN + HIG "$N"BCYN+HIG"ʹ��ӥצ���еġ����ʽ�������һ����������ϣ�˫�����������꣬
������ʽ������׽Ӱʽ����������ʽ��������ɪʽ����������ʽ��������������
ָ���絶�����п���$n"BCYN+HIG"�Ĺؽ�Ҫ����\n" NOR;
	message_vision(msg, me, target);

	if( target->query("boss") || target->query("big_boss") ) {
		duration = 10;
	} else {
		duration = 30;
	}
	duration = duration + F_ABILITY->check_ability(me, "3_cunjin_add", 3) * 2;
	if( COMBAT_D->do_busy_attack(me, target, "eagle-claw/cunjin", "unarmed", 300, mod) ) {
		msg = BLU"$N"NOR+BLU"���ƺ�Ȼ��죬��ƮƮ�ĵ���ȥ����$n"NOR+BLU"��������ָ�ĵڶ����ǽ�һ·
��Ծ��ȥ���������⣬�羮����׵��������\n"NOR;
		message_vision(msg + "\n", me, target);
		tell_object(target, WHT"��������ӥצ��������ʽ!��\n"NOR);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "lockup",
			"att":  "curse",
			"name": "ӥצ��������",
			"time":  duration,
			"buff1": "till_death/lockup",
			"buff1_c": 1,
			"buff_msg": "",
			"warn_msg":"",
			"disa_msg": WHT"$N���λζ������ڴ�ָ�������������\n"NOR,
			"disa_type": 1, 
		]);
		ANNIE_D->buffup(buff);		
	} else {
		message_vision(YEL"$n�������Σ������ƹ�������������$N����ָ�����\n"NOR, me, target);
	}	
	target->set_temp("timer/lockup", time());
	me->set("timer/pfm/fg_cunjin", time());
	me->perform_busy(1);
	return 1;
}