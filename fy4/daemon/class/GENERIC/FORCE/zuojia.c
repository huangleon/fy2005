// Silencer @ FY4 workgroup. Aug.2005
/*

���е���������һ�����칦���й�ʱ����������ʮָ�ᵯ�����΢�ţ�ͷ��ð��˿˿���ɫ����
��סһ��ѩ���Ʒ�������Ϯ�У������������ǡ��ػ���ɨ���侢���ɴݶ�����ʯ���������������䵱һ������

һ���Ծ��ƶ������������һ����������ָ���У�����Ҹ�������ݳ������»���
һ���ߣ���Է��ļ�����Ѩȫ����¶��ָ��֮�£��Է��������ң��������µ�һ�ķ�
�ع���

*/

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
		return notify_fail("ʹ�á�Ϊ�����ޡ�������Ҫ�������5��������˵�����
������ֻ���������"+chinese_number(lvl)+"����\n");
		
    if (me->is_fighting())
       	return notify_fail("ս�����޷�ʹ�á�Ϊ�����ޡ�\n");
    		
	if(!target ) target=me;
	if(target!= me) {
		return notify_fail("��Ϊ�����ޡ�ֻ����������\n");
	}
	
	if (ANNIE_D->check_buff(target, "quest_kee"))
		return notify_fail("�����Ѿ���ʹ�����Ƶ��ķ��ˡ�\n");	
	
	if (me->query("force")< 300)
        	return notify_fail("��Ϊ�����ޡ�������Ҫ300��������\n");
    if (userp(me))	me->add("force",-300);
    
    // STage ADVANCE PERFORM, 
    
    name = "���ơ�Ϊ������";
    
    if (lvl >= 15)		{lvl = 15; name += "�ɣɣ�";} 
    else if (lvl >=10)	{lvl = 10;name += "�ɣ�";}
    else				{lvl = 5;name += "��";}
    
    amount1 = me->query("max_kee")* lvl /100;       	
	
	me -> delete("cont_quest");
	
	duration = 1200;
	
	msg = HBRED + HIY"$N����������ʮָ�ᵯ�����΢�ţ�ͷ��ð��˿˿���ɫ����\n"NOR;
		
	buff =
		([
			"caster": me,
			"who":  target,
			"type": "quest_kee",			// Just annie_d changes
			"att":	"bless",
			"name":	name,
			"buff1":"kee",
			"buff1_c":amount1,		
			"time":  1200 ,
			"buff_msg": msg,
			"special_func":1,
		]);
		
    ANNIE_D->buffup(buff);
	me->perform_busy(1);
	return 1;
}



