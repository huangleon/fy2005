// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("����", ({ "du qi","du","qi","duqi" }) );

		set("class","berserker");
		set("title",MAG"��ɱ��"NOR);
		set("nickname",BLU"�ֹ�׽Ӱ��һ����ɱ"NOR);

        set("gender", "����" );

		set("age",47);

	set("chat_chance",1);
	set("chat_msg", ({
		"��������ش������㣬ҡ��ҡͷ��\n",
	}) );

        set("combat_exp", 6100000);

		set("nb_chat_chance", 100);
		set("nb_chat_msg_combat", ([
			100: 	(: smart_fight() :),
		]) );

        set_skill("blade", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 200);
        set_skill("unarmed", 200);
        set_skill("spicyclaw", 200);

        map_skill("unarmed", "spicyclaw");
        map_skill("parry", "spicyclaw");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("ƽ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("�����´��ñ", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	object me = this_object();
	object ob = select_opponent();
	int i,j;
	if (!is_busy())
	{
		if (random(3))
			return ;
		// 33% pf
		if (!ccommand("perform extrahit5") || !random(3))
			ccommand("perform extrahit4");
		if (!ccommand("perform extrahit4") || !random(3))
			ccommand("perform extrahit3");
		return;
	}
	if (me->query("timer/evade") + 5 > time())
		return;
	
	set("timer/evade",time());

	message_vision(MAG"\n$Nϸ�����۾���¶��һ˿������Ц�ݣ�����һ�У�̧���ñ��\n"NOR,me);
	message_vision(HIR BLK"ֻ��һֻ�Ұ�ɫ�ģ������߸���ָ���֣���ձ�ò�ͣ������ץ����\n"NOR,me);

	message_vision(HIW"�����������ֹ�׽Ӱ��һ����ɱ������\n"NOR,me);

	j=query_busy();
	stop_busy();

	for (i=0; i<7; i++)
	{
		add_temp("apply/attack",i*50);
		add_temp("apply/damage",i*50);
		               	COMBAT_D->do_attack(me,ob,TYPE_PERFORM,"");
		add_temp("apply/attack",-i*50);
		add_temp("apply/damage",-i*50);
	}


	perform_busy(j);
	return;
}