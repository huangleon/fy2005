#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ջ���Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (ANNIE_D->check_buff(target,"cursedflesh"))
		return notify_fail("�Է��Ѿ��ܵ����Ƽ��ܵ�Ӱ���ˡ�\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "cursedflesh",
		"att": "curse",
		"name": "��а�ľ����ջ���Ѫ",
		"time": 30,
		"buff_msg":HIC"\n$n"HIC"���ϸ��ֳ�����֮ɫ�����һ���ȳ���������\n"HIB"$N"HIB"⧲�����������һ�ڶ�����ʱҡҡ��׹������\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	return 1;
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/