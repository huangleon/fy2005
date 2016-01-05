// sharen-sword.c

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","ɱ�˽���");
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("effective_level",150);
	set("damage_level",200);
	set("skill_class","assassin");
	
	action = ({
		([	"name":			"a",
			"action":		"$N���е�$w��һ��ָ������$n��$l��������",
			"dodge":		50,
			"parry" :		100,
			"force":		170,
			"damage" :		150,
			"damage_type":	"����"
		]),
		([	"name":			"b",
			"action":		"$N����һת�����е�$w����������$n��$l���˹�ȥ",
			"dodge":		50,
			"damage":		170,
			"damage_type":	"����"
		]),
		([	"name":			"c",
			"action":		"$N����һ����$wЮ�������������$n��$l",
			"dodge":		40,
			"damage" :		50,
			"force" :		120,
			"damage_type":	"����"
		]),
		([	"name":			"d",
			"action":		"$N����һ�������е�$w�������ϴ���$n��$l",
			"dodge":		40,
			"damage":		80,
			"damage_type":	"����"
		]),
		([	"name":			"e",
			"action":		"$N����$w���Ⱪ������ǧ����Ы��$n$lҧȥ",
			"dodge":		160,
			"damage":		120,
			"damage_type":	"����"
		]),
		([	"name":			"f",
			"action":		"$N���е�$w���޷����ݵ��ٶ�ֱ��$n��$l",
			"dodge":		120,
			"force" :		100,
			"damage":		150,
			"damage_type":	"����"
		]),
	});
}

int valid_learn(object me)
{
	if (me->query("family/master_id")!="master jin"	&& me->query_skill("sharen-sword",1)>160)
		return notify_fail ("�����ɱ�˽���ֻ�ܸ�������ѧ��\n"); 
	if ( (int)me->query_skill("lefthand-sword",1)<75)
		return notify_fail ("ѧ��Ҫѭ�򽥽���ɱ�˽�����Ҫ75�����ֽ���Ϊ������\n");
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

/*
void skill_improved(object me)
{
	if( (int)me->query_skill("sharen-sword", 1)% 10 == 0 ) {
		tell_object(me,
			RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
		me->add("bellicosity", 200);
	} else
		me->add("bellicosity", 50);
}*/


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	string type;
    	
    	if( random(damage_bonus) < 200 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	{
    		type = ob->query("skill_type");
    		if (type != "hammer" && type != "staff" && type!="axe")	return 0;
    		if (me->query_skill("sword")+ 150 >= victim->query_skill(type))
    		{
	    		switch(random(3)) {
		        	case 0:
		                	message_vision(HIR "\n$N���ж�����ר�߿��ţ�ռ�����Ϸ磡" NOR,me,victim);
		                	break;
		        	case 1:
		                	message_vision(HIR "\n$N��Ȼ���Ⱪ�ǣ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
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
