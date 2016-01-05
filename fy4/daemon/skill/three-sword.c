#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","���Ž���");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("skill_class","npc");
	set("difficulty",200);
	
	
	set("parry_msg", ({
	        "$nʹ�����졹�־����Թ�Ϊ�ء����潣������$N�ȵ��������ˡ�\n",
	        "$nʹ��һ�е��־��еġ��ض���ҡ�������е�$v������������$N��$w��\n",
	        "$n����$N��$w��һ�����־��еġ��˷��ˡ��ҷ��ҡ�����$N��ͷ�Ͽ�ȥ��\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n�����е�$v���������������ȵ�$N�������ˡ�\n",
	}) );
	
	action = ({
        ([      "action":               
"$Nʹ�����־��еġ����»�ת����$w�������֣���$n��$l����",
                "dodge":                120,
                "parry":                90,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ճ����־��������е�$wʹ��һ�С�����ͻ�𡹣�ն��$n��$l",
                "dodge":                120,
                "parry":                80,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�е��־��еġ�ɽˮ������������������ˮ������$w����̩ɽ��ն��$n��$l",
                "dodge":                140,
                "parry":                60,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһʽ���־��еġ�ˮ�����项��׼$n��$l�̳�һ��",
                "dodge":                140,
                "parry":                80,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�����־��еġ�����ƽ�ȡ�����������������$n�̳�",
                "dodge":                200,
                "parry":                60,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫���ս���һ�����־��еġ����ϲ���������$n��$l",
                "dodge":                420,
                "parry":                120,
                "damage":               160,
                "damage_type":  "����"
        ]),
	});
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
	    object ob;
	    if( random(damage_bonus) < 300 ) return 0;
	    if(ob=victim->query_temp("weapon"))
	    if(ob->query("skill_type") == "blade")
	    if(victim->query_skill_mapped("blade") == "qiusheng-blade" )
	    if(me->query_skill("sword") > victim->query_skill("blade")) {
	    switch(random(3)) {
	            case 0:
	                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
	                    break;
	            case 1:
	                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
	                    break;
	            case 2:
	                    message_vision(HIR "\n�򵶽���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
	                    break;
	                    }
	    return random(me->query_skill("sword")) * 4;
	    }
	    return 0;
}

