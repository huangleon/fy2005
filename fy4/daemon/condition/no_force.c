
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	
	if (environment(me)->query("no_force")) {
		tell_object(me, MAG"
��ֻ���ýŲ�������ǰ���Σ������˾��ѻ����˯��������ݷ���ƣ�ȴ��
��������۵öࡣ��������\n" NOR );
		me->set("force",0);
		me->set("mana",0);
		me->set("atman",0);
		me->set("force_factor",0);
	} else
		me->change_condition_duration("no_force",0);
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


string cont_name()	{ return "����ɢ"; }

int shown_stat()	{ return 1;}	