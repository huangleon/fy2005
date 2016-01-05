
#include <ansi.h>

inherit SSERVER;
int disrupted (object me, object who, string how);

int cast(object me, object target)
{
	string msg;
	int damage, ap, lvl, cost;
	int dam,extradam;
	int flag ,type;

	function f = (: disrupted :);
	if( ANNIE_D->check_buff(me,"manatwist") > 0 ) {
		flag = 3;
	} else {
		flag = 1;
	}
	if( me->query("class") != "taoist" ) {
		return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
	}
	if( (int)me->query_skill("necromancy",1) < 135 ) {
		return notify_fail("��ȼ����桻��Ҫ135�������������\n");
	}
	if( me->query_skill_mapped("force") != "gouyee" ) {
		return notify_fail("���������ʹ�ù����ķ�����ת���š�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	lvl = me->query_skill("necromancy", 1);
	cost = (20+lvl/2)*flag;
	if( me->query("mana") < cost || me->query("sen") < cost ) {
		return notify_fail("��ȼ����桻������Ҫ"+ cost + "������ͷ�����\n");
	}
	if( userp(me) ) {
		me->add("sen", -cost);
		me->add("mana", -cost);
	}
	msg = BLU "$N"NOR+BLU"�����૵��������ģ�˫���շ���ӡ������ɫ�Ļ�������������ҡ������\n" NOR;
	message_vision(msg, me, target);
	type = me->query_temp("last_sqpfm_used");
	me->set_temp("last_sqpfm_used", 1111);
	me->set_temp("marks/pfm/sq_demonic", time());
	me->delete_temp("last_damage_from");
	me->start_busy(3, f);
	call_out("channeled", 6, me, target, flag, type);
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
		me->delete_temp("marks/pfm/sq_demonic");
		return 1;
	}
	return 0;
}

void channeled(object me, object target, int flag, int type)
{
	string msg;
	int damage, ap, lvl, cost;
	int dam, extradam;
	int i;
	string typ;

	if( !me ) {
		return;
	}
	if( !me->query_temp("marks/pfm/sq_demonic") ) {
		return;
	}
	if( me->query_temp("marks/pfm/sq_demonic") + 5 > time() ) {
		return; // ������һ�������е���ûȡ����channeled.
	}
	if( !target || !me->is_fighting(target) || environment(target) != environment(me) ) {
		return;
	}
	if( me->query_temp("last_damage_from") ) {
		return;
	}
	me->stop_busy();
	msg = HIB "\n$N"HIB"�͵�һ��˫�֣�һ�������$n"HIB"���ϱ��Ѷ�����"NOR; 
	switch( type ) {
		case 2:
			typ = "gin";
			break;
		case 1:
			typ = "sen";
			break;
		case 3:
			typ = "kee";
			break;
		default: 
			typ = "kee";
	}
	lvl=me->query_skill("necromancy", 1);
	me->add_temp("apply/spells", lvl*2);
	if( COMBAT_D->do_magic_attack( me, target, "spells", typ, 0) ) {
		msg +=  HIR "һ�������ʱ�總��֮������ɢ������\n"NOR;
		message_vision(msg, me, target);
		// 900 damage * 2 = 1800 damage fixed.
		ap = me->query_skill("spells");
		damage = 60 + ap*ap/360;
		if( flag == 3 ) {
			damage *= 2;
		}
		// +20% chance double damage.
		if( random(100) < F_ABILITY->check_ability(me,"nether_add",1)*2 ) {
			damage = damage*2;
		}
		damage = COMBAT_D->magic_modifier(me, target, typ, damage*2);
		damage = damage*(100+F_ABILITY->check_ability(me,"3_bolt2_add",3)*2)/100;
		target->receive_damage(typ, damage, me);
		target->set_temp("damaged_during_attack", damage);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,damage);
		
	} else {
		msg += YEL"Ȼ������Ϩ��\n"NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/spells", -lvl*2);
	return ;
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
