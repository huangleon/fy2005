// feixian-steps.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","���ɲ���");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","baiyun");
	set("dodge_msg", ({
		"$nһ�С��������ࡹ�������ɵر��˿�ȥ��\n",
		"ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
		"$nʹ������ת��Ȩ�����������ɵ�������\n",
		"$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
		"����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��\n",
		"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
		"����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ\n"
	}) );

}


mixed dodge_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	if (me->query("class")!="baiyun")	return 0;
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chessism",1);
//	random(150) + 50 > 100	
	if (me->query_busy()>1)
	if (random(skill) + skill/3 > 100 && me->is_busy()) {
		message_vision(HIY"$N������գ�����б�ɣ��ĵ�������ƪ��������Ŀ��������Ȼ����������\n"NOR, me);	
		if (me->query_busy()==1) me->stop_busy();
			else me->start_busy(me->query_busy()-1);
	}
	return 0;
}	
