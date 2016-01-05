// silencer@fengyun4. workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod, duration;
	int damage;
	object ob;

	if( me->query("class") != "shenshui" ) {
		return notify_fail("ֻ����ˮ�����Ӳ���ʹ����׷�����ľ�����\n");
	}
	extra = me->query_skill("nine-moon-steps", 1);
	if( extra < 180 || me->query_skill("nine-moon-claw", 1) < 200 || me->query_skill("nine-moon-spirit", 1) < 200 ) { 
		return notify_fail("��׷��ʽ����Ҫ180����������200��������ץ��200���Ů�񹦡�\n");
	}
	if( me->query_skill_mapped("force") != "nine-moon-force" ) {
		return notify_fail("��׷��ʽ����Ҫ�����ľ�����ϡ�\n");
	}
	if( me->query_skill_mapped("unarmed") != "nine-moon-claw" ) {
		return notify_fail("��׷��ʽ����Ҫ������צ����ϡ�\n");
	}
	if( ob = me->query_temp("weapon") ) {
		if( ob->query("skill_type") != "unarmed" ) {
			return notify_fail("��׷��ʽ���ǿ����书��\n");
		}
	}
	duration = me->query("timer/pfm/zhuimin") + 300 - time();
	if( duration > 0 ) {
		return notify_fail("����Ҫ�ȴ�"+duration+"������ٴ�ʹ�á�׷��ʽ����\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("��׷��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	message_vision(HBRED+HIW"$N"HBRED+HIW"һ����Ц������չ�����������Ű��Է�λ����Ȧ�ɽ���\n"NOR,me,target);
	if( !target->is_busy() ) {
		if(COMBAT_D->do_busy_attack( me, target, "nine-moon-steps/lianhuanbu", "rev-unarmed", 100, 10) ) {
			message_vision(WHT"�������$n"NOR+WHT"���Ѳ�׽����$N�����٣�$n"NOR+WHT"��ʧɫ�������޴�!\n"NOR, me, target);
			target->force_busy(1);
		} else {
			message_vision(YEL"$n"NOR+YEL"��̤���ţ�һȦ��һ�������ƺ���������\n\n"NOR, me, target);
		}
	}

	// 2.7M 900	
	// 6.4M 200*2 + 180 + 180 + 200*2 + 103 *3 = 1469
	// full 200*2  +180 + 180 + 200*2 + 140 *3 = 1580
	extra = me->query_skill("nine-moon-claw",1)*2 
		+ me->query_skill("nine-moon-steps",1)
		+ me->query_skill("nine-moon-force",1)
		+ me->query_skill("nine-moon-spirit",1)*2
		+ F_LEVEL->get_level(me->query("combat_exp"))*3;
			
	// + atk 240 -> 308, dmg 240 -> 308, a normal one-hit perform.	
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/4);
	msg = HIW"\n$N"HIW"��������������Ȱ��۵�$p"HIW"��ߣ���һ�µ������������䣬Ѹ���ޱȡ�\n����̽���������֣������ָ��ץ$n��\n"NOR ;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/4);		

	if( target->query_temp("damaged_during_attack")	) {
		me->set("timer/pfm/zhuimin", time());
		msg=MAG"$n"NOR MAG"ֻ�������������$N��ָ����ˮ��к�ذ������Լ�����������\n\n"NOR;
   		msg += RED"$n"NOR RED"��ͷһ�����Ų����Ʋ��ȡ�����\n\n"NOR;
		msg += HIW"$N"HIW"��������ָ�Ⱪͻ��Ŀ¶����֮ɫ��Ю�����Կ��з��˶��£�\n���Ƽ������ָ����$n"+HIW"��ͷ��������ȥ��\n\n"NOR ;
		message_vision(msg, me, target);
		if( target->query("kee") < 5000 && !target->query("boss") && !target->query("big_boss") && target->query("kee") < target->query("max_kee")/5 ) {
			message_vision(HIR"ֻ����һ���Һ���$N��ָ��û��$n"HIR"ͷ­��$n"HIR"����Ѫ��Ȫӿ���鴤���£����ڵ��ϡ�\n"NOR, me, target);
    		// Most of times it's death sentence
    		target->receive_damage("kee", 6000, me);
    		message_vision(HIW"\n$N"HIW"������צ����������$n"HIW"���ų����ָ�⣬¶��΢΢Ť����Ц�ݡ�\n\n"NOR, me, target);
    		COMBAT_D->win_lose_check(me, target, damage);
		} else {	// +atk 325, +dmg 1580, and full hit damage.
  			me->add_temp("apply/attack", extra/3);	
	  		me->add_temp("apply/damage", extra);
	  		target->add_temp("marks/full_hit_damage", 1);
  			msg = HIW"$n��ʧɫ���������ӣ���ǿ�ܿ��˶���Ҫ����\n"NOR;
	  		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
  			target->add_temp("marks/full_hit_damage", -1);
  			me->add_temp("apply/attack", -extra/3);
  			me->add_temp("apply/damage", -extra); 	 
			if( !target->query_temp("damaged_during_attack") ) {
				message_vision(HIW"$n"HIW"��Σ���ң������ܿ�������֮����$Nһ�����У�������������ץ������׶���\n"NOR, me, target);
			}
		}
	}

	me->perform_busy(2);
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