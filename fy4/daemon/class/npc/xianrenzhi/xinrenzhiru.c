// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ָ·��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra=me->query_skill("xianrenzhi",1);
	if(extra<50)
		return notify_fail("������ָ����Ϊ�������ߡ�\n");	
	if(target->query_temp("till_death/lockup"))
		return notify_fail(target->name()+"�Ѿ������ˣ�\n");	
	if(me->query("force")<200)
		return notify_fail("�����������\n");
	
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("unarmed")/50 + 1;
//	if(me->query("class")!="lama") lvl=lvl/2+1;
	msg = HIR "$Nʹ��������ָ·�ݣ�ָ���絶�����п���$n�Ĺؽ�Ҫ����" NOR;
	if( random(myexp * lvl)+myexp/2 > yourexp )
	{
		message_vision(msg + "\n", me, target);
		msg = BLU"$n��ʧɫ��������ָ��һ���������᲻������\n"NOR;
		message_vision(msg, me, target);
		target->set_temp("till_death/lockup",1);
	      	target->start_call_out( (: call_other, __FILE__, "remove_effect",target:), 8+lvl*2);
		me->add("force",-200);
	}
	else
	{
		me->add_temp("apply/attack",extra/3);	
	        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra/3);	
	}
	me->start_busy(2);
	return 1;
}


void remove_effect(object target)
{
   	target->delete_temp("till_death/lockup");
        message_vision("$N���λζ�����$n��ָ�������������\n");
}
 