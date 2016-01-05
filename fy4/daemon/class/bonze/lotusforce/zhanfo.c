// hippo @ fy2005 workgroup. 2010.03.07

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if( me->query("class")!="bonze" ) {
		return notify_fail("ֻ���˹����µĵ��Ӳ����̡�ս���С���\n");
	}
	if( ANNIE_D->check_buff(me,"xg-cloudstaff-up") ) {
		return notify_fail("���Ѿ����ˡ�ս���С����ˡ�\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") ) {
		return notify_fail("������ʩչ��ս���С���\n");
	}
	//extra = me->query_skill("necromancy",1);
	if( me->query_skill("essencemagic",1) < 150 || me->query_skill("lotusforce")< 150 ) {
		return notify_fail("��ս���С��ķ���150�������ķ���150����ʶ��ͨ��\n");
	}
	
	if( target != me ) 
		return notify_fail("��ֻ�������Լ������ܡ�\n");

	if( me->query("force") < 10 ) {
		return notify_fail("��������Ҫ����10��������\n");
	}
	if( userp(me) ) {
		me->add("force",-10);
	}

	if( userp(me) ) {
		duration = me->query("timer/pfm/xg-cloudstaff-up") + 30 - time();
		if( duration > 0 ) {
			return notify_fail(YEL"��ս���С�������ȴ�"+duration+"�롣\n"NOR);
		}
	}
	
	ANNIE_D->debuff(me,"xg-heal-down");
	
	me->set("timer/pfm/xg-cloudstaff-up",time());
	
  buff =
		([
      "caster":me,
      "who":me,
      "type":"xg-cloudstaff-up",
      //"type2":"manatwist",
      "att":"bless",
      "name":"�����ķ���ս����",
      "time":10800,
      "buff_msg":HIY"$N"HIY"��ս���С����\n"NOR,
      "disa_type":1,
      "disa_msg":RED"$N"RED"��ս���С���ɢ��\n"NOR,
    ]);
    ANNIE_D->buffup(buff);
    return 1;
}