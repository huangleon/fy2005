inherit NPC;
void create()
{
        set_name("������˪������", ({ "oldman", "old man", "man" }) );
        set("gender", "����");
        set("age", 74);
        set("long",
"����һ��������˪�����ˣ�����˫Ŀ����̫��Ѩ�߸�¡��\n"
               ); 

	set("class","fighter");
        set("attitude", "peaceful");
        set("combat_exp", 2000000);
        set("reward_npc", 1);
	set("difficulty", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������˪������������ԶԶ��һ���������̸е�͸����������\n",
        }) );
        
        set_skill("force", 100);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 200);
	set_skill("move", 150);
	set_skill("doomforce", 150);
        set_skill("doomstrike", 150);
	set_skill("doomsteps", 150);
        
        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hantian" :),
        }) );

        setup();
	carry_object("/obj/armor/cloth")->wear();
}
