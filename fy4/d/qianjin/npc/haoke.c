
inherit NPC;

void create()
{
        set_name("����Ӻ���", ({ "haoke", "ke"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�������ӵĴ���͡�\n");
        set("combat_exp", 50000);
	set_skill("dodge", 100);
	set_skill("unarmed", 220);
        set("chat_chance", 1);
        set("chat_msg", ({
		"����Ӻ��͵����ã���������\n",
        }) );
	
	setup();
        
        carry_object("/obj/armor/cloth")->wear();
}

