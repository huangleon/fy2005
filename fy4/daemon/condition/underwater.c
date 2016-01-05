/* ����Ǹ�����ˮ�·��������

set("underwater",depth);
set("water_damage",damage);

depth	�Ǻ���ˮ�����ֵ(1-200),����Ӿ������ء�
damage	��ÿ�η���%��kee�˺���(1-100)

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}

*/

#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration) 
{
	int depth,damage;
	string pos, msg;
	
	if (!userp(me))		return 0;
	
	if (depth = environment(me)->query("underwater")) {
		if (me->query_temp("apply/use_under_water")>=depth) 	//������Ӿ��Ʒ
			return 1;
		damage = environment(me)->query("water_damage") ? 
				environment(me)->query("water_damage") : 100;
		me->receive_damage("kee",me->query("max_kee") * damage /100);
		pos = environment(me)->query("short")?environment(me)->query("short"):"ˮ��";
		me->set_temp("last_damage_from","��"+pos+"�����ˡ�\n");
		
		switch ( me->query("kee") * 100 / (me->query("max_kee") + 1) ) {
			case -100..20:  msg = HIR"$N�Ѿ���óɰ����״̬���ٲ��뿪���¾�û���ˡ�\n"NOR;	break;
			case 21..50: msg = RED"$N�Ѿ���������࣬��������������\n"NOR;		break;
			case 51..80: msg = WHT"$N��ཹ�ཱུ���Ǻ�˼���ˮ������������Ǿ���֮�ء�\n"NOR;	break;
			case 81..200:msg = HIB"$Nֻ���ؿڷ��ƣ�͸����������\n"NOR;			break;
			default: msg = HIR"$N�������ˣ���챨����ʦ��\n"NOR; // for hp<0;
		}
		message_vision(msg, me);
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

string cont_name()	{ return "ˮ��"; }

int shown_stat()	{ return 1;}	