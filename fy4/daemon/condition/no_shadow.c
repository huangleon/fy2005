
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	me->receive_wound("kee", 20);
	me->receive_wound("sen", 20);
	me->set_temp("last_damage_from","����Ӱ��������");
		tell_object(me, HIW "���е�" HIC "��Ӱ��" HIW "�����ˣ�\n" NOR );
		
    duration --;
    if( duration < 1 ){
		tell_object(me, HIW "���е�" HIC "��Ӱ��" HIW "��������ˣ�\n" NOR );
		return 0;
	}
	
	me->apply_condition("no_shadow", duration);
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

string cont_name()	{ return "��Ӱ��"; }

int shown_stat()	{ return 1;}	