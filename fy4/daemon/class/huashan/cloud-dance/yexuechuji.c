//	Busy : ENchance = 380*100/130 = 292

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, bonus, mod, total, enhance;
	
	if (me->query("class")!="huashan") 
		return notify_fail("�÷�Ʈ����ġ�ҹѩ�������ǻ�ɽ�ɾ�����\n");
		
	extra = me->query_skill("anxiang-steps",1);
	bonus = me->query_skill("cloud-dance",1);
	
	if ( userp(me) && extra < 100) return notify_fail("��ҹѩ��������Ҫ100���İ��㸡Ӱ��\n");
	if ( bonus < 100) return notify_fail("��ҹѩ��������Ҫ100���Ļ÷�Ʈ���衣\n");
	
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
		
	message_vision(WHT"\n$N"+WHT"����Ӱ��Ȼ������ʲ������ƺ�������������õ�Ʈ�ơ�\n"NOR, me); 
	message_vision(WHT"��ҹѩ�ں�÷��Ʈ�䣬ѩ���趯֮�䣬����������㸡����\n"NOR, me); 
	
	total = bonus + extra;
	if (total > 380 ) total = 380; 
	enhance = total *100/130;
	
	if (COMBAT_D->do_busy_attack( me, target, "cloud-dance/yexuechuji", "step", enhance, mod))
	{
		message_vision(WHT"\n$N"+WHT"������Խ��Խ����������������ã����ѩ�\n"NOR, target); 
 		message_vision(HIG"�����ư����У�$N"+HIG"������Щ����������\n\n"NOR, target); 
		target->set_temp("busy_timer/cloud-dance",time());
		target->force_busy(3);
	}
	else{
		message_vision(YEL"\n$N"+YEL"���Ĺ�һ����Ϊ$n"+YEL"������һ��̤��������$n"+YEL"�Ŀ��ţ�\n\n"NOR, target, me); 
		me->perform_busy(2);
	}
	return 1;
}
