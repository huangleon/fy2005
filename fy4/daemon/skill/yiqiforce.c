// yiqiforce.c
#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","��Ԫһ����");
	set("usage/parry",1);
	set("usage/force",1);
	set("usage/iron-cloth",1);
	set("usage/unarmed",1);
	set("ic_effect",100);
	set("type","force");
	set("difficulty",1000);
	set("bounce_ratio",40);
	set("effective_level",500);
	set("skill_class","npc");
	set("absorb_msg",			({
			"$n������ת��˫��΢�����޼᲻�ݵĻ�Ԫһ�������ȶ�����\n",
			"$nʩչ����Ԫһ���������������纮����\n",
			"$n����΢չ����Ԫһ�����������ռ䡣\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n�������ȣ��������飬$N�������ɽ���\n",
			"$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
			"$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
			})
	);

	action = ({
			([      "action":
			"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫһ������$n��$l",
			        "force":                300,
			        "damage_type":  "����"
			]),
			([      "action":
			"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫһ������$n��$l",
			        "force":                500,
			        "damage_type":  "����"
			]),
			([ 	"action":
			"$Nʹ��һ�С�������ػ�Ԫ����˫�־۳�һ�Ż�Ԫһ������$n��$l",
			        "force":                700,
			        "damage_type":  "����"
			]),
			([	"action":
			"$Nʹ��һ�С�������ػ�Ԫ����ȫ���ڿն���ȫ����һ�Ż�Ԫһ������$n��$l",
			        "force":                900,
			        "damage_type":  "����"
			]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor) {
	mixed foo;
	int force;
	
	foo = ::hit_ob(me, victim, damage_bonus, factor);
	if(intp(foo) && (damage_bonus + foo > 0) 
&& random(3*(me->query_skill("yiqiforce", 1)/2)) > (damage_bonus + foo)) {
		victim->receive_wound("kee", (damage_bonus + foo));
		victim->receive_wound("gin", (damage_bonus + foo));
		victim->receive_wound("sen", (damage_bonus + foo));
		force = victim->query("force");
		victim->set("force", force-random(10)-1);
		victim->set("max_force", 0);
		return "$N�Ļ�Ԫһ�����ݻ���$n����Ԫ��������\n";
	}
	return foo;
}

void skill_improved(object me) {
	if((int)me->query_skill("incarnation", 1)  < random(501) ) {
		tell_object(me, HIR "\n��ͻȻȫ���飡�߻���ħ�ˣ���....\n\n" NOR);
		me->skill_death_penalty(me->query("combat_exp"));
		me->delete_skill("yiqiforce");
		me->unconcious();
	} 
}

