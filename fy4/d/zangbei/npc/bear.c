inherit NPC;

void create()
{
	set_name("Ұ��", ({ "bear"}) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 6);
	set("long", "����һֻƤ������Ұ�ܣ������׶������ޱȡ�\n");
	
	set("str", 60);
	
	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
               "Ұ��������������������ĺ�����������",
        }) );
	
	set("combat_exp", 2000000);
	
	set_temp("apply/attack", 250);
	set_temp("apply/dodge",250);
	set_temp("apply/move",400);
	set_temp("apply/armor", 100);
	setup();
	carry_object(__DIR__"obj/palm");
}

