#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","�̹ž�ʽ");
	set("damage_level",300);
	set("type","hammer");
	set("usage/hammer",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","yinshi");
	
	set("parry_msg", ({
        	"$n����һ����һ�С������س������е�$v�͵�����$N��$w��\n",
		"$n����΢�٣����е�$vһ�С�Χ�����ԡ�����$N�ıؾ�֮����\n",
		"$n���е�$v�������ϼ��ӣ�һ�С���������Ŀ���$N���е�$w\n",
	}) );

	set("unarmed_parry_msg", ({
		"$nһ�С��ӹ������������е�$v��ƫ�����$N��̫����Ѩ��\n",
		"$n���е�$v�����ң�һ�С���ɨǧ������ס��$N�Ĺ��ơ�\n",
		"$n�����������һ�С���ɳ������е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
	}) );	
	action = ({
        ([      "action":               
"$N���ֻ���һ��ԲȦ�������е�$wһ�С������ķ�����$n��$l��ȥ",
                "damage":               500,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�����е�$w��һ�С�����ɽ�ӡ������е�$w��$n��$l�����������",
                "damage":               150,
                "dodge":                400,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�����ڿշ�����̩ɽѹ��֮ʽ���£����е�$w���ź������һ�С�ǧ��һ��������$n��$l",

                "damage":               270,
		"dodge":                500,
                "parry":                700,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���е�$wһת��һ�С���籩�꡻������˷�����$n��$l",
                "damage":               140,
		"dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�����е�$w��һ�С����տ������ó����촸Ӱ������ʵʵ�Ļ���$n��$l",
                "damage" : 		150,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
	});
}

void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("pangu-hammer", 1);
    	if (s== 100)
    		tell_object(me, HIW "������һ�����ƺ��Ӵ�����������ʲô��\n" NOR);
    	if (s== 130)
    		tell_object(me, HIW "������һ�����ƺ��Ӵ�����������ʲô��\n" NOR);
    	if (s== 150) {
       		tell_object(me,HIW " Ҳ������԰��ⴸ���ڻ��ͨ����ı޷���ȥ����\n"NOR);
       		me->set("marks/hammerwhip",1);
      	} 
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 350 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "blade")
    	if(	victim->query_skill_mapped("blade") == "bat-blade"
     		||victim->query_skill_mapped("blade") == "ittouryu")
    	if(me->query_skill("hammer") > victim->query_skill("blade")) {
    
    		switch(random(3)) {
            		case 0:
                			message_vision(HIR "\n$N�ϵл��ȣ�����ռ���Ϸ磡" NOR,me,victim);
                    		break;
            		case 1:
                    		message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    		break;
            		case 2:
                    		message_vision(HIR "\n$N�����г���$n��ʩչ�����ˣ�" NOR,me,victim);
                    		break;
                    	}
    	return random(me->query_skill("hammer")) * 2;
    	}
    	return 0;
}
