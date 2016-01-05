// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
	set("name","�����ǻ�צ");
	set("usage/parry",1);
	set("damage_level",300);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",150);
 	
	set("difficulty",200);
	set("skill_class","wolfmount");
	set("parry_msg", ({
        	"$n��ָбն$N����ؽڣ�$Nֻ�����С� \n",
        	"$n����ץ$N˫Ŀ������������ȵ�$NһԾ�˿��� \n",
        	"$nצӰƮ����ס��$N�Ĺ��ơ� \n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n��ָбն$N����ؽڣ�$Nֻ�����С� \n",
        	"$n����ץ$N˫Ŀ������������ȵ�$NһԾ�˿��� \n",
        	"$nצӰƮ����ס��$N�Ĺ��ơ� \n",
	}) );	
	action = ({
        ([      "action":               
"$N��Ŀע��$n���Գ�һ��������˼�����飬��Ȼ���Ӷ�ǰץ��$n��$l�� ",
                "dodge":                10,
                "parry":                10,
                "damage":                70,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nб��������˫צ����ץ������ȡ$n��$l�� ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$NĿ��Ư�Ʋ������ƺ�$n��������ʲô��״����Ȼ��$n���������ץ��$n��$l�� ",
                "dodge":                50,
                "parry":                50,
                "damage":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N������צ������$n��ȫ����������������һ���ķ��۽���������ɱ�֣� ",
                "dodge":                70,
                "parry":                70,
                "damage":                140,
                "damage_type":  "ץ��"
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
   	if((int)me->query_skill("wolf-force", 1) < 170){
        return notify_fail("��������ķ�����㣬�޷��������ǻ�צ��\n");
    }
    	return 1;
}
