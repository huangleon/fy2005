inherit NPC;
void hide();
void create()
{
	if( random(2))
        	set_name("��ͷ��", ({ "cricket" }) );
	else
    		set_name("��ͷ����", ({ "cricket" }) );
        set("race", "����");
        set("subrace","����");
        set("age", 1);
        set("long", "һֻ�ı��������󰡣 \n");

        set("combat_exp",7000);
        set("score", 200);
        set("force", 200);
         set("max_force", 200);
        set_skill("dodge", 100);
        set("arrive_msg", "�ɿ�����˹���");
        set("leave_msg", "�ɿ��������");
        
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
        message("vision", "����ű��Ŵڽ�ǽ�ߵĲݴ���ȥ�ˡ�\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

