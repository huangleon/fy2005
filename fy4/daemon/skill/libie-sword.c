// libie-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","��𽣷�");
	set("type","sword");
	set("difficulty",230);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",230);
	
	action = ({
        ([      "action":               
"$N��$wէ��һ�����⣬һʽ��˭֪����顱��ɲ�Ǽ�������$n�ʺ�ü��֮�䡣",
                "dodge":                400,
                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����է�˻��أ�һʽ�������Թ�����𡱣����е�$w���һ�������֣�\n"+
HIC+"$n����ס��ͷӿ��һ�����֮�飬��Ȼ�����ڶ�ս֮�С�"NOR,
                "dodge":                420,
                "damage":               -50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N$w�����ͻ�֣��������߲�ͣ��һ�С��������Զ����$w��������ѣ�����
����$n����Ҫ����",
                "dodge":                300,
                "damage":               -80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ɻ��������������졣���е�$w�����籩��㣬��ʽԴԴ����������
��ҶҶ��������𡱡�",
                "dodge":                370,
                "damage":		-140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ǳ��֮�飬��ͷһʽ�������뻳��ࡱ��������$w���ֻ��衣",
                "dodge":                750,
                "damage":		1600,
                "damage_type":  "����"
        ]),
	});
}
int valid_learn(object me)
{
    if((int)me->query("max_force") < 300 ) {
            return notify_fail("�������������û�а취����𽣷���\n");
	}
	if(!::valid_learn(me)) {
		return 0;
	}
    return 1;
}


mapping query_action(object me, object weapon)
{
	int attack_act;
	object *victims,victim;
	
	attack_act=random(sizeof(action));
	me->set_temp("libie-act",attack_act);
	victims=me->query_enemy();
	victim=victims[random(sizeof(victim))];
	if(attack_act==1)
	victim->start_call_out( (: call_other, __FILE__, "action_busy", victim, me:), 0);
	
        return action[attack_act];
}

int practice_skill(object me)
{
	return notify_fail("��𽣷�ֻ��ѧ�ġ�\n");
}

 
/*
string *parry_msg = ({
	"$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "������ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ�������㽣Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",

});

string *unarmed_parry_msg = ({
	"$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "������ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ�������㽣Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",

});

string query_parry_msg(object weapon)
{	int parry_act;

	parry_act=random(sizeof(parry_msg));
	this_player()->set_temp("xiaohun-parry",parry_act);
        if( weapon )
                return parry_msg[parry_act];
        else
                return unarmed_parry_msg[parry_act];
}
*/
/*
mixed hit_ob(object me, object victim)
{	int act;
        int pro;
        int dam;
        int myskill;
	object weapon;
	
	weapon=me->query_temp("weapon");
	myskill=me->query_skill("sword");
	if(weapon->query("id")!="leave hook") return 0;
	act=me->query_temp("libie-act");	
	if(act==0)
	{
		if(me->query_skill("libie-sword",1)<60) return 0;	
		dam = (int) me->query("force");
		dam = (random(dam)+dam)/2;
		pro = victim->query("con");
        	if (pro>30)
		{
			dam = dam*(1-(pro-30)/30);
		}
		victim->receive_damage("gin",dam/5,me);
		return (HIY "$nֻ������ǰ������ð���ƺ���Щ�������á�\n" NOR);
	}

	else if(act==2)
	{
		if(me->query_skill("libie-sword",1)<80) return 0;
		dam = (int) me->query("force");
		dam = (random(dam)+dam);
		pro = victim->query("con");
        	if (pro>30)
		{
			dam = dam*(1-(pro-30)/30);
		}
		victim->receive_damage("kee",dam/5,me);
		return (HIY "$N����������ͨ����������$n���ڡ�\n" NOR);
	}
	else if(act==3)
	{	
		if(me->query_skill("libie-sword",1)<120) return 0;
		dam = myskill+random(myskill);
		victim->receive_wound("kee",dam*2,me);
		return (HIR "$nֻ�������׻�����Ȼ���˺����ص����ˡ�\n"NOR);
	}

		
}



mixed parry_ob(object victim, object me)
{	int busy_time;

	if (victim->query_temp("xiaohun-parry")==1)
	{
		busy_time=random(7);
		if(busy_time)
			victim->start_call_out( (: call_other, __FILE__, "parry_busy", victim, me,busy_time :), 0);
	}
	return 0;
}	
		
void action_busy(object victim, object me)
{	
	if (me->query_skill("libie-sword",1)<150) return;
//	if (random(2))
	if (me->is_fighting(victim))
	if (!victim->is_busy())
		victim->start_busy(2);
}			
*/