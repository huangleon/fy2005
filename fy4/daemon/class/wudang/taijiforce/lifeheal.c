// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int level,i, n,add;
	object *enemy, *mem;
	
	if(me->query("class")!="wudang")
		return notify_fail("ֻ���䵱���Ӳ����ô��ķ���\n");
	
	level=me->query_skill("taijiforce",1);
	if (level<150) 
		return notify_fail("��Ҫ150����̫���ķ���\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
	}
	
	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("�㲻�������ʹ�ô������ľ���\n");
	
	// L150 -- 300/2250
	// L200 -- 400/3000	
	if( (int)me->query("force") < level*2 && userp(me))
		return notify_fail("��Ҫ" + level*2 + "���������\n");
	if (userp(me))  me->add("force", -level*2);
	
	if (target!=me)
		message_vision(HIW "$N����̫���ڹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,target);
	else
		message_vision(HIW "$N����̫���ڹ��������ؽ�������������ת....\n\n"NOR,me);
	call_out("heal_him", 2, me, target, level);
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


int heal_him(object me, object target, int level)
{
	int amount;
	if (environment(target) != environment(me)) {
		tell_object(me,"��Ҫ���ε����Ѿ����������ˡ�\n");
		return 1;
		}
	
	if (target!=me)
		message_vision(HIW"���˲��ã�$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,target);
	else 
		message_vision(HIW"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me);
	
	amount = level * 15;
	target->receive_fulling("kee", amount,me);
	return 1;	
	
}


