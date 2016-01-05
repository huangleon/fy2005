// xiaohun-sword.c
#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ;

void setup(){
	set("name","��Ȼ���꽣��");
	set("type","sword");
	set("difficulty",250);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",250);
	set("skill_class","task");
	set("parry_msg", ({
		"$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "������ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ�������㽣Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "������ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ�������㽣Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",
	}) );
	
	action = ({
        ([      "action":               
"$Nһչ$w��һ��[��ʱ��ɫ]�������ʣ�������ã�����$n������ ",
                "dodge":                50,
                "damage":               230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��ڣ�����������������֣����������ξ��ĸо�����Ȼ�䣬
���㽣����������$n��������Ȼ���꽣����[�����軨]��",
                "dodge":                120,
                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ���Ƴ���һ��[ҹѩ����]��ֻ��������֯����$n",
                "dodge":                155,
                "damage":               450,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ؽ�������ʹ��[��������]��ƬƬ��Ӱ����ȴ��Ȼ�������������$n",
                "dodge":                300,
                "damage":		320,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������į������$w����бָ��$w��Ȼɫת�Ա̣���Ȼ���꽣���ľ���
[�Ľ�һҹ̦��]�Ѿ��������������������̦�̵���$n������",
                "dodge":                150,
                "damage":		600,
                "damage_type":  "����"
        ]),
	});
}
int valid_learn(object me)
{
	if (!me->query("m_success/���괫��"))
		return notify_fail("��һ�������꽣�����д����ˣ�ѧ��������޷��ɡ�\n");
	
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action));
	me->set_temp("xiaohun-act",act);
	return action[act];

}

string query_parry_msg(object weapon) {
	mapping msg;
	int act;
	
	if(objectp(weapon)) {
		msg = skill_attr["parry_msg"];
	}
	
	if(sizeof(msg) == 0) {
		msg = skill_attr["unarmed_parry_msg"];
	}
	
	if(sizeof(msg) > 0) {
		act=random(sizeof(msg));
		if (this_player()) 
			this_player()->set_temp("xiaohun-parry",act);
		return msg[act];
	}
	
	return 0;
}

mixed hit_ob(object me, object victim){	
	int act, pro, dam;
	
	act=me->query_temp("xiaohun-act");	
	if(act==4)
	{
		dam = me->query("force");
		dam = dam/2 + random(dam/2);
		dam = COMBAT_D->magic_modifier(me, victim, "sen", dam);
		victim->receive_damage("sen",dam/10, me);
		return (HIY "$nֻ����Ȼ���ˣ�������ģ��������\n" NOR);
	}
}

// 50% chance parry busy. busy time random(4)

mixed parry_ob(object victim, object me)
{	int busy_time,alr_busy_time;
	int level;
	if (victim->query("race")!="����") return 0;
	if (victim->query_temp("xiaohun-parry")!=1)	return 0;
		
	if (!check_skill(victim)) return 0;
	level = me->query_skill("xiaohun-sword",1);
	if (level < 100)	return 0;
	
	alr_busy_time=victim->query_busy();
	
	busy_time=random(4);
	if(!busy_time) return 0;
	
	if(busy_time>alr_busy_time)	victim->start_busy(busy_time);
	return HIB"$N��$n�Ľ�������һʱ��������η�Ӧ��\n"NOR;
}	

int check_skill(object victim) {
	
	object weapon;
	if (weapon = victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
		&& victim->query_skill("shenji-blade",1)>100
		&& victim->query_skill_mapped("blade")=="shenji-blade")
		return 0;

	return 1;
}	


int help(object me)
{
	write(@HELP   
L120����𡻣�libie��ÿ����Ӽ���𹳿ɷ������������
HELP
    );
    return 1;
}
