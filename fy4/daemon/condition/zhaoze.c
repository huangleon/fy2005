/* ����Ǹ������󷿼������

�ȼ�Խ�ߡ������������Խ�죬��ֹ�㾭����robot����ط�

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("zhaoze",10);
}

*/

#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration) 
{
	int level,damage;
	
	if (!userp(me) && !userp(me->query("possessed")))	return 0;
	
	if (environment(me)->query("outdoors")=="zhaoze") {
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		damage = (level>70)? level : 0;
		damage = COMBAT_D->magic_modifier(me, me, "kee", damage + random(level*2)+ 10);
		me->receive_wound("kee", damage);
		me->set_temp("last_damage_from","�ڻ������һ���������\n");
		tell_object(me,HIR "\n\n���µ�����ͻȻ�ѿ���һ�ų��ȵĵػ�����Ȫ���������\n"NOR);
		COMBAT_D->report_status(me,1);
		return 1;
	}
	return 0;
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