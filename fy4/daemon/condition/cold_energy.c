
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	me->receive_fulling("kee", 300, me);
	me->receive_fulling("sen", 300, me);
	me->receive_fulling("gin", 300, me);
	
	tell_object(me, HIC "��������������ɽѩ���ĺ�������������һ�ܣ�\n" NOR );
	
	duration --;
	
	if (duration <1)
	{
	 	tell_object(me, HIC "��ɽѩ���Ĺ�Чɢ���ˣ�\n" NOR );
	 	return 0;
	}
	 
	me->apply_condition("cold_energy", duration);
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

	return NO_CURE;
}

string cont_name()	{ return "ѩ����Ч"; }

int shown_stat()	{ return 1;}	