
inherit NPC;

void create()
{
	set_name("��ë����", ({ "wolf", "big wolf" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", "����һֻ�����ޱȵĻ�ɫ���ǡ�\n");
	
	set("attitude", "aggressive");

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "��������񺿼�����\n",
                "����������̹�ʹ�㲻��������\n"
        }) );
	set("combat_exp", 880000);
	set("agi", 10 );
	set("bellicosity", 3000 );
	
	set_temp("apply/attack", 120);
	set_temp("apply/armor", 20);

	setup();
}
