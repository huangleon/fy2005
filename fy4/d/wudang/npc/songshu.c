// dog.c

inherit NPC;

void create()
{
	set_name("����", ({ "song shu" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("long", "��ͷ��β��һֻС����\n");

	set("chat_chance", 1);
	set("chat_msg", ({
		(: random_move :),
	}));
	set("combat_exp",2000);
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}
