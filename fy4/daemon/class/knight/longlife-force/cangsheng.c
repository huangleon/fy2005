#include <ansi.h>

int exert(object me, object target, int amount)
{
	
	int skill, cost, i,duration;
	object *enemy, *mem;
	string msg;
	
		if (me->query("class")!="knight")
			return notify_fail("������Ϊ����ֵ��ؼ���\n");

    	skill = me->query_skill("longlife-force",1);
    	if (skill < 100)
    		return notify_fail("������������Ҫ100���Ĳ�������\n");
    	
    	duration = me->query_temp("timer/pfm/cangsheng")+20 - time();
    	if (duration>0)
    		return notify_fail("��Ҫ�ȴ�"+ duration + "������ٴ�ʹ����������\n");
    	
    	if (!target)	return notify_fail("������˭ʹ����������\n");
    	if (target == me)	return notify_fail("���������������Լ����ϡ�\n");
    	  	
    	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("�㲻�������ʹ�ô������ľ���\n");
    	
    	mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
    	
    	if( me->query("force") < 200 && userp(me))
			return notify_fail("��Ҫ200���������\n");
		if (userp(me))  me->add("force", -200);
	
	//  2000;
		cost = skill * 5;
		if (me->query("kee") < cost)
			return notify_fail("�������ѱ�������ʲô�ˣ���������"+ cost + "����Ѫ��\n");
	
		msg = HIG"$N"HIG"��ɫ���̣���Хһ����һ�ƻ���$n"HIG"�ĺ��ģ����˶��ǻ������\n"NOR;
		message_vision(msg, me, target);
	
		me->set_temp("timer/pfm/cangsheng",time());
		me->receive_damage("kee",cost);
		me->set_temp("last_damage_from","ʹ������������������\n");
		target->receive_fulling("kee", cost*2, me);
	
		if(target->is_fighting()) {
			enemy = target->query_enemy();
			for (i=0;i<sizeof(enemy);i++) {
				if (!enemy[i]->is_fighting(me)) {
					enemy[i]->kill_ob(me);
					me->kill_ob(enemy[i]);
				}
			}	
		}	
	
		me->perform_busy(1);
		return 1;
}