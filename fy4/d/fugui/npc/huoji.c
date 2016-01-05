inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
#define MONEY_VALUE 10000

void create()
{
        set_name("��Ԫ�ݻ��", ({ "huoji" }) );
        set("long","һ��ææµµ�Ŀ�Ԫ�ݻ�ƣ�����ĺ���������������ֱ��������\n");
        set("attitude", "peaceful");
        set("agi", 60);

        set("combat_exp", 12000);
        set("inquiry", ([
                "��" : "���������Ҷ�࣬Ů��������ѵ�һ�ٵ��ϼ����ư���\n",
                "�þ�" : "�͹ٿ��ǻ���Ҫ�㼫Ʒ�ľƣ��ǵÿ��͹��Ƿ������Ǯ��\n",
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "��Ԫ�ݻ��Ц�Ǻǵ����͹٣������ưɣ��������Ҷ����Ǹ�������
�ѵ�һ�ٵ��ϼ����ư���\n",
         }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 30);
        
        set("vendor_goods", ([
			__DIR__"obj/zhuskin":10,
			__DIR__"obj/shaoskin":10,
                __DIR__"obj/beef":15,
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
                        say( "��Ԫ�ݻ��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ���Ҷ�࣬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��Ԫ�ݻ����ë��Ĩ��Ĩ���ŵ�һ�����ӣ�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "��Ԫ�ݻ��˵������λ" + RANK_D->query_respect(ob)
                                + "�����������³����Ľ�ţ�⡣��! ���㰡!...\n");
                        break;
        }
}

int accept_object(object me, object obj){	
		
	object poorpot;
    if( (int) obj->value() >= MONEY_VALUE)
        {
        	command("say С����ƿ��Ǽ�Ʒ����Ů���죬�Ѿ��������ʮ�꣬
�͹ٺ��˾�֪��ʲô�Ǻþ�����\n");
        	poorpot = new(__DIR__"obj/poorpot");
        	if (poorpot)
        	if(!poorpot->move(me))
        		poorpot->move(environment(me));
        	message_vision("$N�ó�һ��"+HIB "���߹�"NOR+"��$n��\n",this_object(),me);
        	return 1;       
        }
	else
	{
	    command("hehe");
	    message_vision(CYN"$N���˵�˵������㣬����"+ RANK_D->query_respect(me) +"���Ǿ������ϵľưɣ�\n",this_object());
		return 0;
	}
}



void reset(){
    set("vendor_goods", ([
		__DIR__"obj/zhuskin":10,
		__DIR__"obj/shaoskin":10,
        __DIR__"obj/beef":15,
	]) );
}
