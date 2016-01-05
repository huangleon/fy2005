// fy-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","������ƽ�");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","tieflag");
	set("effective_level",210);
	set("difficulty",200);
	set("parry_msg", ({
	        "$n�Թ����أ�$vֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
	        "$nʹ��һ�С�ɽ�����ܡ�����ȫ�������$v�γɵĽ�Ļ�С�\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
	}) );	
	action = ({
        ([      "action":
"$Nʹ��һ�С��������ա������е�$w����һ��Բ������$n��$l����",
                "dodge":                30,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���������ĳ�һ�ƣ������е�$wʹ��һ�С��һ����ơ���ն��$n��$l",
                "dodge":                10,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�ˮ�����ɡ�������������ˮ������$w���������ն��$n��$l",
                "dodge":                50,
                "damage":               10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һʽ�ġ������ķ�����׼$n��$l�̳�һ��",
                "dodge":                20,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$w���μ������У�һ�С�����������$n��ȥ",
                "dodge":                60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N˫���ս���ʹ��һ�С���Ŀ�ѻԡ�����$n��$l",
                "dodge":                100,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���н�����һ�Σ�$w��Ϊһ����⣬ʹ����������ġ�����$n��$l",
                "dodge":                100,
                "damage":               100,
                "damage_type":  "����"
        ]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "softsword")
    if(me->query_skill("sword") > victim->query_skill("sword")) {
	    switch(random(3)) {
	        case 0:
	            message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
	            break;
			case 1:
	            message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
	            break;
	        case 2:
	            message_vision(HIR "\n�򽣷���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
	            break;
		}
    return random(me->query_skill("sword")) * 5;
    }
    return 0;
}

