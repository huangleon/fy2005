// yawn pfm
// *bored,#10 *yawn,*bored annie
// ����ר��pfm? doubt

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, busy,busy2,pp=0,pd=0;
	object * pros,weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���λÿջ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query("marry"))
		return notify_fail("����ͷ��������޷�ʩչ���λÿջ�����\n");
	
	if (me->query("quest"))
		return notify_fail("����ͷ���й���޷�ʩչ���λÿջ�����\n");

	if (me->query_skill("zen",1) < 51)
		return notify_fail("������δ���޷�ʩչ���λÿջ�����\n");
	
	if (me->query_skill("zen",1) < 51)
		return notify_fail("������δ���޷�ʩչ���λÿջ�����\n");
	
	extra = me->query_skill("sword");
	extra /= 4;
	
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",me->query_skill("zen",1));	

	msg =  CYN"$N˫��΢�ϣ�ֻ�����¿��ޣ�������ɺ����$w���������ֻ��裬���һ���$n��\n" NOR;

	pros = target->query_temp("protectors");
	target->delete_temp("protectors");
	busy = target->query_busy();
	busy2 = target->query("no_busy");

    msg +=  YEL"�Ρ�"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIB"$Nֻ�����������紺��һ��������������ζ��Ŀ�⽥�����롣\n",target);
		target->delete("no_busy");
	}
    msg =  NOR YEL  "�á�"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack") && !target->query("boss") && !target->query("big_boss"))
	{
		message_vision(HIB"������ʱ����������ư�����$N��ǰ��$N���������������ٻ���\n",target);
		target->force_busy(1);
	}
    msg =  NOR YEL  "�ա�"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIB"���׾�ʱ�����������ع�������һ���޳ɣ�$N���ɾ�����ͷһƬãȻ��\n",target);
		pp = extra * 2;
		pd = me->query_skill("zen",1);
		target->add_temp("apply/parry",-pp);
		target->add_temp("apply/dodge",-pd);	
	}
    msg =  NOR YEL  "����"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack") && !target->query("no_drop") && !target->query("boss") && !target->query("big_boss") && (weapon=target->query_temp("weapon")))
	{
		if (random(me->query("combat_exp") + target->query("combat_exp")) > target->query("combat_exp") / 2 * 3)
		{
			if (weapon->query("skill_type") != "throwing" && weapon->query("skill_type") != "ring" && weapon->query("skill_type") != "unarmed")
			{
				message_vision(HIB"$N���������ң���ǧ�����������Լ�����֮��������̾Ϣһ����������"+weapon->name()+HIB"�۶ϡ�\n"NOR,target);
				weapon->unequip();
				if(weapon->query("owner"))
				{
					weapon->set("orig_name", weapon->query("name"));
					weapon->set("weapon_prop/damage",1);
				}
				else
					weapon->set("weapon_prop",0);
				target->reset_action();
				weapon->set("name","�ϵ���" + weapon->query("name"));
				weapon->set("item_damaged", 1);
				weapon->set("value",0);
				weapon->save();
			}
		}
	}

	target->set_temp("protectors",pros);
    me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);	
	me->perform_busy(3);
	target->perform_busy(busy);
	target->set("no_busy",busy2);
    target->add_temp("apply/parry",pp);
	target->add_temp("apply/dodge",pd);	
	
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

