// annie 6.27.03
// DISORDER - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,j;
	object *tar;

	tar = me->query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(HIY"\n$Nʹ���䵱��ʧ���Ľ������������������黭�˸��뻡�����ƻ�Ȧ��\n��Ȼ��������������Ť��Բת�ľ�������������˶������ᡣ\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// Ϊ����parry busy��Ч(��,̫����),���ﲻʹ��mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",me->query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,HIY"$N"HIY"ֻ����һ���������������ɼ�����$n"HIY"��ȥ��"NOR);
			tar[i]->add("force_factor",-me->query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
			target->receive_damage("kee",1,me);
		}
		me->perform_busy(2);
		return 1;
	}
	else
		return notify_fail("�������������޷�ʹ�á�\n");
	return 1;
}

