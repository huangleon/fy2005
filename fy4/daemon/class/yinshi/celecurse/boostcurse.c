//	Boostcurse �����ٶ�5-10�� haste +30%
//	By Silencer@FY4 workgroup

#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	mapping buff;	
	
	int add_agi, add_str, add_haste, celeskill;
		
	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ����±޽���\n");
	
	celeskill = me->query_skill("celecurse",1); 
    if( celeskill < 80 )
                return notify_fail("�޽���Ҫ80��ͨ�콵��\n");
	
	if( !target ) target = me;
		
	if (target!=me  && !me->team_member(target))
		return notify_fail("�޽�ֻ��ʩ�Ӹ����ѻ��Լ���\n");
	
    if (ANNIE_D->check_buff(target, "haste")|| ANNIE_D->check_buff(target, "agiup"))
       	return notify_fail("��������ʹ�����Ƶ��书��\n");
	
	if( me->query("kee") < 100 )
		return notify_fail("�޽���Ҫ�ķ�100�����Ѫ��\n");
	if (userp(me))	me->receive_wound("kee", 100);
	
	if (target!=me)
	message_vision(HIW "$N��ɫ�Ұ���ѩ�����Ӷ���������еĲ�ᣣ�˫��΢�������������дʣ�
�������죬�����������������ͳ�����Ȼ���һ����$n���һ����Ѫ��\n\n" NOR,me,target);
	else
	message_vision(HIW "$N��ɫ�Ұ���ѩ�����Ӷ���������еĲ�ᣣ�˫��΢�������������дʣ�
�������죬�����������������ͳ�����Ȼ���һ�������һ����Ѫ��\n\n" NOR,me);
	
	if (celeskill>=185 ) {		add_agi = 10;		add_haste = 50;	}	// 33% chance haste in real. 
	else if (celeskill >=125) {	add_agi = 10;		add_haste = 40;	} 
	else  					{	add_agi = 5;		add_haste = 30;	} 
		
	msg = HIG "��Ĺ����ٶȼӿ죬���ָ�Ϊ�����ˣ�\n"NOR;
	tell_object(target, msg);
	
	buff = 
		([
			"caster": me,
			"who":  	target,
			"type":  "haste",
			"type2": "agiup",
			"att":	"bless",
			"name":	"ͨ�콵���޽�",
			"buff1":"apply/agility",
			"buff1_c":add_agi,
			"buff3": "apply/haste",
			"buff3_c":add_haste,
			"time":  900,
			"buff_msg": "",
		]);
	ANNIE_D->buffup(buff);
    return 1;
        
}