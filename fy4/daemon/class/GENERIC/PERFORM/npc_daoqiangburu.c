// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
    int skill;
    
    if(userp(me))
	return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  

    if(!target) target=me;
    if(me->query("class")!="lama")
		return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�ã۵�ǹ����ݡ�\n");

    else if( target != me )
        return notify_fail("��ֻ�ܽ��۵�ǹ����������Լ������ϡ�\n");

    if( (int)me->query_temp("daoqian") )
        return notify_fail("���Ѿ���ʩչ�۵�ǹ������ˡ�\n");
    skill = me->query_skill("jin-gang",1);

    skill = random(skill/2)+skill/2;

    message_vision( HIR
"$N�������ظ����߽��ţ�����ǹ���룡��ǹ���룡��ǹ���룡��������\n" NOR, me);
    me->add_temp("apply/iron-cloth", skill);
    me->set_temp("daoqian", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         skill :), skill+random(skill/2));
    return 1;
}

void remove_effect(object me, int amount)
{
    me->add_temp("apply/iron-cloth", - amount);
    me->delete_temp("daoqian");
    if( me->is_fighting() ) me->start_busy(1);
    tell_object(me, "��ģ۵�ǹ����ݵĹ�Чɢ���ˡ�\n");
}
 
