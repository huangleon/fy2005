#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, extra;
	
	if (me->query_skill("bai-quan",1) < 100)
		return notify_fail("�����ķ�����Ҫ100���İ׼�ȭ��\n");
	
	if( !target ) target = me;
	if(me->is_fighting() )
		return notify_fail("�����ķ���������ս����ʹ�á�\n");
	
	if (!target) target = me;
	if( target != me)
		return notify_fail("�����ķ���ֻ�ܶ��Լ�ʹ�á�\n");
		
	if (me->query("sen")< 300)
		return notify_fail("�����ķ���������Ҫ300������\n");
		
	lvl = me->query_skill("bai-quan", 1) > 200 ? 200: me->query_skill("bai-quan", 1);
	extra = me->query_skill("qingpingforce",1);
		
	msg = WHT "$N"NOR+WHT"����ƽ����̤̤ʵʵ��ʩչ��һ�˰׼�ȭ��\n" NOR;
	
	me->receive_fulling("kee", lvl + extra, me);
	me->add ("sen", -300);
	message_vision(msg, me);
	me->start_busy(2);
	return 1;
}
