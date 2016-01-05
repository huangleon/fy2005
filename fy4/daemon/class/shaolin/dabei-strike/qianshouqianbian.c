#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra, mod, x;

	if (userp(me))
	if (me->query("class")!= "shaolin" && me->query("class")!="bonze")
		return notify_fail("��ǧ��ǧ�䡻�Ƿ����书��\n");
	
	extra=me->query_skill("dabei-strike",1);		
	if(extra<20)
		return notify_fail("��ǧ��ǧ�䡻��Ҫ20���Ĵ�ȴ�ǧҶʽ��\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ǧ��ǧ�䡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if ((target->query("boss") || target->query("big_boss"))&& me->query("class")!="shaolin")
		return notify_fail(HIW"���˹�����տ�����ᱻ���ַ��Ի�ġ�\n"NOR);
		
	mod = COMBAT_D->can_busy(me, target, "dabei-strike");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ���ַ��Ի�ġ�\n"NOR);
			
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
			
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp")* mod/10;

// 	(180/2+1.2x180)	= 306/40+1 = 8
	lvl = (int) me->query_skill("unarmed") / 40 + 1;

	// �˹���BUSYЧ�ʲ���
	if (lvl > 5 && me->query("class")=="bonze")	lvl = 5;
			
	msg = HBRED+HIW "$N"HIW"ʹ����ǧҶ�Ʒ��еġ�ǧ��ǧ�䡻���ó�������Ӱ����$n��" NOR;
			
	if (COMBAT_D->do_busy_attack(me, target, "dabei-strike", "unarmed", lvl* 100, mod)) 
	{
		message_vision(msg + "\n", me, target);
		msg = YEL"���$n��$N���˸���æ���ң�\n"NOR;
		message_vision(msg, me, target);
		target->force_busy(2);
		target->set_temp("busy_timer/dabei-strike",time());
		me->perform_busy(1);
	}
	else
	{
		me->add_temp("apply/attack",extra/2);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra/2);
		me->perform_busy(2);
	}
	
	// INherently, Every busy has 4*level hate, unarmed makes it 10x you/target level every 2 turn.
	if (target && !userp(target)){
		x = me->query("combat_exp")> target->query("combat_exp") 
			? target->query("combat_exp"): me->query("combat_exp");
		target->add_hate(me, F_LEVEL->get_level(x)*6);
	}
	
	return 1;
}



