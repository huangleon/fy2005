// silencer@fengyun  ����ɺ�̶��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int my_exp,your_exp, mod;
	object *weapon;
	int duration;
	int extra, bonus, attack_bonus, damage;
		
   	if(me->query("class")!="shenshui")
    	return notify_fail("ֻ����ˮ�����Ӳ���ʹ������Ⱦ���ơ��ľ�����\n");

	if (userp(me))
	if (me->query_skill_mapped("force")!= "nine-moon-force")
		return notify_fail("�������������ķ��������޷��˵���ʤ��\n");
				
	if (me->query_skill("nine-moon-sword",1) < 200|| me->query_skill("qingpingsword",1)<200)
		return notify_fail("����Ⱦ���ơ���Ҫ200���ľ���������200����ƽ������\n");
		
	duration = 180 - F_ABILITY->check_ability(me,"yrcy_add")*6;
	duration = me->query("timer/pfm/cangyun") + duration - time();
	if (duration>0)
		return notify_fail("���꣬����ͳ�ͺ¿��������ȴ�"+duration+"�룩\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����Ⱦ���ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		me->set("timer/pfm/cangyun",time());
		weapon = me->query_temp("weapon");
    	msg = HIR BLK+"\n$N"HIR BLK"������ɫ��Ȼ����һҧ����"+weapon->name()+HIR BLK"���Լ���໮ȥ������Ľ����н�
$N"HIR BLK"Ʈ�ɵĳ�������Ƶ�������ʻ������������˿�ڿ��з��﷭��\n"NOR;
		msg += CYN"ɢ��ķ��ҷ���$n"NOR+CYN"����ϡ������һ���������㡣$n"NOR+CYN"����һ�ң�
�����û������᲻��һ˿������\n\n"NOR;
		msg += WHT"����֮�䣬ֻ����âһ����"+weapon->name()+WHT"���Ƴ�������ն��ǧ�ᣬ�ֽ�$nü�ġ�\n"NOR;
		message_vision(msg, me, target);
		
		// dmg = (500 + 139)*2 = 1268; atk = (200 + 139)*2 = 678;
				
		bonus = me->query_skill("nine-moon-sword",1) + F_LEVEL->get_level(me->query("combat_exp"));
		bonus *= 2;
		
		extra = me->query_skill("sword");
		extra += F_LEVEL->get_level(me->query("combat_exp"));
		extra *= 2;
		
		me->add_temp("apply/attack", bonus);	
		me->add_temp("apply/damage", extra);
		target->add_temp("cant_dodge",1);
		target->add_temp("cant_parry",1);
		target->add_temp("marks/full_hit_damage",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		target->add_temp("marks/full_hit_damage",-1);
		target->add_temp("cant_dodge",-1);
		target->add_temp("cant_parry",-1);
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -extra);
		
		if (me->query_skill("sword",1)<250)	me->perform_busy(2);
		else if (me->query_skill("sword",1)<300)	me->perform_busy(1);
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
