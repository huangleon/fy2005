// ������ܽ���������������ڵ�һ˳λ�İ�����Ŀ��

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lvl,duration,i;
	object obj,*inv;
	object drug1,drug2;

	amount = 150;	// 1k.
	duration = 1800;// 30 min

	lvl = me->query_skill("divineforce",1);	
	if( lvl < 1)
	return notify_fail("���黪�ɼ�����Ҫ1������а�ľ���\n");

	inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("skill_type") == "throwing")
		{
			obj = inv[i];
			break;
		}
	if (!obj)
	 	return notify_fail("�������޷�ʹ�á��黪�ɼ�����\n");
	if (obj->query("base_value") >= 10000)
	 	return notify_fail("���޷���"+obj->name(1)+"ʹ�á��黪�ɼ�����\n");
	if (obj->query("no_replenish"))
	 	return notify_fail("���޷���"+obj->name(1)+"ʹ�á��黪�ɼ�����\n");
	if (!	obj->query("volumn"))
	 	return notify_fail("���޷���"+obj->name(1)+"ʹ�á��黪�ɼ�����\n");

	if (me->query("timer/replenish") + 3600 > time())
	 	return notify_fail("���黪�ɼ����޷�����ʹ�á�\n");

	if (me->query("force") < 400)
	 	return notify_fail("���黪�ɼ�����Ҫ���٣�������������\n");

	i = me->query("force");
	if (i>lvl*15)
		i=lvl*15;
	if (i>obj->query("volumn") * (lvl/2))
		i=obj->query("volumn") * (lvl/2);
	me->add("force",-i);
	i=i/10;
	obj->add_amount(i);
	obj->set("base_value",1);
	obj->set("no_sell",1);
	obj->set("no_pawn",1);
	obj->set("no_stack",1);

	message_vision( HIB
"\n$N"HIB"˫Ŀ΢�ϣ����ֽ����鰴��"+obj->name(1)+HIB"֮�ϣ��������һ����������â��\n\n	 "NOR HIW+obj->name(1)+HIW"�Ͻ������𵭰׵���⣬���Խ��Խ����������\n" NOR, me);

	me->set("timer/replenish",time());

	me->perform_busy(3);

	return 1;
}
