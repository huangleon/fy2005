// annie 7.04.03
// dancing_faery@hotmail.com
// THOUSAND FEATHER:busy + attack

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,j,k,l,skill,damage;
	object weapon;
	object * enemy;
	if(!me->is_fighting())
		return notify_fail("������ǧ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	skill = me->query_skill("dragonwhip",1);
	if (skill < 50)
		return notify_fail("������ǧ����Ҫ����50������������޷���\n");
	weapon = me->query_temp("weapon");

	enemy = me->query_enemy();

	message_vision( HIR "\n$N"HIR"�з���䣬����էչ���գ��ڿ���������չ������������֮�ˡ�
����һ����Х������춷ɣ�����������������������\n\n"NOR,me);

	for(i=0; i<sizeof(enemy); i++)
	{
		l = 0;	// �����ص�������
		k = 0;

		target = enemy[i];
		for (j=0;j<skill/25;j++)	// 160lv = 6 ,res->175: 7,res->200: 8
		{
			if (random(target->query("combat_exp")* 4) < random(me->query("combat_exp")) )
				l++;	
			else if (random(target->query("combat_exp")) < random(me->query("combat_exp")))
				k += 1+random(200);
			// else... miss.
		}
		message_vision(RED"���$N"NOR+RED"",target);
		if (l)
		{
			message_vision("��������������µĻ���",target);
			if (target->query_busy() <= l)
				target->force_busy(l);
		}
		if (k)
		{			// maximum 7* 200 = 1400*4 then random
			k *=4;
			message_vision("��"+chinese_number(k)+"�������յ���",target);
			target->receive_damage("kee",k,me);
		}

		if (l || k) {
			message_vision("�ֵ���æ���ң�\n\n"NOR,target);
			COMBAT_D->report_status(target);
	        COMBAT_D->win_lose_check(me,target,damage);
		} else
			message_vision("�������ɵıܿ������еĻ���\n\n"NOR,target);
	}
	
//	if (wizardp(me))
//		tell_object(me,"BUSY:"+l);
				
	me->perform_busy(2+random(2));
	return 1;
}

