// hippo @ fy2005 workgroup. 2010.03.07

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if(me->query("class")!="fugui")
    		return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ�����յ����롻��\n");

	if( ANNIE_D->check_buff(me,"fg-youdishenru") ) {
		return notify_fail("���յ����롻���ڽ����С�\n");
	}

	if( me->query_skill("xuezhan-spear",1) < 190 || me->query_skill("skyforce")< 160 ) {
		return notify_fail("���յ����롻�ķ���160���̿��ķ���190��Ѫսǹ����\n");
	}
	
	if( target != me ) 
		return notify_fail("���յ����롻ֻ���Լ�����\n");

	if( me->query("force") < 100 ) {
		return notify_fail("��������Ҫ����100��������\n");
	}
	if( userp(me) ) {
		me->add("force",-100);
	}

	if( userp(me) ) {
		duration = me->query("timer/pfm/fg-youdishenru") + 600 - time();
		if( duration > 0 ) {
			return notify_fail(YEL"���յ����롻������ȴ�"+duration+"�롣\n"NOR);
		}
	}
	
	me->set("timer/pfm/fg-youdishenru",time());
	
  buff =
		([
      "caster":me,
      "who":me,
      "type":"fg-youdishenru",
      "att":"bless",
      "name":"�̿��ķ����յ�����",
      "time":60,
      "buff_msg":HIY"$N"HIY"���յ����롻�ɹ���\n"NOR,
      "disa_type":1,
      "disa_msg":RED"$N"RED"���յ����롻��ȴ��\n"NOR,
    ]);
    ANNIE_D->buffup(buff);
    return 1;
}