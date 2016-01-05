// heart_sense.c
// silencer@fy4 -------- this is the revive skill ------------
// 	Heart_sense can be used at corpse

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
		int skill, extra, exp_recovered,rate,t;
		string victim_id;
		object victim,room;
		mapping buff;
	
		if(me->query("class")!="bonze")
			return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�ð�ʶ��ͨ��\n");
	
		skill = me->query_skill("essencemagic",1);
		if( skill < 100)
        	return notify_fail("��ʶ��ͨ��Ҫ100����ʶ��ͨ��");
                
		if( !target || !target->is_corpse())
			return notify_fail("��ʶ��ͨ����ָ�����壨conjure heart_sense on corpse����\n");
	
		if (!target->query("victim_player"))
			return notify_fail("��ʶ��ֻͨ��ʹ������ҵ������ϡ�\n");
	
		if (!(victim_id = target->query("victim_id")))	
			return notify_fail("��ʶ��ͨ����ʹ���ڴ��������ϡ�\n");

		if (target->query("already_revived")|| !target->query("real_death"))
			return notify_fail("���ʬ���Ѿ��������ظ�ʹ����ʶ��ͨ����ؼ��ˡ�\n");
			
		victim = find_player(victim_id);
	
		if (!victim || !userp(victim))
			return notify_fail(victim_id+"���ڷ��������ڡ�\n");
				
		if( !victim ->is_ghost())
			return notify_fail("�����Ѿ�����ڤ���ˡ�\n");
	
		if (!mapp(victim->query("death")) || victim->query("death/half_quest")>=0
			|| victim->query("death/revived"))
			return notify_fail("��������ʹ�ûظ����ؼ���\n");
			
		if (!victim->query("env/revive"))
        	return notify_fail("���˲�Ը�ⱻ��ʩ��ʶ��ͨ����Ҫ�Է�Set revive 1��\n"); 
        	
       	if (victim->query_busy() || environment(victim)->query("no_revive"))
				return notify_fail("���ڲ��ܶԴ���ʩ��ʶ��ͨ��\n");
	
		if (victim->query("score") < 5)
			return notify_fail("��ʶ��ͨ���������ĶԷ�5�����ۡ�\n");
		
		if( me->query("atman") < 500 ) 
			return notify_fail("��ʶ��ͨ��Ҫ��������������\n");
    	me->add("atman", -500);
		victim->add("score",-5);
		target->set("already_revived",1);
		
		message_vision(WHT "$Nһ��ֱ������ǰ��һ����ǰ΢����ָ����Ŀ������������֮�䣬
�ϟo��������ҹ������٤��ҹ���ߵ�ҹ����������������
�������ߡ�Ϥ���������������ߡ������m��
�������ߡ������m�ࡡ
٤��ā��٤٤�ǡ��׶�����������X\n\n" NOR, me);	

		tell_object(victim, WHT"ڤڤ�к�Ȼ����һ��ͳ��ķ�ţ�
�ϟo��������ҹ������٤��ҹ���ߵ�ҹ����������������
�������ߡ�Ϥ���������������ߡ������m��
�������ߡ������m�ࡡ
٤��ā��٤٤�ǡ��׶�����������X\n\n" NOR);	
	
	   	message_vision( HIW"$N������ҵز����ţ���Ȼ��һ����âע��$N�Ķ��š�\n",victim);
		message_vision( HIW "��âԽ��Խǿ�ң�$N���ɼ�������������"NOR,victim);
	
		message_vision(HIW"��Ȼһ���׹���������ǰ�ƺ����˸���Ӱ��\n"NOR, me);
		tell_object (victim, "\n\n\n");
		tell_object(victim, HIR "�㸴���ˣ���\n"NOR);
		
		skill = me->query_skill("essencemagic",1);
		
		if (skill >= 200)		rate = 90;
		else if (skill>= 180)	rate = 80;
		else if (skill>= 140) 	rate = 70;	
		else if (skill>= 100) 	rate = 60;	
		
		t = victim->query("death/exp_lost")*rate/100;
				
		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) ʹ��heart_sense�ָ��� %s(%s) %d ����ʧ��\n",
	    		ctime(time()),me->name(1), geteuid(me), victim->name(1),geteuid(victim), t ));

		t = victim->query("death/half_quest")+ t;
		victim->set("death/half_quest",t);
		if (t>=0)	{
			t = 0;
			victim->delete("death/half_quest");
			victim->delete("death/exp_lost");
		}
		   				
//		write ("recover to "+ victim->query("death/half_quest") + "\n");    	
	
		// Remove mengpo things.
		ANNIE_D->debuff(victim,"mengpo-soup");
		victim->delete_temp("marks/ready_incar");
    	victim->set("startroom", AREA_FY"church");

		victim->reincarnate();
		victim->set("env/revive",0);
		victim->add("marks/revived",1);

		me->add("annie/11_revive_others_heart",1);
		
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
