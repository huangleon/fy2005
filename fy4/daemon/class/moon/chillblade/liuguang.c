// annie 07.2003
// dancing_faery@hotmail.com
// �������� 
// �����ࡤ���ӱ���ӯ���˺�

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		int i,t,skill,level,damage;
		mapping buff;
		string msg;
		object weapon;

		level = me->query("annie/chillblade_liuguang");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;
		
        skill = me->query_skill("chillblade",1);

		if (skill < 150)
        	return notify_fail("�������ࡻ��Ҫ����150���ı����߾���\n");

		if( !ANNIE_D->check_buff(me,"enchantweapon")) 
			return notify_fail("û�С�����ӯ�������������ࡻ���Ӳ����κ����á�\n");

		if( ANNIE_D->check_buff(me,"shine")) 
			return notify_fail("����������ʩչ���Ƶ�������\n");

		if (skill>=190 && me->query_skill("stormdance",1)>=130)
		msg=HIC"\n$N"HIC"�����ٷ磬��ɫ��������Զɽ���̣�һʱ���㾹�ƿ�����һ�ֵ���ɫ��Բ����$N"HIC"
�������ջ��������������ȣ���$N"HIC"������"+me->query_temp("weapon")->name()+HIC"ӳ�ñ�����Ө��\n\n"NOR;
		else
msg=HIC"\n$N"HIC"˫Ŀ΢�ϣ�ʮָ����ǰ�ಢ��һʱ���㾹�ƿ�����һ�ֵ���ɫ��Բ����$N"HIC"
�������ջ��������������ȣ���$N"HIC"������"+me->query_temp("weapon")->name()+HIC"ӳ�ñ�����Ө��\n\n"NOR;

		buff =
		([
			"caster":me,
			"who":me,
			"type":"shine",
			"att":"bless",
			"name":"�����߾���������",
			"time": 1800,
			"buff_msg":msg,
		]);

		ANNIE_D->buffup(buff);

		me->perform_busy(1);

        return 1;
}



