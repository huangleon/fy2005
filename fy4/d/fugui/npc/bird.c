inherit NPC;

void create()
{
    set_name("Сϲȵ", ({ "bird" }) );
	set("race", "����");
	set("age", 1);
    	set("long", "һֻ�����Ҹ������Сϲȵ��ߴߴ������ͣ�ؽС�\n");
	set("combat_exp",10000);

	set("chat_chance", 1);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"���ҡ�\n",
		"������\n",
	}));
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	setup();
}
