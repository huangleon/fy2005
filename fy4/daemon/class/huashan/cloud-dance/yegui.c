// silencer@fy4 -------- this is the revive skill ------------
//	L150:������ҹ�须��(dodge.yegui):	����ʬ�崦��������壬70��(L150)��90��(L200)

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{

		int cloud, extra, t, rate,stage;
		object victim, room;
		string victim_id;
		mapping buff;
	
    	if (me->query("class") != "huashan") 
    		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á�����ҹ�须\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	extra = me->query_skill("hanmei-force",1);
    	
    	if (cloud < 150) 
    		return notify_fail("����ҹ��������Ҫ150���Ļ÷�Ʈ���衣\n");
    	    	
    	if (extra<150) 
    		return notify_fail("����ҹ��������Ҫ150���ĺ�÷�ķ���\n");
    	    	
		if (userp(me) && !me->query("scroll/cloud-dance_yegui"))
			return notify_fail("�㻹û���������ҹ������У���Ҫ�ҵ����ܼ����С�\n");
			
    	if (me->query_skill_mapped("force") != "hanmei-force")
			return notify_fail("�÷�Ʈ������輼��Ҫ��÷�ķ���ϡ�\n");
	
		if( !target || !target->is_corpse())
			return notify_fail("����ҹ�����ָ����Ч�������壩��\n");
	
		if (!target->query("victim_player"))
			return notify_fail("����ҹ��ֻ��ʹ������ҵ������ϡ�\n");
	
		if (!(victim_id = target->query("victim_id")))	
			return notify_fail("����ҹ�鲻��ʹ���ڴ��������ϡ�\n");

		if (target->query("already_revived")|| !target->query("real_death"))
			return notify_fail("���ʬ���Ѿ��������ظ�ʹ������ҹ������ؼ��ˡ�\n");
			
		victim = find_player(victim_id);
	
		if (!victim || !userp(victim))
			return notify_fail(victim_id+"���ڷ��������ڡ�\n");
				
		if( !victim ->is_ghost())
			return notify_fail("�����Ѿ�����ڤ���ˡ�\n");
	
		if (!mapp(victim->query("death")) || victim->query("death/half_quest")>=0
			|| victim->query("death/revived"))
			return notify_fail("��������ʹ�ûظ����ؼ���\n");
			
		if (!victim->query("env/revive"))
        	return notify_fail("���˲�Ը�ⱻ��ʩ����ҹ�顣����Ҫ�Է�Set revive 1��\n"); 
        	
       	if (victim->query_busy() || environment(victim)->query("no_revive"))
				return notify_fail("���ڲ��ܶԴ���ʩ����ҹ�顣\n");
	
		if (victim->query("score") < 5)
			return notify_fail("����ҹ�����������ĶԷ�5�����ۡ�\n");
		
		if( me->query("atman") < 500 ) 
			return notify_fail("����ҹ����Ҫ��������������\n");
    	me->add("atman", -500);
    	me->force_status_msg("atman");
    	
		victim->add("score",-5);
		target->set("already_revived",1);
		
		message_vision( WHT "
���¶����������Ϸɣ�$N������ڣ���ָ΢�����������裬��������ƺ�
����Ʈ���仨��ϸ�����������������ǣ������ᡣ����������֮���У�
$N������������ͷ��ˮǧɽ��һ֦�ؼ������볦ǧ�ᣬ�볦ǧ�ᡣ��������\n" NOR, me);
	
		message_vision(WHT"
��ˮ���¹��£�$n�������裬һ�����Ỻ���ε�$N���յ�˫��֮�У�
$Nü��һ���������������ˣ�������ȥ��$N������վ��������\n"NOR,victim,me);
	
	// SCROLL ADVANCE PERFORM, 
    	stage = me->query("scroll/cloud-dance_yegui");
        switch (stage) {
	    	case 1:		rate   	= 60; break;	// L150  c-d
	    	case 2:		rate	= 70; break;	// L170 c-d
	    	case 3:		rate	= 90; break;	// L200	c-d
	    }
	
		t = victim->query("death/half_quest") + victim->query("death/exp_lost")* rate/100;
				
		victim->set("death/half_quest",t);

		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) ʹ��cloudy-dance�ָ��� %s(%s) %d ����ʧ��\n",
	    		ctime(time()),me->name(1), geteuid(me), victim->name(1),geteuid(victim),
	    		victim->query("death/exp_lost")* rate/100));

		if (t>=0)	{
			t = 0;
			victim->delete("death/half_quest");
			victim->delete("death/exp_lost");
		}
		victim->set("death/revived",1);
					    					
//		write ("recover to "+ victim->query("death/half_quest") + "\n");    	
	
		// Remove mengpo things.
		ANNIE_D->debuff(victim,"mengpo-soup");
		victim->delete_temp("marks/ready_incar");
    	victim->set("startroom", AREA_FY"church");

		victim->reincarnate();
		victim->set("env/revive",0);
		
		me->add("annie/11_revive_others_yegui",1);
		victim->add("marks/revived",1);
		
		room = environment(me);
		if (room->query("no_fly"))
		{
			room = find_object(AREA_FY"hiretem");
			if (!room) room = load_object(AREA_FY"hiretem");
		}
		victim->move(room);
		victim->perform_busy(1);
		
		victim->set("death_revive",time());
		victim->set("force",0);
		victim->set("mana",0);
		victim->set("atman",0);
		victim->force_status_msg("all");
		victim->status_msg("all");
		
		// THis just serves as a timer, all checks use query(death/time), so even relogin can't bypass
		buff =
		([
			"caster":victim,
			"who":victim,
			"type":"revive-sickness",
			"att":"curse",
			"name":"���ꡤ��������",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$N�����������˼��㣬��վ��վ�����ˡ�\n"NOR,
		]);
		ANNIE_D->buffup(buff);
		
		me->perform_busy(3);
		return 1;
}


