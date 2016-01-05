#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration){
	int i,dam_kee,dam_gin,dam_sen;
		
	i = 30/(duration+1);
	dam_kee = (int) me->query("max_kee")/i;
	dam_gin = (int) me->query("max_gin")/i;
	dam_sen = (int) me->query("max_sen")/i;
	me->receive_wound("kee", dam_kee);
	me->receive_wound("gin", dam_gin);
	me->receive_wound("sen", dam_sen);
	me->set_temp("last_damage_from","��������ϼ������");
	
	tell_object(me, MAG"������ϼ"NOR + "�����ˣ����������һ���䣬Ƥ��͸��һ����ɫ��\n");
	message("vision", me->name() + "�ƺ������䣬����Ӳ����ͣ�ش���£�Ƥ����͸��һ��������ɫ��\n", 
			environment(me), me);
	
	duration --;
    if( duration < 1 )
    {
		tell_object(me, HIG "���е�������ϼ���ڷ������ˣ�\n" NOR );
		return 0;
	}
	me->apply_condition("canxia", duration);
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

string cont_name()	{ return "������ϼ"; }

int shown_stat()	{ return 1;}	