// annie 07.2003
// dancing_faery@hotmail.com
// ��������
// 60����Dodge 3-15 hit��feat��cdt 30min
// ���ڴ�pfm����Ҫ��enable���жϣ���ֹЧ�������dodge��

// ��dodge���ƶ���cast.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
//int perform(object me, object target)
{
	string msg;
	int extra,	level, duration;
	mapping buff;
	
	if (me->query("class")!= "moon" && userp(me))
		return notify_fail("ֻ����¹��˲���ʹ�á��������硻\n");
		
	if(me->query_skill("heart-listening",1) < 200 && userp(me))
		return notify_fail("���������硻����Ҫ����200���Ļ���������\n");

	extra = me->query_skill("stormdance",1);
	if (extra < 150)
		return notify_fail("���������硻��Ҫ����150����������衣\n");

	level = me->query("annie/stormdance_zhaoyuwanqing");
	if (userp(me) && level<1)
		return notify_fail("���������硻��Ҫ�õ��йؾ�������ʹ�á�\n");
		
	duration = me->query("timer/evade")+ 1800 -time();
	if( duration>0 && userp(me))	// 30minһ��
       	return notify_fail(CYN"���������硻�ķ�����������ȴ�"+duration/60+"���ӡ�\n"NOR);

	if (me->query("timer/evade") + 120 > time())
        	return notify_fail("���������硻�ķ��������󣬲�������ʹ�á�\n");

	if (me->query_skill_mapped("force") != "snowforce" && userp(me))
       	return notify_fail("���������硻��Ҫ����ѩ�ľ�������\n");

	if (me->query_skill_mapped("dodge") != "stormdance" && userp(me))
       	return notify_fail("���������硻��Ҫ�����������á�\n");

	if( ANNIE_D->check_buff(me,"feat")) 
       	return notify_fail("���Ѿ���ʩչĳ�����Ƶļ����ˡ�\n");

	if (me->query("force") < 100 && userp(me))
		return notify_fail("���������硻��Ҫ����100��������\n");
	if (userp(me))
		me->add("force",-100);

/*��������?��һ��	stormdance_zhaoyuwanqing_1		L150	1M	6
��������?�ڶ���	stormdance_zhaoyuwanqing_2		L150	2.4M	9
��������?������ stormdance_zhaoyuwanqing_3		L150	4M		12
*/

	level = me->query("annie/stormdance_zhaoyuwanqing");
	if (me->query("class") != "moon")
		level = 0;
	if (!userp(me))
		level = 5;

	if (me->query("class") != "moon")
		level = 0;
	
	extra = 5 + (level-1) * 3;
	if (extra > 15)
		extra = 15;
	
	extra += 1;
	
	me->set("timer/evade",time());
	if (me->is_fighting() && userp(me))
	    me->perform_busy(1);

		buff =
			([
				"caster":me,
				"who":me,
				"type":"feat",
				"type2": "evade",
				"att":"bless",
				"name":"������衤��������",
				"buffup_name":"evade",
				"buffup_type":""+extra,
				"buffup_ratio":extra,
				"time":60,
				"buff_msg":HIC"$N"HIC"��Ϣ����ʩչ���������ʱ�ľ����飬�����Ȼ���\n"NOR,
				"disa_msg":WHT"\n������･��������������ٰ��ճ������硣\n\n"NOR,
				"special_func":2,
			]);
		ANNIE_D->buffup(buff);

        return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
