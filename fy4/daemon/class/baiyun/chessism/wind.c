//	Remove lockup.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	int extra;
	if (me->query("class") != "baiyun") 
		return notify_fail("ֻ�а��Ƶ����ӿ���ʹ�á��ƿ���ɢ��\n");
		
	extra = me->query_skill("chessism", 1);
	if(extra < 50) 
		return notify_fail("���ƿ���ɢ����Ҫ50�����ĵ��ķ���\n");
      
	if( !target ) target = me;
  	if (target!= me)
  		return notify_fail("���ƿ���ɢ��ֻ����������\n");
        
	if( (int)me->query("force") < 200 )
		return notify_fail("�������������\n");

	if( me->query_temp("apply/painting") ) 
		return notify_fail("���Ѿ���ʹ�á��ƿ���ɢ���ˡ�\n");
		
	message_vision(HIG"$N�´�ƮƮ���Ƶ����������Χ������ʱ���ƿ���ɢ�������泩��\n"NOR,me);
	me->add("force", -50);
	me->delete_temp("till_death/lockup");
	return 1;
}

