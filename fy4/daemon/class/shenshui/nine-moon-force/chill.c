// 	Silencer@fy4 workgroup
//	100 + random(100) damage shield and parry shield

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
	int extra;
	mapping buff;
	string msg;

	if( me->query("class") != "shenshui"&& userp(me) ) {
		return notify_fail("ֻ����ˮ�����Ӳ���ʹ���������������ľ�����\n");
	}
	if( ANNIE_D->check_buff(me, "damageshield") || me->query_temp("damage_shield") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
	if( me->query_skill("nine-moon-force", 1) < 150 || me->query_skill("nine-moon-spirit", 1) < 135 ) {
		return notify_fail("��������������Ҫ150�������ľ���135���Ů�񹦡�\n");
	}
	if( me->query("force") < 300 ) {
		return notify_fail("��������������Ҫ300��������\n");
	}
	if( userp(me) ) {
		me->add("force", -300);
	}
	// L60 - L140
	extra = F_LEVEL->get_level(me->query("combat_exp"));
	extra=  extra/2;
	extra = COMBAT_D->magic_modifier(me, target, "kee", extra);
	// For claw and sword hit_ob, it's 30-70 extra wound
	// For claw and sword parry_ob, it's 15-35 extra damagee
	// For ob_hit shield, it's 15-35 extra damage.
	if( me->query_skill("qingpingforce",1) < 150 && userp(me) ) {
		msg = BMAG + HIM"$N�Ŀ��Ϣ����������ľ���һ�㵭����������$N��Χһ�����š�\n"NOR;
		buff = ([
			"caster": me,
			"who": me,
			"type": "damageshield",
			"att": "bless",
			"name": "�����ľ���������",
			"buff1": "nine-moon-force_poison",
			"buff1_c": extra,
			"time": 300,
			"buff_msg": msg,
			"disa_msg": MAG"$N��Χ��������ɢȥ�ˡ�\n"NOR,
			"disa_type": 1,
		]);
	} else {
		msg = BMAG + HIM"$N�Ŀ��Ϣ����������ľ���һ�㵭������������������������$N��Χ��\n"NOR;	
		buff = ([
			"caster": me,
			"who": me,
			"type": "damageshield",
			"att": "bless",
			"name": "�����ľ���������",
			"buff1": "nine-moon-force_poison",
			"buff1_c": extra,
			"time": 300,
			"buff_msg": msg,
			"disa_msg": MAG"$N��Χ��������ɢȥ�ˡ�\n"NOR,
			"disa_type": 1,
			"shield_type": "kee",
			"shield_amount": extra/2,
			"shield_desc": MAG"$n�ƺ�մ����$N��Χ�Ķ����ֽſ�ʼ�����������\n"NOR,
		]);
	}
	ANNIE_D->buffup(buff);
	return 1;
}