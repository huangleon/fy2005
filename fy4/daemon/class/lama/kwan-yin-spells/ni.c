// void_sense.c

#include <ansi.h>

inherit SSERVER;
int bbqthem(object me, object obj);
int cast(object me, object target)
{
	int i;
	int lvl;
	int cost;
	object env, *inv;
	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д����µĵ��Ӳſ���ʹ�ù����������䣡\n");
	}
	lvl = (int)me->query_skill("kwan-yin-spells", 1);
	if( lvl < 140 ) {
		return notify_fail("���ء���Ҫ140���Ĺ����������䣡");
	}
	if( !me->is_fighting() ) {
		return notify_fail("���ء�ֻ����ս����ʹ�á�\n");
	}
	if( target == me ) {
		return notify_fail("��Ҫ���ˣ�\n");
	}
	cost = (lvl/10)*10;
	if( me->query("mana") < cost ) {
		return notify_fail("���ء�������Ҫ" + cost + "�㷨����\n");
	}
	if( userp(me)) {
		me->add("mana", -cost);
	}
	message_vision(WHT"\n$N"NOR+WHT"����һ�����ء������ֻ��ģ�����ƽ̯�����Ǽ��������գ������һ�� 
ֻ�������İ׹�͸�����⡣ \n" NOR, me);
	message_vision(HIW "������$N"HIW"��һ�ɵ����İ�������Χ����\n" NOR, me);
	env = environment(me);
	inv = all_inventory(env);
	for( i = 0; i < sizeof(inv); i++ ) {
		if( inv[i] == me ) {
			continue;
		}
		if( inv[i]->is_corpse() ) {
			continue;
		}
		if( !inv[i]->is_character() ) {
			continue;
		}
		if( !inv[i]->is_fighting(me) ) {
			continue;
		}
		bbqthem(me, inv[i]);
	}
	me->perform_busy(3);  
	return 1;
}

int bbqthem(object me, object obj)
{
	int damage, spells;
	if( COMBAT_D->do_magic_attack(me, obj, "spells", "sen", 500) ) {
		message_vision(BLU "\n������"+"$N"NOR+BLU"��ͷ������������ע��$n"NOR+BLU"�����ڣ�\n" NOR, obj, me);
		message_vision(YEL "$N"NOR+YEL"ͷ��Ŀѣ����ɫ��ή�����������������˴�룡\n" NOR, obj);
		spells = me->query_skill("spells");
		// damage 50 + 500*500/500 = 550 : 30% ability add
		damage = 50 + spells*spells/500;
		// 3ni = 3*damage with 6 busy
		// 2ni = 2*damage with 4 busy 
		if( !obj->query("ghostcurse") ) {
			if( obj->is_ghost() || obj->is_zombie() ) {	
       			damage = damage*2;
			}
		}
		damage = damage * (100 + F_ABILITY->check_ability(me, "ni_add") * 3) / 100;
		damage = COMBAT_D->magic_modifier(me, obj, "sen", damage);
		obj->receive_damage("sen", damage, me);        

		if( !userp(obj) ) {
			obj->add_hate(me, damage/2);
		}
		me->receive_fulling("kee", damage/5, me);
		COMBAT_D->report_status(obj);
		COMBAT_D->win_lose_check(me, obj, 1);
	} 	
	return 1;
}

