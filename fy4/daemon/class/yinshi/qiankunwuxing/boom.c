// L185 recover 75%, otherwise 50% kee

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	int fix, lvl,duration,amount;
		
	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ���ʩչ��Ǭ������\n");
		
	lvl = me->query_skill("qiankunwuxing",1);
	if( lvl < 100  || me->query_skill("celecurse",1) < 100)
    	return notify_fail("��Ǭ��������Ҫ100����Ǭ�����κ�ͨ�콵��\n");
		
	duration = me->query("timer/pfm/dwg_destruct")-time() + 1800;
    if (duration>0)
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ��ܹ��ٴ�ʹ��Ǭ������\n");
	
	if( !target ) 
		return notify_fail("��Ҫ��˭ʩչ��Ǭ��������\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("��Ǭ������ֻ��ʩչ�����Լ��ٻ��������������ϡ�\n");

	if( me->query("atman") < 100 )
                return notify_fail("��Ǭ��������Ҫ�ķ�100��������\n");
  	if (userp(me))	me->add("atman", -100);
        
	msg = HIR"\n\n$N����Ǭ�������еġ�Ǭ������,һ�������$n��ü�������
�⻪���䣬�뵱�أ�Ƭ�̣����һ��ע��$N���ţ�\n\n"NOR ;
	message_vision(msg, me, target);
	
	if (lvl >= 185)			amount = me->query("max_kee")*3/4;
	else 					amount = me->query("max_kee")/2;
		
	me->receive_fulling("kee",amount);
	me->set("timer/pfm/dwg_destruct",time());
	target->die();
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}


