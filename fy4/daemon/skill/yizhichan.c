//mimicat@fy4
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","һָ��");
	set("type","unarmed");
	set("skill_class","shaolin");
	set("effective_level",210);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",1);
	
	set("parry_msg",			({
			"Ȼ��$n��ָ��㣬������ָ�罫$N���ˡ�\n",
			"$n����һ��֮�䣬������$N���棬����һ�ƣ�һָ����$N�����ȵ�$N������� ��\n",
			})
	);
	set("unarmed_parry_msg",	({
			"Ȼ��$n��ָ��㣬������ָ�罫$N���ˡ�\n",
			"$n����һ��֮�䣬������$N���棬����һ�ƣ�һָ����$N�����ȵ�$N������� ��\n",
			})
	);
	action = ({
			([      "action":               
			"$Nб��ʳָ���������£�����Ȼ��һ��������������$n$l ",
			        "dodge":                90,
			        "parry":                150,
			        "force":                100,
			        "damage_type":  "����",
			        "weapon":               "����",
			]),
			([      "action":               
			"$Nһָ������󿪴��أ����ɺ�ΰ����ʯ���쾪���������֮�ƴ���$n$l ",
			        "dodge":                140,
			        "parry":                210,
			        "force":                190,
			        "damage_type":  "����",
			        "weapon":               "����",
			]),
			([      "action":               
			"ֻ��$N����ǰ�壬���ֳ��Ƶ�ֱָ�㣬������������������͡������� ",
			        "dodge":                230,
			        "parry":                170,
			        "force":                220,
			        "damage_type":  "����",
			        "weapon":               "����",
			]),
			([      "action":               
			"$N��ָ��ǰһ�࣬һ��������ָ���佫��ȥ������$n$l ",
			        "dodge":                380,
			        "parry":                360,
			        "force":                390,
			        "damage_type":  "����",
			        "weapon":               "����",
			]),
	});
}

int valid_learn(object me) {
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if((string)me->query("class") != "shaolin" ) 
		return notify_fail("һָ����ֻ�����ָ�ɮ���������书��\n");
	
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    
	int chance, damage;
	if( !userp(victim) ) {
		victim->add_hate(me, me->query_skill("zen",1)*3);
    }
	chance = 30 + F_ABILITY->check_ability(me, "3_yzc_add", 3) * 2;
	if ( random (100) < chance ) {
		damage = COMBAT_D->magic_modifier(me, victim, "sen", damage_bonus/3+random(damage_bonus/2));     
		victim->receive_damage("sen",damage, me);
		return HIB"$nֻ���Ŀڴ�ʹ�����μ��ѱ�$N�������ˣ�\n"NOR;
	}
	return 0;
}


int help(object me)
{
	write(@HELP   
����ʱ��30%������ɵ��˵��������ˡ�
���е���ʱ��������ĳ�ޣ������ȼ�*3��
ͨ�����ɼ�����ǿ�������ӵ�50%���ʡ�

L100���κϡ���canhe��
����������Ѫ������æ��2�غ�
���⹥����=һָ���ȼ�
�����˺���=��Чȭ�ŵȼ�

L140���ͷ硻��hefeng��
�������ֹ�����ÿ10����ʹ��һ�Ρ�
����������г�ޣ���ʹ���ؼ��߳�����ӡ�
				
L150����������poqi��
ж�����ֵĶ��������ÿ10����ʹ��һ�Ρ�
�ɹ���ά��60�롣

L170���黨����nianhua��
������������ֻ���ڶ����������һ��ʱʹ�ã�
����æ��3�غϡ�
�ù����ĳɹ��ʽ���˫����Ծ���ֵ���
HELP
    );
    return 1;
}
