// ������ɽ������ӯ�䣬��Ŀ�����������̾��������˼��ɱʽ,annie 6.29.03
// A BUFF SKILL.

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) 
{
	int i, skill ;
	object weapon,ob;
	string obn;

	skill = me->query_skill("daimonsword",1);
	if (skill < 180)
		return notify_fail(HIG"����˼��ɱʽ��"NOR"������Ҫ180����̾������\n");
	
	if (!me->is_fighting())
		return notify_fail(HIG"����˼��ɱʽ��"NOR"ֻ����ս����ʹ�á�\n");
	
	if (me->query_temp("buff/berserk_attack"))
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
 	if(me->query_temp("feat"))
	 	if(sizeof(me->query_temp("feat")))
 			return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	
	if (userp(me))
	{
		if (me->query("class")!= "demon")
			return notify_fail("ֻ��ħ�̵��Ӳ���ʩչ"HIG"����˼��ɱʽ��"NOR"��\n");

		if (!me->query("marry") || me->query("divorced"))
			return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");

		ob = FINGER_D->acquire_login_ob(me->query("marry"));

		if (ob)
			return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");

		if (me->query("potential") - me->query("learned_points") < 250)
 			return notify_fail(HIG"����˼��ɱʽ��"NOR"���������˵�Ǳ�ܣ����Ǳ�����㣬�����;��ƿݡ�\n");

		me->add("learned_points",250);	// pay 'potz,snicker	// was 100,increase de 250 for new function 07.01.2003,annie
	}
	
	me->start_busy(1);
	
	weapon = me->query_temp("weapon");
	obn = me->query("marry_name");

	message_vision(MAG "\nһ��㱼䣬$N�ƺ��ּ�����"+ obn + HIG"�������ף���Ȼ����ɫ����Ө�����飬�����Ц�գ���\n" NOR, me);
	message_vision(WHT "��������������Ŀ��������ư�һĻĻ������$N��ǰ��\n\n" NOR, me);
	message_vision(RED "$N���챯����Х��˫Ŀ���࣬״��転����ʹ��һ��ƴ���򷨣���Ȼ����������\n" NOR, me);

    me->set_temp("buff/berserk_attack",1);
	me->set_temp("buff/berserk_skill","daimonsword");
	me->set_temp("buff/berserk_attack_msg",MAG"\n$N�ܲ��������˷�����$n��ȥ��\n"NOR);
	me->set_temp("feat/chousibuff",1);

	me->set_temp("feat/precision",200);	// double hitrate
	me->set_temp("feat/mighty",200);	// double damage	 ; annie 7.01.2003

	me->set_temp("counter_action_extra",1);
	me->set_temp("counter_msg",MAG"\n$N�����ò���ǰ������һ������$n��\n\n"NOR);
	me->add_temp("apply/haste",150);
	me->add_temp("apply/parry",200);
	me->add_temp("apply/dodge",-400);
	me->add_temp("apply/dual_attack",150);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);
	return 1;
}


int remove_effect(object me)
{
	if(!me) return 0;
	me->delete_temp("apply/dual_attack",150);
	me->delete_temp("buff/berserk_attack");
	me->delete_temp("buff/berserk_skill");
	me->delete_temp("buff/berserk_attack_msg");
	me->delete_temp("feat/chousibuff");
	me->delete_temp("counter_action_extra");
	me->delete_temp("feat/precision",200);
	me->delete_temp("feat/mighty",200);
	me->add_temp("apply/haste",-150);
	me->add_temp("apply/parry",-200);
	me->add_temp("apply/dodge",400);
	message_vision(HIY "��������ƽ�ţ���ȥ������ˮ�̣�ȴ����Ҳ������ء�\n$N����ƽ������������¶��һ˿��Ĩ��ȥ�����ơ�\n" NOR, me);
	me->perform_busy(4);	// busy 4 due lost effect
	return 1;
}
