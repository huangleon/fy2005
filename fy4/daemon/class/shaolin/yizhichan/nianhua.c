//mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
    int extra,i, enp, ext, enf, damage;
	string *perform_msg=({
  BBLU + YEL"һ��ָ��������Ϣ��Ϯ��$n��\n"NOR,
  BBLU + YEL"\n��ͬ����������󳪣�ָ���������������͵͵�������\n"NOR,
  BBLU + YEL"\n������ָ������������¶�Ļ��꣬Ȼ��¶�����ʱ������Ҳ���Ʈɢ�ˡ�\n\n"NOR,
	});

    if(me->query("class")!="shaolin")
	return notify_fail("�黨�����־���������ô���ܻ�ʹ�أ�\n");

    extra = me->query_skill("yizhichan",1);
    if(extra<170) return notify_fail("�黨��Ҫ170����һָ����Ϊ��\n");

    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
	return notify_fail("�黨ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (target->query("sen")<= target->query("max_sen")/2)
		return notify_fail("�����ķ��黨ʾ�ڣ��������Ƶж������ˣ������˴������˰ɡ�\n");

    message_vision(BBLU + HIY"\n$N����ʳ����ָ�����ס���黨֮״�����ֻ�����������$n���˹�ȥ��\n"NOR,me,target);

	damage =0;
	
	for (i=0;i<3;i++) {
		msg = perform_msg[i];	
		enf = me->query_skill("force");			// 400
		ext = extra * extra* extra+me->query("combat_exp"); // 170^3+ my_exp= 4.9M + my_exp
		enp = target->query("combat_exp");
		message_vision(msg,me,target);
		if(random(ext+enp)>enp)
		{
		    damage = damage + enf + random(enf*extra)/200;		// 400+random(680)
		}
	}
	
	if (damage > 0) {
		message_vision(HIR"$n��һ����͵�ָ��һ����ֻ����ͷ���һ����\n"NOR,me,target);
		damage = COMBAT_D->magic_modifier(me, target,"sen", damage);     
	    target->receive_damage("sen",damage ,me );	
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
	}
	else
	    message_vision(HIC"$n����ָ�����ƣ�����������������һ���� \n\n"NOR,me,target);
	
	
	me->perform_busy(3);
    return 1;        
}     


