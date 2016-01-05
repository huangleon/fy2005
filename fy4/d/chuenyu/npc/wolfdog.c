// mind_beast.c

inherit NPC;

void create()
{
	set_name("����Ȯ", ({ "wolf dog", "dog" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 3);
	set("long", "����һֻ�����ޱȣ����˶�ߵľ�����Ȯ��\n");
	
	set("str", 48);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	
	set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 1);
        set("chat_msg", ({
		"����Ȯ�������������������������������������",
        }) );
                set("chat_msg_combat", ({
		"����Ȯ�������������������������������������",
        }) );

	set("combat_exp", 20000);
	set("bellicosity", 3000 );
	
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	setup();
}
