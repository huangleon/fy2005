inherit NPC;

void create()
{
        set_name("���ŷ�", ({ "jin guard","guard" }) );
        set("long",
                "������Ѿ����ϣ����������ϼ�޻������ӡ�\n"
                );

        set("attitude", "peaceful");
        set("cor", 26);
        set("agi", 60);
        set("combat_exp", 500000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ŷ������̵�˵���ǡ���������˧���𣿡���\n",}) );

        set_skill("unarmed", 100);
        set_skill("parry", 80);
        set_skill("dodge", 100);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
