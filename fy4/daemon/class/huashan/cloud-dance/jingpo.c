// Silencer@fengyun	June.2005
// ���critical_strike ����Ϊԭ����3����i.e.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int extra, bonus, cloud, num, i, level;
    	string msg;
    	object *team, *team1;
    	mapping buff;
    	
		if (me->query("class") != "huashan") 
    		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á�÷�ľ��ơ�\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
    	if (F_LEVEL->get_level(me->query("combat_exp")) < 90)
    		return notify_fail("÷�ľ�����Ҫ����ȼ�90���ϲ���ʹ�á�\n");
    	
    	if (cloud < 200) 
    		return notify_fail("÷�ľ���������Ҫ200���Ļ÷�Ʈ���衣\n");
    		
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("÷�ľ���ֻ����ս����ʹ�á�\n");
    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("�����ڵ������ʺ��赸��\n");
    	
			if (me->query("atman")< 50)
    		return notify_fail("������Ҫ50��ħ����\n");
    	if (userp(me))	me->add("atman",-50);
    	me->force_status_msg("atman");
    		    	
    	cloud = 10;
    	cloud = cloud * ( 100 + F_ABILITY->check_ability(me,"jingpo_add")*5)/100;
    	level = F_ABILITY->check_ability(me,"3_d_damage",3)*5;
    		
    	team1 = me->query_team();
    	if (!team1 || sizeof(team1)<2)	team1 = ({ me });
    	msg = HIY"
��ɽ�������ﾪ��Զ����������ĵ������Ƶ��Ƹߵ����ת�ϣ�$Nһʱ�������
�����渵ĵ������������裬����ͻ��仯������ɷɷ���·�������$N
��Ӱ��ת������ƿ���ɱ����Ӱ֮�У���Ҷ�ﻨ����Ʈ�����\n"NOR;

		message_vision(msg, me);
	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (ANNIE_D->check_buff(team[i],"hs_resistup")) continue;
			buff =
			([
				"caster":me,
				"who":	team[i],
				"type": "hs_resistup",
				"att": "bless",
				"name": "�÷�Ʈ���衤÷�ľ���",
				"time": 10 + F_ABILITY->check_ability(me,"3_d_duration",3)*2,
				"buff1": "resistance/kee",
				"buff1_c": cloud,
					"buff2":  "apply/damage",
					"buff2_c":  level,
				"buff_msg":"",
			]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL"������Ū��÷�ľ��ƣ�����׹���У������趯���޿��ټ���\n"NOR);
			tell_object(team[i],YEL"������Ѫ�˺��ֿ�������10%��\n"NOR);
			if (level)	tell_object(team[i],YEL"���˺�������"+(level)+"��\n"NOR);
    	}
    	
       	buff =
		([
			"caster":me,
			"who":	 me,
			"type": "pseudo-busy",
			"att":  "curse",
			"name": "�赸��",
			"time":  6,
			"buff1": "pseudo-busy",
			"buff1_c": 1,
			"buff_msg": "",
			"condition_type":  "<���ٶ�>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
    	ANNIE_D->buffup(buff);	
    	
    	return 1;
}
