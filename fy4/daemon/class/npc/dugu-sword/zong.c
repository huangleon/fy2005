// po.c ���ܾ�ʽ��
 
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 object weapon;
 int skill, gin_cost;
 mapping my_fam  = me->query("family");
 skill = me->query_skill("dugu-sword",1);
 gin_cost = (int)me->query_int() + 45;
 if ((string)me->query("class") != "huashan")
  return notify_fail("�㲻�ǻ�ɽ�ɵĵ��ӣ�����ѧϰ�����¾Ž�����\n");

 if( me->is_fighting() )
		return notify_fail("���ܾ�ʽ��������ս����������\n");

 if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������ȥ��һ�ѽ���\n");

 if( !skill || (skill < 50))
  return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");

 if( me->query("force") < 50 )
  return notify_fail("�������������û�������������ܾ�ʽ����\n");
 
 if( me->query("gin") < gin_cost )
  return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");

 msg = HIC "$Nʹ�����¾Ž�֮���ܾ�ʽ����������" + weapon->name() + "���������̡�\n" NOR;
 me->add("force", -50);
 me->add("gin", -gin_cost);
 me->improve_skill("dugu-sword",  random((int)me->query_int()) + 1);
	me->start_busy(random(3));
	message_vision(msg, me);
	return 1;
}
