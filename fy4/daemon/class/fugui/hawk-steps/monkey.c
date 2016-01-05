#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,extra,level,duration;
	mapping buff;
	int g,k,s,n;
	function f;

	if (me->query("class") != "fugui")
		return notify_fail("ֻ�и�����Ӳ���ʩչ��������Ѫ����\n");

	extra = me->query_skill("skyforce",1);
	if (extra < 160 && userp(me))
		return notify_fail("��������Ѫ����Ҫ����160���ı̿��ķ���\n");

	extra = me->query_skill("hawk-steps",1);
	if (extra < 160 && userp(me))
		return notify_fail("��������Ѫ����Ҫ����160��������������\n");

	duration = me->query("timer/pfm/fg-monkey") + 30 -time();
	if (duration > 0)
       	return notify_fail("��������Ѫ����Ҫ�ȴ�"+duration+"�������ٴ�ʩչ��\n");

	if (ANNIE_D->check_buff(me,"fg-monkey")>0){
		ANNIE_D->debuff(me,"fg-monkey");
		return 1;
	}
	
	me->set("timer/pfm/fg-monkey", time());
		
	target = me;
	
	n = 2;
	
	g = target->query("max_gin") / n;
	k = target->query("max_kee") / n;
	s = target->query("max_sen") / n;

	f = (: call_other, __FILE__, "fullnpc",target,g,k,s :);

	me->full_me();
	buff =
		([
			"caster":me,
			"who":target,
			"type":"fg-monkey",
			"att":"bless",
			"name":"��ѩ�ľ���������Ѫ",
			"buff0": "apply/dodge",
			"buff0_c": 200,
			"buff1":"gin",
			"buff1_c":-g,
			"buff2":"kee",
			"buff2_c":-k,
			"buff3":"sen",
			"buff3_c":-s,
			"time":10,
			"buff_msg":HIW"$N"HIW"�������������ߣ�ֻ����������ֹ��ѪҺ�������ᣡ\n\n"NOR,
			"disa_msg":WHT"$N"WHT"��Ѫ����ͨ����������������\n"NOR,
			"finish_function":bind(f, this_object()),
			"disa_type":3,
			"special_func":1,
		]);
	ANNIE_D->buffup(buff);
    return 1;
}


void fullnpc(object target,int g,int k,int s)
{
	if (!target)	return;
	target->add("eff_gin",g);
	target->add("eff_kee",k);
	target->add("eff_sen",s);
	return;
}

