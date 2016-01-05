// bandit_leader.c

inherit NPC;

void create()
{
        set_name("��������", ({ "bandit leader", "chief", "leader" }) );
        set("title","����կ");
        set("gender", "����");
        set("age", 47);
        set("long",     "��һ������׶�һ˫���������������������Ĳ��ӡ�\n");
        set("combat_exp", 50000);
        set("score", 7700);
        set("bellicosity", 3000);
        set("attitude", "aggressive");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "\n����������������˵������������è�Ĺ���Ҳ��������կ����Ұ����\n",
                "\n��������˵����ȥ��ģ����ӽ���Ҫ�������ͷ��������צ��\n",
                "\n�������컢��һ����������ǰ��\n"
        }) );
        
        set_skill("blade", 60);
        set_skill("parry", 70);
        set_skill("dodge", 70);

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 50);

        setup();
        carry_object("obj/weapon/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
}

