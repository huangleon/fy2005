#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
   	mapping exits;
    	string *dirs;
    	
	duration--;
	if( duration < 0 )	return 0;

	me->receive_wound("sen", 60);
	me->set_temp("last_damage_from","���Ĺ��ȣ�����������\n");
	
   	if(mapp(exits = environment(me)->query("exits"))) {
    		tell_object(me, WHT"�����к�Ȼӿ��Ī���˸У�ֻ������������ãȻ��֪������\n"NOR);
    		message("vision", me->name() + "������࣬ʧ��һ������Ŀ�ĵ����ߡ�\n",	environment(me), me);
	    	dirs = keys(exits);
    		me->ccommand("go " + dirs[random(sizeof(dirs))]);
	}
	me->apply_condition("libie", duration);
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

string cont_name()	{ return "���"; }

int shown_stat()	{ return 1;}	