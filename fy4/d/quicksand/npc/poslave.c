
inherit NPC;

void create()
{
        set_name("��˹ū", ({ "bosi slave", "slave"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�췢���ۣ��ߴ����ߵķ��ˡ�\n");
        set("combat_exp", 50000);
        set("bellicosity", 30000 );
        set("attitude", "aggressive");
        set_skill("blade", 90);
	set_skill("dodge", 100);
	set_skill("parry", 20);
        	
	setup();
	add_money("coin", 50);
        carry_object(__DIR__"obj/redcloth")->wear();
	carry_object(__DIR__"obj/roundblade")->wield();
}

