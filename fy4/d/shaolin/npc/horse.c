// mind_beast.c

inherit NPC;

void create()
{
	set_name("ľ��", ({ "wood horse", "horse" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 3);
	set("long", "����һֻľ��\n");
	

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "hoof"}) );
		set("combat_exp", 20000);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
}
