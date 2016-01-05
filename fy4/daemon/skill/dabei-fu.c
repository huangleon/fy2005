// dabie-fu.c
// ��ؽ��������󱯸� - ӫ������ķ�
// ȡ���ڡ��������µ���
// - neon
//

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","��ؽ��������󱯸�");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("usage/force",1);
	set("difficulty",200);
	set("effective_level",300);
	set("skill_class","npc");
		
	set("unarmed_parry_msg",	({
			"$n�����ƺ����Ღ����һ�£��ֺ������û�ж�����Ȼ��$N����ʽȴ�Ʊ�\n���ε�˿��ǣ����Ī������ػ��ڿմ���\n",
			"����$n����һ�У������絶���Ʒ��ȵ�$N��Ϣһ�ϡ�\n",
			"$n���ֵ�ָ���죬���ַ������£���ʱ��Χ�������𣬾�Ȼ$nƾ��ʧȥ��Ӱ��\n",
			})
	);

	action = ({
			([      "action":
			"$nֻ������ǰһ������Ӱ�����䣬$N�Ѿ����ƻ���$n$l",
			        "parry":                80,
			        "damage":		230,
			        "dodge":		800,
			        "force":		200,
			        "damage_type":  "����"
			]),
			([      "action":
			"$n��Χ��Ȼ�������ݺ��磬$N�ƻ���ѩ������$n",
			        "parry":                400,
			        "force":		240,
			        "damage_type":  "����"
			]),
			([ 	"action":
			"$Nʹ������ؽ��������󱯸�����ɱʽ��һ��ƮȻ���䣬������$n��������·",
			        "parry":                700,
			        "dodge":		800,
			        "force":		360,
			        "damage":		460,
			        "damage_type":  "����"
			]),
	});
}

int valid_learn(object me) {
	if((int)me->query("max_force") < 600) {
		return notify_fail("�������������\n");
	}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	mixed foo;
	
	foo = ::hit_ob(me, victim, damage_bonus);
	if( intp(foo) ) {

		victim->receive_wound("kee", (damage_bonus + foo));
		return HIW"$N�������Ʒ�͸�Ƕ�����$nֻ��������������롣\n"NOR;

	}
	return foo;
}
 
