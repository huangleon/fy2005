/*jin-gang 200x1.5 + 200x0.5 = 400, 
200/2 + 300 /2 + 100 = 350*/

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration,stage, rate;
	string msg;
	mapping buff;

	target = me;
	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�á���ǹ���롻��\n");
	}
	skill = me->query_skill("jin-gang", 1);
	if( skill < 150 ) {
		return notify_fail("����ǹ���롻��Ҫ150����ղ�������\n");
	}
	if( ANNIE_D->check_buff(me, "damageshield") || me->query_temp("damage_shield") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
	if( me->query("force") < 200 ) {
		return notify_fail("����ǹ���롻��Ҫ200��������\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	msg = HIR"$N�������ظ����߽��ţ�����ǹ���룡��ǹ���룡��ǹ���룡��������\n"NOR;

	// SCROLL ADVANCE PERFORM, 
/*
	stage = me->query("scroll/jin-gang_daoqiangburu");
	switch( stage ) {
		case 0:
		case 1:
			rate = 50;
			break;
		case 2:
			rate = 60;
			break;
		case 3:
			rate = 70;
			break;
	 }
*/

	buff = ([
		"caster": me,
		"who": me,
		"type": "damageshield",
		"att": "bless",
		"name": "��ղ�������ǹ����",
		"buff1": "resistance/kee",
		"buff1_c": 20,
		"buffup_name": "backfire",
		"buffup_type": "kee",
		"buffup_ratio": 10,
		"buffup_msg": "", //WHT"$n"NOR WHT"�ܵ�$N"NOR WHT"��ղ�����������Ѫ��ӿ��\n"NOR,
		"time": 900,
		"buff_msg": msg,
	]);
	ANNIE_D->buffup(buff);
	return 1;
}