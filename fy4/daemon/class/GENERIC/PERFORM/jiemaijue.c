#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon, *inv, env;
		int i, amount;
						
		p_name = "jiemaijue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
		
		if( me->is_fighting()) {
        	tell_object(me,"ս�����˹����ˣ�������\n");
        	return 1;
        }
		
		if (me->query("force")< 300)
			return notify_fail("������Ҫ300��������\n");
		if (userp(me))
			me->add("force",-300);
		
		message_vision(RED"$N���ּ����˴���Χ����ָ�滺���磬�ձ�����Ʈ�ݣ�����ʮ������Ѩ����ʹ
��ʮ���ֲ�ͬ�ַ�����ÿһ�㶼ǡ����Ѫ����������֮�ʡ�\n"NOR,me); 		
		
		tell_object(me,"������ƺ���һЩ��\n");

		amount = me->query("max_kee")/3;
		amount = COMBAT_D->magic_modifier(me, me,"kee",amount);
		me->receive_curing("kee", amount);			
		
		amount = me->query("max_gin")/3;
		amount = COMBAT_D->magic_modifier(me, me,"gin",amount);
		me->receive_curing("gin", amount);			
		
		amount = me->query("max_sen")/3;
		amount = COMBAT_D->magic_modifier(me, me,"sen",amount);
		me->receive_curing("sen", amount);			
				
		
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		return 1;
}
