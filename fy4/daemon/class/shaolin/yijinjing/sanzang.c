// Silencer@fy4 workgroup
// Add 75%-125% force instantly every 15mins.
//	�Ķ���������һ��һ�ţ���Ȼ��ʩ������������Գ����糱֮�ǣ�����֮����

#include <ansi.h>

int exert(object me, object target)
{
	int extra,force, max_force, bonus, duration;
	
	if(me->query("class")!="shaolin")
		return notify_fail("ֻ�����ָ�ɮ����ʹ�á����ؾ���\n");
	
	extra=me->query_skill("yijinjing",1);
	if(extra<200)
		return notify_fail("��Ҫ200���׽����ʹ�á����ؾ���\n");

	duration = me->query("timer/pfm/sl_sanzang")-time()+ 900;
    if (duration>0)
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ�á����ؾ�����\n");

	message_vision(BGRN + WHT"$N�����׽֮���ؾ�������һ��һ�ţ���Ȼ��ʩ������������Գ����糱֮�ǣ�����֮����\n"NOR,me);
	force = me->query("force");
	max_force = me->query("max_force");
	
	bonus = max_force * (75 + F_ABILITY->check_ability(me,"sanzang_add")*5) /100;
	
	if ( force + bonus > 2* max_force)	
		me->set("force",2*max_force);
	else
		me->add("force",bonus);
		
	me->force_status_msg("force");
	me ->set("timer/pfm/sl_sanzang",time());
	return 1;
}


