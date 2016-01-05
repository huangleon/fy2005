// Simon - turtle
// turtle.c ; last modified at 06.26.2003 by annie
// buffup

#include <ansi.h>

inherit NPC;

void buff_mate();

void create()
{
	set_name("����", ({ "turtle" }) );
	set("race", "Ұ��");
	set("attitude", "friendly");
	set("title",WHT"����֮"NOR);
	set("nickname",MAG"��İ"NOR);
	set("no_fly",1);
	set("no_arrest",1);
	set("combat_exp", 6000000);

	set("group","demon");

	set("max_kee",7000);
	set("max_gin",4000);
	set("max_sen",4000);

	set("limbs", ({ "ͷ��", "����", }) );
	set("verbs", ({ "bite", "claw" }) );

	set("str",60);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: buff_mate() :),
        }) );

	set_temp("apply/attack",350);
	set_temp("apply/dodge",1);
	set_temp("apply/parry",1);
	set_temp("apply/armor",1);

	setup();
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}

void buff_mate()
{
	object me = this_object();
	object * friends;
	object target,enemy;
	int i,j,k=999999,l=0;
	enemy = select_opponent();
	friends = enemy->query_enemy();

	switch (query("annie/demon_turtle_buff"))
	{
	case 0:
		message_vision(MAG"\n��������������ƣ��������ڡ�\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add("eff_gin",target->query("max_gin") / 2);
			target->add("eff_kee",target->query("max_kee") / 2);
			target->add("eff_sen",target->query("max_sen") / 2);
			target->add("max_gin",target->query("max_gin") / 2);
			target->add("max_kee",target->query("max_kee") / 2);
			target->add("max_sen",target->query("max_sen") / 2);
			message_vision(MAG"�����ڷ���������������$N��$N��������Ȼ��󼸷֡�\n"NOR,target);
		}
		break;
	case 1:
		message_vision(MAG"\n���侫�������һ�壬ʩ���������񻤡���\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add_temp("apply/dodge",350);
			target->add_temp("apply/parry",350);
			message_vision(MAG"����ɫ������������$N��Χ��������ס$N��\n"NOR,target);
		}
		break;
	case 2:
		message_vision(MAG"\n����ʩ�����������桹��һ����õĻ�����Ȼը����\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add_temp("apply/armor",200);
			target->add_temp("apply/ironcloth",350);
			target->set_temp("damage_shield/type","kee");
			target->set_temp("damage_shield/amount",250+random(200));
			target->set_temp("damage_shield/msg",MAG"$nһ�е��֣�ȴ��$N��߻����յý�ͷ�ö\n"NOR);
			message_vision(MAG"������ɫ�Ļ�����$N���������������ֹ��졣\n"NOR,target);
		}
		break;
	case 3:
		message_vision(MAG"\n������ת������Ѫ�С����͵�������������Ȼ����ȴ�������ǡ�\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add_temp("apply/attack",160);
			target->add_temp("apply/damage",160);
			message_vision(MAG"$NĿ��ɱ��է�֣����ָ�Ϊ���顣\n"NOR,target);
		}
		break;
	}
	add("annie/demon_turtle_buff",1);
	if (query("annie/demon_turtle_buff") < 4)
		start_busy(3);
	return;
}

// Kill Turtle in 12s to prevent buffup; (asap)
// Kill Dragon to prevent heal;
// Kill Phoenix to prevent busy;
// Kill Tiger to deal combat.
