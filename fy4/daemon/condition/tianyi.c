#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	   
	tell_object(me, HIW "���е�" HIY "��һ��ˮ" HIW  "�����ˣ�\n" NOR );
	me->receive_wound("kee", 200);
    me->receive_wound("gin", 200);
    me->receive_wound("sen", 200);
    me->set_temp("last_damage_from","������һ��ˮ������");
    
    duration --;
    if( duration < 1 )
    {
			tell_object(me, HIW "���е�" HIY "��һ��ˮ" HIW "���ڷ������ˣ�\n" NOR );
		return 0;
	}
	
	me->apply_condition("tianyi", duration);
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
	return SPECIFIC_POISON;
}


string cont_name()	{ return "��һ��ˮ"; }

int shown_stat()	{ return 1;}	