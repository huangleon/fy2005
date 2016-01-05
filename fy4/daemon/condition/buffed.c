// silencer@fy

inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object target, int duration)
{
	int gin,kee,sen,amount;
	target=this_player();
	amount= duration*150;
	target->apply_condition("buffed", duration - 1);
        if( duration < 1 ){
        	tell_object(target, HIG "���������ֻ��������һ������������࣡\n" NOR );
    		target->set("max_kee",(int)target->query_temp("buffed_kee_record"));
    		if (target->query("eff_kee")>target->query("max_kee"))
    			target->set("eff_kee",target->query("max_kee"));
    		if (target->query("kee")>target->query("max_kee"))
    			target->set("kee",target->query("max_kee"));
    		target->delete_temp("till_death/buffed_kee");
		}
	else	{ 
		if   (target->query_temp("till_death/buffed_kee")==0) {
			tell_object(target, HIR "�������һ�����������ͻȻע����������壡\n" NOR );
        		kee = (int)target->query("max_kee");
        		target->set("max_kee",kee+amount);
        		target->set_temp("buffed_kee_difference",amount);
        		target->set_temp("till_death/buffed_kee",1);
        		}
		}
	if( duration < 1 ) 	return 0;
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

string cont_name()	{ return "��״̬����ʹ��"; }