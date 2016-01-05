// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("�����ܹϵ�", ({ "gua seller" }) );
        set("gender", "����" );
        set("age", 50);
        set("long",
                "һ������ͨͨ�ı����ˣ�û��һ�����۵ĵط���\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/gua": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/hat")->wear();
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
                        say( "�����ܹϵĸ߽е��������ִ�Ĺ��ܹϣ������ִ�Ĺ��ܹϣ�����\n");
}

void reset(){
	
        set("vendor_goods", ([
                __DIR__"obj/gua": 120,
        ]) );	
	
}