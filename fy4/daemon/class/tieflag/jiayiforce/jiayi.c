// jiayi.c
//written by kouga

#include <ansi.h>

int exert(object me, object target, int amount)
{       
	int skill,force;  
	skill = me->query_skill("jiayiforce",1);  
	if(skill < 140) return notify_fail("��ļ�����̫���ˣ�����Ϊ�����ޣ�\n"); 
	if( !target || target == me)  return notify_fail("��Ҫ��˭ʹ�ü����񹦣�\n" );
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷�ʹ�ü����񹦣�\n");
	if((int)me->query("max_force") < 400)
                return notify_fail("�����������ǿ��\n");
	if((int)me->query("max_force") <= (int)target->query("max_force"))	
		return notify_fail("���������û��"+target->name()+"��ǿ������Ϊ�����ޣ�\n"); 
        message_vision(
                HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
                "���˲��ã�$n�������⣬$Nȴ�赹�ڵء�\n" NOR,
                me, target );
	me->set_skill("jiayiforce",1);
	me->add("max_force",-400);
	me->set("force",0);
	target->add("max_force",200);
	me->unconcious();
        return 1;
}
