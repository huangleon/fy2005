inherit NPC;

void create()
{
	set_name("��ȸ", ({ "bird" }) );
	set("race", "����");
	set("age", 1);
	set("long", "����������һֻС��ȸ��\n");
	
	set("chat_chance", 1);
	set("chat_msg", ({
		"���ң�������\n",
	}));
	set("combat_exp",2000);
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	setup();
}
