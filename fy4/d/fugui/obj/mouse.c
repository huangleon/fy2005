inherit NPC;
void hide();
void create()
{
	if( random(2))
        set_name("С����", ({ "mouse" }) );
	else
    set_name("��������", ({ "mouse" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�����ݹ���ᾣ�Ƥ����ͷ�������Ͱ͵����� \n");

        set("combat_exp",7000);
        set("score", 200);
        set("force", 200);
         set("max_force", 200);
        set_skill("dodge", 100);
        set("arrive_msg", "�ɿ�ش��˹���");
        set("leave_msg", "͵͵��������");
        set("limbs", ({ "ͷ��", "����"}) );
         set("verbs", ({ "bite" }) );
        set_temp("armor", 50);

    set("chat_chance", 25);
    set("chat_msg", ({
            (: random_move :),
            (: hide :)
    }) );

        setup();
}

void hide()
{
        if( !environment() ) return;
       message("vision", "����ҡҡβ�ͣ���ҡ��ڵ�һ���ӱĽ������Ĵ���ȥ�ˡ�\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

