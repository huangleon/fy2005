// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,aaa;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۾���һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("huanhua-sword",1) *3;
	aaa = me->query_skill("huanhua-sword",1) ;
	if ( aaa < 100) return notify_fail("��ģ�佻������ݻ��������죡\n");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("sword") / 100;
	
	if(target->is_busy())
		return notify_fail(target->name()+"���ڷ�����\n");
      	
      	if(random(myexp * lvl) < yourexp )
	{
	        msg=HIR"$N���Ծ�����е�"+ weapon->name() +HIR"���϶��£�"+CYN"���ֵ�һ��---�۾���һ����"+HIR"���羪��֮ʽ����$n��"NOR;
		me->add_temp("apply/attack", extra)/10;	
		me->add_temp("apply/damage", extra)/10;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		message_vision(HIW "ֻ�������һ�����һ����û��������\n"NOR,target);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -extra);
	        target->start_busy(1);    
	        me->start_busy(2);  
	}
	else{
		message_vision(BLU "$N�ֽ����裬$n���۾���һ���ݵĽ����Ŵ��ˣ�ɵ�ճյ�һ��Ҳ������\n"NOR,me,target);
		target->receive_damage("sen",500);
	        target->start_busy(4); 
	     }
      	return 1;
}
