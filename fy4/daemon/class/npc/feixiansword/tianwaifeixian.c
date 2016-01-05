#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int busy_target(object me,object target);

int perform(object me, object target)
{
	string msg;
	int extra;
	int i, force;
	object weapon,*pros;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	force = me->query("force_factor");
	me->set("force_factor",0);
	
	extra = me->query_skill("feixiansword",1) / 10;
	
	me->add_temp("apply/attack", extra*4);	
	me->add_temp("apply/damage", me->query_skill("feixiansword",1)/2);
	me->set_temp("in_feixian_pfm",1);
	weapon=me->query_temp("weapon");
	
	msg = HIR  "$N��̤�������ϣ����ƶ��䣬ʹ�����ɽ����еľ��裭����������ɡ�
���е�"+ weapon->name() +HIR"����һ�����磬�����Ļ���$n��" NOR;

	target->add_temp("buff/no_abs",1);
	pros = target->query_temp("protectors");
	target->delete_temp("protectors");

	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	busy_target(me,target);
	
	for(i=0;i< extra/5;i++)
	{
		msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�" NOR;
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		busy_target(me,target);
	}
	
	me->add_temp("apply/attack", -extra*4);
	me->add_temp("apply/damage", -me->query_skill("feixiansword",1)/2);
	me->delete_temp("in_feixian_pfm");
	me->set("force_factor",force);

	if (target) {
		target->add_temp("buff/no_abs",-1);
		target->set_temp("protectors",pros);
	}
	
	me->perform_busy(2);
	return 1;
}

int busy_target(object me,object target)
{
	if (!target->query_temp("damaged_during_attack")) 
	{
		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N�������񣬾������ͣ��ȿ�$n��ת�ۼ��ض��Ȼ���\n"NOR,me,target);
			me->stop_busy();
		}
		else
		{
			message_vision(WHT "������������ע���������죬��������������Ȥ��$n���������˽��������ֽ����顣\n"NOR,me,target);
			if (target->query("force"))
			{
				target->add("force",-200);
				if (target->query("force") < 0)
					target->set("force",0);
			}
			else
				target->force_busy(1+target->query_busy());
		}			
	}
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

