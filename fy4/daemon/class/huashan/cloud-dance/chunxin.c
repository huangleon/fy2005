// Silencer@fengyun	June.2005
// + 200 force for everyone, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int extra, bonus, cloud, num, i;
    	int duration;
    	string msg;
    	object *team, *team1;
    	mapping buff;
    	
    	if (me->query("class") != "huashan") 
    		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á�ѩ�ﴺ�š�\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
		if (F_LEVEL->get_level(me->query("combat_exp")) < 70)
    		return notify_fail("ѩ�ﴺ����Ҫ����ȼ�70���ϲ���ʹ�á�\n");
    	
    	if (cloud < 200) 
    		return notify_fail("ѩ�ﴺ��������Ҫ200���Ļ÷�Ʈ���衣\n");
    		    	
    	duration = me->query("timer/pfm/hs_chunxin")-time() + 10;
    	if (duration>0)
       		return notify_fail("�㻹��Ҫ�ȴ�"+(duration)+"�������Ҳ����ٴ�ʹ�á�ѩ�ﴺ�š�\n");
    	
    	if (cloud > 200) cloud = 200;
    	
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("ѩ�ﴺ��ֻ����ս����ʹ�á�\n");
    	    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("�����ڵ������ʺ��赸��\n");
    	
    	if (me->query("force")< 100)
    		return notify_fail("ѩ�ﴺ��������Ҫ100��������\n");
    	if (userp(me))	me->add("force",-100);
    		
    	me->set("timer/pfm/hs_chunxin", time());
		
		// + 200 force for everyone, self = +100
		me->add_temp("pfm/free_perform",1);
		   		
    	msg = HIG"
��ѩ�߲���С���´䣬���������ɽ���ŴҴҡ�$N��ָ���ۣ�������ӯ��ݺݺ
������Ү��Ү�������ǻã���������ˣ���������ĸ�����Ц��÷��ѩ�￪�١�
�����ȣ���Ҷ��֦��������ժ�����˴��������ˡ�������\n"NOR;

		message_vision(msg, me);
		
		team1 = me->query_team();
		if (!team1 || sizeof(team1)<2)	team1 = ({ me });
		    		
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (team[i]->query("force") < team[i]->query("max_force")*2) {	
				if (team[i]->query("force") + cloud < team[i]->query("max_force") *2)
					team[i]->add("force",cloud);			
	    	} else
	    		team[i]->set("force", team[i]->query("max_force")*2);
	    	team[i]->force_status_msg("force");
	    	tell_object( team[i],YEL"�����������紺�ٴ�أ�һ����֮���������������澭������\n"NOR);
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
    	me->perform_busy(1);
    	return 1;
}


