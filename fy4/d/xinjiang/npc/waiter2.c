// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("��������", ({ "waiter" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long",
                "һ��ü��Ŀ���ά�����С���ר�������������ѡ�\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ([
                __DIR__"obj/putao": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
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
                        say( "������������һ������Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "������һ���ɣ�\n");
                        break;
                case 1:
                        say( "��������������λ����еĴ�����˵������λ" + RANK_D->query_respect(ob)
                                + "���ǿ���ķ��˹��\n");
                        break;
                case 2:
                        say( "��������˵������λ" + RANK_D->query_respect(ob)
                                + "�������������������Ķ����ˣ�\n");
                        break;
        }
}


void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/putao": 120,
        ]) );
}
