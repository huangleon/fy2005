// silencer@fengyun4. workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod,duration;
	int damage;

   	if(me->query("class")!="shenshui")
    	return notify_fail("ֻ����ˮ�����Ӳ���ʹ����׷�����ľ�����\n");

	extra = me->query_skill("nine-moon-steps",1);
	
	if ( extra < 180 || me->query_skill("nine-moon-claw",1)< 170
		|| me->query_skill("nine-moon-spirit",1)< 170
		|| me->query_skill("chaos-steps",1) < 120 ) 
		return notify_fail("��׷��ʽ����Ҫ180����������120���������ǲ���170��������ץ��170���Ů�񹦡�\n");

	if (me->query_skill_mapped("force") != "nine-moon-force")
		return notify_fail("��׷��ʽ����Ҫ�����ľ�����ϡ�\n");
	if (me->query_skill_mapped("unarmed") != "nine-moon-claw")
		return notify_fail("��׷��ʽ����Ҫ������צ����ϡ�\n");
	
	duration = me->query("timer/pfm/zhuimin") + 120 
			- time()- F_ABILITY->check_ability(me,"zhuiming_add")*5;
	if (duration>0)
		return notify_fail("����Ҫ�ȴ�"+duration+"������ٴ�ʹ�á�׷��ʽ����\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��׷��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	mod = COMBAT_D->can_busy(me, target, "nine-moon-steps");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�ֱ������­�ա�\n");

	me->set("timer/pfm/zhuimin",time());
	message_vision(HBRED+HIW"$N"HBRED+HIW"�����������������Ű��Է�λ���Ų���������Ȧ�ɽ���\n"NOR,me,target);
	
	if (COMBAT_D->do_busy_attack( me, target, "nine-moon-steps/lianhuanbu", "rev-unarmed", 100, mod))
	{
		message_vision(WHT"΢���Ȼ��$N"NOR+WHT"�ѵ���$n"NOR+WHT"���$n"NOR+WHT"�������ѣ��޷���ʩ!\n"NOR,me, target);
		target->force_busy(2);
		target->set_temp("busy_timer/nine-moon-steps",time());
	}
	else{
		message_vision(YEL"$n"NOR+YEL"ʩչ�����Ṧ��ٹ�ĴӸɷ��Ƶ���λ������������\n\n"NOR,me, target);
	}

	// 2.7M 900	
	// 6.4M 200*2 + 180 + 180 + 200*2 + 103 *3 = 1469
	// full 200*2  +180 + 180 + 200*2 + 140 *3 = 1580
	extra =   me->query_skill("nine-moon-claw",1)*2 
		+ me->query_skill("nine-moon-steps",1)
		+ me->query_skill("nine-moon-force",1)
		+ me->query_skill("nine-moon-spirit",1)*2
		+ F_LEVEL->get_level(me->query("combat_exp"))*3;
			
	// + atk 240 -> 308, dmg 240 -> 308, a normal one-hit perform.	
	me->add_temp("apply/attack", extra/7);	
	me->add_temp("apply/damage", extra/5);
	msg = HIW"$N"HIW"�����������������䣬Ѹ���ޱȣ�����Ȱ��۵�$n"HIW"��ߣ�
��������������֣������ָ��ץ$n"HIW"$l��\n"NOR ;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -extra/7);
	me->add_temp("apply/damage", -extra/5);
                                
	if (target->query_temp("damaged_during_attack")	)
	{
		message_vision(HIW"\n$N"+HIW"һ�е��֣�������ͣ�����Ƽ������ָ����$n"+HIW"��ͷ��������ȥ��\n"NOR,me,target);
		if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw", "unarmed", 500, 10))
		{
			damage = extra;
			damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
			target->receive_damage("kee",damage, me);

			extra=0;

			if (target->query("kee") < 0)
			{
				if ( time() - target->query("timer/lifesave") >= 3600 )
				{
					message_vision(MAG"ֻ���ã�������һ����$n"MAG"��ָ�Ѳ���$N"+MAG"���ţ�һ�Ƶ������������ڶ���\n"NOR,target,me);
					extra=1;
				}
			}
			else
				message_vision(MAG"$N"+MAG"�ҽ�һ���������ѱ�$n"+MAG"��������ס��\n"NOR,target,me);

			COMBAT_D->report_status(target);

			if (extra==1)
				message_vision(HIW"\n$N"HIW"������צ����������$n"HIW"���ų����ָ�⣬¶��΢΢Ť����Ц�ݡ�\n\n"NOR,me,target);

		}
		else	
			message_vision(YEL"$N"NOR+YEL"���Ų�æ����ǰ�벽���ܿ�������Ҫ����\n"NOR,target);
	}

	if (target)	target->stop_busy();	// DOn't make it a 100% busy for teammate.
	me->perform_busy(2);
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
