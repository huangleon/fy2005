// tie@fengyun
//ʳ֥Ӣ������Ȫ�����ȹ�֦��������
//�����£��λ�Ԫ���������Σ���Ƿ�����档
//��δ�ƣ�����ǧ��������ɽ������

// Silencer@fengyun	June.2005
//	inherent +20% from six-sense
// no +atk, +dmg, 1st 100, 2nd 100, 3rd 500+200
//	compared to FY4 1st 150, 2nd 150, 3rd 1100

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i, apply, n;
	int chance;
	object weapon;
	extra = me->query_skill("shortsong-blade",1);
	if ( extra < 30) return notify_fail("���̸賤�Ρ���Ҫ30���Ķ̸赶����\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
		return notify_fail("���̸賤�Ρ���Ҫ����ķ�����ϣ�\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���̸賤�Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	weapon = me->query_temp("weapon");
	
	target->set_temp("no_check_pfm_win",1);
	
	n =2;
	chance = 10;
	chance = chance + me->query_temp("pfm/legend_berserk");
	
	if (me->query("timer/pfm/legend_3hit")+ 60 < time())
		chance = 100;

//	CHANNEL_D->do_sys_channel("sys", "chance is "+ chance + "\n");
	
	if (me->query("class")!="legend") {
		msg = HIY "$Nʹ���̸赶���еġ��̸賤�Ρ���һ��������ʽ�����е�"+ weapon->name()+  HIY"�������$n"HIY"������һ������" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	        target->set_temp("skip_damage_record",1);
	        
	        msg = HIY  "�ڶ�����" NOR;
	        me->add_temp("apply/damage",extra);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	        me->add_temp("apply/damage",-extra);
		
		if (extra >= 200 && chance > random(100)) {
			me->add_temp("apply/damage",extra);
	        	msg = HIY  "$N�������ɣ����ֻӳ���������" NOR;
	        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/damage",-extra);
			me->set("timer/pfm/legend_3hit",time());
		} 
	} 
	else 
	{
		me->add_temp("apply/damage",extra);
		msg = HIY  "\n$Nʹ���̸赶���еġ��̸賤�Ρ���һ��������ʽ��
���е�"+ weapon->name()+ HIY "�������$n"HIY"������һ������ʳ֥Ӣ������Ȫ�����ȹ�֦��������\n" NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		target->set_temp("skip_damage_record",1);

       	msg = HIY  "\n�ڶ������������£��λ�Ԫ���������������桱\n" NOR;
       	message_vision(msg,me,target);
       	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
 		me->add_temp("apply/damage",-extra);        	
	
		if (extra >=200 && chance > random(100)) {	
			apply = extra;
			me->add_temp("apply/damage",apply);
			msg = HIY  "\n$N�������ɣ����ֻӳ�������������δ�ƣ�����ǧ��������ɽ������\n" NOR;
        	message_vision(msg, me, target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
			me->add_temp("apply/damage",-apply);	
			me->set("timer/pfm/legend_3hit",time());
		}
	}
	
		if (objectp(target)){
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
			
			me->delete_temp("pfm/tx-hit-dodged");
			me->delete_temp("pfm/tx-hit-parried");
			if (target->query_temp("marks/parried"))
				me->set_temp("pfm/tx-hit-parried",time());
			else if (target->query_temp("marks/dodged"))
				me->set_temp("pfm/tx-hit-dodged",time());
			
			if (wizardp(me))
				tell_object(me, "target dodged = " + target->query_temp("marks/dodged") 
					+ ", target parried = "+target->query_temp("marks/parried") + "\n");
		
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

			       
	me->perform_busy(n);
	return 1;
	
}
       	