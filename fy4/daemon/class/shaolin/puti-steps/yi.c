// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, num, i, duration, title, hate;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	object soldier, *enemy;
	int strategy, leadership;
	int timer;
	if( userp(me) ) {
		if( me->query("family/master_id") != "master yue" || me->query("class") != "official" ) {
			return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ�á�һ�ֳ����󡻡�\n");
		}
	}
	skill = me->query_skill("strategy",1);
	if( me->query_skill("strategy",1) < 100 || me->query_skill("leadership",1) < 100 ) {
		return notify_fail("��һ�ֳ�������Ҫ100��������100������֮����\n");
	}
	timer = 1800 - F_ABILITY->check_ability(me,"yi_add")*60;
	duration = me->query("timer/pfm/alert") - time() + timer;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60)+"�������Ҳ����ٴη���һ�ֳ�����\n");
	}
	if( ANNIE_D->check_buff(me,"lockfield") >= 1 ) {
		return notify_fail("�˵ص��Ʋ������޷�����һ�ֳ�����\n");
	}
	if( !me->is_fighting() ) {
			return notify_fail("һ�ֳ�����ֻ����ս���з�����\n");
	}
	if( me->query_temp("max_guard") > 1 ) {
		return notify_fail("һ�ֳ��������ڷ�����\n");
	}
	msg = BGRN + HIY "$N�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"һ�ֳ���֮��\n" NOR HIB"
���������У�һ�˺��¡��������죬����$N��ǰ�е������Ѷ����������ˣ���ĩ���Ϻ�\n\n"NOR;

	message_vision(msg, me);
	me->set("timer/pfm/yue_array",time());
	seteuid(getuid());
	soldier = new("/obj/npc/danei_guard");
	if( soldier ) {
		soldier->set("no_purge", 1);
		soldier->move(environment(me));
		soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
		soldier->set_name(WHT"��ʿ"NOR,({ "sishi" })); 
		enemy = me->query_enemy();
		if( enemy ) {
			for( i = 0; i < sizeof(enemy); i++ ) {
				hate = enemy[i]->query_hate(me);
				enemy[i]->add_hate(soldier, hate);
			}
			me->remove_all_killer();
			me->add_temp("max_guard",1);
		}
		me -> set("timer/pfm/alert",time());
		soldier->set("no_purge", 0);
	}
	return 1;
}