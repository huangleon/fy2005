// ��������ħ�����к󡣡���

#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{

	duration --;
	
    if( duration < 1 )
    {
		message_vision(HIG "$N��Ȼ�ɶ����࣬��Ϊ���룬�����ߵ�ȥ��\n" NOR ,me);
		me->set_temp("last_damage_from","��Ȼ�ɶ����࣬��Ϊ���룬�����ߵ�ȥ��\n");
		me->die();
		return 0;
	}
	
	me->apply_condition("moon-blade", duration);
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

string cont_name()	{ return "Բ���䵶����­"; }

int shown_stat()	{ return 1;}	