

inherit NPC;
void create()
{
        set_name("���۸�", ({ "woman" }) );
        set("gender", "Ů��" );
        set("age", 48);
        set("str", 58);

        set("long","�������޲�����δϴǦ������ʮ�������ͣ���߶�ߵ���ģ�
��ò���㲣�����ϡ�Կɼ�����ʱ�ķ绪��
\n");
        set("combat_exp", 120000);
        
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 70);
        set_skill("zuixian-steps", 100);
	
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");

        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
