inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 10);
    me->receive_wound("gin", 10);
    me->receive_wound("sen", 10);
	tell_object(me, HIW "��θ��һ���ʹ��ͷ��ð������ĺ��飡\n" NOR );
	message("vision", me->name() + "���ְ�סθ������ɫ�Ұף�ͷ��ð������ĺ��Σ�\n", environment(me), me);
	
	duration --;
	
	if( duration < 1 ) {
			tell_object(me, HIW "���θ�����ڸо��õĶ��ˣ�\n" NOR );
			return 0;
	}
			
	me->apply_condition("mushroom", duration);
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
	return GENERIC;
}


string cont_name()	{ return "ʳ���ж�"; }

int shown_stat()	{ return 1;}	