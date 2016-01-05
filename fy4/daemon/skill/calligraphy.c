// Copyright (C) 2002, by Sinny Shi. All rights reserved.
// This skill is a skill to enable all kinds of "pen-like" weapons - neon

// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","�鷨");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",180);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","baiyun");
	
	set("unarmed_parry_msg", (
	
	 { "$n������ɣ�˲Ϣ֮�䡺�����w��, �κ��κΡ�������$N��֪���롣 \n",
          "$n�������飬����Ȧת�趯�������������֮�кӺ�����$N�ۻ����ҡ� \n",
         }
        ) );

	action = ({
        ([      "action":               
"$N��Хһ��������Ʈ�ݣ������絶����$n���ݺ�֮�䡺��֮���ס�����д������ͰΣ�׿����Ⱥ",
                "dodge":                10,
                "parry":                10,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���δ󿪴��أ�����Ĺ����ݱ����һ���ǳɣ�һ��һ�����Ǳ��ߣ���籩�������$n",
                "dodge":                30,
                "parry":                30,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ⶶ�䣬���ֳٻ����أ�����ǧ��֮������$n��$l��д�����ǡ�׷Ω����������",
                "dodge":                50,
                "parry":                50,
                "damage":               160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����֮����$n��$l���¡���Ľ�ݾ���ʹ���ĸΡ����֣�����Ҳ���أ��Ƴ��֮������
��Ҳ�վ��������֮�� ",
                "dodge":                70,
                "parry":                70,
                "damage":               180,
                "damage_type":  "����"
        ]),
	});
}


int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
	 if((int)me->query_skill("chess", 1) <  (int)me->query_skill("calligraphy",1) ){
        	return notify_fail("����ĵ���Ϊ�������ĸ����겻����ϰ���鷨����\n");
    	}
    	return 1;
}


/*
mixed parry_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chess",1);
	
	if (random(skill) + skill/3 > 100 && me->is_busy()) {
		message_vision(HIG"$N������֣����˾�Ȼ���ĵ��ģ۵���ƪ��������Ŀ��������Ȼ����������\n"NOR, me);	
		me->stop_busy();
	}
	
	return 0;
}	
*/


