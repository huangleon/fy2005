// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","ˤ��");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("effective_level",180);
	set("skill_class","npc");
	set("parry_msg", ({
        	"$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
	}) );
	action = ({
        ([      "action":    "$N˫��ǰ�죬�ƺ�Ҫץס$n��$l",
                "dodge":                230,
                "parry":                110,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":    "$N˫�ִ���$n�����������б���ƺ�Ҫ��$nˤ��",
                "dodge":                120,
                "parry":                320,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":    "$N�䲻�������ţ���ͼ��$n���ڵ���",
                "dodge":                30,
                "parry":                210,
                "damage":                80,
                "damage_type":  "����"
        ]),
        ([      "action":     "$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "dodge":                10,
                "parry":                330,
                "damage":                70,
                "damage_type":  "����"
        ]),
        ([      "action":     "$N��ס$n��$l����$n�ٹ�ͷ���������ºݺ�һˤ",
                "dodge":                20,
                "parry":                230,
                "damage":                60,
                "damage_type":  "����"
        ]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,urexp;
        
        if (userp(me) && me->query_skill("shuaijiao",1)<150)	return;
        if (victim->is_busy() || victim->query_busy()> 2)	return;
        
        myexp=me->query("combat_exp");
	urexp=victim->query("combat_exp")*victim->query("agi")/40;
	
	if (random(myexp+urexp)>urexp)
	{
		victim->force_busy(2);
		return HIW "$n��$N��˫��������һʱ��������\n"NOR;
	}   
}

