// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int lvl, num, i;
	mapping buff;
	object *team, *team1;
		
	if (me->query("class")!= "wudang")
		return notify_fail("ֻ���䵱���Ӳ���ʹ�������ܾ���\n");
		
   	if((int)me->query_skill("qixing",1) < 150 )
   	     return notify_fail("�����Ǿ�����Ҫ150�����Ƿ���\n");
      	
    	if( target ) 
    		return notify_fail("�����Ǿ�������Ҫָ��Ŀ�ꡣ\n");
    
    	target = me;
    	
	if( ANNIE_D->check_buff(target, "armorup")
		|| ANNIE_D->check_buff(target,"damageup")
		|| ANNIE_D->check_buff(target,"powerup2"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��ľ��ˡ�\n");

    	if(me->query("mana") < 200 )
        	return notify_fail("�����Ǿ�����Ҫ200�㷨����\n");
    	if (userp(me))	me->add("mana", -200);
       	
       	msg = HIR"\n\n$N���������дʣ�������â��$Nͷ�������������$N��Χ��\n"NOR ;
	
	message_vision(msg, me);
//	50 + 200 = 250	/5 = 50, capped at 50	
	lvl = me->query_skill("spells")/5;
                
        team1 = me->query_team();
	
	if (!team1 || me->query_skill("qixing",1)< 200) {
		buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup2",
			"att":"bless",
			"name":"���Ƿ��������ܾ�",
			"buff1":"apply/armor",
			"buff1_c":lvl,
			"buff2": "apply/damage",
			"buff2_c": lvl,
			"time":   300,
			"buff_msg":HIR"��â���䣬����ס$N��ȫ��\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	}else {	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if ( ANNIE_D->check_buff(team[i],"damageup")
				|| ANNIE_D->check_buff(team[i],"armorup")
				|| ANNIE_D->check_buff(team[i],"qixingup")
				) continue;
			buff =
			([
				"caster":me,
				"who":  team[i],
				"type":"powerup2",
				"att": "bless",
				"name": "���Ƿ��������ܾ�",
				"buff1":"apply/armor",
				"buff1_c":lvl,
				"buff2": "apply/damage",
				"buff2_c": lvl,
				"time":   300,
				"buff_msg":HIR"��â���䣬����ס$N��ȫ��\n"NOR,
			]);
			ANNIE_D->buffup(buff);
		}
        }
	me->perform_busy(1);
    	return 1;
}
