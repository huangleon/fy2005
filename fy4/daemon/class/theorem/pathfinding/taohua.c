// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object qer;
	string qqq;

	int lvl=10;

	qqq="/d/maze/taoyuan-entry";

	extra = me->query_skill("pathfinding",1);

	if (extra < lvl && userp(me))
		return notify_fail("��Ҫ����"+lvl+"������·���顣\n");
	
	if (me->is_fighting())
		return notify_fail("����������ս�����޷�ʹ����·���顣\n");
	
msg=HIM"
��Ȼ��һ��紵������Χ���һ�֦��Ȼ�ƶ�������������
һ����ҡ��ת���㷢���Լ��ֻص����һ��ֵĽ��ڡ�
"NOR;

	if (base_name(environment(me))[0..19] == "/d/maze/taoyuan-maze")
	{
		tell_object(me,msg+"\n");
		qer=find_object(qqq);
		if (!qer)
			qer=load_object(qqq);
		me->move(qqq);
	}
	else
		tell_object(me,HIG"��ʧ���ˡ�\n"NOR);

	me->perform_busy(3);
	return 1;
}



