// silencer@fy4

#include <ansi.h>
inherit SKILL;

string* xuedao = ({
        "�İ�Ѩ",
        "�ز�Ѩ",
        "��ӭѨ",
        "Ͽ��Ѩ",
        "ͷάѨ",
        "�¹�Ѩ",
        "����Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "�ػ�Ѩ",
	"�ٳ�Ѩ",
        "�ٺ�Ѩ",
        "ͨ��Ѩ",
        "����Ѩ",
        "ӡ��Ѩ",
        "����Ѩ",
        "��ҺѨ",
        "����Ѩ",
        "����Ѩ",
        "�ٻ�Ѩ",
        "��̨Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "����Ѩ"
});

void setup(){
	set("name","÷���ڷ�");
	set("type","throwing");
	set("usage/throwing",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",150);
	set("difficulty",200);
	set("damage_level",200);
	set("parry_msg", ({
	        "$n����ָ������$v������Ϣ�ط���$N����Ѩ��$N��æ�������С�\n",
		"$n�����ᵯ��$v����·ֱȡ$N˫Ŀ��$N�Ͻ����и����\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n����ָ������$v������Ϣ�ط���$N����Ѩ��$N��æ�������С�\n",
		"$n�����ᵯ��$v����·ֱȡ$N˫Ŀ��$N�Ͻ����и����\n",
	}) );	
		
	action = ({
        ([      "action":               
"$N˫��һ�֣���ö$w�����ҷɳ�����;һת����ֱ��$n" + xuedao[random(sizeof(xuedao))]+ "��",
                "dodge":                120,
                "parry":		300,
                "damage":               30,
		"damage_type":  "����"
        ]),
        ([      "action":               
"$NٿȻ���֣�������ָһ�������ĵġ�������$wֱ����$n"+xuedao[random(sizeof(xuedao))],
                "dodge":                140,
                "parry":		320,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫������һ��䣬һ����ɫ�Ĺ�â����$n"+xuedao[random(sizeof(xuedao))]+"���˹���",
                "dodge":                140,
                "parry":		200,
                 "damage_type":  "����"
        ]),
	([      "action":               
"$N����������΢΢һ����е�$w����һ����������$n��"+xuedao[random(sizeof(xuedao))],
                "dodge":                120,
                "parry":		300,
                "damage":               40,
                "damage_type":  "����"
        ]),
       	([      "action":               
"$N˫�����ӣ���ö$w���ź�Х���������ɶ�������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
                "dodge":                120,
                "parry":		100,
                "damage":               70,
                "damage_type":  "����"
        ]),
       	([      "action":               
"$N����Ծ�𣬾Ӹ�������$n������ö$w��ֱȡ$n��˫Ŀ��"+xuedao[random(sizeof(xuedao))],
                "dodge":                50,
                "parry":		210,
                "damage":               240,
                "damage_type":  "����"
        ]),
       	([      "action":               
"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
                "dodge":                120,
                "parry":		40,
                "damage":               140,
                "damage_type":  "����"
        ]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 150 ) return 0;
    if( victim->query_temp("weapon")==0) {
    	if(victim->query_skill_mapped("unarmed") == "dragonstrike" 
    		&& me->query_skill("tanzhi-shentong",1)+50 > victim->query_skill("dragonstrike",1)) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N�������ָ����$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    	return random(me->query_skill("throwing")) * 2;
    	}
    }
    return 0;
}
