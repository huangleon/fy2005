// Silencer @ FY4 workgroup. Aug.2005

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int stage, force, lvl, duration, amount1;
	object obj, *mem;
	string msg, name;
	mapping buff;

	lvl = me->query("cont_quest");
	if( lvl < 5) 	
		return notify_fail("ʹ�á�������˭��������Ҫ�������5��������˵�����
������ֻ���������"+chinese_number(lvl)+"����\n");
		
    if (me->is_fighting())
       	return notify_fail("ս�����޷�ʹ�á�������˭��\n");
    		
	if(!target ) target=me;
	if(target!= me) {
		return notify_fail("��������˭��ֻ����������\n");
	}
	
	if (ANNIE_D->check_buff(target, "quest_dmg"))
		return notify_fail("�����Ѿ���ʹ�����Ƶ��ķ��ˡ�\n");	
	
	if (me->query("force")< 300)
        	return notify_fail("��������˭��������Ҫ300��������\n");
    if (userp(me))	me->add("force",-300);
    
    // STage ADVANCE PERFORM, 
    
    name = "���ơ�������˭";
    
    if (lvl >= 15)		{lvl = 15; name += "�ɣɣ�";} 
    else if (lvl >=10)	{lvl = 10;name += "�ɣ�";}
    else				{lvl = 5;name += "��";}
    
    amount1 = lvl;       	
	
	me -> delete("cont_quest");
	
	duration = 1200;
	
	msg = HBRED + HIY"$N����������������ĵ�����������������֮ˮ�������������ɶ��ơ�\n"NOR;
		
	buff =
		([
			"caster": me,
			"who":  target,
			"type": "quest_dmg",
			"att":	"bless",
			"name":	name,
			"buff1":"apply/quest_dmg",	// used in attack_damage in combatd
			"buff1_c":amount1,
			"time":  1200 ,
			"buff_msg": msg,
			"special_func":0,
		]);
		
    ANNIE_D->buffup(buff);
	me->perform_busy(1);
	return 1;
}



