// bat-dao.c  ���𵶷�

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","���𵶷�");
	set("type","blade");
	set("difficulty",200);
	set("effective_level",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("skill_class","bat");
	set("unarmed_parry_msg",({
		"$nʹ��һ�С������������������Ծȣ����е�$v����$N��ǰ�ء�\n",
		"$n���ƶ�Ȼ���˼���ħ�⣬��$N�Ĺ��ƶ�ʱ����������\n",
		"$n���е�$v�ó�һƬ�������ִ�$N�����е�����������\n",
		"$n��������һ�䣬$v��������ĺ����Ƶ�$N����������\n",
					})
	);
		
	action = ({
			([      "action" : "$N�߾�����$w,ʹ��һ�С�׷����硹��һ��б��$n��$l",
			        "dodge" : 200,
			        "parry" : 100,
			        "damage" : 90,
			        "damage_type" : "����",
			]),
			([      "action" : "$N�͵�һ����ʹһ�С�ն��ɱ����������$w��һ���޷�˼��ĽǶȻ���$n��$l",
			        "dodge" : 150,
			        "parry" : 150,
			        "damage" : 250,
			        "damage_type" : "����",
			]),
			([      "action" : "$N���е�$w��â������ʹ����˭��Ӣ�ۡ����������������$n��$l",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" :220,
			        "damage_type" : "����",
			]),
			([      "action" : "$Nһ�п���ƽ������ġ���ɽ���꡹��$w�����һ����˿��$n��ȥ",
			        "dodge" : 80,
			        "parry" : 80,
			        "damage" : 110,
			        "damage_type" : "����",
			]),
			([      "action" : "$N���˺�һ�����⽻�ڣ�����$w����������$n��$l",
			        "dodge" : 70,
			        "parry" : 70,
			        "damage" : 90,
			        "damage_type" : "����",
			]),
			([      "action" : "$N����������е�$w�ó�һƬ���⣬����Ȼ����һ����ն$n��$l",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" : 220,
			        "damage_type" : "����",
			]),
	});
}

int valid_learn(object me) {
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
		
	if((string)me->query_skill_mapped("force")!= "wuzheng-force") {
		return notify_fail("���𵶷�������������ķ���������\n");
	}
	
	if (me->query_skill("wuzheng-force",1)<me->query_skill("bat-blade",1))
		return notify_fail("��������ķ���򲻹���\n");
	
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "axe")
    if(victim->query_skill_mapped("axe") == "xuanyuan-axe" ||
    	 victim->query_skill_mapped("axe") == "wuche-axe")
    if	(me->query_skill("bat-blade",1)+50 > victim->query_skill("xuanyuan-axe",1)
    		|| me->query_skill("bat-blade",1)+50 > victim->query_skill("wuche-axe",1)) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n$N�ϵл��ȣ�����ռ���Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N����ƫ�棬$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("blade")) * 4;
    }
    return 0;
}
