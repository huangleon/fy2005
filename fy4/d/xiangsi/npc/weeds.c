// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name("ɱ�˲�", ({ "hunting weed", "weed" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 3);
	set("long", "������������һ���Ӳݡ�\n");
	
	set("no_arrest",1);
	
	set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 360000);
	
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 100);

	set_skill("force",200);
	set_skill("divineforce",200);
	map_skill("force","divineforce");
	set("class","demon");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

    set("NO_CORPSE",CYN"ɱ�˲�һ����У�����һ�����̣������ɽ���ϵ������С�\n"NOR);

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

void smart_fight()
{
	object me,target;
	me = this_object();
	
	target = select_opponent();
	
	if (target)
	if (target->query("combat_exp")< this_object()->query("combat_exp")*3/2)
	if (SKILL_D("divineforce")->perform_action(me,"check_gspm"))
	{
		message_vision(CYN"\n$N������һ��������Ӳݴ�����˳��������Ǹ�һ�߸��µ�С�ˡ�"NOR,me);
		SKILL_D("divineforce")->perform_action(me,"guishenpomie");
		stop_busy();
		message_vision(CYN"$N��֨ϸЦ��ֱ���ò�Ҷ�Ҳ���������һ����زݴ��\n"NOR,me);
		return;
	}

	switch (random(3))
	{
	case 1:
		message_vision(CYN"\n$N���ľҶ�������裬���������Ƚ���\n\n"NOR,me);
		me->receive_heal("kee",300);
		break;
	case 2:
		message_vision(CYN"\n$N���ҽ��˼�����\n\n"NOR,me);
		break;
	case 0:
		add_temp("apply/attack",100);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,
					HIG"\n$N�����Ȼ����һ����磬���ŷ�ɳ��ʯ����$n�����ҵ�ɰʯ���Ե�$n������ã��"NOR,
					"����");
		add_temp("apply/attack",-100);
		if (target->query_temp("damaged_during_attack"))
		{
			ccommand("ya");
			target->perform_busy(1);
		}
	}
}

