inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "flower seller", "seller" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("per", 40);
        set("long", "�����������������������˶��ۻ�����\n");
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 25);
        set_skill("dodge", 150);
        set_skill("throwing", 100);
	set("combat_exp", 12300);
	
        set("inquiry", ([
                "С��" : "��Ҫ������ɽȥ�ʡ�", 
        ]) );
                
        set("vendor_goods", ([
                __DIR__"obj/purple_flower":20,
                __DIR__"obj/red_flower":20,
                __DIR__"obj/yellow_flower":20,
                __DIR__"obj/blue_flower":20,
                __DIR__"obj/white_flower":20,
                __DIR__"obj/black_flower":20,
        ]) );

        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/flower")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        string *flower = ({"��ĵ��","��ö��","�ײ軨","������","��ö��","��ö��", });
        
        if( !ob || environment(ob) != environment() ) return;
        say( " ��������Ц�ŵ�����λ"+ RANK_D->query_respect(ob)
                 + "�����"+ flower[random(6)]+ "�� \n");
        
}



