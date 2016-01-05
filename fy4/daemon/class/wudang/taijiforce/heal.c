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
	if (level<20) 
		return notify_fail("��Ҫ20����̫���ķ���\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
	}
	
	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("�㲻�������ʹ�ô������ľ���\n");
	
	// L20 -- 120/160
	// L150 - 250/1200	
	if( (int)me->query("force") < 100+ level && userp(me))
		return notify_fail("��Ҫ" + stringp(level+100) + "���������\n");
	if (userp(me))  me->add("force", -level-100);
	
	if (target!=me)
		message_vision(WHT "$N����̫�����ǹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,target);
	else
		message_vision(WHT "$N����̫�����ǹ��������ؽ�������������ת....\n\n"NOR,me);
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
		message_vision(WHT"���˲��ã�$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,target);
	else 
		message_vision(WHT"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me);
	
	amount = level * 8;
	target->receive_fulling("kee", amount,me);
	return 1;	
	
}