// speed.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
	notify_fail("��ֻ�������Լ���ʳ�\n");

        if( (int)me->query("force") < 200 )     return 
	notify_fail("�������������\n");
              skill = me->query_skill("noloveforce",1);
	if(skill < 50) return notify_fail("�����������̫���ˣ�\n");

      me->add("force", -200);
        message_vision(
                CYN
"$N�����ؾ�������[����]һ����˭�ɼ���\n" NOR, me);
        me->set("food", 200);
        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

