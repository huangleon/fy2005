// mind_beast.c

inherit NPC;

void create()
{
	set_name("�׶��ͻ�", ({ "tiger", "big tiger" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", "����һֻ�����ޱȵİ׶��ͻ���\n");
	
	set("attitude", "aggressive");

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "�׶��ͻ��͵�����һ�ˣ�\n",
                "�׶��ͻ��ݺݵ���β������ɨ����\n"
        }) );

	set("combat_exp", 800000);
	set("bellicosity", 3000 );
	set("agi", 10 );
	
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 20);

	setup();
}
