// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("����", ({ "ding mi","ding","mi" }) );

		set("class","demon");
		set("title",BLU"�������"NOR);
		set("nickname",CYN"ҩ��"NOR);

		set_temp("apply/haste",100);
		set("always_duxin",1);

    	set("attitude","friendly");
        set("gender", "����" );
		set("age",27);

		set("chat_chance",1);
		set("chat_msg", ({
			"������Ц����¥�������ţ�������ô������\n",
		}) );

        set("combat_exp", 7100000);

		set("nb_chat_chance", 100);
		set("nb_chat_msg_combat", ([
			30: 	(: smart_fight() :),
		]) );

        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 150);
        set_skill("unarmed", 200);
        set_skill("hammer", 200);
        set_skill("longfenghuan", 186);
        set_skill("lingxi-zhi", 190);
		set_skill("force",200);
		set_skill("jingxing",200);
		set_skill("spicyclaw",240);
		set_skill("venusfinger",200);
		set_skill("xifengying",180);

		set_skill("divineforce",200);
		set_skill("daimonsword",200);
		
		set_skill("magic", 240);
		set_skill("essencemagic", 240);

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("magic", "essencemagic");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "daimonsword");
        map_skill("parry", "daimonsword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

		setup();

		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�ұ�ɫ��ɥ��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	object me = this_object();
	object *enemy;
	int i;
	enemy = me->query_enemy();

	i=query_busy();
	stop_busy();

	switch (random(3))
	{
	case 0:
/*		ccommand("perform force.decaybreath");
		if (i)
			perform_busy(i);
		else
			stop_busy();*/
		return;
	case 1:
		ccommand("perform force.deathgrip");
		if (i)
			perform_busy(i);
		else
			stop_busy();
		return;
	case 2:
		ccommand("perform force.zombify");
		if (i)
			perform_busy(i);
		else
			stop_busy();
		return;
	}
		if (i)
			perform_busy(i);
		else
			stop_busy();

	return;
}
