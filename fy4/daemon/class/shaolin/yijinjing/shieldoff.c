// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>

int exert(object me, object target)
{
	int extra,ratio,delay;
	
	if(me->query("class")!="shaolin")
		return notify_fail("ֻ�����ָ�ɮ����ʹ���׽�Ļ����񹦡�\n");
	
	extra=me->query_skill("yijinjing",1);
	if(extra<100)
		return notify_fail("��Ҫ100���׽���������շ������񹦡�\n");

    if( !ANNIE_D->check_buff(me,"forceshield")) 
       		return notify_fail("�㲻���˹��С�\n");

	if(target && me!=target)
		return notify_fail("ȡ��������ֻ�������Լ����ϡ�\n");
	
	if (me->query("timer/pfm/yjj_off") + 60 > time())
		return notify_fail("�׽ÿ����ֻ���չ�һ�Ρ�\n");
	
	ANNIE_D->debuff(me,"forceshield");
	me->set("timer/pfm/yjj_off",time());
	
	return 1;
}
