// ���D�� manatwist
// mana cost x 3,damage x 2

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if( ANNIE_D->check_buff(me,"feat") ) {
		return notify_fail("������ʩչ���Ƽ��գ��޷�ʹ�õ�ת������\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") ) {
		return notify_fail("������ʩչ��ת������\n");
	}
	extra = me->query_skill("necromancy",1);
	if( me->query_skill("taoism",1) < 220 || me->query_skill("gouyee")< 150 ) {
		return notify_fail("����ת�������ķ���150�������ķ���220����ʦ������\n");
	}
	if( userp(me) ) {
		duration = me->query("timer/pfm/manatwist") + 1800 - time();
		if( duration > 0 ) {
			return notify_fail(MAG"����ת��������������̫��������ȴ�"+(duration/60)+"���ӡ�\n"NOR);
		}
	}
	me->set("timer/pfm/manatwist",time());
	buff =
		([
			"caster":me,
			"who":me,
			"type":"feat",
			"type2":"manatwist",
			"att":"bless",
			"name":"�����������ת����",
			"time":30,
			"buff_msg":HIB"$N"HIB"��׶��£�����̫�����ǣ���������Ƽ�����ʱ����ɫ���ڷɴ������ﱬ����\n"NOR,
			"disa_type":1,
			"disa_msg":CYN"$N��ߵ���������ɢȥ��ֻ��$N"NOR+CYN"������Ϣ���������¡�\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}


/* bolt --> 50 + 560 + random(560) = [610+random(560)]*flag
  demonic --> 1800 *flag
  thunderbolt --> (690*flag)
  thunderstorm --> (1380) * flag
  */