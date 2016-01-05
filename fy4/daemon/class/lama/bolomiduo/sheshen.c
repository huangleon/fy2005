// Silencer @ FY4 workgroup. Aug.2004
//	-160 sen DS

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	int i, skill, duration, iron;

	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д��ѵ��Ӳ������á�����\n");
	}
	skill = me->query_skill("bolomiduo", 1);
	if( skill < 100 ) {
		return notify_fail("��������Ҫ100�������۶��ľ���\n");
	}
	iron = me->query_skill("lamaism", 1);
	if( iron < 100 ) {
		return notify_fail("��������Ҫ100�����ڷ𷨡�\n");
	}
	duration = me->query_temp("timer/pfm/dz_sheshen") + 20 - time();
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+ duration + "������ٴ�ʹ�á�����\n");
	}
	amount = me->query("max_kee")*15/100;
	if( (int)me->query("kee") < amount ) {
		return notify_fail("������������Ҫ15%����Ѫ��\n");
	}
	me->receive_damage("kee", amount);
	message_vision(BBLU+HIY"$N��͸�ȱ�֮ɫ��˫�ֺ�ʮ���Ƽ�֮������Ȼ���ţ���С���˲���貣�����������⣬
ֱ���������͵��󳪣���С���˲���쳹��ء�\n"NOR, me);
	me->set_temp("timer/pfm/dz_sheshen", time());
	amount = me->query("max_mana")*4/5;
	if( me->query("mana") + amount < me->query("max_mana")*2 ) {
		me->add("mana", amount);
	} else {
		me->set("mana", me->query("max_mana")*2);	
	}
	me->force_status_msg("mana");
	me->perform_busy(1);
	return 1;
}