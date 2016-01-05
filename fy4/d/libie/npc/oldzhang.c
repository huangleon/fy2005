inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����ͷ", ({ "old zhang", "zhang" }) );
        set("gender", "����" );
        set("age", 65);
        set("str", 27);
        set("max_kee", 2000);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
һ�����������壬�ݹ���᾵����ˡ�
LONG
);
        set("attitude", "peaceful");
	set("inquiry", ([
                "���³���":	"С�꿪�������������³�����\n",
                "di qinglin" : "����������С��ү����ͽ�������֡�\n",
                "������" : 	"����������С��ү����ͽ�������֡�\n",
                "����" : 	"��������������ͷ��Ů����\n",
                "���" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "yang" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "yang zheng" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
        ]));
        set("combat_exp", 10000);
        set("bellicosity", 0);
	set("vendor_goods", ([
		__DIR__"obj/hot_rice":20,
		__DIR__"obj/hot_greens":20,
		__DIR__"obj/hot_soup":20,
	]) );
        
        setup();

        add_money("coin", 50); 
        carry_object("/obj/armor/cloth")->wear();
        
}
int accept_fight(object me)
{
        command("say ��ͷ�����������Ķ��֣�");
        return 0;
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
    switch( random(5) )
    {
        case 0:
message_vision("$N��ͣ̾�����������ݺ��������˵�����ö�õ��޶�����ô��Ͷ���أ���\n",this_object(),ob);
        break;

        case 1:
message_vision("$Nת����ʰ��꣬�����Ա����������տյ���ɴ���ȴͣ�ֲ���������̾Ϣ��ֹ����\n",this_object(),ob);
        break;
    }
}

void reset()
{
        set("vendor_goods", ([
		__DIR__"obj/hot_rice":20,
		__DIR__"obj/hot_greens":20,
		__DIR__"obj/hot_soup":20,
        ]) );
}
