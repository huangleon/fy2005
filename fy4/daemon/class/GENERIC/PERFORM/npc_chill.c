#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object wp;
	int extra, myexp,yourexp, i;
	int base;
	string msg;
	object	*enemy;

	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
	if (me->query("class") != "huashan") 
		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á���˪��÷����\n");
	extra = me->query_skill("hanmei-force", 1);
	if( !me->is_fighting() )
		return notify_fail("�ۺ�˪��÷��ֻ����ս����ʹ�á�\n");
	if( !target ) target = offensive_target(me);
	
	wp = me->query_temp("weapon");
	myexp = me->query("combat_exp");
	yourexp = target->query("combat_exp");

	if (extra>100) base = extra;
	if (extra>150) base = extra*3/2;
	
	me->add_temp("apply/attack", extra);
       	me->add_temp("apply/damage", extra + base);
	
	enemy =	me->query_enemy();

	if(!wp){
		message_vision(HIW"$N�������ۣ�����������һ�㺮˪��\n$N˫�Ʒ��ף���ƮƮ�ĳ����ƺ���û��ʲôĿ�ꡣ\n"NOR, me);
	} else {
		message_vision(HIW"$N�������ۣ�һ�㺮˪���������е�"+ wp->name()+"�ϡ�\n"NOR+
			HIW"$N"+HIW"���й����˰�˪��" + wp->name() + HIW"������һ�����������ߡ�\n", me);

	}
	
	for (i = 0 ; i< sizeof(enemy); i++) {	
		if( enemy[i]&& enemy[i]->is_character()
        		&& me->is_fighting(enemy[i]) )
                
		{	target = enemy[i];
			if(!wp){
				msg = HIW "$n������������һ����ս��\n" NOR;
			} else {
				msg = HIW + wp->name() + HIW"ɢ�������ư���Χ����$n��\n" NOR;
			}
	
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        
        		if(extra > 150 &&  target->query_temp("damaged_during_attack") 
        			&& !target->is_busy()) target->start_busy(1);
        	}
	}	        		

        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -(extra + base));      
	me->perform_busy(2);
	return 1;
}

