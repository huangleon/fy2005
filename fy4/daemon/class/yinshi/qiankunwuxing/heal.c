#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;

	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ���ʩչ��Ǭ������\n");
	
	if( me->query_skill("qiankunwuxing",1) < 150 || me->query_skill("celecurse",1) < 150)
                return notify_fail("��Ǭ��������Ҫ150����Ǭ�����κ�ͨ�콵��\n");
	
	if( !target ) 
		return notify_fail("��Ҫ��˭ʩչ��Ǭ��������\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("��Ǭ������ֻ��ʩչ�����Լ��ٻ��������������ϡ�\n");

	if( me->query("atman") < 150 )
                return notify_fail("��Ǭ��������Ҫ�ķ�150��������\n");
    if (userp(me))	me->add("atman", -150);
        
	msg = WHT "\n\n$N����Ǭ�������еġ�Ǭ������,����������ָ����������۲�ɢ��
Ƭ�̣�����һ��Ӥ�Σ�ɢ��$n���ţ�\n\n"NOR ;
	message_vision(msg+NOR, me, target);
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/heal_curse",1);
	target->set("title",WHT"��ʬ����"NOR);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}