//silencer@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, myexp, enemyexp, lvl;
	int gwxd_dmg;
	object weapon,hisweapon;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("�����־���ֻ���ڸ�ؤ����ӣ�\n");
	}
	lvl = (int)me->query_skill("dagou-stick", 1);
	if( lvl < 20 ) {
		return notify_fail("�����־�����Ҫ20���Ĵ򹷰�����\n");
	}
	if( me->query_skill_mapped("force") != "huntunforce" ) {
		return notify_fail("�����־�����Ҫ�����ķ�����ϡ�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	weapon = me->query_temp("weapon");
	msg = YEL"\n$N"NOR+YEL"ӭ��һ����ȥ��������ز�ã������������裬
����ζ������Ǵ������̣�ȴ������$n"NOR+YEL"����·����\n"NOR;

	if( target->query_temp("annie/beggar/6") == "cuo" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		msg += HIY"���ذ�Ӱ�к�Ȼ�ɳ�һ�У�������$n"HIY"������֮�У�\n"NOR;
		lvl *= 2;
		target->delete_temp("annie/beggar/time");
	}

	//	atk, 180	marks/pfm_dagou
	message_vision(msg, me, target);
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl*2);
	me->add_temp("marks/pfm_dagou", 1);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, "");
	me->add_temp("marks/pfm_dagou", -1);
	me->add_temp("apply/attack", -lvl);
	me->add_temp("apply/damage", -lvl*2);
	
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 && !me->is_busy() ) {
		if( random(100) < F_ABILITY->check_ability(me,"doggie_tail",1)*2 + 20 ) {
			// 20% + 20%
			msg = YEL"$N"+YEL"�����촽��ֻ��������δ����˵��������һ�У�\n"NOR;
			message_vision(msg, me, target);
			gwxd_dmg = F_ABILITY->check_ability(me,"3_gwxd_add",3)*15;
			me->add_temp("apply/damage", gwxd_dmg);
			COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
			me->add_temp("apply/damage", -gwxd_dmg);
		}
	}
	if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
		me->perform_busy(1);
	} else {
		me->perform_busy(2);
	}
	return 1;
}


/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
