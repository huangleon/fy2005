// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, num, i, duration, title;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	object soldier;
	int strategy,leadership;
	int timer;

	if( userp(me) ) {
		if( me->query("family/master_id")!="master yue" || me->query("class")!="official" ) {
			return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ�á�ʮ������󡻡�\n");
		}
	}
	skill = me->query_skill("strategy",1);
	if( me->query_skill("strategy",1) < 250 || me->query_skill("leadership",1) < 250 ) {
		return notify_fail("��ʮ���������Ҫ250��������250������֮����\n");
	}
	if( me->query_temp("guard_count") < 2 ) {
		return notify_fail("��Ļ���̫�٣��в�����Ү��\n");
	}
	timer = 900;
	duration = me->query("timer/pfm/yue-shi") - time() + timer;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60)+"�������Ҳ����ٴη���ʮ�����֮��\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("ʮ�������ֻ����ս���з�����\n");
	}
	if( me->query_temp("max_guard") > 1 ) {
		return notify_fail("ʮ�����֮�����ڷ�����\n");
	}
	if( (int)me->query("force") < 200 ) {
		return notify_fail("��ʮ���������Ҫ�ķ�200���������\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	me->set("timer/pfm/yue-shi",time());
	msg = BGRN + HIY "$N"BGRN + HIY "�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"ʮ�����֮��\n" NOR HIW"
���������У��������ٰ��°��ۣ�������콵����ɱ������\n\n"NOR; 	
	message_vision(msg, me);
	seteuid(getuid());
	soldier = new("/obj/npc/spirit_guard");
	soldier->set("no_purge", 1);
	soldier->move(environment(me));
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
	if( soldier ) {
		message_vision(WHT"$N�ߺȣ��������ߣ��԰�����һǹ��\n"NOR, soldier);
	}
	soldier->set("no_purge", 0);
	soldier = new("/obj/npc/spirit_guard");
	soldier->set("no_purge", 1);
	soldier->set("name","����");
	soldier->move(environment(me));
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
	if( soldier ) {
		message_vision(WHT"$N�ߺȣ��������ߣ��԰�����һǹ��\n"NOR, soldier);
	}
	soldier->set("no_purge", 0);
	return 1;
}