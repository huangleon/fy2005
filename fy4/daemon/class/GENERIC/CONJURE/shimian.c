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
	int qin, skill, your_exp, my_exp, damage, mod, i;

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

	if (me->query("annie/music_choose") != 1 && userp(me))
		return notify_fail("���������ƺ�ûѧ������\n");
	
	if (skill < 150)
		return notify_fail("�㷢�ִ��׹��ڸ��������Ҫ150�����ٵ��������ࡣ\n");

	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʮ���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
    if (target->is_busy())
       	return notify_fail("�Է���æ���ң��ķ����ң���Ͼ�˼����������\n");
        	
    if( me->query("atman") < 200 )
		return notify_fail("��ʮ�����������Ҫ��������������\n");
	if (userp(me))me->add("atman",-200);
		        
	message_vision(HIB"
$N�����������ָ����ң���������ҹĻ�ͳ����������أ�˲��������أ�����
����׹�������֮���н�����������������������������������������֮��
Թ�������ߣ�Ϊ�����������׳�ߣ�Ϊ�������迶��֮������������������
�ᣬ�������飬�򵶱�������ź���������������\n\n"NOR,me);
	me->perform_busy(1);	

	mod = COMBAT_D->can_busy(me, target, "music");	
	if (!mod)
		return notify_fail(HIW"���������������ᱻ���������ŵġ�\n"NOR);

	if (COMBAT_D->do_busy_attack(me, target, "music/shimian", "step", 200+qin/2, mod)){
		message_vision(MAG"$N������ʮ�����֮�У������ͻ���������ѡ�\n"NOR,target);
		target->set_temp("busy_timer/music",time());
		target->force_busy(2);
	}
 	else {
 		message_vision(WHT"$N��¶΢Ц���������񣬲�Ϊ����������\n"NOR,target);
	}
	return 1;
 		
}
