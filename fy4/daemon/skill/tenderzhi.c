// tenderzhi.c

inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","���ָ");
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("type","unarmed");
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","taoist");
	
	set("parry_msg", ({
        	"$n��ָ΢��$N$w�ļ�ˣ�$N���е�$w�������ֶ�����\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
	}) );	
	action = ({
        ([      "action":               
"$N����һ�ӣ�һ�С���¥���¡������ֵ���$n$l",
                "dodge":                30,
                "parry":                30,
                "damage":                80,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"$Nʹһ�С�ѩ����÷������Ӱ��ǰ���ᣬͻȻһת��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"$N���Զ٣�����һ��ʹ������ͤ��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "damage":                140,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"ֻ��$N����һ�ڣ���Ȼ�������ߣ�����˳������һ�С��ҷ��˵�����$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
	});
}


int valid_learn(object me)
{
    	if((string)me->query("gender") != "Ů��") {
        	return notify_fail("���ָ��ֻ��Ů�Ӳ��������书��\n");
    	}
    	return ::valid_learn(me);
}
 

mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object my_weapon;
    	int badint;
//    	my_weapon=me->query_temp("weapon");
    	if(damage_bonus < 300 ) return 0;
        if (me->query("possessed"))	return 0;	// Nah, don't let pet do it.
        if(victim->query_skill_mapped("iron-cloth") == "yijinjing") {
        	badint = 2*victim->query_skill("iron-cloth")+ random(victim->query_skill("iron-cloth"));
		if(badint) {
			victim->receive_wound("kee",badint,me);
			switch(random(2)) {
        			case 0: return HIW"$Nָ�����˿˿����,������$n�Ļ����񹦣�\n"NOR;
               			case 1: return HIW"$nֻ����ͷһ��,$N������ָ����͸����� ������\n"NOR;
           		}
		}
	}
	return 0;
}



int help(object me)
{
	write(@HELP   
�����׽Ӳ��

��Ǭ������qiankun��
ָ���������裱���������ָ
�����˺�������Чȭ�ŵȼ�
���⹥���������ָ�ȼ�
����æ�����غ�
HELP
    );
    return 1;
}
