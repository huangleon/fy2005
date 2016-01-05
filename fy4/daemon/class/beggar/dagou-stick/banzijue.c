//neon@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);

int perform(object me, object target)
{
	string msg;
	int extra, enhance, lvl, mod, damage, flag;
	int gwxd_dmg;
	object weapon;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("�����־���ֻ���ڸ�ؤ����ӣ�\n");
	}
	lvl = me->query_skill("dagou-stick",1);
	if( lvl < 60 ) {
		return notify_fail("�����־�����Ҫ60���Ĵ򹷰�����\n");
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
	if( target->query_temp("is_unconcious") || target->is_busy() || target->query_temp("marks/pfm/dagou_fallen") ) { 
		return notify_fail("�Է��Ѿ����ܶ����ˣ������˻�������\n");
	}
	if( me->query("force") < 50 ) {	
		return notify_fail("�������������\n");
	}
	if( userp(me) ) {
		me->add("force", -50);
	}
	mod = COMBAT_D->can_busy(me, target, "dagou-stick");	
	if( !mod ) {
		return notify_fail(HIW"�����������ᱻ�����־����Ի�ġ�\n"NOR);
	}
	weapon = me->query_temp("weapon");

	//	extra = 180*2.1 + 150 = 528
	//	enhance == 200 + 45	
	extra = me->query_skill("staff");
	enhance = 200 + me->query_skill("dagou-stick",1)/4;
	if( target->query_temp("annie/beggar/6") == "ban" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		enhance *= 2;
		flag = 1;
		target->delete_temp("busy_timer/dagou-stick");
		mod = COMBAT_D->can_busy(me, target, "dagou-stick");	
		msg = YEL"\n$N����"+ weapon->name() + YEL"��Ȼ����һ�գ������ѵ�ˮ����������$n"YEL"���̡�\n" NOR;
	} else {
		msg = YEL"\n$N"YEL"��׼$n"YEL"����������������"+ weapon->name() + YEL"�����ѵ�ˮ����������$n"YEL"���̡�\n" NOR;
	}
	message_vision(msg, me, target); 
	if( COMBAT_D->do_busy_attack(me, target, "dagou-stick/banzijue", "step", enhance, mod) ) {
		msg = HIG"\nֻ��"+ weapon->name() + HIG"���ڵ��£����ᵯ��$n"HIG"�ƺ���һ����������ȥһ����\n"
			HIR+ weapon->name()+HIR"��ž����һ�����ݺ�����$n"HIR"�ֹ��ϣ�"NOR"\n\n"
			WHT"���ų����ҽУ�$n��ͨһ�µ��ڵ��ϣ�\n\n"NOR;
		if( me->query("cps") < random(target->query("cps")*3) && !flag ) {
			msg +=CYN"$N����$n�۵��ڵ��ϴ����Ц������ֱ��������\n��������������˵�����ֲ��ù�����Ҫ�����ȶ���������\n"NOR;
			if( ANNIE_D->check_buff(me, "fastcast") > 0) {
				me->perform_busy(2);
			} else {
				me->perform_busy(3);
			}
		} else {
			if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
				me->perform_busy(1);
			} else {
				me->perform_busy(2);
			}
		}
		//Beat down enemy
		target->force_busy(3);
		// 	180 + random(180) + My_LEvel -- 320+ random(180);
		damage = F_LEVEL->get_level(me->query("combat_exp")) + lvl + random(lvl);  
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		target->receive_damage("kee", damage, me);
		target->set_temp("busy_timer/dagou-stick", time());
		target->set_temp("marks/pfm/dagou_fallen", 1);
		call_out("get_up",5, me, target);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me, target, 1);
	} else {
		me->add_temp("apply/attack", lvl);
		me->add_temp("apply/damage", extra/2);
		me->add_temp("marks/pfm_dagou", 1);
		msg = HIR"\n�ۼ�$nѸ�ٱ任������$Nֻ����ʽͻ����һ�����ֻӳ���\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
		me->add_temp("marks/pfm_dagou", -1);
		me->add_temp("apply/attack", -lvl);
		me->add_temp("apply/damage", -extra/2);
		
		if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
			me->perform_busy(1);
		} else {
			me->perform_busy(2);
		}
	}
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 ) {
		damage = me->query_busy();
		if( random(100) < F_ABILITY->check_ability(me, "doggie_tail", 1)*2 + 20) {
			// 20% + 20%
			me->stop_busy();
			msg = YEL"$N"+YEL"�����촽��ֻ��������δ����˵��������һ�У�\n"NOR;
			message_vision(msg, me, target);
			gwxd_dmg = F_ABILITY->check_ability(me,"3_gwxd_add",3)*15;
			me->add_temp("apply/damage", gwxd_dmg);
			COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
			me->add_temp("apply/damage", -gwxd_dmg);
		}
		me->perform_busy(damage);
	}
	return 1;
}

void get_up(object me, object target)
{
	if( !target ) {
		return;
	}
	target->delete_temp("marks/pfm/dagou_fallen");
	if( !living(target) ) {
		return;
	}
	message_vision(YEL "\n\n$N�ڵ��ϴ��˼�������������ʹ�Ǳ�������������������\n\n" NOR, target);	
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
