
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	int dam_kee,dam_gin,dam_sen;
	string msg;
	
	dam_kee = (int) me->query("max_kee")/10;
	dam_gin = (int) me->query("max_gin")/10;
	dam_sen = (int) me->query("max_sen")/10;
	me->receive_wound("kee", dam_kee);
    me->receive_wound("gin", dam_gin);
    me->receive_wound("sen", dam_sen);
    me->set_temp("last_damage_from","�������Ϻ�ɢ�������ã�ȫ���Ѷ�����\n");
	tell_object( me, HIR "���е�" HIY "�����Ϻ�ɢ" HIR  "�����ˣ������ȫ�����Ȳ��ѣ�\n" NOR );
	msg = me->query("gender") == "����" ? 
			"ͷ����췢�ȣ�����һ˫�۾����������������۹���Ҫ����ǹ⡣\n" 
			: "����΢΢�����Ϸ���һ���һ��㵭���ĺ�ɫ�������ѽ��������Ĳ��������ƺ�Ҫ�γ�ˮ����\n" ;
	message("vision", "ֻ��" + me->name() + msg, environment(me), me);
		
	
    duration --;
    if( duration < 1 )
	{
		tell_object(me, HIR "�������ܲ���" HIY "�����Ϻ�ɢ" HIR "�Ĵ������ã�ȫ���Ѷ�����\n" NOR );
		message("vision", me->name() + "ȫ�������ѡ�\n", environment(me), me);
		me->die();
		return 0;
	}
	
	me->apply_condition("hehe", duration);
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

string cont_name()	{ return "�����Ϻ�ɢ"; }

int shown_stat()	{ return 1;}	