inherit NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;

void create()
{
        set_name("������ϸ���", ({ "oldwoman" }) );
        set("gender", "Ů��" );
        set("age", 60);
        set("long",
                "�ϸ��˳��Ű��������������£���ǰ���Ÿ������ͼ������롣\n");
	set("combat_exp", 5);
	set("inquiry", ([
 		
   	]));

        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/teapot": 30,
               __DIR__"obj/dumpling": 30,
               __DIR__"obj/fan": 30,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "�ϸ���Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "�ϸ�����ë��Ĩ��Ĩ����˵������λ" + RANK_D->query_respect(ob)
                                + "������������\n");
                        break;
                case 2:
                        say( "�ϸ���˵������λ" + RANK_D->query_respect(ob)
                                + "�����������Ųɵ��²�Ҷ����! ���㰡!...\n");
                        break;
        }
}

void reset(){
	        set("vendor_goods", ([
                __DIR__"obj/teapot": 30,
               __DIR__"obj/dumpling": 30,
               __DIR__"obj/fan": 30,
        ]) );
}