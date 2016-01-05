//modified pfm msg by still
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod, lvl, enhance;
	int skill, myexp, yourexp, count, i;
	int gwxd_dmg;
	object weapon, hisweapon;
	mapping buff;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("�����־���ֻ���ڸ�ؤ����ӣ�\n");
	}
	lvl = (int) me->query_skill("dagou-stick", 1);
	if( lvl < 100 ) {
		return notify_fail("�����־�����Ҫ100���Ĵ򹷰�����\n");
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
	hisweapon=target->query_temp("weapon");
	if( !hisweapon ) {
		if( target->query_temp("annie/beggar/6") == "tiao" && target->query_temp("annie/beggar/time")+8 >= time() ) {
			target->delete_temp("annie/beggar/time");
			message_vision(CYN"$N�����ߵ�$n���󣬷���������Ȼ��$n��ȥ��" NOR, me, target);
			skill = me->query_skill("betting",1);
			myexp = me->query("combat_exp");
			yourexp = target->query("combat_exp");
			count = me->query_agi()/10;
			i = 0;
			if( myexp/2 + random(myexp*4) <  yourexp ) {
				message_vision(YEL"$N��֪��ʱȴ��ת����$n�����$n���˸��ա�\n"NOR,target,me);
			} else {
				while( count-- ) {
					if( me ->is_busy() ) {
						continue;
					}
					msg = BLU"��Ӱ�зɳ���"+chinese_number(i+1)+"��\n"NOR;
					me->add_temp("apply/damage", lvl);
					COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
					me->add_temp("apply/damage", -lvl);
					i++;
				}
			}
			me->perform_busy(1);
			return 1;
		} else {
			return notify_fail("�Է�û���������޴�ʹ�á����־�����\n");
		}
	}
	if( hisweapon->query("nodrop_weapon") ) {
		if (target->query_temp("annie/beggar/6") == "tiao" && target->query_temp("annie/beggar/time")+8 >= time() ) {
			target->delete_temp("annie/beggar/time");
			message_vision(CYN"$N�����ߵ�$n���󣬷���������Ȼ��$n��ȥ��"NOR, me, target);
			skill = me->query_skill("betting", 1);
			myexp = me->query("combat_exp");
			yourexp = target->query("combat_exp");
			count = me->query_agi()/10;
			i = 0;
			if( myexp/2 + random(myexp*4) <  yourexp ) {
				message_vision(YEL"$N��֪��ʱȴ��ת����$n�����$n���˸��ա�\n"NOR, target, me);
			} else {
				while( count-- ) { 
					if( me->is_busy() ) {
						continue;
					}
					msg = BLU"��Ӱ�зɳ���"+chinese_number(i+1)+"��\n"NOR;
					me->add_temp("apply/damage", lvl);
					COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
					me->add_temp("apply/damage", -lvl);
					i++;
				}
			}
			me->perform_busy(1);
			return 1;
		} else {
			return notify_fail("�����������û����������\n");
		}
	}
	enhance = 150;
	if( target->query_temp("annie/beggar/6") == "tiao" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		enhance *= 2;  // +100%
		target->delete_temp("annie/beggar/time");
	}
	if( target->query_temp("marks/disarmed")+60 > time() && enhance == 150 ) {
		// slll������־�����60secӰ��
		return notify_fail("�Է����ڷ����ĺ��ϣ�ûϣ����������\n");
	}
	mod = COMBAT_D->can_busy(me, target, "dagou-stick");
	if( !mod ) {
		mod = 1000;
	}
	if( me->query("force") < 100 ) {
		return notify_fail("�������������\n");
	}
	if( userp(me) ) {
		me->add("force", -50);
	}
	target->set_temp("marks/disarmed", time());
	msg = YEL"\n$N�������������"+weapon->name()+YEL"һת�����һ�����𣡡���ʹ�������־�������ס"
			+hisweapon->name()+YEL"����������\n\n"NOR;
	message_vision(msg, me, target);
	if( COMBAT_D->do_busy_attack(me, target, "dagou-stick/taiozijue", "step", enhance, mod) ) {
		msg = HIG"$nֻ��"+hisweapon->name()+HIG"�������ַɳ���һ�����ղ�ס������"+hisweapon->name()+HIG"�������˳�ȥ��\n"
				+HIG"$n���������"+hisweapon->name()+HIG"�������ӣ�ȴ��$N"HIG"���е�"+weapon->name()+HIG"��һ��������\n"
				+HIG"ֻ����"+hisweapon->name()+HIG"����һ�ߡ�\n"NOR;
		if( hisweapon->unequip() ) {
			buff =
			([
				"caster":me,
				"who":target,
				"type":"disarmed",
				"att":"curse",
				"name":"�򹷰��������־�",
				"buff1":"disarmed",
				"buff1_c":1,
				"time":30,
				"buff_msg":" ",
			]);
			ANNIE_D->buffup(buff);
		}
	}  else {
		msg = WHT"$n"+WHT"������������"+hisweapon->name()+WHT"����һѹ����"+weapon->name()
				+WHT"���˿�ȥ��\n\n"NOR;
	}
	message_vision(msg, me, target); 
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 ) {
		if( random(100) < F_ABILITY->check_ability(me, "doggie_tail", 1)*2 + 20 ) {
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
