// springrain-sword


#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","���굶��");
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","npc");
	set("parry_msg", ({
        	"$n�������裬һʽ"HIG"������������ŪӰ��"NOR"�ó����쵶�⣬�·�����ˮ��
��$N������ʽ�������Ρ�\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n����һ�䣬��Ȼ��̾һ��"HIC"������ɴ���׷�䡹"NOR"��$N���𲻿����£���
�ɵس��ˡ�\n",
	}) );	
	action = ({
		([	"action":		"$N��������"HIG"���������ϣ��磭�����ꩤ����"NOR"��$w�����������ϵĴ��꣬�ӳ���һ������ϸ������$n��",
			"force":		70,
			"dodge":		30,
			"parry":		30,
		        "damage" : 		100,
			"damage_type":	"����"
		]),
		([	"action":		"$N�ٷ����������֮��"HIC"����ҹ���磭��̣�����"NOR"���·���������$w���ǵ�����$n��$l��",
			"force":		90,
			"dodge":		50,
	      		"parry":		40,
		        "damage" : 		150,
			"damage_type":	"����"
		]),
		([	"action":		HIR"�������仨���죭�����꡹"NOR"�ĵͺ��У�$N��$w������ʮ�䵶��������һƬѤ����Ѫ��ӿ��$n��",
			"force":		90,
			"dodge":		50,
			"parry":		40,
		        "damage" : 		200,
			"damage_type":	"����"
		]),
		([	"action":		"$N˫������Զ����һʽ"HIY"��������ʶ���࣭�飭����"NOR"�����β���˼�������һת��$w˳�ƻ�����һ���������»���",
			"force":		80,
			"dodge":		20,
			"parry":		30,
		        "damage" : 		300,
			"damage_type":	"����"
		]),
	});
}


