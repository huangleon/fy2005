// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	string msg;
	int amount;
	mapping buff;
	
	if((int)me->query_skill("xisui",1) < 120 )
                return notify_fail("�׽����Ҫ120����ϴ�辭��\n");
	    
        if (ANNIE_D->check_buff( me, "strup"))
               	return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
	
	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");
	me->receive_wound("kee", 100);
	
	amount = 5;
	
	buff =
		([
			"caster":me,
			"who": 	me,
			"type":	"strup",
			"att":	"bless",
			"name":	"ϴ�辭���׽��",
			"buff1":"apply/strength",
			"buff1_c":amount,
			"time":  300 ,
			"buff_msg":BGRN + WHT"$N��������������������죬���ξ�Ȼ�ߴ���һ�أ���\n"NOR,

		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	
	return 1;
}
