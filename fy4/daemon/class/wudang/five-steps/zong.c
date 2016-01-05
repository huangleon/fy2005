//	 Silencer@fy4 workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int skill, add_agi;
 	string msg;
 	mapping buff;
 	
 	skill = (int) me->query_skill("five-steps",1);
 	 	
 	if (me->query("class") != "wudang")
  		return notify_fail(WHT"�㲻���䵱���ӣ�����ʹ�á������ݡ���\n"NOR);

	if( !skill || (skill < 100))
  		return notify_fail(WHT"�ݱ䡺�����ݡ���Ҫ100������������\n"NOR);
 	
 	if (!target)	target = me;
 	
 	if (target!= me ) 
 		return notify_fail(WHT"�������ݡ�ֻ����������\n"NOR);
 	
 	if (ANNIE_D->check_buff(me, "agiup")|| ANNIE_D->check_buff(me,"boostcurse"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
        
        if( me->query("force") < 100 )     
        	return  notify_fail("�������ݡ���Ҫ100��������\n");   	
	me->add("force", -100);
 	
 	add_agi = skill / 20;		// 0-20
 	
 	msg = BGRN + HIG"
$N����������������ҽ�����Žű�һ̤��ٿȻ��������ƾ�հ������ɣ�
����������ǰƮ�����ɣ�Ȼ��������أ������䵱�����������ݡ���\n\n"NOR;

	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"agiup",
			"att":		"bless",
			"name":		"���в�����������",
			"buff1":	"apply/agility",
			"buff1_c":	add_agi,
			"time":  	300,
			"buff_msg":	msg,
			"disa_msg":	YEL"��ʩչ��ϡ������ݡ�����ס���Ρ�\n"NOR,
		]);
	ANNIE_D->buffup(buff);
 	       	
	return 1;
}
