// mother.c

inherit NPC;

void create()
{
	set_name("���ĸ", ({ "mother" }) );
	set("gender", "Ů��" );
	set("age", 39);
	set("per", 6);
	set("long", @LONG
    �ĸ�Ǹ�Ũױ��Ĩ������Ů�ӣ����΢�֣�ȫ��������ⱦ����
LONG
);
	set("combat_exp", 30000);
	set("attitude", "friendly");
       set("chat_chance", 5);
        set("chat_msg", ({
		"�ĸ����������½ǣ�����˵�����������Ҹ����Ҹ���õģ�\n",
                
        }) );

	set_skill("unarmed", 100);
	set_skill("parry", 50);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"�ĸ˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
	}) );
	setup();
	
	carry_object(__DIR__"obj/color_cloth")->wear();
	carry_object("/obj/item/poison_dust.c");
}

