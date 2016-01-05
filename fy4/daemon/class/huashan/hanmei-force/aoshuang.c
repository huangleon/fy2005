//����˪������aoshuang�������䵱�ĵ�һ����������ƣ�
 // L20:120���� 160heal ����ߵ�  L200 - 300������1600heal, 2 sec delay,self-busy 1.

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int level,i, n,add, force;
	object *enemy, *mem;
	
	if(me->query("class")!="huashan")
		return notify_fail("ֻ�л�ɽ���Ӳ����ô��ķ���\n");
	
	level=me->query_skill("hanmei-force",1);
	if (level<20) 
		return notify_fail("��Ҫ20���ĺ�÷�ķ���\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
	}
	
	if (userp(me) && !COMBAT_D->legitimate_heal(me,target))
		return notify_fail("�㲻�������ʹ�ô������ľ���\n");
	
	if (level < 50)			{ force = 100; amount = 250;}
	if (level < 100) 		{ force = 150; amount = 400;}
	else if (level < 150) 	{ force = 200; amount = 800;}
	else if (level < 200) 	{ force = 250; amount = 1200;}
	else					{ force = 300; amount = 1600;}

/*	XG's 	
	L20 heal:100������300heal,2 sec delay, self-busy 1
	L80 mheal: 200������600heal,2 sec delay, self-busy 1
	L120 gheal: 300������1500heal,3 sec dealy, self-busy 1
	L180 sheal:500 ������4000heal,4 sec delay, self-busy 1	
	L190 fheal:500 ����  3000heal, 2 sec delay, self-busy 1
	L200 cheal:600 ����  8000heal, 6 sec delay,self-busy 1	*/

	if (me->query_temp("am_healing"))
		return notify_fail("������ʹ�������ķ��С�\n");
		
	if( (int)me->query("force") < force)
		return notify_fail("��Ҫ" + force + "���������\n");

	if (target == me)
		write( WHT "�����𡺰�˪��������ʼ�˹����ˡ�\n" NOR);
	else
		write( WHT "�����𡺰�˪��������ʼ��"+ WHT+ target->name()+ WHT"�˹����ˡ�\n" NOR);
		
        message("vision", WHT + me->name() + NOR + WHT
"����÷�ķ�֮����˪�����������Ϸ������Ʒ�����ԣ�������һ�亮÷��\n" NOR, 
		environment(me), me);

	if (userp(me))  {
		if (F_ABILITY->check_ability(me,"heal_add")> random(100))	
			tell_object(me,YEL"������Ϣ��ͨ�����������ʹ������һ�У�\n"NOR);
		else
			me->add("force", -force);
	}
	
		call_out("heal_him", 3, me, target, amount);
		me->set_temp("am_healing",1);
		me->start_busy(1);
	
		if(target->is_fighting()) {
			enemy = target->query_enemy();
			for (i=0;i<sizeof(enemy);i++) {
				if (!enemy[i]->is_fighting(me)) {
					enemy[i]->kill_ob(me);
					me->kill_ob(enemy[i]);
				}
			}	
		}
			
		return 1;
}


int heal_him(object me, object target, int amount)
{
	if (!me || !target)	
		return 1;
		
	if (me)	me->delete_temp("am_healing");
		
	if (environment(target) != environment(me)) {
		tell_object(me,"��Ҫ���ε����Ѿ����������ˡ�\n");
		return 1;
	}
	amount = COMBAT_D->magic_modifier(me, target, "kee",amount);
		
	message_vision(WHT"һ�㵭���İ�����ָ�Ƽ�͸����$N�����˿�ʼ�������ϡ�\n" NOR, target);
	target->receive_fulling("kee", amount,me);
	return 1;	
	
}