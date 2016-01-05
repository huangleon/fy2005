// hippo @ fy2005 workgroup. 2010.03.07

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if( me->query("class")!="taoist" ) {
		return notify_fail("ֻ��������Ӳ���ʹ�ô��ķ���\n");
	}
	if( ANNIE_D->check_buff(me,"feat") ) {
		return notify_fail("������ʩչ���Ƽ��գ��޷�ʹ�á�רע����\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") ) {
		return notify_fail("������ʩչ��רע����\n");
	}
	extra = me->query_skill("necromancy",1);
	if( me->query_skill("taoism",1) < 220 || me->query_skill("gouyee")< 150 ) {
		return notify_fail("��רע���ķ���150�������ķ���220����ʦ������\n");
	}
	
	if( userp(me) ) {
		duration = me->query("timer/pfm/manatwist") + 180 - time();
		if( duration > 0 ) {
			return notify_fail(MAG"��רע����������̫��������ȴ�"+duration+"�롣\n"NOR);
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
      "name":"�����ķ���רע",
      "time":120,
      "buff_msg":HIB"$N"HIB"Ĭ�������䣬�·������ѵ�������硣\n"NOR,
      "disa_type":1,
      "disa_msg":CYN"$N"CYN"������ƣ������Ҳ�޷����о���\n"NOR,
    ]);
    ANNIE_D->buffup(buff);
    return 1;
}