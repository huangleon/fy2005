// Silencer@fengyun	June.2005
// ����Ѫ�ε�������һ�е����������书������BUSY��ϣ�2-SB����20��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string forceskill, msg;
	int extra, exp_bonus, i;
	int chance;
	int tmp;
	object weapon, *team, *team1;
	
	weapon = me->query_temp("weapon");
 	extra = me->query_skill("xuezhan-spear",1);
	tmp = me->query_skill("skyforce",1);
    	    	
	if( tmp < 20 || extra < 20 ) {
		return notify_fail("����Ѫ�ε�����Ҫ20����Ѫսǹ���ͱ̿��ķ�!\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("����Ѫ�ε���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}

	exp_bonus = F_LEVEL->get_level(me->query("combat_exp"));
	extra = extra/2 + exp_bonus;
	me->add_temp("apply/attack", extra);    
	me->add_temp("apply/damage", tmp*2);
	msg = YEL  "\n$N"YEL"����"+weapon->name()+YEL"��Ȼ��ת������˲�����������Ҷ����������$n"NOR+YEL"���̹�ȥ��\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -tmp*2);
    
	chance = 20 + F_ABILITY->check_ability(me, "3_lxgd_add", 3) * 3;
 	team1 = me->query_team();
	if(pointerp(team1) && sizeof(team1) > 1 ) {
		team = filter_array(team1, (: present($1,environment($2)) :), me);
		if( pointerp(team) && sizeof(team) > 1 ) {
	    	for( i = 0; i < sizeof(team); i++ ) {
				if( me->is_busy() ) {
					break;
				}
				if( !me->query_temp("weapon") ) {
					break;
				}
				if( team[i] == me ) {
					continue;
				}
				if( random(100) > chance ) {
					continue;
				}
				message_vision(YEL"\n�����Ҷ�ۻ����Ҽ䣬$N������"+team[i]->name(1)+NOR YEL "��󣬷�������һǹ��\n"NOR, me, target);	
				me->add_temp("apply/damage", extra);
			    me->add_temp("apply/damage", tmp*2);
			    COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
			    me->add_temp("apply/damage", -extra);
	    		me->add_temp("apply/damage", -tmp*2);
	    	}
	   	}
    }
    me->perform_busy(2); 
    return 1;
}
