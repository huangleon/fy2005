// Silencer @ FY4 workgroup. Aug.2004

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int stage, force, lvl, duration, ability;
	object obj, *mem, target2;
	int extra_amount;
	string msg;
	mapping buff;

	if( me->query("class") != "yinshi" ) {
		return notify_fail("�����ľ����ǵ����ȵĲ���֮�ա�\n");
	}
	lvl = me->query_skill("iceheart",1);
	if( lvl < 50 || me->query_skill("celecurse",1) < 50 ) {
		return notify_fail("�����ľ�����Ҫ50���ı��ľ���ͨ�콵��\n");
	}
	if( me->is_fighting() ) {
		return notify_fail("ս�����޷�ʹ�á����ľ���\n");
	}
	if( !objectp(obj = present(target, environment(me))) ) {
		return notify_fail("����û������ˡ�\n");
	}
	if( !obj->is_character() || obj->is_corpse() ) {
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me) {
		target2 = target;
		if( objectp(target->query("possessed")) ) { // Spirit
			if( !userp(target->query("possessed")) ) {
				return notify_fail("�����ľ���ֻ�����ڶ��ѡ�\n");
			} else {
				target2 = target->query("possessed");
			}
		}
		mem = me->query_team();
		if( (!pointerp(mem) || member_array(target2,mem) == -1 ) && target2 != me ) {
			return notify_fail("�����ľ���ֻ�����ڶ��ѡ�\n");
		}
	}
	
	if( ANNIE_D->check_buff(target, "gks") ) {
		return notify_fail("�����Ѿ���ʹ�����Ƶ��ķ��ˡ�\n");
	}
	if( me->query("force") < 400 ) {
		return notify_fail("�����ľ���������Ҫ400��������\n");
	}
	if( userp(me) ) {
		me->add("force", -400);
	}
	// SCROLL ADVANCE PERFORM, 
	stage = me->query("scroll/celecurse_buffup") > 0 ? me->query("scroll/celecurse_buffup") : 1;
	if( stage >= 4 && me->query_skill("celecurse", 1) >= 200 && lvl >= 150) {
		amount = 2500;
	} else if( stage >= 3 && lvl >= 150) {
		amount = 1500;
	} else if( stage >= 2 && lvl >= 110 ) {
		amount = 900;
	} else {
		amount = 300;
	}

	// 1-10, add 5%-50%
	ability = F_ABILITY->check_ability(me,"buffup_add",2);
	amount = amount * (100 + ability*5)/100;
	duration = 600;
	if( target == me ) {
		extra_amount = F_ABILITY->check_ability(me,"3_buffup_add",3)*100;
		msg = HIW"$N�����������һ��Ԫ���������˿�����������ľ��С����ľ�����\n"NOR;
	} else {
		extra_amount = F_ABILITY->check_ability(me,"3_buffup_add",3)*50;
		msg =  HIW"$n�����������һ��Ԫ���������˿�����������ľ��С����ľ�����\n"NOR;
		msg += WHT"$n���Ƶ���$N���ģ�����ԴԴ�����ش����Ĵ���������\n"NOR;
	}
	buff =
		([
			"caster": me,
			"who":  target,
			"type": "kee",
			"att":	"bless",
			"name":	"���ľ������ľ�",
			"buff1":"gin",
			"buff1_c":extra_amount,
			"buff2":"kee",
			"buff2_c":amount+extra_amount,
			"buff3":"sen",
			"buff3_c":extra_amount,
			"time":  900 ,
			"buff_msg": msg,
			"special_func":1,
		]);
		
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
	return 1;
}