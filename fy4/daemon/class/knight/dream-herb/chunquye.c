// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int duration, i;
    	object *inv, herb;
    	
    	if(me->query("class")!="knight")
    		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ�á���ȥҲ����\n");

	if (me->query_skill("dream-herb",1)<170)
		return notify_fail("����ȥҲ����Ҫ170���������廨����\n");

	if (!target) target = me;
	
	if (me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷�ʹ�á���ȥҲ��\n");
	
	if (userp(me) && !userp(target))
		return notify_fail("����ȥҲ��ֻ�ܶԷ�NPCʹ�á�\n");
			
	duration = me->query("timer/lifesave_cast") + 3600 - time();
	
	if (duration > 0)
		return notify_fail("����ȥҲ��ÿһСʱֻ��ʩ��һ�Σ������´�ʹ�û���"+ duration/60 + "���ӣ�\n");
	
	if (target!=me) {
		inv= all_inventory(me);
		i = sizeof(inv);
		while (i--) {
			if (inv[i]->query("name") == BLU"�����"NOR && inv[i]->query("revive"))
				herb = inv[i];
		}
		if (!herb)
			return notify_fail("��Ҫ��������ݵ�ҩ�����ܶ�������ʩ����ȥҲ��\n");
		tell_object(me,"�㰵��������������ݻ��������ġ�\n");
		herb->add_amount(-1);
	}
	
	if( (int)me->query("force") < 400 )
		return notify_fail("����ȥҲ����400���������\n");

	if( (int)me->query("kee") < 250 )
		return notify_fail("����ȥҲ����250�����Ѫ��\n");

	if (userp(me)){
		me->add("force", -400);
		me->add("kee", -250);
	}		
			
	if (target == me) {
	message_vision(HIG"\n
$N"HIG"�ӻ��г���������룬�����Լ�ͷ��Ѩ��������ͻȻ������ת������
����Ѫɫȫ����ȥ����ɫ�ɰױ��̣�����ת�ƣ����ɻƷ��죬һ˲��
������ʮ���Σ����ڻָ��˳�̬��\n\n"NOR,me);
	} else {
	message_vision(HIG"\n
$N"HIG"�ӻ��г���������룬����$n"HIG"ͷ��Ѩ��������ͻȻ������ת������
���һ������$n"HIG"���š�$n"HIG"����Ѫɫȫ����ȥ����ɫ�ɰױ��̣�����ת�ƣ�
���ɻƷ��죬һ˲�侹����ʮ���Σ����ڻָ��˳�̬��\n\n"NOR,me,target);
	}	
	target->set("timer/lifesave",time());
	target->set("pfm/chunquye_pw",1);	// 20+1, 21% chance
	tell_object(target,WHT"���仨��ˮ��ȥҲ��������"+chinese_number(60)+"���ӡ�\n"NOR);
	me->set("timer/lifesave_cast",time());	
	
	return 1;
}
