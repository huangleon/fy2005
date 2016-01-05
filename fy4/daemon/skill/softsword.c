// softword.c

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","���ϸ�����ὣ");
	set("practice_limit",100);
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","swordsman");
	set("parry_msg", ({
        "$n���ƹ��У��ҽ�����һ�С��麣���ġ������е�$v����Ŀ���$N��$w��\n",
		"$n������������ס$N��$w��һ�С�����ĺĺ����ʹ$N���԰ѳ����е�$w��\n",
	}) );

	set("unarmed_parry_msg", ({
        "$nʹ��һ�С������¶���������๥����ʹ$N��֪�ǹ����ء�\n",
		"$nһ�����е�$v��ʹ��һ�С��������á������е�$v������ƣ���ȫ��������ס��\n",
	}) );
	
	action = ({
		([	"name":			"����է��",
			"action":		
			"$Nʹһ�С�����է�𡹣�����$w����㴺������$n��$l��û����֪�������������Ҳ���޷��ֵ�",
			"dodge":		200,
			"parry" :		200,
			"damage":		70,
			"force" : 		200,
			"damage_type":	"����"
		]),
		([	"name":			"ϸ������",
			"action":		
			"$N���е�$wһ�С�ϸ�����ࡹ������ϸ�꣬�޿ײ���Ĵ���$n��$l",
	                "dodge":                200,
	                "parry" :               200,
	                "damage":               50,
	                "force" :               100,
			"damage_type":	"����"
		]),
		([	"name":			"���Ǵ���",
			"action":		
			"$N�趯$w��һ�С����Ǵ��ޡ�����������������磬�˽���һ������$n��$l",
	                "dodge":                200,
	                "parry" :               300,
	                "damage":               150,
	                "force" :               250,
			"damage_type":	"����"
		]),
		([	"name":			"������ˮ",
			"action":		
			"$Nһ������$w��ʹ����������ˮ�������ɵð������ˣ�����Ԧ������$n��$l�̳�һ��",
	                "dodge":                100,
	                "parry" :               100,
	                "damage":               50,
	                "force" :               150,
			"damage_type":	"����"
		]),
		([	"name":			"֯��Ū��",
			"action":		
			"$N����$w������ɢ��һ�С�֯��Ū�ɡ����������ƣ�������$n��$l�����˲�֪�����Ժη�",
	                "dodge":                250,
	                "parry" :               250,
	                "damage":               90,
	                "force" :               220,
			"damage_type":	"����"
		]),
		([	"name":			"��������",
			"action":		
			"$N�����������������������������$wֱָ$n$l��һ�С��������Ρ����̳��˾��춯�ص�һ��",
			"dodge":		200,
			"damage":		150,
			"damage_type":	"����"
		]),
	});
}


int practice_skill(object me)
{
	return notify_fail("���ϸ�����ὣ��ֻ��ѧ�ġ�\n");
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    
    if(me->query_temp("cut_mana"))
    {
    	victim->set("mana",0);
    	victim->set("force",0);
    	return HIB"�ȵ�������ʧʱ��$n�����������ƺ���ʧȥ���ģ��ݷ����Ƽ������� \n"NOR;
    }

    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "doomsword")
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
    return random(me->query_skill("sword")) * 2;
    }
    return 0;
}

