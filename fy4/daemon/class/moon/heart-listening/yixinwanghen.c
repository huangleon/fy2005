#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	object obj,owner;
	int duration, sk = me->query_skill("heart-listening",1);
	int a=0;

	if(me->query("class")!="moon" && userp(me))
		return notify_fail("ֻ����¹����˲��ܹ�ʩչ���������ޡ���\n");

	if(me->query_skill("heart-listening",1) < 80 && userp(me))
		return notify_fail("���������ޡ�������Ҫ80������������\n");

	duration = me->query("timer/hypnosis")+ 120 - time();
	if (duration > 0)
       	return notify_fail("���������ޡ�����ȴ�"+duration+"���ӡ�\n");
	
	// NPC self-remove-hate-list hehe :)
	if (!userp(me))	{
		target = me;
		message_vision(WHT"\n$n"WHT"�ܿ�һ�ƣ����κ��������ֶ�ָ���ᰴ��ü�ģ�����¶��һĨЦ�⡣\n"NOR,target,me);
		target->reset_hate();
		return 1;
	}
	
	if( !target ) target = offensive_target(me);        
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target)  || !target->is_fighting(me))
			return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query("mana") < 150  && userp(me))
		return notify_fail("��ķ���������\n");
	if (userp(me))
		me->add("mana",-150);
	me->set("timer/hypnosis",time());
		
	message_vision(WHT"\n$n"WHT"�ܿ�һ�ƣ����κ��������ֶ�ָ���ᰴ��ü�ģ�����¶��һĨЦ�⡣\n"NOR,target,me);
	
	if (COMBAT_D->do_busy_attack(me, target, "heart-listening", "unarmed", 1000, 10)) {
		message_vision(BLU"\n$N"BLU"�Ժ�����˼������ɲ�Ǽ仯����磬ãȻ�޴������$n"BLU"��\n\n"NOR,target,me);
		target->reset_hate();
	} else
		message_vision(YEL"$N��Цһ������Ϊ$n�Ļ���������\n"NOR, target,me);
		
	me->perform_busy(2);
	return 1;
}



/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
