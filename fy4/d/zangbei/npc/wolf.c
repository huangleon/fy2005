inherit NPC;

void create()
{
	set_name("�๷", ({ "hyena"}) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 6);
	set("long", "����һֻ�����ޱȵ��๷��\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 500);
	set("attitude", "aggressive");

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "�๷����񺿼�����\n",
                "�๷������̹�ʹ�㲻��������\n"
        }) );
	
	set("combat_exp", 20000);
	set("bellicosity", 3000 );
	
	set_temp("apply/attack", 120);
	set_temp("apply/armor", 120);
	setup();
}


