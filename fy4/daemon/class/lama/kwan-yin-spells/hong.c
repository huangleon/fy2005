
#include <ansi.h>

inherit SSERVER;
int bbqthem(object me, object obj);

int cast(object me, object target)
{
	int i;
	object env, *inv, *myteam;

	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д����µĵ��Ӳſ���ʹ�ù����������䣡\n");
	}
	if( (int)me->query_skill("kwan-yin-spells", 1) < 160) {
		return notify_fail("���ˡ���Ҫ160���Ĺ����������䣡\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("���ˡ�ֻ����ս����ʹ�á�\n");
	}
	if( me->query("mana") < 300 ) {
		return notify_fail("���ˡ���Ҫ300�㷨����\n");
	}
	if( userp(me) ) {
		me->add("mana", -300);
	}

	message_vision("\n"BRED + HIW "$N"BRED+HIW"��������ǰչ������֮״��������������������̨�����������£������ྲ�����\n"NOR
			"       "+ BRED+ HIY" ���ˡ���" + BRED + HIW" ������ֻ��$N"BRED+HIW"˫��һ˲�䷢����̫����Ҫҫ�۵Ĺ�â������\n" NOR, me);

	env = environment(me);
	inv = all_inventory(env);
	for( i = 0; i < sizeof(inv); i++) {
		if( inv[i] == me ) {
			continue;
		}
		if( inv[i]->is_corpse() ) {
			continue;
		}
		if( !inv[i]->is_character() ) {
			continue;
		}
		if( !me->is_fighting(inv[i]) ) {
			continue;
		}
		bbqthem(me, inv[i]);
	}
	me->perform_busy(2);
	return 1;
}

int bbqthem(object me, object obj) 
{
	int mod;

	mod = COMBAT_D->can_busy(me, obj, "kwan-yin-spells");   
	if( !mod ) {
		return 1;
	}
	if( !COMBAT_D->do_busy_attack(me, obj, "kwan-yin-spells/hong", "unarmed", 400, mod) ) {
		message_vision(YEL"$N"NOR+YEL"��æת��ͷȥ������$n��\n"NOR, obj, me);
		return 1;
	}

	obj->set_temp("busy_timer/kwan-yin-spells", time());

	if( userp(obj) ) {
		tell_object(obj, HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�����\n"NOR);
		obj->add_temp("block_msg/all", 1);
		obj->force_busy(3 + random(2));
		message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n\n"NOR, obj);
		call_out("recover", 10, obj);
	} else {
		obj->force_busy(3);
		obj->add_hate(me, me->query_skill("spells")*2);
		message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n\n"NOR,obj);
	}
	return 1;
}


int recover (object obj)
{
	if(obj->query_temp("block_msg/all") >= 1 ) {
		obj->add_temp("block_msg/all", -1);
	}
	tell_object(obj, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
	return 1;
}	

