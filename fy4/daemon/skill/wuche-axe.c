// TIE@FY3
inherit SKILL;
void setup()
{
	set("name","�򳹲��縫��");
	set("skill_class","shaolin");
	set("type","axe");
	set("effective_level",200);
	set("usage/axe",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("difficulty",200);
		
	set("parry_msg", ({
			"���$nһ�С�������į�����Ӷ�����$v����$N��$w��\n",
			"���$n����$vһ�֣�һ�С���ħ��𡹣�б��$N��$w��\n",
			"���$n����$v�ն���ɣ�һ�С��鲨���������$N��$w��\n",
			"���$n����$v������ת��һ�С�������ۡ�����ɨ$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n���е�$v�趯��ɣ�һ�С�������ҡ������ס��$N�Ĺ��ơ�\n",
			"$n��Ӱ�ζ���һ�С�ǧ̶���ʡ�������$N�����̡�\n",
			"$n����һ����һ�С�������������$N�Ĺ��ơ�\n",
			"$n���е�$v���϶��£�һ�С�ʼ�����ء�������$N��Ҫ����\n",
	}) );	
	action = ({
		([      "action":               
				"$N����$w�տ���Ю�ź���������һ�С�����ÿÿ����ֱȡ$n�ĸ���Ҫ����",
				"dodge":                -150,
				"parry":                -200,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":               
				"$N����һԾ������$w�����Х��һ�С����ֳ��ա��������$n$l��ȥ��",
				"dodge":                -160,
				"parry":                -210,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":               
				"$N����$w������������һ�С�ԨԴ������������㿳��$n$l��",
				"dodge":                -150,
				"parry":                -150,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
		([      "action":               
				"$Nʹ��һ�С����ɳ��ڡ�������$w�趯�����渫�ƣ�����һ���̳�����������$n��$l��",
				"dodge":                -140,
				"parry":                -240,
				"post_action":  "bash_weapon",
				"damage_type":  "����"
		]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	int ratio;
	ratio = F_ABILITY->check_ability(me, "3_weapon_add", 3) * 2;
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "blade" || ob->query("skill_type") == "staff" ) {
			ratio += 15;
		}
	}
	return damage_bonus*ratio/100;

}

int effective_level(object me)
{
	int skill,n;
	if( me ) {
		skill = me->query_skill("wuche-axe",1);
		if( skill <= 150 || (me->query("class") != "shaolin" && userp(me)) ) {
			return 150;
		}
		if( skill >= 170 ) {
			return 200;
		}
		n=(skill-150)/4*10+150;
		return n;
	}
	return 200;
}

int skill_difficulty()
{
	object me = this_player();
	int skill, n;
	if( me && userp(me) ) {
		skill = me ->query_skill("wuche-axe",1);
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
���÷縫�������е������ȷ��ж��⣱�������˺�����
���÷縫����ϵ����150����ʼ�𲽴�150��ߵ�200��L170��
��ѧϰϵ�����ӵ�400

L150�����師����sanbanfu��
��������ĳһ���֣�����æ��3�غ�
���⹥����=�򳹸��ȼ�/2
�����˺���=�򳹸��ȼ�
�����������˺����ӱ�

L170������ն����xuanfengzhan��
��170�����÷縫����170������������
�����������ж��֣�60��ʹ��һ�Σ���ɶ����ޡ�
����æ��1�غϡ�
���⹥����=�򳹸��ȼ�
�����˺���=�򳹸��ȼ�*3

HELP
    );
    return 1;
}