// annie 07.2003
// dancing_faery@hotmail.com
// �������� 
// ����Ʒѩ�����ϵ��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
		int i,t,skill,level,damage;
		mapping buff;
		string msg;
		object weapon;

        skill = me->query_skill("chillblade",1);

		if (skill < 120)
        	return notify_fail("������Ʒѩ����Ҫ����120���ı����߾���\n");

		if( ANNIE_D->check_buff(me,"skillup")) 
			return notify_fail("����������ʩչ���Ƶ�������\n");

		msg=HIR BLK"\n$N"HIR BLK"���еĵ�ͻȻ���ˣ����ü������ͣ�"NOR WHT"���Ǹ���֮�������һƬ����ѩӰ��������������"HIW"ȴ�޴����ڣ��޼᲻�ݡ�\n\n"NOR;

		buff =
		([
			"caster":me,
			"who":me,
			"type":"skillup",
			"att":"bless",
			"buff1":"annie/chillblade_skillup",
			"buff1_c":skill,
			"name":"�����߾�������Ʒѩ",
			"time":30,
			"buff_msg":msg,
		]);

		ANNIE_D->buffup(buff);

        return 1;
}



