//	 increase damage potential *150%, but resistance-30%
// 	actually the duration here is detrimental in a degree
//	SS has burst damage zhuiming/yirancangyun on a long timer
//	short duration is better to reduce the penalty :D
 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
		string msg;
		int extra, duration, attack_bonus, damage;
		mapping buff;
	
		if (me->query_skill("nine-moon-sword",1) < 170)
			return notify_fail("����ӳ�⺮����Ҫ170������������\n");
				
		duration = me->query("timer/pfm/ss_bygh") + 120 - time();
		if (duration>0)
			return notify_fail("����Ҫ�ȴ�"+duration+"������ٴ�ʹ�á���ӳ�⺮����\n");
					
		if (!me->is_fighting())
			return notify_fail("���ؼ�ֻ����ս����ʹ�á�\n");
			
		if (ANNIE_D->check_buff(me,"criticalup"))
	   	   	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

		msg = HIG "$N"HIG"���죬��ü���ľ��̣��ν�����ɫ���̣���������ӳ���������������ɱ�⡣\n"NOR;	    	
		buff =
		([
			"caster":me,
			"who": 	me,
			"type":"criticalup",
			"att":	"bless",
			"name":	"������������ӳ�⺮",
			"buff1":"feat/critical",
			"buff1_c":1,
			"buff2":"resistance/kee",
			"buff2_c":-30,
			"buff3":"resistance/gin",
			"buff3_c":-30,
			"time":  30,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/ss_bygh",time());
		return 1;
}		
