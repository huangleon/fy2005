inherit NPC;

void create()
{
        set_name("������", ({ "rat" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ���Ĵ�����\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set_skill("dodge", 50);
        setup();
}

