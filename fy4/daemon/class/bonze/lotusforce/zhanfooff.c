// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>

int exert(object me, object target)
{
	mapping buff;
	int extra,ratio,delay;
	
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳ���ʹ�á�ս���С���\n");
	
	extra=me->query_skill("lotusforce",1);
	if(extra<150)
		return notify_fail("��Ҫ150�������ķ�������ɢ��ս���С�״̬��\n");

    if( !ANNIE_D->check_buff(me,"xg-cloudstaff-up")) 
       		return notify_fail("�㲻���˹��С�\n");

	if(target && me!=target)
		return notify_fail("��ɢ��ս���С�ֻ�������Լ����ϡ�\n");
	
	if (me->query("timer/pfm/xg-heal-down") + 30 > time())
		return notify_fail("��ս���С���ɢÿ30��ֻ��ʹ��һ�Ρ�\n");
	
	ANNIE_D->debuff(me,"xg-cloudstaff-up");
	
	me->set("timer/pfm/xg-heal-down",time());
	buff =
		([
      "caster":me,
      "who":me,
      "type":"xg-heal-down",
      //"type2":"manatwist",
      "att":"curse",
      "name":"�����ķ���ս���С�����֢",
      "time":180,
      "buff_msg":HIY"$N"HIY"��ս���С�����֢��������\n"NOR,
      "disa_type":1,
      "disa_msg":RED"$N"RED"��ս���С�����֢��������\n"NOR,
    ]);
  ANNIE_D->buffup(buff);
	return 1;
}
