// Silencer@fengyun workgroup	June.2005
// �ƽ����ٻ��Ƴ棬���ӹ�������һ�У��߳ɹ��ʣ���ɱ�����ϸ�
//	������10%����backfire�����ս����ʹ����40% chance to backfire��

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
        int extra, skill, num;
        string msg;

		if(me->query("class")!="yinshi"&& userp(me))
			return notify_fail("ֻ�е����ȵ��Ӳ���ʹ�����ƽ���\n");
 	
		skill = me->query_skill("celecurse",1);

		if (me->query_skill_mapped("force")!= "iceheart")
        	return notify_fail("ʩ�ùƽ����Ա��ľ����塣\n");
        
        if (me->query_temp("pfm/locustcurse"))
        	return notify_fail("���Ѿ����˹ƽ��ˡ�\n");
        	
        if (me->query("force") < 50)
                return notify_fail("���ƽ�����Ҫ50��������\n");
        if (userp(me))	me->add("force", -50);
               
        msg = BMAG + HIR"
$N���������дʣ������зɳ�һ�ź�⣬���ʱ��ʱ����ʱǿʱ����ʱ��ʱ�ԡ�
��ϸ��ȥ����Ȼ�������䶯�ĺ�棬��ɶ��˻��������$N���ϡ�\n"NOR;	
	
		message_vision(msg, me);
	
		if (me->is_fighting())
			me->set_temp("pfm/locustcurse",40);
		else
			me->set_temp("pfm/locustcurse",10);	
	
		return 1;
}	