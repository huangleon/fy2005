// Silencer@fy4
// ���ķ��������ṩһ��temp_Mark������ؤ�＼�ܡ�

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	object *team;
	int i, skill, duration;
	mapping buff;

	if (me->query("class")!= "beggar")
		return notify_fail("ֻ��ؤ����Ӳ������á�ٿ������\n");
		
	skill = me->query_skill("huntunforce",1);
	if (skill < 150 || me->query_skill("begging",1)<200 || me->query_skill("advanced-unarmed",1)<200)
		return notify_fail("��ٿ������������Ҫ150�����繦��200������֮���͸߼���֮����\n");

	duration = me->query("timer/gb_shuhu")-time() + 900 - F_ABILITY->check_ability(me,"shuhu_add")*30;
    if (duration>0)
       	return notify_fail("�㻹��Ҫ�ȴ�"+duration+"�������Ҳ����ٴ�ʹ�á�ٿ��������\n");

	if (ANNIE_D->check_buff(me, "fastcast")>0)
               	return notify_fail("���Ѿ���ʹ�á�ٿ�������ˡ�\n");  
    
    me->set("timer/gb_shuhu",time());
	
    buff =
		([
			"caster":me,
			"who": me,
			"type":"fastcast",
			"att":"bless",
			"name":"���繦��ٿ����",
			"time":  180,
			"buff_msg":HIG"$Nһ����Х�����ζ�����Ӱ����������������ٿ����������ȥ����������\n"NOR,
			"disa_msg":YEL"��ġ�ٿ������������ϣ��������ջص��\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	
	return 1;
}


/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
