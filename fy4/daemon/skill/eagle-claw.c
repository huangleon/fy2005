// eagle-claw.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","ӥצ��");
	set("type","unarmed");
	set("effective_level",210);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("damage_level",250);
	set("difficulty",300);
	set("skill_class","fugui");
	set("parry_msg", ({
	        "$nһ�С�������á����ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
	        "$n��ȭ��Σ���ȭһ�С�ӭ����᡹���Ƶ�$N����������\n",
	        "$n�Թ�Ϊ�أ�һ�С��γ��ɡ����ͻ�$N��$w������\n",
	        "$nһ�С���ӥ��צ��������һ��$N��$w���֣���ƫ��$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$nһ�С�������á����Ƶ�$N��;���С�\n",
	        "$n����������һ�С��γ��ɡ�����$N֮�ؾȡ�\n",
	        "$n��ȭ���£���ȭ�Ա���һ�С�ӭ����᡹����$N���ڳ��⡣\n",
	        "$n˫ȭ�����ʹ��һ�С���ӥ��צ����$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

	}) );
	action = ({
		([  "action" : "$N�εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l",
		    "force" : 100,
		    "dodge" : 250,
		    "parry" : 250,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צ£��$n��$l",
		    "force" : 120,
		    "dodge" : 200,
		    "parry" : 400,
		    "damage": 5,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$Nһʽ���γ��ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
		    "force" : 150,
		    "dodge" : 200,
		    "parry" : 400,
		    "damage": 10,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����",
		    "force" : 190,
		    "dodge" : 150,
		    "parry" : 450,
		    "damage": 10,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�",
		    "force" : 150,
		    "dodge" : 500,
		    "parry" : 400,
		    "damage": 15,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$N���ػ��У�һʽ������հ�ա�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
		    "force" : 110,
		    "dodge" : 265,
		    "parry" : 365,
		    "damage": 20,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n",
		    "force" : 180,
		    "dodge" : 375,
		    "parry" : 575,
		    "damage": 25,
		    "damage_type" : "ץ��"
		]),
		([  "action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",
		    "force" : 170,
	 	    "dodge" : 800,
	 	    "parry" : 400,
		    "damage": 20,
		    "damage_type" : "ץ��"
		])
	});
}
/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
	mapping buff;
	int mod;
	
	if (me->query_skill("eagle-claw",1) < 100 || me->query("class")!="fugui")	
		return;
	
	if (victim->query("race")!="����")	return;
		
	mod = COMBAT_D->can_busy(me, victim, "eagle-claw");	
	if (!mod) mod = 1000;
	
	if (!ANNIE_D->check_buff(victim,"lockup"))
	if (COMBAT_D->do_busy_attack(me, victim, "eagle-claw/suomai","unarmed", 200,mod))
	{
		msg = BLU"\n$N��Ȼ���֣���ƮƮ�ĵ���ȥ����$n��������ָ�ĵڶ����ǽ�һ·��Ծ��ȥ��
�������⣬�羮����׵��������\n"NOR;
		message_vision(msg + "\n", me, victim);
		tell_object(victim, WHT"��������ӥצ��������ʽ!��\n"NOR);
		buff =
		([
			"caster":me,
			"who":	 victim,
			"type": "lockup",
			"att":  "curse",
			"name": "ӥצ��������",
			"time":  20 + random(10),
			"buff1": "till_death/lockup",
			"buff1_c": 1,
			"buff_msg": "",
			"warn_msg":"",
			"disa_msg": WHT"$N���λζ������ڴ�ָ�������������\n"NOR,
			"disa_type": 1, 
		]);
		ANNIE_D->buffup(buff);
		
	} 
}

void skill_improved(object me)
{
        int s;
        s = me->query_skill("eagle-claw", 1);
 	if (s == 100)
 		tell_object(me, WHT"���������ӥצ����������ˡ������������Զ���ս����Ӧ�á�\n" NOR);
}
*/


int help(object me)
{
	write(@HELP   	
L50����������qinlong��
�����غ��ڽ��͵��ֵ��м����㹥������������æ��1�֡�
��ʽ���۳ɰ�����ʹ�óɹ��ʶ����½���

L120������ж�ס���xiejia��
�ɹ���ɽ��ͶԷ�Ӳ�����ͻ��׵ȼ��߳ɣ�
����BOSS�������Ч��
�ɹ�ÿ3���ӿ���ʹ�ã�Ч��ά��60�롣
ʧ��ÿ1���ӿ���ʹ�á�
�ɰ��������æ��1�֡�

L150���������cunjin��
�����ֺ�ɽ�ֹ������15�غ���ʹ���ؼ���
����BOSS����˳���ʱ��Ϊ5�غϣ�
ÿ10����ʹ��һ�Σ�����æ��1�֡�

HELP
    );
    return 1;
}
