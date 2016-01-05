// liuxing-hammer.c
inherit SKILL;
void setup()
{
	set("name","��ת���Ǵ���");
	set("skill_class","shaolin");
	set("type","hammer");
	set("effective_level",150);
	set("usage/hammer",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("difficulty",200);

	set("parry_msg", ({
			"$n����һ����һ�У۲�����������е�$v�͵�����$N��$w��\n",
			"$n����΢�٣����е�$vһ�У�ָ�������ݷ���$N�ıؾ�֮����\n",
			"$n���е�$v�������ϼ��ӣ�һ�У۷��鱾�ԣݿĿ���$N���е�$w\n",
	}) );

	set("unarmed_parry_msg", ({
			"$nһ�У�������ת�ݣ����е�$v��ƫ�����$N��̫����Ѩ��\n",
			"$n���е�$v�����ң�һ�У�������ƣݷ�ס��$N�Ĺ��ơ�\n",
			"$n�����������һ�У۽������֣����е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
	}) );	
	action = ({
		([      "action":               
				"$N����$w�ն���ɣ��������಻�ϣ�һ�У�������Ϣ�ݣ��������$n��к��ȥ",
				"force":                70,
				"dodge":                100,
				"parry":                100,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":               
				"$N������ɣ���Ӱ�������֣�һ�У��������֣ݣ����е�$wȴ�絽$n����ǰ",
				"damage":               70,
				"dodge":                20,
				"parry":                60,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":               
				"$N����$w�趯��һ�У��׶������Ю�������ײ��֮��������$n��$l",
				"damage":               70,
				"force" :	            200,
				"dodge":                100,
				"parry":                200,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":               
				"$N���е�$wһת��һ�У��������Уݴ�����˷�����$n��$l",
				"damage":               40,
				"force" :	            200,
				"dodge":                10,
				"parry":                40,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":
				"$Nһ�����е�$w��һ�У��ҷ���գݴ�Ӱ������裬����ʵʵ�Ļ���$n��$l",
				"force":                100,
				"damage" :              50,
				"dodge":                100,
				"parry":                400,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
	});
}

int effective_level(object me)
{
	int skill, n;
	if( me ) {
		skill = me->query_skill("liuxing-hammer",1);
		if( skill <= 150 || (me->query("class") != "shaolin" && userp(me)) ) {
			return 150;
		}
		if( skill >= 170 ) {
			return 200;
		}
		n = (skill-150)/4*10+150;
		return n;
	}
	return 200;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	if( ob=victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "sword" || ob->query("skill_type")=="spear" ) {
			return damage_bonus*15/100;
		}
	}
	return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill, n;
	if( me && userp(me) ) {
		skill = me ->query_skill("liuxing-hammer",1);
		if( skill < 150 ) {
			return 200;
		} else {
			return 400;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP   
���Ǵ��������н�����ǹ���ж��⣱�������˺�����	
���Ǵ�����ϵ����150����ʼ�𲽴�150��ߵ�200��L170��
��ѧϰϵ�����ӵ�400

����������fanbei��
L50������������æ�ң���
L80��������������æ�ң���
L110��������������æ�ң���
���⹥����=���Ǵ��ȼ�*3/2

����������xuanji��
��Ҫ170�����Ǵ�����170������������
60�����Զ���������������ʽ��ÿʮ����ʹ��һ�Ρ�
ע��ʹ�ø��ؼ���ת���������ܲ������ơ�

HELP
    );
    return 1;
}
