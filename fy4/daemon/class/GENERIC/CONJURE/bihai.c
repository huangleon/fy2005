// �� ˼· by Sinny/Silencer@fy4.
// ������������ 
// ʮ���������
// ���񳯷����� 
// �̺�������:  
// ����ˮ������
// ����ɢ

#include <combat.h>
#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	object * stuff;
	int skill, your_exp, my_exp, damage, qin, i;
	
	if (me->is_ghost())
		return notify_fail("�����ǹ�꣬�����뷨�Ȼ�����ɡ�\n");
	
	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		   qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("��������Ǵ����ˡ�\n");
	
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("��������һ�ϲ�ͨ��Ϲ���˼��£��پ���Ȼ��ζ��\n");
		if (me->query("annie/music_choose") != 3 && userp(me))
		return notify_fail("���������ƺ�ûѧ������\n");

	if (skill < 150)
		return notify_fail("�㷢�ִ��׹��ڸ��������Ҫ150�����ٵ��������ࡣ\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���̺���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
	if( me->query("atman") < 200 )
		return notify_fail("���̺�����������Ҫ200��������\n");
	if (userp(me)) me->add("atman",-200);
		        
	message_vision(HIB"
$N�����������ָ����ң�������󺣺��������޲���Զ����ˮ�����ƽ�����
�����죬��������ӿ��������ɽ������ˮ����Ծ�����������Ϸ�ХŸ�ɣ�ˮ
�����֣�ȺħŪ����������ɽƮ���������Ⱥ���У��������֮���¡�\n\n"NOR,me);
	me->start_busy(3);	

	// 60+300+139 => 499 + random(499)
	damage = qin + me->query_skill("magic")
			+ F_LEVEL->get_level(me->query("combat_exp"));
	damage = damage + random(damage);
	
	me->add_temp("apply/magic",skill);
	if (COMBAT_D->do_magic_attack(me, target, "magic","sen", 0)){
		message_vision(MAG"
$N����Ƭ�̣����ҡ����ֻ���ؿ���������������泩��������ʱ��һ��
�ļ���Ҫ����ǻ������ȴ�����������������ˡ�\n"NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
		target->receive_damage("sen",damage, me);
		COMBAT_D->win_lose_check(me,target,1);
		COMBAT_D->report_status(target);
	}
 	else {
 		message_vision(WHT"$N��¶΢Ц���������񣬲�Ϊ����������\n"NOR,target);
	}
	me->add_temp("apply/magic",-skill);

	return 1;
 		
}
