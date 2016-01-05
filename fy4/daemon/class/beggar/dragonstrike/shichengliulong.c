#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, myexp, enemyexp, lvl, chance;
	object weapon, hisweapon;
	int mod;
	mapping buff;
	
	lvl = (int) me->query_skill("dragonstrike",1);
	if( lvl < 90 ) {
		return notify_fail("��ʱ����������Ҫ90���Ľ���ʮ���ơ�\n");	
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("��ʱ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	
	if( ANNIE_D->check_buff(target,"pseudo-busy") ) {
		return notify_fail(target->name()+"�Ѿ�������¶�������û�������\n");	
	}
	mod = COMBAT_D->can_busy(me, target, "dragonstrike");	
	if( !mod ) {
		return notify_fail(HIW"���˹�����տ��ó�ô��пַǵ��֡�\n"NOR);
	}
	lvl = 300;
	msg = HIY"
$N"HIY"ٿȻ�����ĳ�һ�ƣ��䲻����һ�ƣ�ȴ��������������������$n"HIY"����
������С�$n"HIY"��һ���ɣ�$N"HIY"������ǰ�ƣ�˫����������һ����ɽ����
��ѹ��������ֻһ˲֮�䣬��������ŭ����ӿ���Ʋ��ɵ���������һ����
�εĸ�ǽ����$n"HIY"��ǰ���塣\n"NOR;

	message_vision(msg, me, target);
	
	if( COMBAT_D->do_busy_attack( me, target, "dragonstrike/shichengliulong", "unarmed", lvl, mod) || target->query("race") != "����" ) {
		message_vision(BLU"$n"NOR+BLU"ֻ���Ʒ����棬��Ϣ���͡�\n"NOR, me, target);
		buff =
		([
			"caster":me,
			"who":target,
			"type":"pseudo-busy",
			"att":"curse",
			"name":"����ʮ���ơ�ʱ������",
			"time":8,
			"buff1":"pseudo-busy",
			"buff1_c":1,
			"buff_msg":"",
			"condition_type":"<���ٶ�>",
			"warn_msg":" ",
			"disa_type":0, 
		]);
		ANNIE_D->buffup(buff);	
		target->set_temp("busy_timer/dragonstrike", time());
	
		chance = random(6);
		if( wizardp(me) ) {
			chance = me->query("marks/scll");
		}
//		chance = 2;
		if( me->query_skill("dragonstrike",1) >= 150 ) {
			switch( chance ) {
				case 0:		
					message_vision(WHT"$n"NOR+WHT"��Ц�в������˿�����ң�ٲȻ��и�ɻ���\n"NOR, me, target);
					break;		// Normal, NO special effect (SE). 
				case 1:
					message_vision(YEL"$n"NOR+YEL"бб�������ߣ�һʱ����·���Ŵ󿪣�����ʱ����\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "cuo");
					break;		// SE: CHUO can do x2
				case 2:
					message_vision(YEL"$n"NOR+YEL"����էȻһ����$N"NOR+YEL"�����Ӷ��������о����յرܿ����С�\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "ban");
					break;		// SE BAN has double rate
				case 3:
					message_vision(YEL"$n"NOR+YEL"������У����˷��������ƻ���$N��\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "yin");
					break;		// SE YIN has double dmg
				case 4:
					message_vision(WHT"$n"NOR+WHT"�������ϣ���ת�ŵ����켲���۽�$N��\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "zjbl");
					break;
				case 5:
					if( target->query_temp("weapon") ) {
						message_vision(YEL"$n"NOR+YEL"����ð�գ�������"+target->query_temp("weapon")->name()+NOR+YEL"С�Ĳ�⣬�мܴ��С�\n"NOR, me, target);
					} else {
						message_vision(YEL"$n"NOR+YEL"����ð�գ��������أ��мܴ��С�\n"NOR, me, target);
					}
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "tiao");	// SE: DISARM
					break;
			}
		}
	} else {
		message_vision(WHT"$n��������������Բ��ס��ǰ�����������Ʈ����ˡ�\n"NOR, me, target);
		me->perform_busy(1);
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
