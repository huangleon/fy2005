// Silencer@fengyun	June.2005
// ���+100 parry

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
    		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á���Ӱǧ�á�\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
		if (F_LEVEL->get_level(me->query("combat_exp")) < 80)
    		return notify_fail("��Ӱǧ����Ҫ����ȼ�80���ϲ���ʹ�á�\n");
    	
    	if (cloud < 200) 
    		return notify_fail("��Ӱǧ��������Ҫ200���Ļ÷�Ʈ���衣\n");

    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("��Ӱǧ��ֻ����ս����ʹ�á�\n");
    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("�����ڵ������ʺ��赸��\n");

			if (me->query("atman")< 50)
    		return notify_fail("������Ҫ50��ħ����\n");
    	if (userp(me))	me->add("atman",-50);
    	me->force_status_msg("atman");
    		    	
    	if (cloud > 200) cloud = 200;
    	level = F_ABILITY->check_ability(me,"3_d_damage",3)*5;
    		
    	team1 = me->query_team();
    	
    	if (!team1 || sizeof(team1)<2)	team1 = ({ me });
    	
    	msg = HIC"
$N����ػͱڻ��ϵ���Ůһ�㣬��������ɽ�ɶɣ��������һ���ӳ���������
��Ͷ�֣���һ�裬��������һ������һ��������һʱ��ǧ����ã���Ӱ���أ�һ
ʱ�����쳩������Ʈ���r��\n"NOR;

		message_vision(msg, me);
		
		team = filter_array(team1,(: present($1,environment($2)) :),me);
			
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (ANNIE_D->check_buff(team[i],"hs_parryup")) continue;
			buff =
				([
					"caster":me,
					"who":	team[i],
					"type": "hs_parryup",
					"att": "bless",
					"name": "�÷�Ʈ���衤��Ӱǧ��",
					"time": 10 + F_ABILITY->check_ability(me,"3_d_duration",3)*2,
					"buff1": "apply/parry",
					"buff1_c": cloud/2,
					"buff2":  "apply/damage",
					"buff2_c":  level,
					"buff_msg":"",
				]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL"�����α�ת���·���͵��֣���Ȼû�а��ɳ�֮������\n"NOR);
	    	tell_object(team[i],YEL"����Ч�м�����"+(cloud/2)+"��\n"NOR);
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
