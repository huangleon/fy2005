inherit NPC;
void hide();
void create()
{
	if( random(2))   set_name("������", ({ "mouse" }) );
		else	set_name("������", ({ "mouse" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�����Բ�Ĵ����� \n");

        set("combat_exp",10000);
        
        set("force", 200);
        set("max_force", 200);
        set_skill("dodge", 100);
        
        set("arrive_msg", "�Ӳݶ������˳���");
        set("leave_msg", "һ���̵��ܵ���");
        set("limbs", ({ "ͷ��", "����","ǰצ","��צ","β��"}) );
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
        message("vision", "�����������žͲ����ˡ�\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

