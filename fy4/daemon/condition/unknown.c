#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{	
	me->receive_wound("kee", 50);
    me->receive_wound("gin", 50);
    me->receive_wound("sen", 50);
    me->set_temp("last_damage_from","������������������");
    tell_object(me, HIW "�����ϵĶ��ط����ˣ�\n" NOR );
    
    duration --;
	if( duration < 1 )
    {
		tell_object(me, HIW "�����ϲ�֪�е�ʲô�����ڷ������ˣ�\n" NOR );
		return 0;
	}
	
	me->apply_condition("unknown", duration);
	return 1;
	
}

int condition_type()
{
// in condition.h
/*

#define NO_CURE        		100
#define SPECIFIC_POISON		30
#define MID_POISON   		20
#define LOW_POISON   		10
#define GENERIC			0

*/
	return MID_POISON;
}

string cont_name()	{ return "������"; }

int shown_stat()	{ return 1;}	