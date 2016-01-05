

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	object weapon;
	
	if ((string)me->query("class") != "wudang")
  		return notify_fail(WHT"̫�������־������䵱����֮�ء�\n"NOR);
	
	extra = me->query_skill("taiji-sword",1);
	if ( extra < 130) return notify_fail("�����־�����Ҫ130����̫��������\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "taijiforce")
		return notify_fail("�����־�����Ҫ̫���ķ�����ϣ�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	mod = COMBAT_D->can_busy(me, target, "taiji-sword");	
	if (!mod)
		return notify_fail(HIW"��������������տ�����ᱻ�˽����Ի�ġ�\n"NOR);
	
	if(target->is_busy())
		return notify_fail("�Է��Ѿ���æ�����ˡ�\n");
		
//	����3��5M��ĳɹ��ʡ�
	if (!userp(target))
	if (target->query("combat_exp") > 3500000) mod = mod * 8/5;

	if (!target->query_temp("annie/wd_busy_test_1") || time() > target->query_temp("annie/wd_busy_test_1") +4 )
	{
		message_vision(HIY"$N"HIY"չ��̫�����������־���������Բת���⣬������һ����һ��Ȧ�ӡ�\n",me);
		
		if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/chanzijue", "rev-unarmed", 120, mod))
		{ 
			target->force_busy( 2+ random(3) );
			message_vision(HIC "$N"HIC"��$n"HIC"�Ľ�����������������������\n"NOR,target,me);
		} else	{
			me->perform_busy(2);
			if (weapon = target->query_temp("weapon"))
				message_vision(HIW"$N"HIW"������ʤ��"+weapon->name()+HIW"��$n�Ľ���Ȧ�й��˽�ȥ�������ཻ����Ȧ��ɢ��\n"NOR,target,me);	
			else 
				message_vision(HIW"$N"HIW"�������䣬�й���������$n����Ȧ�й��˽�ȥ���Ʒ絽������Ȧ��ɢ��\n"NOR,target,me);
		}
	}
	else
	{
		message_vision(HIY"$N"HIY"��$n"HIY"�������ͣ�����һ��"+me->query_temp("weapon")->name()+HIY"�ó��������������ʵʵ�������޷죬����̫�������в��־����С��ϸ��Ʒ⡹��\n"NOR,me,target);
		me->perform_busy(1);
		
		if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/chanzijue", "rev-unarmed", 120, mod))
		{ 
			target->force_busy(2);
			message_vision(HIC "$N"HIC"Ϊ$n"HIC"������������ܲ�������ʱ�����ٳ���\n"NOR,target,me);
			target->set_temp("annie/wd_busy_test_2",time());

		} else	{
			if (weapon = target->query_temp("weapon"))
				message_vision(HIW"$N"HIW"������ʤ��"+weapon->name()+HIW"��$n�Ľ���Ȧ�й��˽�ȥ�������ཻ����Ȧ��ɢ��\n"NOR,target,me);	
			else 
				message_vision(HIW"$N"HIW"�������䣬�й���������$n����Ȧ�й��˽�ȥ���Ʒ絽������Ȧ��ɢ��\n"NOR,target,me);
		}
		
	}

	return 1;
}
