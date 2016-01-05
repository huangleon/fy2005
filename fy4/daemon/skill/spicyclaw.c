inherit SKILL;

#include <ansi.h>

void setup() {
	set("name","��¥����������ʽ");
	set("type","unarmed");
	set("effective_level",200);
	set("difficulty",300);
	set("skill_class","demon");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("parry_msg",			({
		"$n����$N�����ţ��Ƶ�$N��;�������е�$w��\n",
	})	);
	set("unarmed_parry_msg",		({
        "$n����$N�����ţ��Ƶ�$N��;���С�\n",
	})	);
	action = ({
	([	"action":		"$N����΢�֣�����һ��ʹ��һ�С������嵰������$n��$l",
		"dodge":		30,
		"parry":		70,
		"damage":		160,
		"force":		160,
		"damage_type":	"����"
	]),
	([	"action":		"$Nٿ��һ��ת��˫��һ����ߥ�ȹ���ֱ��$n$l",
		"dodge":		10,
		"parry":		60,
		"force":		140,
		"damage":		140,
		"damage_type":	"����"
	]),
	([	"action":		"$N����΢б���漴���һ�������ֺ��ƺ�צʹ������¯�ҡ�������$n��$l",
		"dodge":		30,
		"parry":		40,
		"force":		120,
		"damage":		120,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��������ʮ�ν�����˫�ֻ����쳣��׼$n��$lץȥ",
		"dodge":		10,
		"parry":		60,
		"force":		140,
		"damage":		140,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ�����ƮƮ��һ�С����Ͼ�������ƿ������$n$l",
		"dodge":		20,
		"parry":		50,
		"force":		150,
		"damage":		150,
		"damage_type":	"����"
	]),
	([	"action":		"$N������$n$l����������һ�С�����ʢ������צ����ͬһ��λץ��",
		"dodge":		90,
		"parry":		90,
		"force":		100,
		"damage":		100,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ�����������㡹�����Ծ���䲻�������ǰ��׼$n$l�ɳ�һ��",
		"dodge":		500,
		"parry":		500,
		"force":		400,
		"damage":		400,
		"damage_type":	"����"
	]),
});

}

int valid_learn(object me)
{	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
			return notify_fail("����¥����������ʽ������֡�\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��¥����������ʽֻ��ѧ�ġ�\n");
}

mixed parry_ob(object victim,object me)
{
	object ob;
	if (!victim->query_temp("weapon"))
		return 0;
	ob=victim->query_temp("weapon");
	if (ob->query("skill_type") == "throwing" || ob->query("skill_type") == "unarmed" )
		return 0;
	
	ob->add("weapon_prop/damage",-1);
	if(ob->query("weapon_prop/damage") < 1 ) 
		ob->set("weapon_prop/damage",1);
	else
		victim->add_temp("apply/damage",-1);
	ob->set("item_damaged", 1);
	ob->save();
	return RED"$n"RED"��Ե������٣�"+ob->name()+RED"������Щ�ۻ�������\n"NOR;;
}

mapping query_action(object me, object weapon) {
	mapping act=([]);
	int skill,i;
	string *color= ({
		HIM,HIW,HIB,HIY,HIC,
	});
	if(sizeof(action) > 0)
	{
		if (me->query_temp("annie/spicyclaw_perform"))
		{
			i=random(sizeof(action));
			act["action"] = color[me->query_temp("annie/spicyclaw_perform")-1] + action[i]["action"] + NOR;
			act["dodge"] = action[i]["dodge"];
			act["force"] = action[i]["force"];
			act["parry"] = action[i]["parry"];
			act["damage"] = action[i]["damage"];
			act["damage_type"] = "����";
			return act;
		}
		return action[random(sizeof(action))];
	}
}

int help(object me)
{
	write(@HELP   
�ü������мܳɹ�ʱ����Է��������˺�������1
	
����������ʽ��
��extrahit1����extrahit2����extrahit3����extrahit4����extrahit5��
������ͨ������û���˺��������ȼӳɣ��й̶�ɫ��
ÿ������ͬextrahit������1������
��ͬextrahit������15����

HELP
    );
    return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
