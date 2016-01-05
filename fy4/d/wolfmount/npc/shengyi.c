inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
        set_name("������", ({ "hao shengyi","hao" }) );
        set("long",
                "һ���ܺ������ܿ����Ŀ�ջ�ϰ塣\n"
                );
        set("title",  "��ջ�ϰ�" );

        set("attitude", "peaceful");

        set("combat_exp", 500000);
                set("inquiry", ([
                "��ɽ" : "������Ҫȥ�����ˣ��������̫үƢ���е���֣����ǲ�Ҫ���������˼ҡ�\n",
                "̫ƽ��ջ" : "�����Ҵ�ţ����ɽ��Բ����������̫ƽ��\n",
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                }) );

        set_skill("unarmed", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set("vendor_goods", ([
				__DIR__"obj/wolfskin":10,
                __DIR__"obj/wolfmeat":15,
                __DIR__"obj/wolfpen":20,
                __DIR__"obj/wolftea":15,
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
                        say( "������Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������ɡ�\n");
                        break;
                case 1:
                        say( "�����⹰��˵������λ" + RANK_D->query_respect(ob)
                                + "����Դ�����������¡����\n");
                        break;
                case 2:
                        say( "������˵������λ" + RANK_D->query_respect(ob)
                                + "��������ɽ�ز��ɣ�����ֻ�����������õ���\n");
                        break;
        }
}

void reset ()
{
        set("vendor_goods", ([
				__DIR__"obj/wolfskin":10,
                __DIR__"obj/wolfmeat":15,
                __DIR__"obj/wolfpen":20,
                __DIR__"obj/wolftea":15,
	]) );

}