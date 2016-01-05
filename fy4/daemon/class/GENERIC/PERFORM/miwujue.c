#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon;
		int mod;
		
		p_name = "miwujue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
								
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		if (target->is_busy())
			return notify_fail("�Է��Ѿ���æ�����ˡ�\n");
			
		mod = COMBAT_D->can_busy(me, target, "yunwu-strike");	
		if (!mod)
			return notify_fail(HIW"���˹�����տ�����ᱻ���ַ��Ի�ġ�\n"NOR);
		
		msg = HIR "$Nʹ�������Ʒ��еġ�ʮ��������˫�ƻ��裬��Ӱ�ܲ���������$n��" NOR;
		message_vision(msg + "\n", me, target);
	
		if (COMBAT_D->do_busy_attack(me, target, "yunwu-strike", "unarmed", 700, mod))
		{
			msg = CYN"$n"NOR CYN"�����ͻ���ý��ѣ�\n"NOR;
			message_vision(msg, me, target);
			target->force_busy(3);
			target->set_temp("busy_timer/yunwu-strike",time());
		}
		else
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		
		return 1;
}

