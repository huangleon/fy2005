// astral_vision.c 

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	mapping buff, *mem;
	if( me->query("class") != "taoist" ) {
		return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
	}
	if( (int)me->query_skill("necromancy",1) < 10 ) {
		return notify_fail("�������ۡ���Ҫ10�������������\n");
	}
	if( !target ) {
		target = me;
	} else {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target,mem) == -1 ) {
			return notify_fail("��ֻ�ܸ�ͬһ�����е���ʩչ�����ۡ�\n");
		}
	}
	if( ANNIE_D->check_buff(target, "astral_vision") ) {
		return notify_fail("�����Ѿ�ʩչ�������۵ķ����ˡ�\n");
	}
	if( (int)me->query("mana") < 30 || me->query("sen") < 5 ) {
		return notify_fail("��Ҫ30�㷨����5������\n");
	}
	if( userp(me) ) {
		me->add("mana", -30);
		me->receive_damage("sen", 5);
	}
	buff =
		([
			"caster":me,
			"who": target,
			"type":"astral_vision",
			"att":"bless",
			"name":"���������������",
			"buff1":"apply/astral_vision",
			"buff1_c":1,
			"time":  900,
			"buff_msg":BBLU + HIB "$N΢һ����ʩչ�������ۡ������������۾����˼������\n" NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
