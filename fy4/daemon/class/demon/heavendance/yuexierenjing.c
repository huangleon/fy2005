
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

	string *event1_msg=     ({
	CYN"\n����֮�У�$Nִ��$w"CYN"�������裬���˷·���������֮���£�ƮƮ��������֮��ѩ��\n�����������ֻص�һʽ�������ѩ��\n"NOR,
	MAG"\n�������ɵ�Ʈת����������ı�����ǳǳ���£��������ﻨ�䡣\n�������ﻨ�������һ����\n"NOR,
	RED"\n$N�ֻ�������������$w"RED"�����񶯣�ʹ���ˣ���Ӱҡ�죢��\n�����ӳ���£���Ӱ������Ӱ���ڷ���ҡ�ڲ�����\n����������һĨ�ʺ���������ŵ�Ӱ���䡣\n"NOR,
	WHT"\n�轥����ֹ�ˣ�����ǰ��һ�ж�������ȥ�����ڵ�Ω��������ǹ���¼ŵ����¡�\n����������粻��������������顣�ϸ�ɢ��Ƴ��ѡ���\n��Ժ��б�˾���\n"NOR,
	});

int perform(object me, object target)
{
	object weapon;
	mapping buff;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����б�˾���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (me->query_skill("heavendance",1) < 200 && userp(me))	// due research: 10x -> 200
		return notify_fail("��������ֻص�����Ϊ������ʩչ����б�˾�����\n");

	buff =
	([
		"caster":me,
		"who": me,
		"type":"prtshield",
		"att":"bless",
		"name":"�����ֻص�������б�˾�",
		"shield_type":"force",
		"shield_amount":10000,
		"shield_desc":WHT"$n��߷���һ����ϵ�΢�⣬��$N�������⡣\n"NOR,
		"time":  40,
		"buff_msg": " ",
		"disa_msg": " ",
	]);
				
	ANNIE_D->buffup(buff);
	weapon = me->query_temp("weapon");
	message_vision( WHT "$NէȻ������������������������ɫ�����޷��ҵĵ��⣬���޷ɽ�����Ѫ��\n" NOR, me,target);
    call_out("do_yuexie", 1, me,target,0,weapon);

	me->start_busy(2);

	return 1;
}

int do_yuexie(object me,object target,int count,object weapon)
{
	int i;
	if (!me)
		return 0;
	if(!target||!me->is_fighting(target)||environment(target)!=environment(me))
	{
		ANNIE_D->debuff(me,"prtshield");
		return 0;
	}
	if(!present(weapon,me)||weapon->query("equipped")!="wielded")
	{
		ANNIE_D->debuff(me,"prtshield");
		return 0;
	}
	
	me->stop_busy();
	me->set_temp("annie/perform_heavendance",1);
	i=me->query_skill("heavendance",1);
	me->add_temp("apply/damage",i*(count+1));
   	COMBAT_D->do_attack(me,target, TYPE_PERFORM,event1_msg[count]);
	me->add_temp("apply/damage",-i*(count+1));
	me->delete_temp("annie/perform_heavendance");
	me->perform_busy(2);
	if (count < 3)
	{
		count++;
	    call_out("do_yuexie", 1, me,target,count,weapon);
	}
	else
	{
		ANNIE_D->debuff(me,"prtshield");
		me->start_busy(1);	// immune to parry busy
	}
	return 1;
}

