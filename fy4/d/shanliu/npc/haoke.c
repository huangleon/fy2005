
inherit NPC;

void create()
{
        set_name("����Ӻ���", ({ "dahuzi haoke", "haoke"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ��������ӵĽ�������ͣ�һ��������Ǯ������\n");
        set("combat_exp", 300000);
		set("str",40);
        set("fle",30);
        set_skill("dodge", 100);
        set_skill("iron-cloth",150);
   		set_skill("unarmed", 220);
        set("chat_chance", 1);
        set("chat_msg", ({
"����Ӻ��ͺ������µ�����Ѷĵģ���񫣡�������ѵĹ�������\n",
        }) );
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
}

