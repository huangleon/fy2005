// һ�wͬ�^(���\�g)

#include <ansi.h>

int exert(object me, object target, int amount)
{
	string msg;
	int lvl, num, i,teampf;
	mapping buff;
	object *team, *team1;

	if (userp(me))
		return notify_fail("����书��û�������ؼ���\n");

	if(me->query("class")!="beggar")
		return notify_fail("ֻ������˼Ҳ��������ܺ��ı��ܡ�\n");

	if(me->query("deposit") > 100000)
		return notify_fail("ֻ������˼Ҳ��������ܺ��ı��ܡ�\n");

	if(me->query_skill("huntunforce",1) < 160 )
		 return notify_fail("��ͬ�۾�����Ҫ160����⽹���\n");
	
	if(me->query_skill("betting",1) < 50 )
		 return notify_fail("��ͬ�۾�����Ҫ50����֮����\n");
	
	if(me->query_skill("begging",1) < 160 )
		 return notify_fail("��ͬ�۾�����Ҫ160������֮����\n");
	
	if (me->query_skill("betting",1) >= 100)
		teampf =1;

	target = me;

	team1 = me->query_team();
	if (!team1)
		teampf=0;

	if(me->query("force") < 100 )
		return notify_fail("��ͬ�۾�����Ҫ100��������\n");

	if (ANNIE_D->check_buff(me,"criticalup") && !teampf)
		return notify_fail("���Ѿ����ܡ�ͬ�۾�����Ӱ���ˡ�\n");

	if (userp(me))
		me->add("force", -100);

	msg = WHT"\n\n$N�������ģ�Ĭ������ķ���"NOR ;
	message_vision(msg, me);

	lvl = me->query_skill("huntunforce",1);

	// huntunforce 150,+75%
	// full foreknowledge 200lv. = 40 kar,vs 3-5M npc(25-30) rate = 17.5% ~ 26%

	if (!teampf) {
		buff =
		([
			"caster":me,
			"who": me,
			"type":"criticalup",
			"att":"bless",
			"name":"����ķ���ͬ�۾�",
			"buff1":"apply/critical_strike",
			"buff1_c":lvl/2,
			"time":   30+lvl/2,
			"buff_msg":YEL"������ֳ�ǳǳ��⡣\n\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	}
	else
	{	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
    	msg = WHT"�������鱧ס��Χ���ˡ�\n"NOR ;
		message_vision(msg, me);
		for (i=0; i<num; i++)
		{
			if (ANNIE_D->check_buff(me,"criticalup"))
				continue;
			buff =
			([
				"caster":me,
				"who":  team[i],
				"type":"criticalup",
				"att":"bless",
				"name":"����ķ���ͬ�۾�",
				"buff1":"apply/critical_strike",
				"buff1_c":team[i]->query("class") == "beggar"?(lvl-10)/2:(lvl-10)/3,
				"time":   25+lvl/2,
				"buff_msg":YEL"$N��߷����������޵�ǳǳ��⣮����\n"NOR,
				"disa_msg":YEL "\n\n������Ĺ�׷���ҫ�۵�һ������ʧ�ˡ�\n\n" NOR,
				"special_func":0,
			]);
			ANNIE_D->buffup(buff);
		}
    }
	me->start_busy(1);
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
