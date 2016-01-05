// Silencer@fengyun	June.2005
//	+atk 85. +dmg 0;

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, duration, timer, time;
	object* enemy;
	mapping buff;

	if( me->query("class") != "shaolin" ) {
		return notify_fail("�������������ֵ��ӵľ��С�\n");
	}
	extra = me->query_skill("liuxing-hammer",1);
	if( extra < 170 || me->query_skill("hammer", 1) < 170 ) { 
		return notify_fail("����������Ҫ170���ķ�ת���Ǵ�����170���Ļ���������\n");
	}
	timer = 600;	
	duration = me->query("timer/pfm/sl_xuanji") + timer - time();
	if( duration > 0 ) {
		return notify_fail("����������Ҫ"+chinese_number(duration)+"�������ٴ�ʹ�á�\n");
	}
	enemy = me->query_enemy();
	if( !sizeof(enemy) ) {
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( target ) {
		return notify_fail("������������Ҫָ��ʹ�ö��󣡣�\n");
	}
	if( ANNIE_D->check_buff(me, "riposte") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
	me->set("timer/pfm/sl_xuanji", time());
	time = 60 + F_ABILITY->check_ability(me, "3_xuanji_add", 3) * 6;
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"riposte",
			"att":"bless",
			"name":"���Ǵ���������",
			"buff1":"counter_action_extra",
			"buff1_c":1,
			"time":time,
			"buff_msg":BBLU+HIY"$N"NOR+BBLU+HIY"��ʽ�Ż������ӻ��Ŀ����������ָ���������֮����\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
