// silencer fy4 workgroup

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	
	int skill;
	string msg;
	mapping buff;

	if (me->query("class")!="wudang")
    		return notify_fail("�����־������䵱�Ķ����书��\n");
	
	skill = me->query_skill("taiji-sword",1);
	if( (int)me->query_skill("taiji-sword", 1) < 50 )
		return notify_fail("�����־�����Ҫ50����̫��������\n");
	
	if (ANNIE_D->check_buff(me,"parryup"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	
	msg = HIC "$Nʹ�������־���������ר־����Ȧ����С����һ��̫������ʹ��Բת���⣬
�����쳣����ס�Ż���������и�ɻ���\n"NOR;
	
	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"parryup",
			"att":		"bless",
			"name":		"̫�����������־�",
			"buff1":	"perform/taiji_shou",
			"buff1_c":	 1,
			"buff2":	"apply/attack",
			"buff2_c":	-skill,
			"time":  	120,
			"buff_msg":	msg,
		//	"warn_msg":	WHT"�������ݡ��Ĺ�Ч��Ҫ�����ˡ�\n"NOR,
		//	"disa_msg":	YEL"��ġ����־���������ϡ�\n"NOR,
			"special_func":0,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
