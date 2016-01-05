// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","������ħ������ʽ");
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","demon");
	set("parry_msg", ({
		"$nʹ����ħ������ʽ�еġ�ħ���ޱߡ������е�$v���ɾ��ص�Ļ��סȫ��\n",
		})
	);
	set("unarmed_parry_msg", ({
        	"$nʹ����ħ������ʽ�еġ�ħ���ޱߡ������е�$v���ɾ��ص�Ļ��סȫ��\n",
		})
	);
	action = ({
	([	"action":	"$Nʹ����ħ��ʽ�е�����ʽ����ħ���ѡ������е�$w����һ���âն��$n��$l",
		"force":	500,
		"damage_type":	"����"
	]),
	([	"action":	"$N��һ����һ�С�ħ�����ɡ����е�$w�ó�һƬ������ɢ��$n��$l",
		"force":	300,
		"damage_type":	"����"
	]),
	([	"action":	"$N�����ת�����е�$wһ�С�ħ��է�֡������������$n��$l",
		"force":	200,
		"damage_type":	"����"
	]),
	([	"action":	"$N��Ӱ�ζ������������ң�һ�С���ħ���𡱣����е�$w������·ͻȻ����$n��$l",
		"force":	300,
		"damage_type":	"����"
	]),
	([	"action":	"$N��˫�ŵ�أ���������һ�С�������ħ��ȫ��ת��һ�ŵ������$n",
		"force":	200,
		"damage_type":	"����"
	]),
	([	"action":	"$N�������ϣ�һ�С���ħ���족����һ��$n���벻���ĽǶ�����$n��$l",
		"force":	200,
		"damage_type":	"����"
	]),
	([	"action":	"$N���е�$w���ҺỮ��һ�С���ħ���֡��������ػصؿ�ɨ��$n��$l",
		"force":	100,
		"damage_type":	"����"
	]),
    	([	"action":       "$Nʹ��������ħ������ʽ�е�����ʽ����ħ���ڡ������е�$wѸ���ޱȵؿ���$n��$l",
        	"force":        500,
        	"damage_type":  "����"
     ]),
	});
}

int valid_learn(object me)
{
        if(!::valid_learn(me)) {
        	return 0;
        }
        if( (int)me->query_skill("demon-force", 1) < me->query_skill("demon-blade",1)) {
            return notify_fail("��������ħ�ķ�����㣬�޷���������ħ������ʽ��\n");
		}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 300 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "throwing")
        if(victim->query_skill_mapped("throwing") == "tanzhi-shentong" )
        if(me->query_skill("demon-blade",1) > victim->query_skill("tanzhi-shentong",1)) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n$N���иֵ����غ�ɨ��$n�İ����޴�ʩչ��" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("blade")) * 4;
        }
        return 0;
}
