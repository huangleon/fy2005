#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;

	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ���ʩչ��Ǭ���ҡ�\n");
	
	if( me->query_skill("qiankunwuxing",1) < 170  || me->query_skill("celecurse",1) < 170)
                return notify_fail("��Ǭ���ҡ���Ҫ170����Ǭ�����κ�ͨ�콵��\n");
	
	if( !target ) 
		return notify_fail("��Ҫ��˭ʩչ��Ǭ���ҡ���\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("��Ǭ���ҡ�ֻ��ʩչ�����Լ��ٻ��������������ϡ�\n");

	if( me->query("atman") < 150 )
        return notify_fail("��Ǭ���ҡ���Ҫ�ķ�150��������\n");
    if (userp(me))	me->add("atman", -150);
        
	msg = YEL"\n\n$N����Ǭ�������еġ�Ǭ���ҡ�,�����������������𣬾�����ߣ�������ɢ��
���й������֮����Ƭ�̣�����ע��$n���ţ�\n\n"NOR ;
	message_vision(msg, me, target);
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/busy_curse",1);
	target->set("title",YEL"��ʬ����"NOR);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}