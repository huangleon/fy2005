// Silencer @ FY4 workgroup. Feb.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int skill, atk, lmt, j, i,duration;
		string *perform_msg = ({
			WHT"	�ȷ�\n"NOR,
			HIR"		Ѫ��\n"NOR,
			WHT"			������\n"NOR,
			HIR"				�˶ϳ�\n"NOR,
			WHT"			��	\n"NOR,
			HIR"  		��	\n"NOR,

		});

		skill = me->query_skill("wolf-strike",1);
    	if( skill < 150 || me->query_skill("summonwolf",1)< 150) 
			return notify_fail(" ����֫����Ҫ150�������ǰ���ȭ�ͻ�������\n");

    	// duration = 90sec.
		duration = me->query("timer/pfm/wm_canzhi")+ 90 -time();
		if (duration>0)
    		return notify_fail("����֫����Ҫ"+chinese_number(duration)+"�������ٴ����á�\n");
    	
    	if( !target ) target = offensive_target(me);
    	if( !target
      		||      !target->is_character()
      		||      !me->is_fighting(target) )
			return notify_fail("����֫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		lmt = 6;
    	atk = skill;	// +200��
    		 
    	message_vision(HIB"\n
$N��ʽһ�䣬�������ݶ��쳣��ʮָ����ʮ��������ɲ��֮����ѹ������У���\n"NOR, me);
		    	
    	me->add_temp("apply/attack", atk);
    	
    	for(i=1;i<=lmt;i++)
    	{
	    	msg =  perform_msg[i-1];
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);					
//			if (!target->query_temp("damaged_during_attack")) break;
			if (me->is_busy())		break;
    	}

    	me->add_temp("apply/attack",-atk);
    	me->set("timer/pfm/wm_canzhi", time());  	    	
    	me->perform_busy(1);

        return 1;
}

