#include <ansi.h>
inherit SSERVER;
int thunderspell(object me, object obj,int flag);
int disrupted (object me, object who, string how);

int cast(object me)
{
	string msg;
	object env;
	object *inv, *myteam;
	int lvl, i, k, j, cost;
	int flag;

	function f = (: disrupted :);
	if( me->query("class") != "taoist" ) {
		return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�á����ײԻ�����\n");
	}
	lvl = me->query_skill("necromancy",1);
	if( lvl < 170 ) {
		return notify_fail("�����ײԻ�����Ҫ170�����������\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("ֻ����ս���в���ʹ�á����ײԻ�����\n");
	}
	if( ANNIE_D->check_buff(me, "manatwist") > 0 ) {
		flag = 3;
	} else {
		flag = 1;
	}
	cost = lvl * flag;
	if( me->query("mana") < cost || me->query("sen") < cost ) {
		return notify_fail("�����ײԻ�����Ҫ"+ cost + "�������"+ cost + "�㷨����\n");
	}
	if( userp(me) ) {
		me->add("mana", -cost);
		me->add("sen", -cost);
	}
	msg = BLU "$N"BLU"�Ų�����������૵��������ģ�˫���ճ�����ӡ������ӡ�����̷�ӿ������\n" NOR;
	message_vision(msg, me);
	me->delete_temp("last_damage_from");
	me->set_temp("marks/pfm/sq_thunderstorm", time());
	me->start_busy(3, f);
	call_out("channeled", 6, me, flag, environment(me));
	return 1;
}

int disrupted(object me, object who, string how)
{
	if( how == "hit" ) {
		if( ANNIE_D->check_buff(me,"feat") && random(100) < 55) {
			tell_object(me,WHT"��ȫ���עδ��Ӱ�졣\n"NOR);
			me->delete_temp("last_damage_from");
			return 0;
		}
		tell_object(me,WHT"���ʩ�䱻����ˡ�\n"NOR);
		me->delete_temp("marks/pfm/sq_thunderstorm");
		return 1;
	}
	return 0;
}

void channeled(object me, int flag, object envx)
{
	string msg;
	object env;
	object *inv, *myteam;
	int i, k, j, cost;

	if( !me ) {
		return;
	}
	if( !me->query_temp("marks/pfm/sq_thunderstorm") ) {
		return;
	}
	if( me->query_temp("marks/pfm/sq_thunderstorm") + 5 > time() ) {
		return; // ������һ�������е���ûȡ����channeled.
	}
	if( envx != environment(me) ) {
		return;
	}
	if( me->query_temp("last_damage_from") ) {
		return;
	}
	me->stop_busy();
	msg=MAG"\n$N"NOR+MAG"�͵�˫��һ�ӣ�����ӡɢ���Ƭ����ɫ���������ݶ�������������������
��ʮ�ɸߴ���������������֮�Ρ����ϵİ�������ظ��Ӵ�أ�
�̶�����������˲ʱ��"HIW"	������ѣ���İ׹⡡�硡�ꡡ������\n\n"NOR;
	message_vision(msg, me);
	inv = me->query_enemy();
	for( i = 0; i < sizeof(inv); i++ ) {
		thunderspell(me, inv[i],flag);
	}
	return;
}

int thunderspell(object me, object obj,int flag)
{
	int lvl, spi, kar, kee, damage, spells;
	int clll, cle;

	// (550 + 140)*2*flag = 1380*flag
	damage = 2*(me->query_skill("spells") + F_LEVEL->get_level(me->query("combat_exp")));
	if( flag == 3 ) {
		damage *= 2;
	}
	if( !obj->query("ghostcurse") && (obj->is_ghost() || obj->is_zombie()) ) {
		damage = COMBAT_D->magic_modifier(me, obj, "sen", damage*2);
	} else {
		damage = COMBAT_D->magic_modifier(me, obj, "sen", damage);
	}
	damage = damage*(100+F_ABILITY->check_ability(me,"3_bolt2_add",3)*2)/100;
	message_vision(YEL "\nһ��������$N��ͷ�ϴ�����\n" NOR, obj);
	lvl = me->query_skill("necromancy", 1);
	me->add_temp("apply/spells", lvl*2);
	if( COMBAT_D->do_magic_attack(me, obj, "spells", "sen", 0) ) {
		message_vision(HIR"$N�ҽ�һ��������Ѫ����֣������ɢ��\n"NOR, obj);
		obj->receive_damage("sen", damage, me);
		COMBAT_D->report_status(obj);
	} else {
		message_vision(RED "����$N����ض���ˣ�\n" NOR, obj);
	}
	me->add_temp("apply/spells",-lvl*2);
	COMBAT_D->win_lose_check(me,obj,damage);
	return 1;
}

/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/

