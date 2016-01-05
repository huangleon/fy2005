// Silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int stone_done(object me, object caster);

int perform(object me, object target)
{
	int skill, timer, duration;
	int chance, num, time;
	mapping buff;

	if( me->query("class") != "fugui" ) {
		return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ���������ڡ��ľ�����\n");
	}
	skill = me->query_skill("henglian", 1);
	if( skill < 180 ) {
		return notify_fail("��������Ҫ180���ĺ�������\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("��ֻ�ܽ������������Լ������ϡ�\n");
	}
	timer = 600;		
	duration = me->query("timer/pfm/hl_erchuan") + timer-time() - F_ABILITY->check_ability(me,"erchuan_add")*45;
	if( duration > 0 ) {
		return notify_fail("��������ɢ��һʱ�޷��ٴ�ʹ�ö������񹦣���"+duration+"�룩��\n");
	}
	if( me->query_skill_mapped("force") != "skyforce" ) {
		return notify_fail("������Ψ��ʹ�ñ̿��ķ�����Ч��\n");
	}

	chance = F_ABILITY->check_ability(me, "3_erchuan_add", 3) * 10;
	if( random(100) < chance ) {
		num = 6;
		time = 60;
	} else {
		num = 3;
		time = 30;		
	}
	me->set_temp("pfm/fg_erchuan", num);
	me->set("timer/pfm/hl_erchuan", time());
	buff =
		([
			"caster": me,
			"who": me,
			"type": "stoneskin",
			"att": "bless",
			"name": "������������",
			"time": time,	
			"buff_msg": YEL"$Nȫ��ÿһ���ǽں�Ȼȫ����������������з���֮������\n"NOR,
			"warn_msg": WHT"��ĺ����������ںܿ��ҪʧЧ�ˡ�\n"NOR,
			"finish_function": (: stone_done :),
		]);
	ANNIE_D->buffup(buff);
	return 1;
}

int stone_done(object me, object caster)
{
	me->delete_temp("pfm/fg_erchuan");
	return 1;
}