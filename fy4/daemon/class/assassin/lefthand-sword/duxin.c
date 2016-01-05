// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	
	extra = me->query_skill("sword");
	bonus = me->query_skill("lefthand-sword", 1);

	if (bonus>130) extra = extra + bonus;

	if (me->query("always_duxin") == 1)
	{
		// Fatal stroke ' ���׽���SCROLL
		me->add_temp("apply/attack", bonus*2);
		me->add_temp("apply/damage", extra*2);
		msg = HIY"\n$N"HIY"���֣�ͻȻ�����˽����������������ݳ���һ����û��\n"NOR;
	
		me->set_temp("annie/perform_duxin",1);
		target->add_temp("combat_no_report",1);
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		if (!target->query_temp("damaged_during_attack"))
			message_vision(YEL"\n$n"YEL"�������������ձܿ����ǵ����纮�⡣\n\n"NOR,me,target);
		else
		{
			if (target->query("kee")<0)
				message_vision(WHT"
����ֻһ���Ѵ�����$n�ʺ����������߷֡�
$n����ͻȻһ��鴤���ʺ��з����ˡ��񡱵�һ�졣"HIR"
��������Ѫ�ɼ���
\n"NOR, me, target);
			else
			{
				msg = WHT"����ֻһ���Ѵ�����$nǰ�أ��뼡���磡\n"NOR;
				message_vision(msg, me, target);						
				COMBAT_D->report_status(target);
			}
		}
		target->add_temp("combat_no_report",-1);
		me->set_temp("annie/perform_duxin",0);
		me->add_temp("apply/attack", -bonus*2);
		me->add_temp("apply/damage", -extra*2);
		me->set("timer/pfm/duxin",time());

		// this perform ignore parry_busy' BUSY.
		me->stop_busy();
		me->perform_busy(2);
		return 1;
	}

	if ((!me->query("annie/duxin") 
		|| (target->query("kee") > target->query("max_kee")/4 
		&& target->query("kee")> 1000)
		|| me->query("timer/pfm/duxin") + 120 > time())
	)
	{
		me->add_temp("apply/attack", bonus);	
		me->add_temp("apply/damage", extra);
		msg = HIR"$N"+HIR"��"+weapon->name() +HIR"�������֣����죬��������׼����$n"+HIR"�̳���\n" NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -extra);
	}
	else
	{
		// Fatal stroke ' ���׽���SCROLL
		me->add_temp("apply/attack", bonus*2);
		me->add_temp("apply/damage", extra*2);
		msg = HIY"\n$N"HIY"���֣�ͻȻ�����˽����������������ݳ���һ����û��\n"NOR;
	
		me->set_temp("annie/perform_duxin",1);
		target->add_temp("combat_no_report",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		message_vision(msg,me,target);
		if (!target->query_temp("damaged_during_attack"))
			message_vision(YEL"\n$n"YEL"�������������ձܿ����ǵ����纮�⡣\n\n"NOR,me,target);
		else
		{
			if (target->query("kee")<0)
				message_vision(WHT"
����ֻһ���Ѵ�����$n�ʺ����������߷֡�
$n����ͻȻһ��鴤���ʺ��з����ˡ��񡱵�һ�졣"HIR"
��������Ѫ�ɼ���
\n"NOR, me, target);
			else
			{
				msg = WHT"����ֻһ���Ѵ�����$nǰ�أ��뼡���磡\n"NOR;
				message_vision(msg, me, target);						
				COMBAT_D->report_status(target);
			}
		}
		target->add_temp("combat_no_report",-1);
		me->set_temp("annie/perform_duxin",0);
		me->add_temp("apply/attack", -bonus*2);
		me->add_temp("apply/damage", -extra*2);
		me->set("timer/pfm/duxin",time());

		// this perform ignore parry_busy' BUSY.
		me->stop_busy();
	}
	
	me->perform_busy(2);
	return 1;
}


/* too romantic, Jing is a killer, annie :)

msg = HIR"\n$N"+HIR"ͻȻ΢Ц������������ס"+weapon->name() +HIR"��������ʱ�⻪�������ݳ���һ����û��" NOR;
message_vision(HIR"\nֻ��$n��ǰ��ɢ��һƬ��Ѫ���·���ͥ�л���ҡ���������̣��羡��Ϣ�������زк졣\n"NOR,me,target);

�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
