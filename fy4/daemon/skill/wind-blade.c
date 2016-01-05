// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","ӭ��һ��ն");
	set("damage_level",300);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("type","blade");
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
		"$n�����ؽ����е�$v������ǰ��ǿ�ҵĵ��罫$N�Ƶ����˼�����\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n���е�$v�����ػӳ������Ҳ����ĵ������$N��\n",
	}) );	
	action = ({
		([	"action":		
		"$N���е�$wӭ��һ�Σ���������ѽ���������������ڰ�ؿ���$n��$l",
			"force":		400,
	                "damage":               200,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N���е�$wӭ����裬�󱩷��еĹ�ɳ������$n��$l",
	                "damage":               200,
			"force":		300,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N���е�$w�����е����ƣ����ۺ�ɢ�ؿ���$n��$l",
			"force":		100,
	                "damage":               200,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N�ζ����е�$w������������֣�������е���Ҷ��һ����һ����ɢ��$n��$l",
			"force":		100,
	                "damage":               200,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N����ȫ��Ĺ��������е�$w��̹Ǻ�������$n",
			"force":		200,
			"damage":		200,
			"damage_type":	"����"
		]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 200 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "hammer")
    if(victim->query_skill_mapped("hammer") == "pangu-hammer" )
    if(me->query_skill("blade") > victim->query_skill("hammer")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n�򵶴���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("blade")) * 10;
    }
    return 0;
}

