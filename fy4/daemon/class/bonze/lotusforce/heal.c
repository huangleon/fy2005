// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int level,ess_level,i,force_cost,delay;
	object *enemy, *mem;
	string color;
	
	level = 20;
	ess_level = 20;
	force_cost = 100;		
	color = WHT"";
	delay = 2;
	amount = 300;
	
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳ����ô��ķ���\n");
	
	if( ANNIE_D->check_buff(me,"xg-cloudstaff-up") || ANNIE_D->check_buff(me,"xg-heal-down")) {
		return notify_fail("��ս���С��ڼ��޷�ʹ�÷��������ķ���\n");
	}

	if (ANNIE_D->check_buff(me,"xg-evil")>0)
		return notify_fail("ʹ�����ɾ�ʱɱ��̫�أ��޷�ʹ�÷��������ķ���\n");
	
	if ( me->query_skill("lotusforce",1) <level || me->query_skill("essencemagic",1)< ess_level) 
		return notify_fail("��Ҫ"+level+"���������ķ���"+ess_level+"���İ�ʶ��ͨ��\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
	}
	
	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("�㲻�������ʹ�ô������ľ���\n");

	if (me->query_temp("am_healing"))
		return notify_fail("������ʹ�������ķ��С�\n");
					
	if( (int)me->query("force") < force_cost && userp(me))
		return notify_fail("��Ҫ"+force_cost+"���������\n");
	if (userp(me))  me->add("force", -force_cost);
	
	if (target!=me)
		message_vision(color+"$N�����ڹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,target);
	else
		message_vision(color+"$N�����ڹ��������ؽ�������������ת....\n\n"NOR,me);
	call_out("heal_him",delay, me, target, amount);
	
	me->set_temp("am_healing",1);
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


int heal_him(object me, object target, int amount)
{
	int i;
	string msg;
	object *enemy;
	
	if (me)	me->delete_temp("am_healing");
	
	if (!me || !target )	return 1;
	if (environment(target) != environment(me)) {
		tell_object(me,"��Ҫ���ε����Ѿ����������ˡ�\n");
		return 1;
	}
	
	if (!COMBAT_D->legitimate_heal(me,target)) return 1;
		
	if (target!=me)
		msg = WHT"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�����Ѫ����ɫ������������ˡ�";
	else 
		msg = WHT"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�";
	
	amount = amount * (100 + F_ABILITY->check_ability(me,"heal1_add")*2)/100;
	if (F_ABILITY->check_ability(me,"heal2_add") > random(100)){
		amount = amount*2;
		msg = WHT"����"+msg+"����";
	}
	
	message_vision(msg + "��+"+amount + "��\n"NOR, me, target);
	target->receive_fulling("kee", amount,me);
	
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
