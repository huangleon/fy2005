// lefthand-sword.c

#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","���ֽ�");
	set("damage_level",100);
	set("practice_limit",100);
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",120);
	set("skill_class","assassin");
	set("unarmed_parry_msg",({
			"$nʹ��һ�С������������������Ծȣ����е�$v����$N��ǰ�ء�\n",
			"$n����һת������һ�ӣ�����$v����$N��$l��\n",
			"$n�Թ�Ϊ�أ�һ��ֱָ$N���ʺ�\n",
	}));



	action = ({
		([	"name":			"one",
			"action":		"$N��ǰһ��������$w���߰����$n��$l",
			"dodge":		50,
			"damage":		70,
			"damage_type":	"����"
		]),
		([	"name":			"two",
			"action":		"$N����һת������һ�ӣ�����$w����$n��$l",
			"dodge":		50,
			"damage":		20,
			"damage_type":	"����"
		]),
		([	"name":			"three",
			"action":		"$n��ǰһ����$N���е�$w�Ѿ�Ѹ���ޱȵĴ���$n��$l",
			"dodge":		40,
			"force" :		100,
			"damage_type":	"����"
		]),
		([	"name":			"four",
			"action":		"$Nֻ�����أ�����$wһ������$n��$l�̳�һ��",
			"dodge":		40,
			"damage":		40,
			"damage_type":	"����"
		]),
		([	"name":			"five",
			"action":		"$N�ġ����ֽ�����ֻ�д̣��򵥶���Ч����$n��$l��ȥ",
			"dodge":		60,
			"damage":		80,
			"force" :		100,
			"damage_type":	"����"
		]),
		([	"name":			"six",
			"action":		"$N����$wֱָ$n$l���������˽���������ȥ",
			"dodge":		20,
			"damage":		20,
			"damage_type":	"����"
		]),
	});
}


int valid_learn(object me)
{	
	if(!::valid_learn(me)){
		return 0;
	}
	if (me->query("combat_exp")<1000000 && me->query_skill("lefthand-sword",1)>160){
		tell_object(me,"���ʵս����̫��,�޷���һ���������ֽ�����\n");
		return 0;
	}
	if (me->query("combat_exp")<2000000 && me->query_skill("lefthand-sword",1)>170){
		tell_object(me,"���ʵս����̫��,�޷���һ���������ֽ�����\n");
		return 0;
	}
	if (me->query("combat_exp")<3000000 && me->query_skill("lefthand-sword",1)>180){
		tell_object(me,"���ʵս����̫��,�޷���һ���������ֽ�����\n");
		return 0;
	}	
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 200 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(victim->query_skill_mapped("sword") == "snowshade-sword")
        if(me->query_skill("sword")+100 > victim->query_skill("sword")) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n���书·����ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("sword")) * 3;
        }
        return 0;
}

