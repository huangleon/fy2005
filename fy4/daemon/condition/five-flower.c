// bat_poison.c

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 140);
	me->receive_wound("gin", 140);
	me->set_temp("last_damage_from","���廨��������");
	tell_object(me, RED "���е��廨�������ˣ����ۿ����Ķ���ɫ�ʰ�쵵Ļ����ڷ�����\n" NOR );
    
    duration --;
    if( duration < 1 ) {
    	tell_object(me, HIG "���е��廨�����ڷ������ˣ�\n" NOR );
    	return 0;
    }	
	me->apply_condition("five-flower", duration);
	
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
	return LOW_POISON;
}


string cont_name()	{ return "�廨��"; }

int shown_stat()	{ return 1;}	