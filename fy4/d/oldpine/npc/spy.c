inherit NPC;

void create()
{
        object ob;

        set_name("������", ({ "spy" }) );
        set("gender", "����");
        set("age", 24);
        set("long", "������˿������������ģ���ز���ʲ��ö�����\n");
        set("combat_exp", 6000);
        set("score", 400);
        set("bellicosity", 2000);
        
        set_skill("throwing", 20);
        set_skill("unarmed", 20);
        set_skill("sword", 20);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        
        setup();
        ob = carry_object(__DIR__"obj/throwing_knife");
        ob->set_amount(30);
        ob->wield();
        carry_object(__DIR__"obj/black_suit")->wear();
        carry_object("/obj/item/dust")->set_amount(30);
}


void killed_enemy(object who)
{
        command("say ��������������");
        call_out("dissolve", 1);
}

void dissolve()
{
        command("dissolve corpse");
}

