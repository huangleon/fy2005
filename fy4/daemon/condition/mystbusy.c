#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	int j;
	j=me->query_busy();
	me->perform_busy(j+1);
	message_vision("$N�ж����ֽŲ��飬�ƺ��Ǳ���ϸС����˿��סһ�㡣\n",me);
	me->apply_condition("mystbusy", duration - 1);
	if( duration < 1 ) 
		return 0;
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


string cont_name()	{ return "��˿����"; }