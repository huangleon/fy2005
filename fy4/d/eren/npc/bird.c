inherit NPC;

void create()
{
	set_name("������", ({ "bird" }) );
	set("race", "����");
	set("age", 1);
	set("long", "����������һֻС������\n");
	
	set("combat_exp",2000);
	set("chat_chance", 2);
	set("chat_msg", ({
		"���ҡ�\n",
		"������\n",
	}));
	
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	setup();
	carry_object(AREA_TIEFLAG"npc/obj/tongue",(["name":"��������"]));
}
