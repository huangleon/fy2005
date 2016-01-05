#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","̫������");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("skill_class","wudang");
	set("difficulty",200);
	set("unarmed_parry_msg",({
   	        "$nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$N��$l\n",
        	"$nһ�С�ȴ���齣�������Ծ����أ�$v�س飬���ֹ���$N��$l\n",
		"$nʹ����ʨ��ҡͷ����$v�������󻮳�һ�����֣���$NȦ������\n",
		"$nһ�С�ӭ�絧������$v���������һ�ӣ�$Nȴ����һ�ɾ���ӭ��Ϯ����\n",
		"$n���Ȱ�����ף�һ�С�����Ʊա����㽫$N�Ĺ��ƻ�����\n",        
	}) );		
	set("parry_msg",	({
		"$nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$N��$w\n",
        	"$nһ�С�ȴ���齣�������Ծ����أ�$v�س飬���ֹ���$N��$w\n",
		"$nʹ����ʨ��ҡͷ����$v�������󻮳�һ�����֣���$N��$wȦ������\n",
		"$nһ�С�ӭ�絧������$v���������һ�ӣ�$Nȴ����һ�ɾ���ӭ��Ϯ����\n",
		"$n���Ȱ�����ף�һ�С�����Ʊա����㽫$N�Ĺ��ƻ�����\n",			
	}) );
	
	
	
action = ({
([      "action" : "$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��$l",
        "dodge" : 20,
        "parry" : 10,
        "damage" : 105,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹ֱ��$n��$l",
        "dodge" : 15,
        "parry" : 10,
        "damage" : 120,
        "lvl" : 4,
        "damage_type" : "����"
]),
([      "action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ������ǡ�����$n��$l",
        "dodge" : 15,
        "parry" : 10,
        "damage" : 130,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$N˫ϥ�³�������$wʹ��һʽ��̽��ʽ�������¶��ϼ���$n��$l",
        "dodge" : 15,
        "parry" : 10,
        "damage" : 140,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������Ӳ�����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 160,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$N���������һš��һ�С�������β��������$w������$n��$l��ȥ",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 170,
        "lvl" : 24,
        "damage_type" : "����"
]),
([      "action" : "$N������ϥ������$wбָ��һ�С�����Ͷ�֡�����$n��$l",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 200,
        "lvl" : 34,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������ˮ����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 200,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����������¡���$w��������ԲȦ������ֱ�������಻�ϻ���$n
��$l",
        "dodge" : 10,
        "parry" : 20,
        "damage" : 220,
        "lvl" : 44,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����Ҷ����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 205,
        "lvl" : 49,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ͷ����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 240,
        "lvl" : 54,
        "damage_type" : "����"
]),

([      "action" : "$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž���������$n��$l",
        "dodge" : 5,
        "parry" : 20,
        "damage" : 270,
        "lvl" : 64,
        "damage_type" : "����"
]),
([      "action" : "$N����Ծ��һ�С�Ұ����������$w�ڰ���л�ΪһȦ��â������$n��$l",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 283,
        "lvl" : 69,
        "damage_type" : "����"
]),
([      "action" : "$N����ǰ���󹭣�һ�С�����ʽ��������$wֱ��$n��$l",
        "dodge" : 20,
        "parry" : 20,
        "damage" : 285,
        "lvl" : 74,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�С���ǡ�����������һ�죬���ֽ���������$wƽƽ����$n��$l��ȥ",
        "dodge" : 40,
        "parry" : 20,
        "damage" : 300,
        "lvl" : 79,
        "damage_type" : "����"
]),
([      "action" : "$N������ϣ�һ�С���Գ�׹���������$wбб����$n��$l��ȥ",
        "dodge" : 30,
        "parry" : 20,
        "damage" : 310,
        "lvl" : 84,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�˳ˮ���ۡ���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ��",
        "dodge" : 45,
        "parry" : 25,
        "damage" : 320,
        "lvl" : 94,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����Ǹ��¡���$w����$n��$l",
        "dodge" : 35,
        "parry" : 25,
        "damage" : 370,
        "lvl" : 99,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�̶���������һ�С��������¡���$w���¶��ϵ���$n��$l��ȥ",
        "dodge" : 25,
        "parry" : 25,
        "damage" : 350,
        "lvl" : 104,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ʽ����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l��ȥ",
        "dodge" : 35,
        "parry" : 25,
        "damage" : 190,
        "lvl" : 109,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��Ʒ��붴����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
        "dodge" : 40,
        "parry" : 25,
        "damage" : 202,
        "lvl" : 114,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����չ�᡹������Ծ������$w����$n��$l",
        "dodge" : 45,
        "parry" : 25,
        "damage" : 106,
        "lvl" : 119,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ֽ�����$w����һƬ���̣�ƽƽ����$n��$l��ȥ",
        "dodge" : 45,
        "parry" : 25,
        "damage" : 120,
        "lvl" : 124,
        "damage_type" : "����"
]),
([      "action" : "$N��������棬������ǰһ�ˣ�һ�С������пա���$w��$n��$l��ȥ",
        "dodge" : 45,
        "parry" : 30,
        "damage" : 125,
        "lvl" : 129,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ɨ÷����������Ծ�ڰ�գ�����$wɨ��$n��$l",
        "dodge" : 45,
        "parry" : 30,
        "damage" : 130,
        "lvl" : 90,
        "damage_type" : "����"
]),

([  "action" : "$N����š���������鱧��һ�С�����հ�ա���$w�й�ֱ��������$n��$l",
        "dodge" : 35,
        "parry" : 30,
        "damage" : 160,
        "lvl" : 149,
        "damage_type" : "����"
]),
});

}
int valid_learn(object me)
{
        object ob;

        if( (string)me->query_skill_mapped("force")!= "taijiforce")
                return notify_fail("̫�������������̫���ڹ��ķ���������\n");

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,urexp;
	myexp=me->query("combat_exp");
	urexp=victim->query("combat_exp")*victim->query("cps")/20;
	if (!victim->is_busy())
		if (random(myexp+urexp)>urexp && me->query_skill("taiji-sword",1)>100)
		{
			victim->force_busy(2);
			return HIW "$n��$N�Ľ����������ٶȲ��ɵ÷���������\n"NOR;
		}   
}

int eff_parry_level(object me) {
	if (me)
	if (me->query_temp("perform/taiji_shou"))
	{
		return 250;
	}
	return 170;
}