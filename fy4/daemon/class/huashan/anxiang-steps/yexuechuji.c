//	Busy : ENchance = 200*100/85 = 235

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, enhance,mod;
	
	if (userp(me) && me->query("class")!="huashan")
		return notify_fail("��ҹѩ������Ϊ��ɽ�ؼ���\n");
		
	extra = me->query_skill("anxiang-steps",1);
	if ( extra < 50) 
		return notify_fail("��ҹѩ��������Ҫ50���İ��㸡Ӱ����\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("��ҹѩ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	
	mod = COMBAT_D->can_busy(me, target, "cloud-dance");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
		
	message_vision(WHT"$N����Ӱ��Ȼ������ʲ������ƺ�������һ�Ƶ����İ���\n"NOR, me); 
	message_vision(WHT"��ҹѩ�ں�÷��Ʈ�䣬ѩ���趯֮�䣬����������㸡����\n"NOR, me); 
	
	if (extra > 200) extra = 200;
	enhance = extra * 100/85;
			
	if (COMBAT_D->do_busy_attack( me, target, "cloud-dance/yexuechuji", "step", enhance, mod))
	{
		message_vision(HIW"\n$N"+HIW"������Խ��Խ����������������ã����ѩ�С�\n"NOR, target); 
 		message_vision(HIG"�����ư����У�$N"+HIG"������Щ����������\n"NOR, target); 
		target->set_temp("busy_timer/cloud-dance",time());
		target->force_busy(3);
	}
	else{
		message_vision(YEL"\n$N"+YEL"���Ĺ�һ����Ϊ$n"+YEL"������һ��̤��������$n"+YEL"�Ŀ��ţ�\n"NOR, target, me); 
		me->perform_busy(2);
	}
	
	return 1;
}
