#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;

	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ���ʩչ��Ǭ��ת��\n");
	
	lvl = me->query_skill("qiankunwuxing",1);
	if( lvl < 140  || me->query_skill("celecurse",1) < 140)
                return notify_fail("��Ǭ��ת����Ҫ140����Ǭ�����κ�ͨ�콵��\n");
	
	if( !target ) 
		return notify_fail("��Ҫ��˭ʩչ��Ǭ��ת����\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("��Ǭ��ת��ֻ��ʩչ�����Լ��ٻ��������������ϡ�\n");

	if( me->query("atman") < 100 )
    	return notify_fail("��Ǭ��ת����Ҫ�ķ�100��������\n");
    if (userp(me))	me->add("atman", -100);
        
	msg = CYN"\n\n$N����Ǭ�������еġ�Ǭ��ת��,��Ȼ�����˱ǣ��׹�������һ���ʻ���
��������ǰ����̣������ķ����ѣ����������������ע��$n���ţ�\n\n"NOR ;
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/turn_curse",2);
	target->set("title",HIC"��ʬ����"NOR);
	message_vision(msg, me, target);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}
