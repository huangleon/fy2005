// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	int i, skill, iron, num, duration, ratio;
	mapping buff;

	if( me->query("class") != "shenshui" && userp(me) ) {
		return notify_fail("ֻ����ˮ�����Ӳ���ʹ������Ѫ�񹦡��ľ�����\n");
	}
	if( me->query_skill("nine-moon-force",1) < 160 || me->query_skill("nine-moon-spirit",1) < 160 ) {
		return notify_fail("����Ѫ�񹦡���Ҫ160�������ľ���160���Ů�񹦡�\n");
	}
	if( ANNIE_D->check_buff(me, "damage_to_heal") ) {
		return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");
	}
	if( userp(me) ) {
		duration = me->query("timer/pfm/9moon_huaxue") + 600 - time() - F_ABILITY->check_ability(me, "3_huaxue_add", 3) * 20;
		if( duration > 0 ) {
			return notify_fail("����Ѫ�񹦡�������������ȴ�"+duration/60+"�������ҡ�\n");
		}
	}

	if( me->query("sen") < 100 ) {
		return notify_fail("����Ѫ�񹦡���Ҫ100������\n");
	}
	if( userp(me) ) {
		me->receive_damage("sen", 100);
	}
	skill = me->query_skill("nine-moon-claw", 1);
	ratio = 50;
	ratio = ratio+F_ABILITY->check_ability(me,"huaxue_add")*5;
	buff =
		([
			"caster":me,
			"who":me,
			"type":"damage_to_heal",
			"att":"bless",
			"name":"�����ľ�����Ѫ��",
			"buff1":"damage_to_heal",
			"buff1_c":ratio,
			"time":120,
			"buff_msg":BMAG + HIM"$N"BMAG+HIM"����Ѫ�񹦣�����������֮�ա��ƹ�֮�顣\n"NOR,
			"special_func":0,
		]);

	ANNIE_D->buffup(buff);
	me->set("timer/pfm/9moon_huaxue", time());
	return 1;
}

