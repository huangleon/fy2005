#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	int lvl;
		
	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ���ʩչ��Ǭ������\n");
	
	if( !target ) 
		return notify_fail("��Ҫ��˭ʩչ��Ǭ��������\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("��Ǭ������ֻ��ʩչ�����Լ��ٻ��������������ϡ�\n");

	if( me->query("atman") < 100 )
    	return notify_fail("��Ǭ��������Ҫ�ķ�100��������\n");
    if (userp(me))	me->add("atman", -100);

	msg = GRN"\n\n$N����Ǭ�������еġ�Ǭ������,��Ȼ�����˱ǣ��׹�������һ���ʻ���
��������ǰ����̣������ķ����ѣ��������������̹�ע��$n���ţ�\n\n"NOR ;
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/turn_curse",1);
	target->set("title",HIG"��ʬ����"NOR);
		
	message_vision(msg, me, target);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}


