#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int lvl;
	object corp, room, ghost;

	if( me->query("class") != "yinshi" ) {
		return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
	}
	if( (int)me->query_skill("celecurse",1) < 100 ) {
		return notify_fail("ʬ����Ҫ100����ͨ�콵��\n");
	}
	if( !target || !target->is_ghost() || userp(target) ) {
		return notify_fail("��ֻ�ܶԹ���������ͷ��\n");
	}
	room = environment(target);
	if( me->query_temp("timer/solidghost") > 0 ) {
		return notify_fail("���Ѿ�����סһ�������ˡ�\n");
	}
	if( !corp = present("corpse",environment(me)) ) {
		return notify_fail("�����Χû��ʬ�壡\n");
	}
	if( (int)me->query("kee") < 100 ) {
		return notify_fail("��Ҫ����������Ѫ��\n");
	}
	me->receive_wound("kee", 100);
	lvl=me->query_skill("cursism");
	msg = HIC "$N��ն���$n��㼸�£�$n������վ��������\n\n" NOR;
	message_vision(msg,me,corp);
	seteuid(getuid());
	ghost = new("/obj/npc/solidghost");
	if( ghost ) {
		ghost->set("no_purge", 1);
		ghost->set("name", corp->query("victim_name")+"������");
		ghost->set("gender", corp->query("gender"));
		ghost->move(environment());
		ghost->invocation(me, lvl); // maximum enable lvl = 200x�� + 200*0.5 = 500
		destruct(target);
		destruct(corp);
		me->set_temp("timer/solidghost",1);
		msg = HIC "$n��$N����������ë���Ȼ��Ц���������ˣ���ʲô�Ը���������\n\n" NOR;
		message_vision(msg, me, ghost);
		ghost->set("no_purge", 0);
		me->perform_busy(2);
	}
	return 1;
}

