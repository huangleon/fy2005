// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;

	extra = me->query_skill("longfenghuan",1) ;
	if ( extra< 100) return notify_fail("�������˫�����������죡\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������˫�ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (extra> 185 && me->query("class")=="assassin") extra *= 3;
		else if (extra >150 && me->query("class")=="assassin") extra = extra *5/2;
			else extra = extra*2;
				

	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", extra/3);	
	me->add_temp("apply/damage", extra);
	msg = HIR "$N˫��һ��һ�С�����˫�ɡ������е�"+ weapon->name()+ HIR"�ɳ�����$n��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra/3);
	me->add_temp("apply/damage", -extra);

        if(extra > 550 &&  target->query_temp("damaged_during_attack")) {
        	if (target->query_busy()<=1) target->start_busy(1);
		message_vision(WHT"$N���ҵ���ͷת�򣬲�֪���롣\n"NOR,target);
		}
		
	if ( me->query_skill_mapped("force") == "jingxing"
		&& me->query_skill("jingxing",1)>=150 && me->query("class")=="assassin")
			message_vision(YEL"      $N���˾����ķ���˫��һ��������"+weapon->name()+YEL"�������԰�ɻص�$N���С�\n"NOR,me);
		else if (userp(me) && weapon->unequip()) weapon->move(environment(me));

	me->perform_busy(2);
	return 1;
}
