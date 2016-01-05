#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{

	me->receive_wound("sen", 20);
	me->receive_damage("kee", 10);
	me->set_temp("last_damage_from","�л�õ�嶾������");
	tell_object(me, HIG "���е�" HIR "��õ�嶾" HIG "�����ˣ�\n" NOR );
	
	duration --;
	if( duration < 1 )
    {
		tell_object(me, HIG "���е�" HIR "��õ�嶾" NOR "���ڷ������ˣ�\n" NOR );
		return 0;
	}	
	me->apply_condition("rose_poison", duration);
	
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

string cont_name()	{ return "��õ�嶾"; }

int shown_stat()	{ return 1;}	