// fat_bandit.c

inherit NPC;
void call_for_help();
void create()
{
        set_name("����������", ({ "bandit" }) );
        set("title","����կ");
        set("gender", "����");
        set("age", 36);
        set("long", "��һ��ְ����֣�Բ�����������������������й�µµ��ת��תȥ��\n");
        set("combat_exp", 400000);
        set("class","lama");
        
        set("attitude", "aggressive");
        
        set_skill("iron-cloth", 120);
        set_skill("unarmed", 150);
        set_skill("bloodystrike", 150);
        set_skill("jin-gang",80);
        set_skill("parry",150);
        
		map_skill("unarmed", "bloodystrike");
		map_skill("iron-cloth","jin-gang");
	
		set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fofawubian" :),
                "\n���������˴�У��������ϵ�Ǯͨͨ��������\n",
                "\n�������������ﲻǬ��������������\n",
                (: call_for_help :),
        }) );

        setup();
        carry_object(__DIR__"obj/leather")->wear();
}


void call_for_help()
{
        object ob;

        if( query("called_help") || present("bandit chief", environment()) ) return;
        set("called_help", 1);
        command("say ����ģ�����צ��̫Ӳ....");
        say("���������˴�У��ϴ��ϴ��ֵܳŲ�ס����\n");
        ob = new(__DIR__"bandit_chief");
        ob->move(environment());
        ob->start_help();
}
