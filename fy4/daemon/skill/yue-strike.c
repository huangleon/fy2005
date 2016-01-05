#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","С��ɽ��");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",230);
	set("difficulty",230);
	set("skill_class","task");
	set("parry_msg", ({
        	"$nһ�С���ɽ�����ϣ����̡���˫�������$Nֻ�ó������е�$w��\n",
        	"$n���ֲ�ס������ʹ��һ�С��������¸����١���$N��$w������һ�飬����ʹ����������\n",
        	"$nһ�С����������ƽ��С����ѽ�$N��$w�������С�\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$nһ�С���ɽ�����ϣ����̡���˫��������Ƶ�$N�������ˡ�\n",
        	"$n���ֲ�ס������ʹ��һ�С��������¸����١���$N������һ�飬����ʹ����������\n",
        	"$nһ�С����������ƽ��С�����$NӲ��Ӳ��ƴ��һ�У����˶�ֻ��ȫ��һ��\n", 
	}) );
	action = ({
        ([      "action":               "$Nʹһ�С���ҹ���˲�ס������˫�ư��˹�������׼$n��$lɨȥ",
                "dodge":                80,
                "parry":                20,
		"damage":		100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������֣�һ�С�����ǧ���Σ�������������$n��$l��ȥ",
                "dodge":                40,
                "parry":                90,
		"damage":		80,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫�ֽ���ֱȡ$n��$l��ȴ��һ�С�����Ϊ������",
                "dodge":                120,
                "parry":                20,
		"damage":		120,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ����ֺ�����ʹ��һ�С������ģ�������������������$n��$l",
                "dodge":                60,
                "parry":                80,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�����˺�����ȴ�̺�������һ�С�֪���٣��Ҷ���˭����ֱ��$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                130,
                "damage_type":  "����"
        ]),
	});
}



mixed parry_ob(object victim, object me)
{	int busy_time,alr_busy_time;
	int skill;
	int my_exp, your_exp;
	
	if (victim->query("race")=="Ұ��") return 0;
	
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	skill=me->query_skill("yue-strike",1);
	
	if ( 
		(userp(me) && !random(4-skill/60) && 4*random(my_exp)>your_exp) ||
		me->query_temp("pfm/yue-strike/shts")
		|| !userp(me) ) {
		me->set_temp("counter_action",1);
		me->set_temp("counter_msg",HIY"$N˫ȭ�����Ӳ��Ӳ����$n�����к��˹�ȥ��\n"NOR);
	}
	
	return 0;

/*		if(busy_time>alr_busy_time)
			victim->start_busy(busy_time);
		switch(random(3)){
			case 0:
				message_vision(HIY"$Nֻ������ǰ��Ӱ�׷��ѱ���á�\n"NOR, victim);
				break;
			case 1:
				message_vision(HIY"$Nһ�����칥��$n����;��ͻȻ�ӿ죬$nһʱ�䲻֪����Ǻá�\n"NOR, me, victim);
				break;
			case 2:
				message_vision(HIY"$N�Ʒ��ƶ�����������$n�������ܣ�$n����Խ��Խ����ʩչ������\n"NOR, me, victim);
				break;
		}
	}
	return 0;
*/
}	


