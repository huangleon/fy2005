// xiaohun-sword.c
#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ;

void setup(){
	set("name","��Ȼ����޷�");
	set("type","whip");
	set("usage/whip",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("skill_class","task");
	set("difficulty",200);
	set("parry_msg", ({
		"$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "��Ӱ��ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ���������Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "��Ӱ��ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ���������Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",
	}) );
	
	action = ({
        ([      "action":               
"$Nһչ$w��һ��[��ʱ��ɫ]��Ӱ���룬������ã�����$n������ ",
                "dodge":                50,
                "damage":               230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��ڣ�����������������֣����������ξ��ĸо�����Ȼ�䣬
����޹���������$n��������Ȼ����޷���[�����軨]��",
                "dodge":                120,
                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�޻ӳ���һ��[ҹѩ����]��ֻ����Ӱ��Ļ����$n",
                "dodge":                155,
                "damage":               450,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ر޷��죬ʹ��[��������]��ƬƬ��Ӱ����ȴ��Ȼ�������������$n",
                "dodge":                300,
                "damage":		320,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������į������$w����бָ��$w��Ȼɫת�Ա̣���Ȼ����޷��ľ���
[�Ľ�һҹ̦��]�Ѿ��������������������̦�̵���$n������",
                "dodge":                150,
                "damage":		600,
                "damage_type":  "����"
        ]),
	});
}
int valid_learn(object me)
{
	if( (int)me->query("max_force") < 500 ){
	    return notify_fail("�������������û�а취����Ȼ����޷���\n");
	}	
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��Ȼ����޷�ֻ����ѧ�ġ�\n");
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
		dam = (int) me->query("force");
		dam = (random(dam)+dam)/2;
		pro = victim->query("con");
        	if (pro>30)
		{
			dam = dam*(1-(pro-30)/30);
		}
		dam = COMBAT_D->magic_modifier(me, victim, "sen", dam);
		victim->receive_damage("sen",dam/10,me);
		return (HIY "$nֻ����Ȼ���ˣ�������ģ��������\n" NOR);
	}
}

mixed parry_ob(object victim, object me)
{	int busy_time,alr_busy_time;
	int level;
	
	if (victim->query("race")!="����") return 0;
	if (victim->query_temp("xiaohun-parry")!=1)	return 0;
	if (!check_skill(victim)) return 0;
	
	level = me->query_skill("xiaohun-whip",1);
	
	if (level < 100) return 0;
	alr_busy_time=victim->query_busy();
	busy_time=random(level/40);
	if(!busy_time) return 0;
	if(busy_time>alr_busy_time)	
		victim->start_busy(busy_time);
	return HIB"$N"+HIB"��$n"+HIB"�ı�������һʱ��������η�Ӧ��\n"NOR;
}	

int check_skill(object victim) {
	
	object weapon;
		
	if (weapon=victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
		&& victim->query_skill("shenji-blade",1)>100
		&& victim->query_skill_mapped("blade")=="shenji-blade")
		return 0;

	return 1;
}	
