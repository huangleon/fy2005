inherit SKILL;

void setup() {
	set("name","���ƴ�");
	set("type","dagger");
	set("difficulty",200);
	set("usage/dagger",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","npc");
	set("unarmed_parry_msg",			({
		"$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����Ĺ�Ӱ������$n��ȫ��ӿȥ��\n",
		"$Nʹ��һ�С�����նȡ�����ۻ��գ�����������ֱ��$n��$l,�ܵ�$n�������ˡ�\n",		
			})
	);

	action = ({
		([	"action":	"$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
			"damage":		70,
			"dodge":		70,
			"damage_type":	"����"
		]),
		([	"action":	"$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
			"damage":		40,
			"damage_type":	"����"
		]),
		([	"action":	"$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
			"damage":		20,
			"damage_type":	"����"
		]),
		([	"action":	"$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
			"damage_type":	"����"
		]),
		([	"action":	"$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
			"damage":		70,
			"damage_type":	"����"
		]),
		([	"action":	 "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
			"damage":		30,
			"damage_type":	"����"
		]),
		([	"action":	"$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
			"damage":		50,
			"damage_type":	"����"
		]),
	});
}


