
inherit NPC;

void create()
{
        set_name("������", ({ "yellow guard", "guard"}) );
        set("gender", "����" );
        set("age", 32);
	set("cor",15);
        set("long", "����һλ��Ǯ���ܶ�Ļ�������\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        
        set_skill("sword", 30);
	set_skill("dodge", 50);
	set_skill("lefthand-sword", 30);
        map_skill("sword","lefthand-sword");
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
        }) );
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "����������ȵ��������\n",
                "����������ȵ���վס����������ƣ�\n",
        }) );
	
	setup();
	
        carry_object(__DIR__"obj/tangfu")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

