// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

int annie_drug()
{
	object me = this_player();


	if (me->query_temp("annie/find_herb/����") && me->query_temp("annie/find_herb/������") && me->query_temp("annie/find_herb/��С��") && me->query_temp("annie/find_herb/����") && me->query_temp("annie/find_herb/����ѩ") && me->query_temp("annie/find_herb/Ҷ��ʿ")	)
	{
		message_vision(query("name")+"�ɵ�����Ҷ���֪�����ǡ����ǡ���\n",me);
		message_vision(query("name")+"ͻ��һ��ͷЦ�����㿴������ԣ���������÷��������\n",me);
		return 1;
	}

	if (me->query_temp("annie/find_herb/��С��"))
	{
		message_vision(query("name")+"ҡͷ������ίʵ����������\n",me);
		return 1;
	}
	message_vision(query("name")+"����һ���������ң�����˭��\n",me);
	message_vision(query("name")+"��æ���֣��㻹���Լ�������常ȥ�ɡ�\n",me);

	me->set_temp("annie/find_herb/��С��",1);
	return 1;
}

void create()
{
        set_name("��С��", ({ "wan xiaochun","wan" }) );
        set("gender", "����" );
        set("title", "��ѧ����" );
        set("age", 23);
        set("long",
                "һ����ü��������ͷɥ���ļһ�Գ�����ҽ������Զ����ֶ��\n����������͵��Щ�鵤��Ǯ����\n");
       set("combat_exp", 600000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��С����������������������˵����㰡�����������ؼҵ��̲���û�ˣ�\n�������������кðɡ���\n",
                "��С��������һ�ۣ����������������Һ��һ�����Щ�����常��\n��͵�����鵤��ҩ���ɶ�����ҽ�����ı�����\n",
                "��С��һƨ�����ڵ��ϣ�һ�����ذ���̾����\n",

        }) );


	  	set("inquiry", ([
        	"���̲�" : 	(: annie_drug :),
   	]));
	
		set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/senyao":50,
                __DIR__"obj/keeyao":50,
                __DIR__"obj/ginyao":50,
        ]) );
        setup();

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
        switch( random(2) ) {
                case 0:
                        say( "��С��������������λ" + RANK_D->query_respect(ob)
                                + "������ͷ��Щ�鵤��ҩ�ɶ����޼�֮����Ҫ��\n����ȫ��ҵ�����λ����㡣����\n");
                        break;
                case 2:
                        say( "��С������˵������λ" + RANK_D->query_respect(ob)
                                + "������˵������¾����⻹���⼸��ҩ���ߣ�����ͷ��\n�ϴ��������գ��ҾͰ����ı����䷽ȫ���ˡ���\n");
                        break;
        }
}


void reset(){
        set("vendor_goods", ([
                __DIR__"obj/senyao":50,
                __DIR__"obj/keeyao":50,
                __DIR__"obj/ginyao":50,
        ]) );	
}