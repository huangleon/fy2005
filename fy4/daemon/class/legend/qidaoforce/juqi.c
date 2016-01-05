#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
    int juqi, skill, dorm;
	mapping buff;
	string name, msg;
	
	if(me->query("class")!="legend"&& userp(me))
		return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�þ�������Ρ�\n");

 	if (ANNIE_D->check_buff( me, "juqi"))
 		return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
        
    skill = me->query_skill("qidaoforce",1);
    dorm = me->query_skill("dormancy",1);
    
    if(skill < 100 )
    	return notify_fail("���������������100������ķ���\n");
    
    if (me->query("force")<100)
    	return notify_fail("���������������Ҫ100��������\n");
    	       
    if (userp(me))	me->add("force", -100);
               	
	if (skill >= 150 && dorm >=250)		juqi = 80;
	else if (skill >= 150 && dorm>=200)	juqi = 70;
	else	juqi = 60;
						
	if(me->query("family/master_id")=="master xuerui") {
		msg = HIG"$N˫�����棬����������չ������Ө����ɫ��â����໺����ɢ����������\n"NOR;
		name = "���������";
	} else {
		msg = HIW"$N�˾����������ۣ�ȫ������������һ���������޵İ���������\n"NOR;
		name = "���������";	
	}
		
	juqi = COMBAT_D->magic_modifier(me, me, "kee",juqi);
		
	buff =
		([
			"caster":me,
			"who": me,
			"type":"juqi",
			"att":"bless",
			"name": name,
			"buff1": "pfm/qidaoforce_juqi",
			"buff1_c":juqi,
			"time":  900,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
	
	return 1;
}
