// modified by mimicat@fy4

#include <ansi.h>	

inherit SKILL;
void setup(){
	set("name","ѩӰ����");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("difficulty",150);
	set("skill_class","taoist");
	set("parry_msg", ({
	        "$n�������ϣ��ԡ�����һ���㡻����$N��$w��\n",
	         "$n����һ����$v�����ƶϷ塻бɨ������\n",
	        "$n���˷������������У��������ˣ�$vֱ�̣�����$N�ҽš�\n",
	        "$n�Ҽ��������ʺ羭�졻��$v���ã�������$N�Ĺ��ơ�\n",
	        "$n�������������Ƕ�ء���ֱ�����µ��ܡ�\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n����һ����$v�����ƶϷ塻бɨ������\n",
	        "$n���˷������������У��������ˣ�$vֱ�̣�����$N�ҽš�\n",
	        "$n�Ҽ��������ʺ羭�졻��$v���ã�������$N�Ĺ��ơ�\n",
	        "$n�������������Ƕ�ء���ֱ�����µ��ܡ�\n",
	}) );
	action = ({
		([	"action":		"$Nʹһ�С��ع�õ硻������$w����һ���������$n��$l",
			"dodge":		20,
			"damage":		130,
			"damage_type":	"����"
		]),
		([	"action":		"$Nʹ��ѩӰ�����еġ���˪��Ӱ����$w���ӣ��������ն��$n��$l",
			"dodge":		20,
			"damage":		130,
			"damage_type":	"����"
		]),
		([	"action":		"$Nһ�С�������ѩ��������Ʈ�����ߣ�����$wն��$n��$l",
			"dodge":		30,
			"damage":		120,
			"damage_type":	"����"
		]),
		([	"action":		"$N����$w�й�ֱ����һʽ�����ȳ��硻��׼$n��$l�̳�һ��",
			"dodge":		40,
			"damage_type":	"����"
		]),
		([	"action":		"$N����һԾ������$wһ�С�������������׼$n��$lбб�̳�һ��",
			"dodge":		40,
			"damage_type":	"����"
		]),
		([	"action":		"$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
			"dodge":		20,
			"damage":		140,
			"damage_type":	"����"
		]),
	});
}

mixed hit_ob(object me, object victim)
{
	object weapon;
	string result;
	int extra;
	
	weapon=me->query_temp("weapon");
	extra=weapon->query("exorcising");
	
	//	allow ���˷� to do some demo without troubles.
	if (!userp(me) && me->query("id")=="master ding") {
		extra = 1500;
	}
	
	if(!extra )	return ;
		
	result = HIR"��ֽ�ϵ�Ѫɫ�ƺ��ּ�����һ�֡�����\n";
	if(victim->is_ghost() || victim->is_zombie())
		extra = extra *2;
	extra = COMBAT_D->magic_modifier(me, victim, "sen", extra);
		
	victim->receive_wound("sen",extra,me);
		
//	message_vision("damage is "+(extra+extra/2)+".\n",me);
	result+=HIY"$n�����������ݣ���Ϊ֮�ᡣ\n"NOR;
	return result;
}

int help(object me)
{
	write(@HELP   
����ѩ��������baixueaiai��
��������������æ�ң��غ�
���⹥������ѩӰ��������Ч��������
�����˺�����ѩӰ��������Ч������������
HELP
    );
    return 1;
}


