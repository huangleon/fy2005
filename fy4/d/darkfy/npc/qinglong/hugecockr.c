inherit NPC;
void create()
{
        set_name("�������", ({ "huge cockroach" }) );
        set("race", "Ұ��");
        set("age", 999);
        set("long", "һֻ�ǳ��޴����롣�ƺ������Եĳ�� \n");

        set("combat_exp",18000000);
        set("score", 2000);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 150);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set("arrive_msg", "�ɿ�����˹���");
        set("leave_msg", "�ɿ��������");
        set("limbs", ({ "ͷ��", "����"}) );
         set("verbs", ({ "bite" }) );
        set_temp("armor", 300);

    set("chat_chance", 25);
    set("chat_msg", ({
            (: random_move :),
    }) );

        setup();
}


