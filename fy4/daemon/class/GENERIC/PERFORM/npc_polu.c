// silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int hit_break(object target, object me, int factor);

int perform(object me, object target)
{
	string msg;
	int extra, my_exp, exp_factor;

	    if(userp(me))
                return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  

	my_exp = (int) me->query("combat_exp");
	exp_factor = 750000000/my_exp;
        if (exp_factor < 100) exp_factor = 100;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����­��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	extra = me->query_skill("nine-moon-claw",1)*3/2+ me->query_skill("nine-moon-steps",1)/2
		+ me->query_skill("nine-moon-force",1)+ me->query_skill("nine-moon-spirit",1);
	extra = extra *4;
	
	
		target->delete_temp("last_damage_from");
		me->add_temp("apply/attack", extra/6);	
		me->add_temp("apply/damage", extra/10);
		msg = HIW"$N�����������������䣬Ѹ���ޱȣ�����Ȱ��۵�$n��ߣ�
��������������֣������ָ��ץ$n$l��\n"NOR ;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -extra/6);
		me->add_temp("apply/damage", -extra/10);
                //<- adjust damage here
                
		if (target->query_temp("last_damage_from")==me && (int)me->query("timer/polu") + exp_factor/20 < time()) {
			//<- Adjust timer here
			message_vision(HIW"$Nһ�е��֣�������ͣ�����Ƽ������ָ����$n��ͷ��������ȥ��\n"NOR,me,target);
		        hit_break(target, me, extra/2);
		}
		if (me->query_busy()<2) 
			me->start_busy(2);    //<- Addjust busy here
		

	return 1;
}

int hit_break(object target, object me, int factor) {
	int resist;
	if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10)
	{
		message_vision(MAG"$N�ҽ�һ���������ѱ�$n��������ס��\n"NOR,target,me);
		resist=target->query("resistance/kee");
		target->set("resistance/kee",0);
		target->receive_wound("kee",factor/2+random(factor)/2);
		target->receive_damage("kee",factor/2+random(factor)/2);
		target->set("resistance/kee",resist);
		target->set_temp("last_damage_from",me);
		COMBAT_D->report_status(target);
	}
	else	
		message_vision(YEL"$N���Ų�æ����ǰ�벽���ܿ�������Ҫ����\n"NOR,target);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : perform polu
���������ݣ������ʼ��ߵ�һ�У�Ϊ��ˮ�书��
�������ۡ���������������ȣ�ֻ������ɱ��
̫ʢ�������롰������ͬʱʹ�á�

HELP
        );
        return 1;
}