// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("��ǧɽ", ({ "ma qianshan","ma","qianshan" }) );

		set("class","assassin");
		set("title",CYN"�������ɽ"NOR);
		set("nickname",MAG"ӯɽ"NOR);

		set("always_duxin",1);
        set("gender", "����" );
		set("age",47);

		set("chat_chance",1);
		set("chat_msg", ({
			"��ǧɽ̾����ħ�̱�̳�ھ�λ������ʯ��֮�󣬿ɺ����ܵü���\n",
		}) );

        set("combat_exp", 8100000);

		set("nb_chat_chance", 100);
		set("nb_chat_msg_combat", ([
			100: 	(: smart_fight() :),
		]) );

        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 200);
        set_skill("unarmed", 200);
        set_skill("spicyclaw", 350);
        set_skill("spear", 200);
        set_skill("eclipse-spear", 200);

        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "lefthand-sword");
        map_skill("spear", "eclipse-spear");
        map_skill("parry", "eclipse-spear");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name("ӯʱǹ", ({ "spear" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	object me = this_object();
	object ob = select_opponent();
	int i,j;

	if (random(4))
		return 0;
	if (random(4))
		ccommand("perform eclipse");
	else
		ccommand("perform riyuetongtian");
	return;
}

