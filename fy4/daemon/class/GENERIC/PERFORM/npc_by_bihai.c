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

int perform(object me, object target)
{
	string msg;
	object weapon, *inv, *instr;
	int skill, your_exp, my_exp, damage;
	
    	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
		
	inv = all_inventory(me);
	instr = filter_array(inv,(: $1->query("timbre") :));
	if (!instr || !sizeof(instr)) 
		return notify_fail("������û��Я��������\n");
	else 
		weapon = instr[0];
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���̺���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
      	skill = me->query_skill("music",1);	
      
	message_vision(HIG"
$N�����������ָ����ң�������󺣺��������޲���Զ����ˮ�����ƽ���
�������죬��������ӿ��������ɽ������ˮ����Ծ�����������Ϸ�ХŸ�ɣ�ˮ
�����֣�ȺħŪ����������ɽƮ���������Ⱥ���У��������֮���¡�\n\n"NOR,me);
	me->start_busy(2);	

	my_exp = me->query("combat_exp");
	your_exp = target->query("combat_exp");
	damage = weapon->query("timbre") + me->query_skill("magic");
	damage = damage *2 + random(damage*2);
	// 500*2 + random(500*2)
	if ( my_exp/2 + random(my_exp)*3 > your_exp ) {
		message_vision(MAG"
$N����Ƭ�̣����ҡ����ֻ���ؿ���������������泩��������ʱ��һ��
�ļ���Ҫ����ǻ������ȴ�����������������ˡ�\n"NOR,target);
		target->receive_damage("sen",damage, me);
		COMBAT_D->win_lose_check(me,target,1);
		COMBAT_D->report_status(target);
	}
 	else {
 		msg = WHT"$N��¶΢Ц���������񣬲�Ϊ����������\n"NOR;
		message_vision(msg,target);
	}
	return 1;
 		
}
