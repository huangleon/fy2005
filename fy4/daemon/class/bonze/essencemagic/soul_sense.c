#include <ansi.h>

int conjure(object me, object target)
{
	int lvl,i;
	mapping buff;
	string msg;

	lvl = (int) me->query_skill("essencemagic",1);	
    if ( lvl < 20)
         return notify_fail("����ʶ����Ҫ20���İ�ʶ��ͨ��\n");
	
	if (target && target!=me && !target->team_member(me))
		return notify_fail("��ʶֻ������������߶��ѡ�\n");
	
	if (!target || target == me )	{
		target = me;
		msg = WHT "$N΢һ���񣬱����۾�ʹ����ʶ��ͨ�е���ʶ������\n" NOR;
	} else
		msg = WHT "$n΢һ���񣬽���ʶ��ͨ�е���ʶʩ����$N����\n" NOR;
	
	
	if (target->query_temp("apply/astral_vision"))
		return notify_fail("���˲���Ҫ��ʶ��ͨ��\n");
	
	if( me->query("atman") < 30 )
		return notify_fail("��Ҫ30���������\n");            
	me->add("atman", -30);
	

	buff =
		([
			"caster":me,
			"who": target,
			"type":"soul_sense",
			"att":"bless",
			"name":"��ʶ��ͨ����ʶ",
			"buff1":"apply/astral_vision",
			"buff1_c":1,
			"time": 900,
			"buff_msg": msg,
			"warn_msg":WHT"�����ʶ�ܿ��ҪʧЧ�ˡ�\n"NOR,
			"disa_msg":YEL"�����ʶʧЧ�ˣ�\n"NOR,
		]);
		
	ANNIE_D->buffup(buff);
	
    return 1;

}
