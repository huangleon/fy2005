// Silencer@fy4 workgroup
// Add 100% force instantly every 15mins.

#include <ansi.h>

int exert(object me, object target)
{
	int extra, timer, duration, i, num, time;
	mapping buff;
	object *enemy;

	if( me->query("class") != "shaolin" ) {
		return notify_fail("ֻ�����ָ�ɮ����ʹ�á�������ա�\n");
	}
	extra = me->query_skill("yijinjing", 1);
	if( extra < 150 ) {
		return notify_fail("��Ҫ150���׽����ʹ�á�������ա�\n");
	}
	duration = me->query("timer/pfm/sl_fgpz") - time() + 1200 - F_ABILITY->check_ability(me,"foguang_add")* 30;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ�á�������ա���\n");
	}
	enemy = me->query_enemy();
	num = sizeof(enemy);
	if( num == 0 ) {
		return notify_fail("��������ա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( me->query("force") < 200 ) {
		return notify_fail("��������ա���Ҫ200��������\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	time = 20 + F_ABILITY->check_ability(me, "3_foguan_add", 3) * 2;
	message_vision(BRED + HIY"\n$N"BRED + HIY"˫�ֺ�ʮ��һ��������Թ��֮��ƽƽ�������ϼ�����ɣ�������ա�\n\n"NOR,me);
	for( i = 0; i < num; i++) {
		buff =
		([
			"caster":me,
			"who":enemy[i],
			"type":"nulldodge",
			"att":"curse",
			"name":"�׽���������",
			"buff1":"cant_dodge",
			"buff1_c":1,
			"time":time,
			"buff_msg":HIG"$N"HIG"Ϊ$n"HIG"�������������𺳣������ؾ���֪���ܡ�\n"NOR,	
			"disa_msg":WHT"$N"NOR+WHT"����һ�ݣ��������γ��ѡ�\n" NOR,
			"disa_type":1,		
		]);
		ANNIE_D->buffup(buff);
	}	
	me->set("timer/pfm/sl_fgpz", time());
	return 1;
}


