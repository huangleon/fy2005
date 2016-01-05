// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int ap, dp,myexp;
    
    if((int)me->query_skill("charm", 1) < 120 )
	        return notify_fail("������������ߣ�\n");
    if(!me->is_fighting())
	return notify_fail("����û�б�Ҫ���������������! \n");
    if( !target ) target = offensive_target(me);
    
    if( !target
	||!target->is_character()
	||target->is_corpse()
	||target==me)
        return notify_fail("��Ҫ��˭ʩչ���������\n");

    if((int)me->query("mana") < 100 )
        return notify_fail("��ķ���������\n");

    if((int)me->query("sen") < 50 )
        return notify_fail("��ľ���û�а취��Ч���У�\n");

    me->add("mana", -100);
    me->receive_damage("sen", 50);
    
    if( random(me->query("max_mana")) < 30 )
    {
        write("��ʧ���ˣ�\n");
        return 1;
    }

    msg = MAG "$N����΢������̬��ǧ�������ŵ�ѩ��մ�����ޱߵ����ޣ��ջ���$n��\n\n" ;
    
    ap = me->query_skill("charm",1);
    myexp = me->query("combat_exp");
    ap = ( ap * ap * ap/40 ) * (int)me->query("per") ;
    dp = target->query("combat_exp");
	if (target->query("gender") != me->query("gender"))
	{		
		if( (random(ap + dp) > dp) && (random(myexp) > dp/2) )
		{
			msg +=WHT "$n���ɳ��ˣ���Ȼ������һ�С� \n";
			//if( me->is_fighting() )
				//target->increase_action(-50);
				target->remove_killer(me);
				me->remove_killer(target);
		}
		else  
		{
			msg += WHT "����$n��Ϊ������\n";
			me->start_busy(4);
		}
	}
	else
	{
		//will never success on same gender while target not homo
		msg += YEL "����$n��$N˿��������Ȥ��\n";
		me->start_busy(4);
	}
     message_vision(msg+NOR, me, target);
    return 1;
}
