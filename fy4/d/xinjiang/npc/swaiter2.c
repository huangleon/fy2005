// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("�������ӵ�", ({ "bao seller" }) );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "һ��������źܶ���ӵ��ˣ�����������װ���ӵģ���������ð���͹⡣\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/baozi": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/kacloth")->wear();
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
                        say( "�������ӵĸ߽е���ţ��������ӣ��������ֺóԣ���\n");
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/baozi": 120,
        ]) );
}