#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	
	me->receive_wound("gin",10);
	me->receive_wound("sen",10);
	me->set_temp("last_damage_from","���̹��ȣ����첡���ˡ�");
	if (!random(3)) {
		tell_object(me, WHT "�����ɤ�ӷ��ɷ�����\n" NOR );
		message_vision(WHT"$N�����ﹾ�����죬�˵�һ���³�һ��Ũ̵��\n" NOR,me );
	}
    
    duration --;
    if( duration < 1 ) {
		tell_object(me, HIG "��Ŀ������ںõ��ˣ�\n" NOR );
		return 0;
	}
	me->apply_condition("cough", duration);
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

string cont_name()	{ return "����"; }

int shown_stat()	{ return 1;}	