// Simon - phoenix
// phoenix.c ; last modified at 06.25.2003 by annie
// cast thousand-feather,busy target

#include <ansi.h>

inherit NPC;

void busy_attack();

void create()
{

	set_name("��ȸ", ({ "phoenix" }) );
	set("race", "Ұ��");
	set("attitude", "friendly");
	set("title",WHT"����֮"NOR);
	set("nickname",RED"�쳾"NOR);
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
               (: busy_attack() :),
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

void busy_attack()
{
	object me = this_object();
	object * enemy;
	object target;
	int i,j,k=0,l=0;
	enemy = query_enemy();
	// cast ����ǧ�� ; annie 6.25.03
	message_vision(RED"\n��ȸ����һ����Х���䣬������\n��ȸ�ڿ���ת�����Σ�˫���Ķ�������������������������\n\n",me);
	for(i=0; i<sizeof(enemy); i++)
	{
		target = enemy[i];
		for (j=0;j<10;j++)
		{
			if (random(target->query("combat_exp") * 3 / 2) < random(me->query("combat_exp")) )
				l++;
			else if (random(target->query("combat_exp")) < random(me->query("combat_exp")))
				k += 1+random(200);
			// else... miss.
		}
		message_vision(RED"���$N",target);
		if (l)
		{
			message_vision("��������������µĻ���",target);
			if (target->query_busy() <= l)
				target->start_busy(l);
			if (wizardp(target))
				tell_object(target,"BUSY:"+l);
		}
		if (k)
		{
			message_vision("��"+chinese_number(k)+"�������յ���",target);
			target->receive_damage("kee",k*(5+random(5)),me);
			if (wizardp(target))
				tell_object(target,"DAMAGE:"+k);
		}

		if (l || k)
			message_vision("�ֵ���æ���ң�\n\n"NOR,target);
		else
			message_vision("�������ɵıܿ������еĻ���\n\n"NOR,target);
	}
	start_busy(3);
	return;
	// tough? weak? silencer...pls balance this perform,thanks :) ; annie
}
