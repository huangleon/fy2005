// Swords to Plowshares: ����Ϊ��
// Destroy target guard .The controller gains life equal to its kee/4.
// 

// �����Ը�robot quest������nb_chat֮�С�����һ��0 busy skill��


#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	object obj,owner;
	int sk = me->query_skill("heart-listening",1);
	int a = 0;

	if( userp(me) ) {
		return notify_fail("�����õ��书��û�������ؼ���\n");
	}
	if( me->query("class")!="moon" && userp(me) ) {
		return notify_fail("ֻ����¹����˲��ܹ�ʩչ������б�졻��\n");
	}
	if( me->query("mana") < me->query_skill("heart-listening",1) && userp(me) ) {
		return notify_fail("��ķ���������\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) || !target->is_fighting(me) ) {
		return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	obj = target; // lazy annie
	// ������ solidspirit
	if( base_name(obj) == "/obj/npc/solidghost") {
		if( sk >= 60 ) {
			a = 1;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ��ɽ wolf
	if( base_name(obj) == "/obj/npc/wolf" ) {
		if( sk >= 50 ) {
			a = 2;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ��͢ alert-guard
	if( base_name(obj) == "/obj/npc/danei" ) {
		if( sk >= 25 ) {
			a = 3;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ��͢ alert-guard
	if( base_name(obj) == "/obj/npc/danei_guard" ) {
		if( sk >= 25 ) {
			a = 3;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ��͢ yin shiwei
	if( base_name(obj) == "/obj/npc/shiwei" ) {
		if( sk >= 75 ){
			a = 4;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ��͢ yue huwei
	if( base_name(obj) == "/obj/npc/fighter1" ) {
		if( sk >= 100 ) {
			a = 5;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ��͢ yue huwei
	if( base_name(obj) == "/obj/npc/huwei" ) {
		if( sk >= 100 ) {
			a = 5;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� zombie
	if( base_name(obj) == "/obj/npc/zombie" ) {
		if( sk >= 10 ) {
			a = 6;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� zombie
	if( base_name(obj) == "/obj/npc/zombie2") {
		if( sk >= 80 ) {
			a = 6;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� hell guard
	if( base_name(obj) == "/obj/npc/hell_guard" ) {
		if( sk >= 30 ) {
			a = 7;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� heaven soldier
	if( base_name(obj) == "/obj/npc/heaven_soldier" ) {
		if( sk >= 70 ) {
			a = 7;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� sq-taoist
	if( base_name(obj) == "/obj/npc/taoist_guard" ) {
		if( sk >= 110 ) {
			a = 8;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� sq-taoist
	if( base_name(obj) == "/obj/npc/devil_guard" ) {
		if( sk >= 150 ) {
			a = 8;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ���� fire crane
	if( base_name(obj) == "/obj/npc/fire_crane" ) {
		if( sk >= 135 ) {
			a = 9;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ħ�� guardian
	if( base_name(obj) == "/obj/npc/guardian1" ) {
		if( sk >= 40 ) {
			a = 10;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ħ�� guardian
	if( base_name(obj) == "/obj/npc/guardian2" ) {
		if( sk >= 80 ) {
			a = 10;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ħ�� guardian
	if( base_name(obj) == "/obj/npc/guardian3") {
		if( sk >= 120 ) {
			a = 10;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ħ�� guardian
	if( base_name(obj) == "/obj/npc/guardian4" && sk >= 160 ) {
		if( sk >= 160 ) {
			a = 10;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	// ħ�� guardian
	if( base_name(obj) == "/obj/npc/guardian5" ) {
		if( sk >= 200 ) {
			a = 10;
		} else {
			return notify_fail(" ����Ŀǰ�Ի������������򣬻��޷��Ի��������Ķ��֡�\n");
		}
	}
	if( !a ) {
		return notify_fail("������б�졻ֻ�ܶԱ��ٻ������ĸ��ֻ���ʹ�á�\n");
	}
	if( obj->query("no_purge") ) {
		return notify_fail("����ʱ���ܶ���ʹ�á�����б�졻��\n");
	}
	if( userp(me) ) {
		me->add("mana",-sk);
	}
	if( random(2) && userp(me) ) {
		me->perform_busy(1);
		return notify_fail("��ʧ���ˣ�\n");
	}
	message_vision(WHT"\n$n"WHT"����γ�����������羵����ϡӳ��$N"WHT"�ĵ�Ӱ��ȴ����һĨǳǳ���Ĺ�������������\n"NOR,obj,me);
	message_vision(BLU"\n$N"BLU"������$n"BLU"��Ŀ������جج�����תȥ��\n\n"NOR,obj,me);
	owner=obj->query("possessed");
	if( owner && a != 3 && me->is_killing(owner->query("id")) && !environment(me)->query("no_death_penalty") ) {
		if( a != 6 && a != 7 ) {
			owner->receive_fulling("kee",obj->query("kee")/4);
		} else {
			owner->receive_fulling("kee",obj->query("kee")*2/3);
		}
	}
/*
	obj->set_temp("last_damage_from",me);
	obj->backattack();
	obj->move(load_object("/obj/void"));
	obj->die();
*/
	obj->remove_killer(me);
	me->remove_killer(obj);
	me->set("mana",me->query("mana")/2);
	if( owner ) {
		obj->kill_ob(owner);
		if( !me->is_fighting(owner) ) {
			owner->kill_ob(me);
			me->kill_ob(owner);
		}
	}
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
