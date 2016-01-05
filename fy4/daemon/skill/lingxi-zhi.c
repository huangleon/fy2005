inherit SKILL;

//original design by mimicat
#include <ansi.h>
int check_skill(object victim) ;
void setup() {
	set("name","��Ϭָ");
	set("type","unarmed");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","task");
	
	set("parry_msg",			({
        	"$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n",
		"$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n"
	})	);
	set("unarmed_parry_msg",		({
         	"$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n",
		"$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n"
	})	);
	action = ({
([      "action" : "$N��ָ�ӳ���һʽ����ҹ���硹������$n����Ե",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "��ҹ����",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������һָ��һʽ���������项��ָ��$n����ǰ",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ��������֡�����$n��$l����",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ���������ġ���˫ָ����$n�Ķ�����硢�ۡ��ء���",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������ˡ��������������⣬��ָ���Ƶ���$n��$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���������ʮָ�濪��һʽ�����߱��项��Сָ����$n��̫ԨѨ",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "���߱���",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֱų�������������һʽ���������ࡹ����$n��ȫ��",
        "force" : 400,
        "dodge" : 25,
        "damage": 120,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
});

}

int valid_learn(object me)
{	
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����Ϭָ��������֡�\n");
        return 1;
}



mixed parry_ob(object victim,object me)
{
	int myexp,hisexp,mylvl,extra, n;
	int alr_busy_time;
	object owner, weapon;
	string msg;
	
	if (victim->query("race")!="����") return 0;
	
	if (victim->is_busy()) return 0;
	
	if (!check_skill(victim)) return 0;

	myexp=me->query("combat_exp")/10000;
	hisexp=victim->query("combat_exp")/10000;
	
	mylvl=me->query_skill("lingxi-zhi",1);
	
	hisexp	*=180;
	myexp	*=mylvl;
	
	if (ANNIE_D->check_buff(me,"parry_busy")||!userp(me))
	{
		if (objectp(owner = me->query("owner")))
		if (userp(owner))	return 0;		// It's a copycat from Player
					
		if (victim->query_temp("weapon"))
			msg=HIY"$n"+HIY"��Ȼ���ʳ����ָ����$N"+HIY"�ı��м�ס����\n"NOR;
		else 
			msg=HIY"$n"+HIY"��Ȼ���ʳ����ָ����$N"+HIY"�ĳ��м�ס����\n"NOR;
		
		victim->force_busy(3);				
		return msg;
	}

	if (random(myexp+hisexp) > hisexp 
		&& me->query_skill("lingxi-zhi",1)>100 && userp(me))
	{
		if (!random(2)) {
			victim->force_busy(1);
			return HIW"���$N��$n�ķ������˸���æ���ҡ�\n"NOR;
		}
	}
	
	if (random(3*myexp+hisexp) > hisexp && !userp(me))
	{
		victim->force_busy(1);
		return HIW"���$N"HIW"��$n"HIW"�ķ�������һ����æ���ҡ�\n"NOR;
	}

}


int check_skill(object victim) {
	
	object weapon;
	
	if (weapon=victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
		&& victim->query_skill("shenji-blade",1)>100
		&& victim->query_skill_mapped("blade")=="shenji-blade")
		return 0;

	if (weapon=victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="sword" && victim->query_skill("sword",1)>100 
		&& victim->query_skill("daimonsword",1)>100
		&& victim->query_skill_mapped("sword")=="daimonsword")
		return 0;

	if (victim->query_temp("marks/no_parry_busy_pfm"))
		return 0;
		
	return 1;
}

		
int effective_level(object me)
{
	if(me) {
		if(me->query_skill("lingxi-zhi",1)<160)
			return 150;
		else return 200;
	}
	return 200;	
}


int help(object me)
{
	write(@HELP   
��Ϭָ�ɴ�½С�ﴦѧ��150�����书ϵ��Ϊ150��
����ϻ����������о���research��ʮ�����书ϵ������ߵ�200��
ͬʱ��ʹ���ؼ���������Ϭ��

100�����ϵ���Ϭָ�����мܳɹ�ʱ��һ�������жϵ��˵Ĺ���
�������æ��һ�֡�

��������Ϭ��
��Ҫ160����Ϭָ������ʱ��5�غϡ�
ʹ�ô��ؼ����мܳɹ���Ȼ��Է�æ��3�֡�
��ս����ʹ�ô��ؼ�����2������æ�ң�ս����ʹ��������æ�ҡ�

HELP
    );
    return 1;
}

