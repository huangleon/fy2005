// Silencer @ FY4 workgroup. Aug.2004
//	�޷��Թģ����ֽ�ӡ�����ַ��������������н������������ɱ���������ɣ�
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int skill,gin, kee, sen, am1, am2, am3;
	mapping buff;
	
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳ����̡����ɾ�����\n");

	skill = me->query_skill("lotusforce", 1);
	if(skill < 140) return notify_fail("�����ɾ���������Ҫ140�������ķ���\n");

	if( target != me ) 
	return notify_fail("���ɾ�ֻ����������\n");

	if (ANNIE_D->check_buff(me,"xg-evil"))
		return notify_fail("���Ѿ��������ɾ����ˡ�\n");

	if (ANNIE_D->check_buff(me,"powerup") || ANNIE_D->check_buff(me,"dodgeup")
		|| ANNIE_D->check_buff(me,"parryup"))
		return notify_fail("���Ѿ���ʹ�����Ƶ��ؼ��ˡ�\n");
		
	if( (int)me->query("force") < 100 )   return 
		notify_fail("�������������\n");
	me->add("force", -100);
	
	buff =
		([
			"caster":me,
			"who": me,
			"type":"xg-evil",
			"type2": "powerup",
			"att":"bless",
			"name":"�����ķ������ɾ�",
			"buff1": "apply/parry",
			"buff1_c":	100,
			"buff2": "apply/dodge",
			"buff2_c":  100,
			"time":  180,
			"buff_msg":HIC"$N"HIC"�����޷��Թģ����ξ�Ȼ����˲�����������������������н����������
���ֽ�ӡ�����ַ�����ָ�罣������������ֽ������죬�����ɱ��\n" NOR,
		]);
		
	ANNIE_D->buffup(buff);
	if( me->is_fighting() && userp(me)) me->perform_busy(1);
	return 1;
}
