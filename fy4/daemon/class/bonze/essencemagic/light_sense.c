// Silencer@fengyun	June.2005
// ����ʶ��(light_sense)   -��400+random(400)�Թ��ɱ����*2	����120����ʶ��ͨ�� 

#include <ansi.h>
inherit SSERVER;

int bbqthem(object me, object obj);

int conjure(object me, object target)
{
	int lvl, i, j ,k;
	object env, *inv, obj;
	object *myteam;
	string id_enemy;

	if( me->query("class")!="bonze" ) {
		return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�á���ʶ��\n");
	}
	lvl = (int) me->query_skill("magic");
	if( (int)me->query_skill("essencemagic",1) < 120 ) {
		return notify_fail("����ʶ����Ҫ120����ʶ��ͨ��");
	}
	if( !me->is_fighting() ) {
		return notify_fail("ֻ����ս���в���ʹ�ù�ʶ��\n");
	}
	if( me->query("atman") < 200 ) {
		return notify_fail("����ʶ����Ҫ200���������\n");
	}
	if( userp(me) ) {
		me->add("atman", -200);
	}
	message_vision(WHT "
$N˫�����գ��Ƽ�۳ɴ����Сһ��������ÿƬ��Ҷ��"HIC"�ࡢ"HIR"�졢"HIY"�ơ�"HIW"�ף�"BLK"�ڡ�"HIB"����\n"+
HIM"��"NOR+WHT"������ɫ��Ƭ�̣��⻪����ǿʢ���������ֺ���ٿ���糸��"WHT"�͵�һ�Ż����з�
������Ϊ��㺮�ǣ��ķ���ɢ��������\n" NOR, me);

	inv = me->query_enemy();
	for( i = 0; i < sizeof(inv); i++) {
		bbqthem(me, inv[i]);
	}
	me->perform_busy(2);
	return 1;
}


int bbqthem(object me, object obj)
{
	int magic, skill;
	string id_enemy;

	magic = (int) me->query_skill("magic");
	skill = me->query_skill("essencemagic",1);
	message_vision(HIR "\n���ȵĺ��������������$N��\n" NOR, obj);
	me->add_temp("apply/magic", skill*2);
	if( COMBAT_D->do_magic_attack(me, obj, "magic", "sen") ) {
		magic = random(magic) + magic; // random(400)+ 400;
		magic = magic*(100+F_ABILITY->check_ability(me,"lightsense_add")*2)/100;
		if( ANNIE_D->check_buff(me,"xg-evil") ) {
			magic = magic*(150+F_ABILITY->check_ability(me,"3_zhuxian_add",3)*2)/100;
		}
		if( !obj->query("ghostcurse") ) {
			if( obj->is_ghost() || obj->is_zombie() ) {
				magic = magic*2;
			}
		}
		magic = COMBAT_D->magic_modifier(me, obj, "sen", magic);
		obj->receive_damage("sen", magic, me);
		COMBAT_D->report_status(obj);
		COMBAT_D->win_lose_check(me,obj,magic);
	} else {
		message_vision(YEL"��â����$Nȴ��������\n"NOR, obj);
	}
	me->add_temp("apply/magic", -skill*2);
	return 1;
}



