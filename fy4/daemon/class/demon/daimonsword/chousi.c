// ������ɽ������ӯ�䣬��Ŀ�����������̾��������˼��ɱʽ,annie 6.29.03
// A DEBUFF SKILL.

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) 
{
	int i, skill,dmg;
	object weapon,ob;
	string obn;

	skill = me->query_skill("daimonsword",1);
	if (skill < 180)
		return notify_fail(HIG"����˼��ɱʽ��"NOR"������Ҫ180����̾������\n");
	
	if (!me->is_fighting())
		return notify_fail(HIG"����˼��ɱʽ��"NOR"ֻ����ս����ʹ�á�\n");
	
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

	weapon=me->query_temp("left_hand");
	if (!weapon)
		weapon=me->query_weapon();
	message_vision(HIW"\n$N"HIW"������Ȱ�Ʈ��$n"HIW"��ǰ��Ө�������������$n"HIW"��ǰ̽ȥ������
"HIG"$n"HIG"��ʧɫ����æ���з�ס$N"HIG"����ȴ����$N"HIG"����"+weapon->name()+HIG"�Ѿ�����������ֱ�̶��¡�\n" NOR, me, target);

	dmg=ANNIE_D->debuff(target,"all",1);
	if (dmg)
	{
		dmg = COMBAT_D->magic_modifier(me, target, "kee", dmg*1000);
		target->receive_damage("kee",dmg,me);
		target->receive_wound("kee",dmg,me);
	    COMBAT_D->report_status(target);
	}
	me->perform_busy(1);
	return 1;
}

