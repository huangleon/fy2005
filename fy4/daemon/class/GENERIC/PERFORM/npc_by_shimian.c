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
	int skill, your_exp, my_exp, damage, mod;
	 	
    	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
	
	inv = all_inventory(me);
	instr = filter_array(inv,(: $1->query("timbre") :));
	if (!instr || !sizeof(instr)) 
		return notify_fail("������û��Я��������\n");
		
	skill = me->query_skill("music",1);	
	
	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʮ���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if (target->is_busy())
        	return notify_fail("�Է���æ���ң��ķ����ң���Ͼ�˼����������\n");
        	
               
	message_vision(HIB"
$N�����������ָ����ң���������ҹĻ�ͳ����������أ�˲��������أ�����
����׹�������֮���н�����������������������������������������֮��Թ
�������ߣ�Ϊ�����������׳�ߣ�Ϊ�������迶��֮�����������������ݺᣬ
�������飬�򵶱�������ź���������������\n\n"NOR,me);
	me->start_busy(1);	

	mod = COMBAT_D->can_busy(me, target, "music");	
	if (!mod)
		return notify_fail(HIW"���������������ᱻ���������ŵġ�\n"NOR);
	
	my_exp = me->query("combat_exp");
	your_exp = target->query("combat_exp")*mod;
		
	if ( my_exp/2 + random(my_exp)*3 > your_exp ) {
		message_vision(MAG"$N������ʮ�����֮�У������ͻ���������ѡ�\n"NOR,target);
		target->force_busy(2);
	}
 	else {
 		message_vision(WHT"$N��¶΢Ц���������񣬲�Ϊ�������������������Ȼ������\n"NOR,target);
 		COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);
	}
	return 1;
 		
}
