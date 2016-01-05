// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
		notify_fail("��ֻ���õ����ķ��ģ��������������Լ���������\n");
	if (me->query_skill("cloudforce")<80)
		return notify_fail ("��ĵ����ķ���������.\n");
	if( (int)me->query("force") < 300 )    
	        return 	notify_fail("�������������\n");
        if( (int)me->query_temp("lingxin") ) return 
		notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("cloudforce",1);

        me->add("force", -300);
        message_vision(
                HIR 
"$N΢΢�����������ķ��ģ��������ݣ�ͷ���ϳ���һ˿�����İ���\n" NOR, me);

        me->add_temp("apply/intelligence", skill/80);
        me->set_temp("lingxin", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/80 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/intelligence", - amount);
        me->delete_temp("lingxin");
        tell_object(me, "��ģ���������������ϣ��������ջص��\n");
}
 
