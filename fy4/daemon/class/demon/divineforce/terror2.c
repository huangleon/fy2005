// Modifiction of Terror 1, leave one to kill

#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl,i,j,k=0,l,n;
	object *enemy,*enemy_here;

	if (!me->is_fighting())
		return notify_fail("����ħ���Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	enemy = me->query_enemy();
			
	msg = HIG "\n$N��ɫ������˫�ֽ��а��ӡ�����������дʣ���Ȼһ��˫�֣�\n"HIM"\nֻ��һ����ը���죬����������$N��ǰ�ۼ����Σ��û�Ϊ���ɸ��µľ޴���ħ��\n\n" NOR;
	message_vision(msg, me);
	
	lvl = me->query_skill("force");

	n = random(sizeof(enemy));
	
	for (i=0; i<sizeof(enemy);i++ )
	{
		if (random(enemy[i]->query("combat_exp")) > me->query("combat_exp") || i == n)
		{
			msg = WHT "$N��Ϊ��������Ц�������������Ҳ�����������ۣ�\n" NOR;
			message_vision(msg, enemy[i]);
			k++;
		}
		else
		{
			msg = MAG "$N��ʧɫ����·���ӣ�\n" NOR;
			message_vision(msg, enemy[i]);
			enemy[i]->add_temp("apply/agility",me->query("agi")*2);
			l = enemy[i]->query_busy();
			enemy[i]->stop_busy();
			for (j=0; j<random(3)+3; j++)
			{
				if (environment(enemy[i]) == environment(me))
					GO_CMD->do_flee(enemy[i]);
			}
			enemy[i]->add_temp("apply/agility",-me->query("agi")*2);
			enemy[i]->perform_busy(l);
			if (environment(enemy[i]) != environment(me))
			{
				tell_object(enemy[i],HIY"���ӳ����죬���ɰ���Ĩ��һ���亹����Ϣ������\n"NOR);
				enemy[i]->perform_busy(10);
			}
		}
	}

	return 1;
}


