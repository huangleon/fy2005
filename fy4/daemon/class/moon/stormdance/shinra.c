// annie 08.2004
// dancing_faery@hotmail.com
// ��ѩ����

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra, level, duration;
	
	if (userp(me))
		return notify_fail("�����õ��书��û�������ؼ���\n");
		
	if (me->query("class") != "moon")
		return notify_fail("ֻ����¹��ĵ��Ӳ���ʩչ����Ӱ���ޡ���\n");

	extra = me->query_skill("stormdance",1);
	if (extra < 140)
		return notify_fail("����Ӱ���ޡ���Ҫ����140����������衣\n");

	duration = me->query("timer/pfm/shinra") + 1800 - time();
	if (duration > 0 && userp(me))
       	return notify_fail("�㻹��ȴ�"+ duration/60+"�������Ҳ����ٴ�ʩ������Ӱ���ޡ�\n");

	if( ANNIE_D->check_buff(me,"feat")) 
       	return notify_fail("���ؼ������Ѿ���ʩչ��һЩ�ؼ���ͻ������ͬʱʹ�á�\n");

	buff =
		([
			"caster":me,
			"who":me,
			"type":"feat",
			"type2":"shinra",
			"att":"bless",
			"name":"������衤��Ӱ����",
			"time":90,
			"buff_msg":CYN"$N"NOR+CYN"������Ϭ����������ϯ������������������ġ�\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	me->set("timer/pfm/shinra",time());
	return 1;
}
