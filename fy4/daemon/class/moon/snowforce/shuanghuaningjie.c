// annie 07.2003
// dancing_faery@hotmail.com
// AE Stun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int check_legit(object ob); 
int stun(object me, object obj,int flag);

int exert(object me, object target, int amount)
{
	int i, level, extra, duration;
	object env;
	object * inv;

	if( me->query("class") != "moon" ) {
		return notify_fail("ֻ����¹����˲���ʩչ��˪�����᡻��\n");
	}
	extra = me->query_skill("snowforce",1);
	if( extra < 60 ) {
		return notify_fail("��˪�����᡻��Ҫ����60������ѩ�ľ���\n");
	}
/* 
˪������?��һ	snowforce_shuanghuaningjie_1	L60		1M
˪������?��һ	snowforce_shuanghuaningjie_2	L100	2.4M
˪������?��һ	snowforce_shuanghuaningjie_3	L150	4M
*/
	level = me->query("annie/snowforce_shuanghuaningjie");
	if( !userp(me) ) {
		level = 5;
	}
	if( level >= 3 ) {
		i = 300;
	} else if( level >= 2 ) {
		i = 600;
	} else if( level >= 1 ) {
		i = 720;
	} else {
		i = 900;
	}
	if( !userp(me) ) {
		i = 45;
	}
	duration = me->query("timer/shuanghuaningjie") + i - time() - F_ABILITY->check_ability(me,"3_shnj_add",3)*15;
	if( duration > 0 ) {
		return notify_fail("��˪�����᡻����ȴ�" + duration + "���Ӳ����ٴ�ʩչ��\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("��˪�����᡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( me->query("force") < 100 && userp(me) ) {
		return notify_fail("��˪�����᡻��Ҫ����100��������\n");
	}
	if( userp(me) ) {
		me->add("force",-100);
	}
	me->set("timer/shuanghuaningjie",time());
	message_vision(HIW"\n$N"HIW"˫��Ĵָʳָ�����ϣ�˫��΢���������дʡ�ɲʱ�䣬һ���溮���ǵ������
$N"HIW"˫��Բ������Ȼй���������¶���Ȼ���ͣ�������������˸�ŵ��˪����������\n\n" NOR, me);

	env = environment(me);
	inv = all_inventory(env);
	extra = 2;
	for( i = 0; i < sizeof(inv); i++ ) {
		if( inv[i]->is_corpse() ) {
			continue;
		}
		if( !inv[i]->is_character() ) {
			continue;
		}
		if( !me->is_fighting(inv[i]) ) {
			continue;
		}
		stun(me, inv[i], extra);
	}
	return 1;
}


int stun(object me, object obj, int flag)
{
	int b;
	message_vision(WHT"$N"NOR+WHT"����һ����һʱ�侹�����ý������ͣ��ֽŲ��飡\n" NOR, obj);
	if( b = obj->query("no_busy") ) {
		obj->delete("no_busy");
		obj->perform_busy(obj->query_busy()+flag);
		obj->set("no_busy", b);
		return 1;
	}
	obj->perform_busy(obj->query_busy()+flag);
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
