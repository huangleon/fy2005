// annie 07.2003


#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int do_thyx(int stage, object me,object target,object weapon);

int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill, count, i, level, sic, duration;

	if( me->query("class") != "moon" ) {
		return notify_fail("ֻ����¹��Ĵ��˲���ʩչ�����һ�ߡ���\n");
	}
	skill = me->query_skill("starrain",1);
	if( skill < 200 ) {
		return notify_fail("�����һ�ߡ���Ҫ����200���ĺ���������\n");
	}
	duration = me->query("timer/tianheyixian")+ 300  - time();
	if( duration > 0 && userp(me) ) {
		return notify_fail("�����һ�ߡ��������������޷�����ʩչ,���ٵȴ�"+ duration +"�롣\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�����һ�ߡ�ֻ����ս����ʹ�á�\n");
	}
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if( count < 10 ) {
		return notify_fail("������Ҫ10ö������\n");
	}
	msg = HIW"\n$N"HIW"ĬĬ�Ĵ�ͷ���䣬ü��΢�ۣ���ɫԽ��ѩ�ף���ɫ��һƬ��Ȼ�龲��\n"NOR;
	message_vision(msg,me);
	me->set("timer/tianheyixian", time());
	do_thyx(1, me, target, weapon);
	me->perform_busy(3);
	return 1;
}

/*
skill = 200
stage 1: atk 400, dmg 200
stage 2: atk 400, dmg 400
stage 3: atk 600, dmg 800
stage 4: atk 800, dmg 1600

Total busy time = 8 turns.

*/


int do_thyx(int stage, object me,object target,object weapon)
{
	int i, count, skill, sic, flag, atk, comp, level;
	int no_parry, rate;
	string msg;
	mapping buff;

	if( !me || !target || !me->is_fighting(target) || environment(target) != environment(me) ) {
		return 0;
	}
	if( !present(weapon, me) ) {
		return 0;
	}
	if( weapon->query("equipped") != "wielded" && userp(me) ) {
		return 0;
	}
	if( me->is_ghost() ) {
		return 0;
	}
	me->perform_busy(3);
	if( stage >= 2 ) {
		if( me->query("kee") < me->query("max_kee")/3 || me->query("sen")< me->query("max_sen")/3 || me->query("gin")< me->query("max_gin")/3 ) {
			tell_object(me,"�����˹��أ��Ѿ��޷�ά�����һ���ˡ�\n");
			return 0;
		}
	}
	me->map_skill("throwing","starrain"); // Prevent PPL cheats.
	count = weapon->query_amount();
	if( count < 2 ) {
		return 0;
	}
	if( userp(me) ) {
		weapon->add_amount(-2);
	}
//	write ("stage = "+ stage + "\n");
	switch (stage) {
		case 1: msg = HIW"\n$N"HIW"üͷէչ��̧��ͷ����$n"HIW"��ȻһЦ����Ȼ΢΢�������л�����������â��£�۳�
һ�����߱���$n��\n"NOR;
				break;
		case 2: 
		case 3: msg = HIW"\n�������಻����˿˿��ۻ���$n��\n"NOR;break;
		case 4: msg = HIW"��һɲ�ǣ��·�����������ǻ��������ӱ��и��˲�䣬��񷱳��Ĺ�â�������ݣ���
һ�Ż𻨣���ȼ��������ǳ�������������۾���\n"NOR;
	}

	message_vision(msg, me, target);
	me->stop_busy();
	skill = me->query_skill("starrain", 1);
	// 8 busy for +atk 400-800, +dmg 400-1600 hits --> combined with enforce and weapon and dmg/atk bonus	
	switch( stage ) {
		case 1:
			atk = 300;
			sic = 0;
			break;
		case 2:
			atk = 300;
			sic = 150;
			break;
		case 3:
			atk = 450;
			sic = 300;
			break;
		case 4:
			atk = 600;
			sic = 900;
			break;
	}

	rate = F_ABILITY->check_ability(me,"3_thyx_add",3)*10;
	if( random(100) < rate ) {
		no_parry = 1;
	} else {
		no_parry = 0;
	}

	level = F_LEVEL->get_level(me->query("combat_exp"));
	if( level > 90 ) {
		sic = sic + (level-90)*2;
	}
	me->add_temp("apply/attack",atk);
	me->add_temp("apply/damage",sic);
	me->set_temp("annie/perform_starrain",1);
	me->add_temp("marks/full_hit_damage",1);
	if( no_parry == 1 ) {
		target->add_temp("cant_parry",1);
	}

	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");

	if( no_parry == 1 ) {
		target->add_temp("cant_parry",-1);
	}
	me->add_temp("marks/full_hit_damage",-1);
	me->add_temp("apply/damage",-sic);
	me->add_temp("apply/attack",-atk);
	me->delete_temp("annie/perform_starrain");
	if( stage < 4 ) {
		me->perform_busy(3);
	}
	stage++;
//	write ("stage = "+ stage + "\n");
	if( stage <= 4 ) {
		call_out("do_thyx", 4, stage, me, target, weapon);
	}
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
