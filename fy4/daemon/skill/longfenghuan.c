// longfenghuan.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","����˫��");
	set("type","hammer");
	set("difficulty",200);
	set("usage/hammer",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("damage_level",200);
	set("skill_class","assassin");
	
	set("unarmed_parry_msg", ({
        	"$n�ζ�$v�����д�����������$Nӭͷ���£�$N���ò����ع��ơ�\n",
        	"$n���΢ƫ��һ�� ����Ǳ��Ұ�����������ڵ÷��겻͸��\n",
        	"$nһ�С�Ⱥ�����ס���$v����ǰ�����㻭�˸�Բ����������и�ɻ���\n",	
	}) );
	
	action = ({
        ([      "action":               
"$N���Ž𼦶���������ʩչ������˫��������ʽ���������硹",
                "force":                500,
                "dodge":                500,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������¡¡������һ�С��������ˡ�����$n$l",
                "force":                600,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���һ�ӣ�ʹ������˫���еġ����ɷ��衹����$n$l",
                "force":                500,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������졹��$w�����ŷ���ײ��$n$l",
                "force":                800,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
	});
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	string type;
    	
    	if( random(damage_bonus) < 300 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	{
    		type = ob->query("skill_type");
    		if (type != "blade" && type != "dagger" && type!="sword")	return 0;
    		if (me->query_skill("hammer") >= victim->query_skill(type))
    		{
	    		switch(random(3)) {
		        	case 0:
		                	message_vision(HIR "\n$N�����г���ռ�����Ϸ磡" NOR,me,victim);
		                	break;
		        	case 1:
		                	message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
		                	break;
		        	case 2:
		                	message_vision(HIR "\n����б��ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
		                	break;
	                }
    			return (damage_bonus/2 + random(damage_bonus)/2);
    		}
    	}
    	return 0;

}

