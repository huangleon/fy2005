#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,bonus,a,b;
	extra = me->query_skill("dug",1);
	if ( extra < 200) return notify_fail("��Լ����ɱ�������ճ̶Ȳ�����ʹ������ڤ��֮������\n");
	bonus = me->query_skill("dagger",1);
	if ( bonus < 200) return notify_fail("��Ի����̱��е����ճ̶Ȳ�����ʹ������ڤ��֮������\n");

	if (me->query("force") < 1200 && userp(me))
		return notify_fail("�������������ʹ������ڤ��֮������\n");

	if (NATURE_D->is_day_time() && userp(me))
			return notify_fail("����ڤ��֮����ֻ����ҹ��ʹ�á�\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIR BLK"��ڤ��֮��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query("age") - me->query("annie/dug") < 1 && userp(me))
		return notify_fail("��ľ��û�����ϴ�ʩչ����ڤ��֮����������лָ��������޷��ٴ�ʹ�á�\n");

	me->set("annie/dug",me->query("age"));
	if (userp(me))
		me->add("force",-1200);

	a=extra+random(bonus)+bonus;			// 200 + random(200) + 200 = 400-600
	b=bonus*2+random(extra*3)+extra*2;		// 200*2 + random(200*3) + 200*2 = 800 - 1600

	me->add_temp("apply/attack", a);	
	me->add_temp("apply/damage", b);

	msg = HIR BLK"һ��Ũ��Ʈ���������$n"HIR BLK"��ǰ��$N"HIR BLK"����һ�����ȵ�$n"HIR BLK"��ߣ���������˼����ɱ��������ʽ����"NOR BLU"��ڤ��֮��"HIR BLK"����"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

	me->add_temp("apply/attack", -a);	
	me->add_temp("apply/damage", -b);

	return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
