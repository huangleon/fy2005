//TIE@FY3
inherit SKILL;
void setup()
{
	set("name","�ϻ�ǹ");
	set("skill_class","shaolin");
	set("type","spear");
	set("effective_level",150);
	set("usage/spear",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("difficulty",200);

	set("parry_msg", ({
			"$nʹ��һ�С��������ơ������е�$v������$N��$w��\n",
			"$nʹ��������˵�Ρ�����$N��$w�������⡣\n",
			"$nʹ��һ�С�̤�����ġ������е�$v����������գ�������$N��$w��\n",
			"$n���е�$vһ����һ�С�������;������$N��$w�������ȥ��\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n�����е�$v����ܲ�͸�磬һ�С���黴��С���ס��$N�Ĺ��ơ�\n",
			"$n����һ�С��Ƹ����ࡹ����������ʧ��һ�Ž���֮�С�\n",
			"$nʹ��һ�С������С���$vֱ��$N��˫�֡�\n",
			"$n�����е�$vһ����һ�С����Ŀճۡ����ȵ�$N�������ˡ�\n",
	}) );
	action = ({
		([      "action":               
			"$Nʹһ�С�������Ρ�������$wһ������������ǹͷ��ֱ��$n��$l",
			"dodge":                520,
			"parry":		300,
			"force" :		100,
			"damage_type":  "����"
		]),
		([      "action":               
			"$Nʹ���ϻ�ǹ�еġ�ִ��Ϊ�桹������$w�ζ��������ǹ��ͻȻ��Ӱ�з���һǹ������$n��$l",
			"dodge":                520,
			"parry":		300,
			"force":               200,
			"damage_type":  "����"
		]),
		([      "action":               
			"$Nһ�С���Գ��Ρ�����ǰ�ʹܣ�����$w����һǹ��ֱ��$n��$l",
			"dodge":                530,
			"parry":		200,
			"force":               50,
			"damage_type":  "����"
		]),
		([      "action":               
			"$N����$wһʽ������֪�Ρ�������$wǹͷ�Ҷ�������ǵ�ɱ����ǹǹ����$n��$l",
			"force":                90,
			"dodge":                230,
			"parry":                400,
			"damage_type":  "����"
		]),
		([      "action":               
			"$N��$w��㣬��ؽ�������һ�С������ۡ�����$n��$l",
			"dodge":                200,
			"parry":		300,
			"force":               300,
			"damage_type":  "����"
		]),
		([      "action":               
			"$N����$wһ�ݣ�ǹ������°���ת����һ�С�һ��ع⡹���ֶ�׼$n$lһǹ��ȥ",
			"dodge":                260,
			"parry":		330,
			"force":               100,
			"damage_type":  "����"
		]),
	});
}


int effective_level(object me)
{
	int skill, n;
	if( me ) {
		skill = me->query_skill("duanhun-spear", 1);
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
	int ratio;
	ratio = F_ABILITY->check_ability(me, "3_weapon_add", 3) * 2;
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "whip" || ob->query("skill_type") == "axe" ) {
			ratio += 15;
		}
	}
	return damage_bonus*ratio/100;
}

int skill_difficulty()
{
	object me = this_player();
	int skill, n;
	if( me && userp(me) ) {
		skill = me ->query_skill("duanhun-spear",1);
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
�ϻ�ǹ�����б޷��������ж��⣱�������˺�����
�ϻ�ǹ����ϵ����150����ʼ�𲽴�150��ߵ�200��L170��
��ѧϰϵ�����ӵ�400

��1�������β��꡻��suomengchanhun��
��Ҫ150���Ķϻ�ǹ��150���Ļ���ǹ������һ�����ʻ������������
���ʧ���򹥻�����һ�С����۳ɹ���������������60���ڵ�
�ٴι���ͬһ���ֲ����ٻ����������������æ��2�غϡ�
���⹥����=�ϻ�ǹ���ȼ�
����ɱ����=�ϻ�ǹ���ȼ�*2

��2�������Ƕ��ǡ���qixingduopo��
��Ҫ170���Ķϻ�ǹ����170���Ļ���ǹ��
��������ͻ�����֣�������ɱ�����ϴ�60��ʹ��һ�Σ�
����æ��1�غϣ���ɶ����ޡ�
���⹥����=�ϻ�ǹ���ȼ�*3
����ɱ����=�ϻ�ǹ���ȼ�*6

HELP
    );
    return 1;
}
