// annie 07.2003
// dancing_faery@hotmail.com
// ˪��ѩ��
// HASTE 60 - 200��10 - 75��
// ���ڴ�pfm����Ҫ��enable���жϣ���ֹЧ�������dodge��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra,level;
	
	if (me->query("class")!= "moon" && userp(me))
		return notify_fail("��˪��ѩ�衻Ϊ��¹��ؼ���\n");
		
	extra = me->query_skill("stormdance",1);
	if (extra < 30)
		return notify_fail("��˪��ѩ�衻��Ҫ����30����������衣\n");

	
	if( ANNIE_D->check_buff(me,"haste")) 
       	return notify_fail("���Ѿ���ʩչ���Ƶ������ˡ�\n");

/*
˪��ѩ��?�ϲ�	stormdance_shuangtianxuewu_1	L50		1M
˪��ѩ��?�в�	stormdance_shuangtianxuewu_2	L100	2.4M
˪��ѩ��?�²�	stormdance_shuangtianxuewu_3	L150	4M
*/
	level = me->query("annie/stormdance_shuangtianxuewu");
	if (me->query("class") != "moon")
		level = 0;
	if (!userp(me))
		level = 5;

	if (me->query("force") < 50)
		return notify_fail("��˪��ѩ�衻��Ҫ����50��������\n");
	if (userp(me))	me->add("force",-50);

	extra = 150 + level * 50;		// 150 - 200 - 250 - 300, 60%-75%

		buff =
			([
				"caster":me,
				"who":me,
				"type":  "haste",
				"att": "bless",
				"name": "������衤˪��ѩ��",
				"buff1": "apply/haste",
				"buff1_c":extra,
				"time":	  extra/5,
				"buff_msg":WHT"$N"NOR+WHT"��̤��ã��������飬���纮��Ʈѩ�����ƽ�����\n"NOR,
			]);
			
		ANNIE_D->buffup(buff);
        return 1;
}

