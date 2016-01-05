// dugu-jiujian.c ���¾Ž�

inherit SKILL;
void setup() {
	set("name","���¾Ž�");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",130);
	set("difficulty",200);
	set("skill_class","npc");
	set("unarmed_parry_msg", ({
	        "ȴ��$n̤ǰһ������ʽбָ$N���ұۣ���Ҫʹ$N������ˡ�\n",
	        "$n����ͻ��Ц�ݣ��ƺ��ѿ���$N���书��ʽ�����г����һ������$N��\n",
	        "$n����һ��ָ��$N���������$N���������ڣ��˵����������ף�����˼�飡\n",
	}) );

	action = ({
		([	"action" : "$NĿ�����ǣ��������£�$wбб����$n��$l",
			"force" : 100,
			"dodge" : 5,
			"damage": 50,
			"damage_type" : "����"
		]),
		([	"action" : "$N����Ʈ�����������ƣ�����$w������Ϣ��Ȼ����$n��$l",
			"force" : 80,
			"dodge" : 0,
			"damage": 30,
			"damage_type" : "����"
		]),
		([	"action" : "$N����ͻת���ͣ�����$w����ǧ����$n������ȥ�����ؽ��޷桢���ɲ���֮�⾡������",
			"force" : 200,
			"dodge" : 15,
			"damage": 100,
			"damage_type" : "����"
		]),
		([	"action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ����ƻ���$n��$l",
			"force" : 110,
			"dodge" : 10,
			"damage": 60,
			"damage_type" : "����"
		]),
		([	"action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô����",
			"force" : 180,
			"dodge" : 5,
			"damage": 80,
			"damage_type" : "����"
		]),
		([	"action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò���",
			"force" : 220,
			"dodge" : -10,
			"damage": 100,
			"damage_type" : "����"
		]),
		([	"action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ���\n��������",
			"force" : 240,
			"dodge" : -15,
			"damage": 120,
			"damage_type" : "����"
		]),
		([	"action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ",
			"force" : 260,
			"dodge" : 0,
			"damage": 100,
			"damage_type" : "����"
		]),
	});

}

int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if ((string)me->query("class") != "npc") {
		return notify_fail("�����¾Ž�����ֻ�ܴ�����ɽ�ɵ��ӵġ�\n");
	}
	if ((int)me->query("max_force") < 1000) {
		return notify_fail("�������������\n");
	}
	if ((int)me->query_skill("dugu-sword",1) > 90) {
		return notify_fail("���׽�����������Ҫ���Լ����ˡ�\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("���¾Ž�ֻ��ͨ�����ܾ�ʽ����������\n");
}

