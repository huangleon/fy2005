// annie 07.2003
// dancing_faery@hotmail.com
// �������� 
// ����ӯ�������˺�

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		int i,t,skill,level,damage;
		mapping buff;
		string msg;
		object weapon;

		level = me->query("annie/chillblade_binglunyinjing");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;
		
/*		����ӯ��?����֮�� chillblade_binglunyinjing_1 L100, 1M
		����ӯ��?̫��֮�� chillblade_binglunyinjing_2 L150, 2.4M
						
		Level = 0, damage = 165 @ 1M
				@ 1M --> scroll I
		Level = 1, damage = 251 @ 1M
		Level = 1, damage = 373 @ 2.7M
		Level = 1, damage = 437 @ 4 M
		Level = 1, damage = 514 @ 6 M
		Level = 1, damage = 604 @ 9 M
		Level = 1, damage = 630 @ 10M
		
				scroll II --> removed from PLAYER
		Level = 2, damage = 582 @ 2.7M
		Level = 2, damage = 760 @ 5M
		Level = 2, damage = 977 @ 9M
*/
		
		if (level == 1)
			damage = to_int(pow(to_float(me->query("combat_exp")),0.38));
		else if (level >= 2)
			damage = to_int(pow(to_float(me->query("combat_exp")),0.44));
		else
			damage = to_int(pow(to_float(me->query("combat_exp")),0.37));

		damage = damage- 65;
				
        skill = me->query_skill("chillblade",1);

		if (skill < 80)
        	return notify_fail("������ӯ������Ҫ����80���ı����߾���\n");

		if( ANNIE_D->check_buff(me,"enchantweapon")) 
			return notify_fail("����������ʩչ���Ƶ�������\n");

		weapon = me->query_temp("weapon");
			if (!weapon->query("ice_blade"))
			return notify_fail(weapon->query("name")+"�޷�������������������ʩչ����ӯ����\n");

		if (me->query("gender") != "Ů��")
			msg=HIG"$N"HIG"�����³�"+weapon->query("name")+HIG"̤�裬��ɫ�Ĺ�â��"+weapon->query("name")+HIG"����������������һ��ǳǳ���廪��\n"NOR;
		else
			msg=HIG"$N"HIG"�����³�"+weapon->query("name")+HIG"���裬��ɫ�Ĺ�â��"+weapon->query("name")+HIG"����������������һ��ǳǳ���廪��\n"NOR;

		
		if (!userp(me))		damage = 0;		// 	��chillblade���Ѿ����Զ������ˣ�	
		
		buff =
		([
			"caster":me,
			"who":me,
			"type":"enchantweapon",
			"att":"bless",
			"buff1":"annie/chillblade_extradamage",
			"buff1_c":damage,
			"buff2":"marks/kongmen_adjust",
			"buff2_c": 1,
			"name":"�����߾�������ӯ��",
			"time": 1800,
			"buff_msg":msg,
		]);


		ANNIE_D->buffup(buff);

		me->perform_busy(1);

        return 1;
}



