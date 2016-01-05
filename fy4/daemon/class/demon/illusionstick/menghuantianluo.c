#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int do_pfr(object me, object target,int loc);

int do_pfm(object me, object target,int idx,int loc)
{
	string msg;
	int l;

	string *style = ({
"������Ұ����$N�ն�����$w�������Х������$n��$l��",
"�������ѣ���$N����$w������Ӱ���أ���$n����Χס��",
"��ֹ��Ұ����$N��ǰһ�ݣ�����$w���裬��$n���˹�ȥ��",
"��Ӱ���У���$N������������$wͷβ������ִ�$n������Ҫ����",
"�Ϻ����죭��$N����$wһ�٣���������������$n��$l��",
"������Գ����$N����������Ծ������$w���ƶ�����������$n��ȥ��",
"�������ţ���$N��Ӱ����$n�����ζ�������$w������ɨ��$n��$l��",
"��ӥ���ã���$N������������$w���϶��£�Ѹ���ޱȣ�����$n��$l��"});

	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;

	msg = HIY+style[idx]+NOR;

	me->stop_busy();
	l = target->query("kee");
    me->add_temp("apply/attack", idx * me->query_skill("illusionstick",1)/3);
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    me->add_temp("apply/attack", -idx * me->query_skill("illusionstick",1)/3);
	if (me->is_busy())
	{
		loc += 1;
		if (loc < 3)
		{
			message_vision(HIG"$N�������񣬾������ͣ��ȿ�$n��ת�ۼ��ض��Ȼ���\n"NOR,me,target);
			me->stop_busy();
		}
	}
	else if (!target->query_temp("damaged_during_attack"))
		loc += 1;
	me->perform_busy(3);	
	if (target->query("kee") < 1)
	{
		message_vision(HIY"\n$N�Ӻ����꣬�����Լ̣����ν����ȶ�������\n"NOR,me,target);
		return 1;		// Unconcious/Dead
	}
	if (loc >= 3)
	{
		message_vision(HIY"\n$N����ʧ�֣�����ƾ�У����ν����ȶ�������\n"NOR,me,target);
		return 1;		// no enough force
	}
	if (me->query("force") < 50)
	{
		message_vision(HIY"\n$N�Ӻ����꣬�����Լ̣����ν����ȶ�������\n"NOR,me,target);
		return 1;		// no enough force
	}
	me->add("force",-50);
	
	if (idx == 7)
	{
		message_vision(HIG"\n$N����ʹ��һ�֡�����˪�쾹���ɡ������ν����ȶ�������\n\n"NOR,me,target);
		call_out("do_pfr",1,me,target,loc);
		return 1;
	}

	do_pfm(me,target,idx+1,loc);
}


int do_pfr(object me, object target,int loc)
{
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	message_vision(HIG"$N������һ�ڳ���������һ£���֣��ٴλ���һƬ��Ӱ����$n��࣬"NOR,me,target);
	if(random(target->query("combat_exp")) < random(me->query("combat_exp")))
	{
		message_vision(HIG"\n$n�����ۻ����ң���Ȼû�п����κ�������\n\n"NOR,me,target);
		me->perform_busy(2);
		target->perform_busy(1);
		call_out("do_pfm",1,me,target,loc);
	}
	else
		message_vision(HIG"\n$nһ����Ц�������˴�����һ����$N�����ʱ��ȥ��\n\n"NOR,me,target);
	me->perform_busy(2);
	return 1;
}

int do_pfx(object me, object target)
{
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	message_vision(HIY"$N��Ȼһ����ȣ����Է����������Ϲ���ʹ�������Ƕ��ǵ�һʽ������˪�쾹���ɡ���\n"NOR,me,target);
	do_pfm(me,target,0,0);
	return 1;
}


int perform(object me, object target)
{
 	string msg;
 	int extra;
	
 	extra = me->query_skill("unarmed");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���λ����ޡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	message_vision(HIG"$N����"+me->query_temp("weapon")->name()+HIG"�ڵ���������������ν�ɢ���߰˸���Ӱ����$n��"NOR,me,target);

	if(random(target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
		message_vision(HIG"\n����$nֻ���紦�λã�Ŀ�ɿڴ����������š�\n\n"NOR,me,target);
		target->perform_busy(1);
		me->perform_busy(2);
		call_out("do_pfx",1,me,target);
	}
	else
		message_vision(HIG"\n$nһ����Ц�������˴�����һ����$N�����ʱ��ȥ��\n\n"NOR,me,target);
	me->perform_busy(2);
	return 1;
}

