#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
    me->receive_wound("kee", 200);
    me->receive_wound("gin", 100);
    me->receive_wound("sen", 100);
    me->set_temp("last_damage_from","����������������\n");
    tell_object(me, HIM "��θ��һ���ʹ�������������ᣬð������ĺ���ɫ���飡\n" NOR );
    message("vision", me->name() + "���ְ�סθ���������������ᣬͷ��ð������ĺ���ɫ���Σ�\n", 
			environment(me), me);
    
    duration --;
    if( duration < 1 ) {
    	tell_object(me, YEL "���³�һ�����������ڸо���̹����࣡\n" NOR );
		return 0;
    }
	
	me->apply_condition("mag_mushroom", duration);
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

string cont_name()	{ return "����"; }

int shown_stat()	{ return 1;}	