#include <ansi.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("����", ({ "tian xin", "tian" }) );
        set("gender", "Ů��" );
        set("age", 14);
	set("title", GRN"��Ѿ��"NOR);
        set("long", "��������˿˿������Ѿ�ߣ�Ҳ����õ����ѣ�һ��С���ѿɰ����ˡ�\n");
        set("combat_exp", 100000);
    
        set("attitude", "friendly");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set_skill("dodge", 150);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/neck1":1,
                __DIR__"obj/neck2":1,
                __DIR__"obj/neck3":1,
                __DIR__"obj/neck4":1,
		__DIR__"obj/hat1":1,
		__DIR__"obj/hat2":1,
		__DIR__"obj/hat3":1,
		__DIR__"obj/pin1":1,
		__DIR__"obj/pin2":1,
		__DIR__"obj/ring1":1,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) {
                case 0:
                       say( "��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "����ʲô��Ҫ���� �ҼҴ�С�㰡��ƽʱ\n��˵������ү�޵�ҧ���гݣ����ڿɲ�������ү��ͷһ�����Ͱ����ƽʱ\n���ĸα�����������ȫ�ó������ˡ�\n");
                        break;
                case 1:
            say( "���ĺ�����С��������λ"
                             + RANK_D->query_respect(ob)
                             + "��������ǻƽ�����������ʵ������\n��С��ı�����Ҫ����...... \n");
                        break;
        }
}

				
