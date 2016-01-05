#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon, *inv, env;
		int i, lvl;
		mapping buff;
						
		p_name = "jixingjue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
		
		if (me->query("mana")<100)
			return notify_fail("������Ҫ100�㷨����\n");
		if (userp(me))
			me->add("mana",-100);
		
		if(ANNIE_D->check_buff(me, "magicup"))
			return notify_fail("���Ѿ���ʩչ������߷������������ľ��ˡ�\n");
		
		msg = HIC "\n$N���������дʣ�һ����â��$Nͷ�������������$N��Χ��\n" ;
		msg +="��â����һ��������ע����$N��ȫ��\n\n"NOR;

		lvl = F_LEVEL->get_level(me->query("combat_exp"));
                
        buff =
		([
			"caster":me,
			"who": 	me,
			"type":"magicup",
			"att": "bless",
			"name":"���»���",
			"buff1":"apply/spells",
			"buff1_c":lvl,
			"buff2":"apply/magic",
			"buff2_c":lvl,
			"buff3":"apply/cursism",
			"buff3_c":lvl,	
			"time":   20,
			"buff_msg":msg,
		]);
		ANNIE_D->buffup(buff);
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		return 1;
}
