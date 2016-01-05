#include <ansi.h>
#include <weapon.h>

inherit SKILL;
void setup(){
	set("name","����ն");
	set("type","unarmed");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
        "$n�����ƣ������з磬�Ƶ�$N����һ�ԡ�\n",
	}) );
	set("unarmed_parry_msg", ({
        "$n�����ƣ������з磬�Ƶ�$N����һ�ԡ�\n",
	}) );	
	action = ({
		([	"action":		"$N�������ģ�����˫�ۣ�һʽ����ɽ���꡹������Ϯ��$n",
			"damage":		100,
	        "force":        100,
			"dodge":		-30,
			"parry":		-120,
			"damage_type":	"����"
		]),
		([	"action":		"$N˫�ֽ���$w��һ���Ϻ�������$n�������������������죬��һ�С��˼�ĩ·��",
			"damage":		50,
	        "force":        35,
			"dodge":		25,
			"parry":		70,
			"damage_type":	"����"
		]),
		([	"action":		"$N��������������ʹһ�С�׳��������ն$n����",
			"damage":		220,
	        "force":        190,
			"dodge":		-175,
			"parry":		30,
			"damage_type":	"����"
		]),
		([	"action":		"$N˫�����֣����ȵ��𴦷���$n�����С��������Ρ���Ȼ�Ѿ���ȫ��",
			"damage":		450,
	        "force":        330,
			"dodge":		-130,
			"parry":		-255,
			"damage_type":	"����"
		]),
	});
}


int valid_learn(object me)
{
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object wep;
	int i=0,t;
	wep = me->query_temp("weapon");
	if (!(wep->query("flag")&TWO_HANDED))
		return -damage_bonus;
	// ֻ��˫�ֳ������ܷ��ӳ�������
	return wep->query_weight()/400;
	// 40000 / 400 = 100.
}

int help(object me)
{
	write(@HELP   
����ն�������ؼ��кܴ������ԡ�
	
L150������ն����fentianzhan��
����������æ��2��
���⹥����=random(random(����ն�ȼ�*6))+1
�����˺���=random(random(random(����ն�ȼ�*12)))+1

L200����׷��١���fenqin��
����������æ��2��
���⹥����=random(random(random(random(����ն�ȼ�*40))))+1
�����˺���=random(random(random(random(random(����ն�ȼ�*80)))))+1
HELP
    );
    return 1;
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
