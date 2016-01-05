// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void setup() {
	set("name","��������");
	set("type","throwing");
	set("usage/throwing",1);
	set("usage/parry",1);
	set("skill_class","moon");

	set("effective_level",150);
	set("eff_parry_level",210);

	set("difficulty",250);
	set("practice_limit",50);

	set("parry_msg", ({
        "$n�����ˣ�˫�����$N��ס�Ų���ȴ��һʽ���С�\n",
		"$n����էչ��ֻ������к���������꣬�����������С�\n",
		"$n����������������ݣ���$N�������֣���ʽ��ա�\n", 
	}) );
	set("unarmed_parry_msg", ({
        "$n�����ˣ�˫�����$N��ס�Ų���ȴ��һʽ���С�\n",
		"$n����էչ��ֻ������к���������꣬�����������С�\n",
		"$n����������������ݣ���$N�������֣���ʽ��ա�\n", 
	}) );	

	action = ({
        ([      "action":               
"$Nһ�����䣬ֻ�����ǵ��$w�׷ɶ�����ֱ��ө����裬��������㸲",
                "parry":                1,
				"damage":				4,
				"post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���䷭ת����ʱ���ѩ�׷ף�$wƮ�������������滨�����������������",
                "parry":                2,
				"damage":				3,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����ʱ���������죬���䴦������ϼǧ�ƣ�����$w������������벻ɢ���������",
                "parry":                3,
				"damage":				2,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"ֻ��$Nһ����Х��˫�����ģ�����$w�������꼱�꣬΢���Զ������Ƶ�������",
                "parry":                4,
				"damage":				1,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
	});
}

int damage_level(object me)
{
	return me->query_skill("starrain",1)+50;
}

int accuracy_level(object me)
{
	return me->query_skill("starrain",1)+50;
}

int valid_learn(object me)
{
	if(!::valid_learn(me))
		return 0;
	if( me->query_skill("starrain",1)> 100 && me->query_skill("throwing", 1) < me->query_skill("starrain",1) ) {
		return notify_fail("��Ի����İ����շ�֮����δ���侫�裬����ѧ����ɴ󹤵ĺ���������\n");
	}
	if( me->query("class") != "moon" && me->query_skill("starrain",1) >= 100 ) {
		return notify_fail("�����޷��������������������\n");	// ����RESEARCH��
	}
	return 1;
}

int valid_research(object me)
{
	if( me->query_skill("throwing", 1) < me->query_skill("starrain",1) ) {
		return notify_fail("��Ի����İ����շ�֮����δ���侫�裬����ѧ����ɴ󹤵ĺ���������\n");
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob,*enemy;
	int i;
	if (me->query("class") != "moon" && userp(me))
		return 0;
	if (me->query_temp("annie/perform_starrain") && userp(me))
		return 0;
	if (me->query("annie/no-multi-target"))
		return 0;
	enemy = me->query_enemy();
	if (sizeof(enemy) < 2)
		return 0;
	me->set_temp("annie/multi-target",victim);

    return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("starrain", 1);
		if( skill < 200 ) {
			return 250;
		} else {
			return 400;
		}
	}
	return 250;
}

int help(object me)
{
	write(@HELP   
����������ͨ����ʱ���Թ������ж��֣�
100�����ϣ�����֮���ĵȼ�������ں���������
������������200���ϣ�ѧϰϵ�����ӵ�400��

���޿���������wukongxuanliu��
��50�������������ڶ���æ��<3ʱʹ�ã����ɹ����˵�æ�Ҷ�Ϊ���֣�����
����æ�Ҵ�����������Ӱ�죩����ʧ�ܵ��˵�æ�Ҽ���һ�֣��Լ�Ҳ����
��Щ����Ѫ�˺���ÿ12��ʹ��һ�Ρ�

������˥�ݡ���liantianshuaicao����
��80���������������ɹ����Ͷ���10%�ֿ������˺�����������10�롣
ÿ20��ʹ��һ�Σ����۳ɰ�������æ�ҡ�

�����ǰ��¡���qixingbanyue�� 
�ɹ���10�������л��иõ����߶���õ�һ������Ѫ�ָ���ħ���๥�����⣩��
�ɣ���Ҫ100���ĺ���������+50��Ѫ��
�ɣɣ���Ҫ160���ĺ���������������Ͼ�+70��Ѫ��
�ɣɣɣ���Ҫ180���ĺ���������������¾�+90��Ѫ��
ÿ20��ʹ��һ�Σ����۳ɰ�������æ�ҡ�

����ź��С���hongouxiangcan��
��130���������������ɹ�����ֹͣ���غ���ͨ����
ÿ20��ʹ��һ�Σ����۳ɰ�������æ�ҡ�

�����������ؼ�����ͬһ��20��ʱ�ޡ�

����©���̡���fengloufeiyan��
��150��������������һ˲֮�����������ɵ���������ʵ�����õ��˵Ĵ�����
�϶��û����ж��֣����ؼ��ڶԷ�������æ��״��ʱ�и��ߵ������ʣ�����
æ��2�֡�ÿ20����ʹ��һ�Ρ�
���Է�����æ���У����⹥����=��Ч�����ȼ�

�����һ�ߡ���tianheyixian��
��Ҫ200���ĺ����������������۳�һ��ԴԴ���ϵ�������
ʹ�ô���ʱÿ2�غϻ���һʽ����4ʽ������������
������������ʱ����Ҳ����æ���У�ʮ�����ա�
�����������30%ʱ���Զ��ж�
ÿ5����ʹ��һ��
���⹥����=400/400/600/800
�˺���=400/600/800/1600
�˺�ȡ������ֵ������������ȼ�������������
HELP
    );
    return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
