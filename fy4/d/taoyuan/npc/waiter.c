// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("С����", ({ "waiter" }) );
    set("gender", "����" );
    set("age", 23);
    set("long", 
    	"С���糤��Ũü���ۣ�����æµ���к����ˡ�\n");
	set("combat_exp", 5);
    set("attitude", "friendly");
    set("rank_info/respect", "С����");
    set("vendor_goods", ([
        "/obj/food_item/teapot": 10,
        __DIR__"obj/wineskin": 10,
    	__DIR__"obj/taopian": 20,
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
        say( "С����Ц���е�˵������λ" + RANK_D->query_respect(ob)
                             + "�������ȱ���裬ЪЪ�Ȱɡ�\n");
}

