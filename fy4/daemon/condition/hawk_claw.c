
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	me->receive_wound("kee", 100);
	me->set_temp("last_damage_from","����ӥץ�ˣ��������Σ�ʧѪ����������\n");
	tell_object(me, HIR"��ӥ����צץ��������ֱۡ���ĸ첲�ϲ�ͣ����Ѫ��\n" NOR );
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


string cont_name()	{ return "��ӥץ��"; }