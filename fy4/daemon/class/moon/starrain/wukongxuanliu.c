// annie 07.2003
// dancing_faery@hotmail.com

// Cast on busied npc only. (cast after npc pfm)
// A: zero self busy. high hitrate.
// D: damage self if failed(up to 200 kee). reduce target busy by 1 if failed. 18sec cooldown time. 
//    cannot use to issue 'first strike'. very bad against ������ת npc. high throwing cost. 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,temp1;
	object weapon,*pros,shadow,newweapon;
	int attack_points, dodge_points,skill,count,i,j,k,level,num1,mod,duration;

	if (me->query("class")!="moon" && userp(me))
		return notify_fail("���޿�������Ϊ��¹��ؼ���\n");
	
	skill = me->query_skill("starrain",1);	
	if (skill < 50)
		return notify_fail("���޿���������Ҫ����50���ĺ���������\n");

	if (me->query_skill_mapped("force") != "snowforce")
       	return notify_fail("���޿�������������ѩ�ľ�������\n");	// limit enforce

	duration = me->query("timer/pfm/pyramid") + 12 -time();
	if (duration >0 )
       	return notify_fail("�㻹��ȴ�"+ duration + "���Ӳ����ٴ�ʩ�����޿���������\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���޿�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!target->is_busy())
		return notify_fail("��������δ�ͣ����ԡ��޿���������ס��ֻ�²�̫���ס�\n");

	mod = COMBAT_D->can_busy(me, target, "starrain");	
	if (!mod)
		return notify_fail("���������鶯�����ԡ��޿���������ס��ֻ�²�̫���ס�\n");
		
	if (target->query_busy()>=3)
		return notify_fail("�����Ѿ��ڼ���æ�����ˣ�>3������ץ��ʱ������ɡ�\n");

	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 10)
		return notify_fail("������Ҫ10ö������\n");

	if (userp(me))	weapon->add_amount(-10);
	me->set("timer/pfm/pyramid",time());

	msg = HIW"\n$N"HIW"΢΢һЦ��ͻȻ��ת���䣬ֻ�����䴦��ϼǧ�ƣ����ǵ�����â
�������꣬��к�㸲��ֱ����졣\n"NOR;
	message_vision(msg,me,target);
	msg = WHT"��â������$n"NOR+WHT"��࣬˿˿��ۣ�����ʴ�ꡭ��\n"NOR;
	message_vision(msg,me,target);

	if (COMBAT_D->do_busy_attack( me, target, "starrain/wukongxuanliu", "unarmed", 400, mod))
	{
		if (target->query_busy() <3)
		{
			target->force_busy(3);
			target->set_temp("busy_timer/starrain",time());
		}
	}
	else
	{
		msg = HIR BLK"$N"HIR BLK"һ�����ģ��������һ����Ѫ������������ɢ��$n"HIR BLK"Ҳ���Ƶ��ѡ�\n"NOR;
		message_vision(msg,me,target);
		if (target->query_busy() == 1)
			target->stop_busy();
		else
			target->force_busy(target->query_busy()-1);
			me->receive_damage("kee",skill,target);	
	}
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

