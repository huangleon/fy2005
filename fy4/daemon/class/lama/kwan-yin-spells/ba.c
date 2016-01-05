// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>

int cast(object me, object target)
{
	int extra;
	int amount, friend_amount;
	int i, num;
	object *myteam, *team;
	mapping buff;
	string msg;

	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�ù����������䡣\n");
	}
	extra = me->query_skill("kwan-yin-spells", 1);
	if( extra < 140 ) {
		return notify_fail("���ȡ���Ҫ140���Ĺ����������䡣\n");
	}
	target = me;
	if( ANNIE_D->check_buff(me, "forceshield") ) {
		return notify_fail("���Ѿ����˷�֮���ˡ�\n");
	}
	if( (int)me->query("mana") < 100 ) {
		return notify_fail("��Ҫ100��ķ�����\n");
	}
	if( userp(me) ) {
		me->add("mana", -100);
	}
	message_vision(HIW "\n$N"HIW"���ְ�����ǰ����ָ΢����Ĵָ������ָ�࣬������ָչ�����������ţ���������ȡ� \n"NOR, me, target );

	msg = "$N�������½�������һȦʥ��Ĺ⻪�������������ӡ�\n";

	if( extra >= 220 ) {
		amount = 3000;
		friend_amount = 200;
		msg = HIR"$N"HIR"�������½�������һȦʥ��Ĺ⻪�������������ӡ�\n"NOR;
	} else if( extra >= 180 ) {
		amount = 250;
		friend_amount = 150;
		msg = HIY"$N"HIY"�������½�������һȦʥ��Ĺ⻪�������������ӡ�\n"NOR;	
	} else {
		amount = 200;
		friend_amount = 100;
		msg = HIC"$N"HIC"�������½�������һȦʥ��Ĺ⻪�������������ӡ�\n"NOR;
	}
	me->perform_busy(2);
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"forceshield",
			"att":"bless",
			"name":"�����������䡤���ȡ�",
			"time":90,
			"buff_msg":msg,
			"disa_msg":YEL"�����ϵĹ⻪������ʧ�ˡ���\n"NOR,
			"shield_desc":CYN"$n���ϵĹ⻪������$N�Ĺ��ơ�\n"NOR,
			"shield_amount":amount,
			"shield_type":"mana",
		]);
	ANNIE_D->buffup(buff);
		
	myteam = me->query_team();	
	if( myteam && extra >= 120 ) {
		team = filter_array(myteam, (: present($1, environment($2)) :), me);
		num = sizeof(team);
		for( i = 0; i < num; i++ ) {
			if( ANNIE_D->check_buff(team[i], "forceshield") ) {
				continue;
			}
			if( team[i] == me) {
				continue;
			}
			buff = 
				([
					"caster":me,
					"who":team[i],
					"type":"forceshield",
					"att":"bless",
					"name":"�����������䡤���ȡ�",
					"time":90,
					"buff_msg":CYN"$N�������½�������һȦʥ��Ĺ⻪�������������ӡ�\n"NOR,
					"disa_msg":YEL"�����ϵĹ⻪������ʧ�ˡ���\n"NOR,
					"shield_desc":CYN"$n���ϵĹ⻪������$N�Ĺ��ơ�\n"NOR,
					"shield_amount":friend_amount,
					"shield_type":"mana",
				]);
			ANNIE_D->buffup(buff);
		}
	}
	return 1;
}
