//	����˪��÷������multiple enemies, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	object wp,weapon;
	int cost, extra, myexp,yourexp, i;
	int base,duration;
	string msg, msg2, skill;
	object	*enemy;
	mapping buff;
	
	if (me->query("class") != "legend") 
		return notify_fail("ֻ����ѩ���ӿ���ʹ�á���������\n");
	
	extra = me->query_skill("six-sense",1);
	if( extra < 230 || me->query_skill("qidaoforce",1)< 150)
		return notify_fail("����������Ҫ230�������鰵ʶ��150������ķ���\n");
	
	wp = me->query_temp("weapon");
	
		
	duration = me->query("timer/pfm/tx_juwei")-time() + 180;
    
    if (extra>=300)	duration = duration -60;
    else if (extra>=270)	duration = duration-30;
    
    if (duration>0)
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration)+"�������Ҳ��ܹ��ٴ�ʹ�þ�������\n");
    
    if(!wp)
    	return notify_fail("��������������϶̸赶�������������ʹ�á�\n");
    
    if( !me->is_fighting() )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");
			
	if(wp->query("skill_type") == "blade" && me->query_skill_mapped("blade")=="shortsong-blade"){
		msg=HIW"\n$NĿ������������һ�����һ�����϶��´�ֱ���䣡
��һ�����ƷǷ���������;���ֱ��ʮ����б�����������޿ɱܡ�\n\n"NOR;
		msg2 = WHT"$N���磬š����"+wp->name()+NOR+WHT"�����׻��¡�\n"NOR;
	} else if (wp->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "diesword") {
		msg = HIW"$N�Ľ�����Ȼ���ˣ�һ��ƽ����"+wp->name()+NOR+HIW"����Ȼ������һ���⻪��Ŀ�����ǡ�
��������������ǣ�����׽�������ɵ�����\n\n"NOR;
		msg2 = WHT"$N�Ų�΢����������"+wp->name()+NOR+WHT"�������¡�\n"NOR;
	} else
		return notify_fail("��������������϶̸赶�������������ʹ�á�\n");
		
	message_vision(msg, me);
	
	me->set("timer/pfm/tx_juwei",time());
		
	enemy =	me->query_enemy();
	
	me->add_temp("apply/attack", extra*2);		
	me->add_temp("apply/damage", extra*2);
	for (i = 0 ; i< sizeof(enemy); i++) {	
		if( enemy[i]&& enemy[i]->is_character()
        		&& me->is_fighting(enemy[i]) && !me->is_busy() )               
		{	
			target = enemy[i];
			target->add_temp("cant_parry",1);  
			target->add_temp("cant_dodge",1); 									       			
	   		message_vision(msg2,me,target);
	   		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	   		target->add_temp("cant_parry",-1);
	   		target->add_temp("cant_dodge",-1);
	   		if (!userp(target))
	   			target->add_hate(me, extra*5);
	   		
	   		if (target->query_temp("damaged_during_attack")
	   			&& ANNIE_D->check_buff(target,"fight_stop")<1) {
		  		buff =
				([
					"caster":me,
					"who":target,
					"type":"fight_stop",
					"att":	"curse",
					"name": "����ķ�������",
					"time":  10,
					"buff1": "marks/fight_stop",
					"buff1_c":	1,	
					"buff_msg":"",
					"disa_type": 1,
				]);
				ANNIE_D->buffup(buff);	 				
	   		  }
       	}
	}	        		
	
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*2);    
	me->perform_busy(1);
	
	return 1;
}

