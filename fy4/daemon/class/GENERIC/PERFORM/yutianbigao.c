#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra,mod;
	int tmp;
	int basic;
	int i, flag;
	object weapon,*team, *team1;
	mapping buff;
	
	
	if (ANNIE_D->check_buff(me,"fg-afo-ytbg")<1)
		return notify_fail("��ѧ���书��û�д����ؼ���\n");
		
	weapon = me->query_temp("weapon");
	if (!weapon)
		return notify_fail("�����޷�ʹ�ô��ؼ���\n");
				
	extra = me->query_temp("pfm/fg-afo-ytbg");
	
//	write ("extra = " + extra + "\n");	
/*	if ( extra < 140 || me->query_skill("skyforce",1) < 140 || tmp < 120) 
		return notify_fail("������Ҫ140����Ѫսǹ����140���ı̿��ķ���120��������������\n");	*/
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ȸߡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	basic=4;
	
	extra = extra * 60/200;			// coeff adjustion.	half of real ytbg
	
	msg = HIY "\n\n$N"HIY"������" +weapon->name()+ HIY"��أ�����������չ�ᣬһ�ɳ��죬��Ȼʹ����һʽ������ȸߡ���\n"NOR;
	message_vision(msg, me, target);
		
	mod =10;
	 	
	if(COMBAT_D->do_busy_attack( me, target, "xuezhan-spear/yutianbigao", "rev-unarmed", 100, mod))
	{
		message_vision(BLU"���$N"NOR+BLU"Ŀ�ɿڴ�����֪����мܣ�\n"NOR,target);
		target->start_busy(1);
       	me->add_temp("apply/damage",extra);
       	for(i=0;i<basic;i++)
       	{
	   		if (me->is_busy()) continue;
	   		msg = HIY"��Ц���У�$N"YEL"����»��������ֽ�����Ծ��\n"NOR;
	   		
	   		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");		
		}
		me->add_temp("apply/damage",-extra);
		target->stop_busy();
		me->perform_busy(3);	
	}
	else{
		me->perform_busy(2);
		message_vision(YEL"����$Nһ�ۿ���$n"NOR+YEL"�Ĺ��ƣ�$n"NOR+YEL"���ּ�ʧ���������ƣ�\n"NOR,target,me);
		if (!target->is_busy()){
			msg = YEL"$N"NOR+YEL"�˻���$n"NOR+YEL"������\n"NOR;
			target->add_temp("apply/attack", extra);
			target->add_temp("apply/damage", extra);
			COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);
			target->add_temp("apply/attack",-extra);
			target->add_temp("apply/damage",-extra);
		}
	}
	
	ANNIE_D->debuff(me,"fg-afo-ytbg");
	
	return 1;
}



