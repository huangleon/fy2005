// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
	
	if(!target) target=me;
            	
    	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  
    	
        if( target != me ) return 
		    notify_fail("��ֻ�ܽ��������֡������Լ������ϡ�\n");
        
        if( (int)me->query_temp("daoqian") ) return 
    			notify_fail("���Ѿ���ʩչ�������֡��ˡ�\n");
        
        skill = me->query_skill("henglian",1);
	if(skill < 100) return notify_fail("���ʮ��̫��������̫���ˣ�\n");
	skill = random(skill/2)+skill/2;
        message_vision( 
HIY"$N��������ȫ��ǽ�һ�����죬�������κ�Ȼ����һȦ����\n" NOR, me);
        me->add_temp("apply/iron-cloth", skill);
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill*3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("daoqian");
        tell_object(me, "��ġ������֡���Чɢ���ˡ�\n");
}
 
