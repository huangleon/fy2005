
inherit NPC;

void create()
{
        set_name("ũ��", ({ "farmer" }) );
        set("gender", "����" );
        set("age", 25+random(20));
        set("long", "һλ��òƽ��ũ������Ϊ�����æµ�š�\n");
        set("combat_exp", 200+random(200));
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                        (: random_move :)
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

