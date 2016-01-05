// shiwanshenmo.c   ʮ����ħ
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, n, force;
	int tmp,chance;
	object weapon;
	
	if ( (string) me->query_skill_mapped("dodge") != "meng-steps")
		return notify_fail("��ʮ����ħ����Ҫ���β�������ϣ�\n");
	
	extra = me->query_skill("bat-blade",1);
	if (extra < 100) return notify_fail("��ʮ����ħ����Ҫ100�����𵶷���\n");
	
	tmp = me->query_skill("meng-steps",1);
	if (tmp < 100)	return notify_fail("��ʮ����ħ����Ҫ100�����β�����\n");
	
	if (me->query("class")=="bat") n=0;
		else n=20;
	
	if(userp(me) && me->query_temp("timer/shiwanshenmo")+n > time())
		return notify_fail("��ʮ����ħ����Ҫ����Ƭ�̡���\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ʮ����ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	// 220 + 160
	chance=extra+tmp;
	
	// 110
	if (me->query_skill_mapped("force")=="wuzheng-force" && me->query("class")=="bat")
		force= me->query_skill("wuzheng-force",1)/2;
	
	// atk 220, dmg 160/3 + 220/2 = 160
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra/3+force);
	target->set_temp("no_check_pfm_win",1);
	
	weapon = me->query_temp("weapon");
	msg = MAG  "\n\n$N��������ؼ�ʮ����ħ���ޱ�������һʽ��ʮ������ħ ���缱�������$n��\n" NOR;
	message_vision(msg, me, target);
	
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        target->set_temp("skip_damage_record",1);
    
    	if (chance>random(300)) {
	        msg = HIB  "\n$N"+HIB"����"+weapon->name()+HIB"�ó�����Ĺ⻪����$n��" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		}
		if (chance>random(350)) {
	        msg = HIR  "\n$N"+HIR"����"+weapon->name()+ HIR"�����������ǵĺ�Х��$n"+HIR"��ȥ��" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(400)) {
	        msg = HIW  "\n$N"+HIW"����"+weapon->name()+HIW"��Ȼ��������Ե���������$n��" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(450)) {
	        msg = HIC  "\nʮ����ħ�����ƶ����֣�$N"+HIC"����"+weapon->name()+HIC"����Ī����Ȼ����$n"+HIC"����ǰ��" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		if(!userp(me) && random(10)>3)
                	target->apply_condition("qicaibat",random(10)+10);
        }
	
		me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra/3-force);
        me->set_temp("timer/shiwanshenmo",time());
        

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
	       
        me->perform_busy(3);
        
		return 1;
}

