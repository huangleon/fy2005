// low damage
// hard to dodge / parry
// annie. 07.02.2003

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void setup(){
	seteuid(getuid());
	set("name","������������Ӱ��");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("effective_level",120);
	set("skill_class","demon");
	set("parry_msg", ({
        "$nһʽ������ǳ����һ����ָ�⵭��������$Nֻ������һ�飬��Ȼ����ȫʧ�� \n",
        "$nʹһ�С�С¥һҹ�����꡹��ָ��������ϸ��һ������$N�� \n",
	}) );

	set("unarmed_parry_msg", ({
        "$nһʽ������ǳ����һ����ָ�⵭��������$Nֻ������һ�飬��Ȼ����ȫʧ�� \n",
        "$nʹһ�С�С¥һҹ�����꡹��ָ��������ϸ��һ������$N�� \n",
	}) );	
	action = ({
        ([      "action":               
"$N��Ŀע��$n��������������Ӱ���еġ���ˮ���ϱ��꡹�ż����ȵ�ʹ�� ",
                "dodge":                500,
                "parry":                500,
                "damage":               -100,
                "damage_type":  "ץ��",
        ]),
        ([      "action":               
"$Nįį������$n���⣬һʽ���������̼�����������Ļ�������",
                "dodge":                600,
                "parry":                600,
                "damage":               -200,
                "damage_type":  "ץ��",
        ]),
        ([      "action":               
"$Nʩ����������������֮����һ˫���迴������𴦣�ȴ����$n��ߡ� ",
                "dodge":                700,
                "parry":                700,
                "damage":               -300,
                "damage_type":  "ץ��",
        ]),
        ([      "action":               
"$N��̾һ����ָ�����ȵ�$n��ߣ���������Ӱ��һ�����ǡ�����һ�ʻ����ѡ�",
                "dodge":                800,
                "parry":                800,
                "damage":               -400,
                "damage_type":  "ץ��",
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
	if (me->query("gender") != "Ů��")
		return notify_fail("һ�������ˣ�Ҳ����˼ѧ��ŤŤ������ַ���\n");
	if( me->query_agi()  * 5 < me->query_skill("daimonstrike",1) )
		return notify_fail("����ٶ�̫�ͣ����ʺ���ϰ������������Ӱ�֡�\n");

    	return 1;
}

mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action)-1);
		return action[act];
}

mixed hit_ob(object me, object victim){	
	object wep;
	int i=0,t;
	wep = me->query_temp("right_hand");
	if (!wep)
		return -800;
	if (wep != me->query_temp("left_hand"))
		return -800;
	if (wep->query("annie/for_daimonstrike"))
	{
		t = random(me->query_skill("daimonstrike",1));
		i = t / 100;
		if (i && !me->query_temp("extra_action"))
		{
			me->set_temp("extra_action_msg",CYN"\n$N��Ӱ��磬գ��֮������һ�У�\n"NOR);
			me->set_temp("extra_action",i);
		}
		return wep->query("weapon_prop/damage") * 20;	// 0 ~ 30 : 0 ~ 600 extra damage,�����ǲ���Ϊһ�ֺõĿ�������
	}
	return -800;
}

