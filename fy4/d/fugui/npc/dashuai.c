#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"���˧"NOR, ({ "jin dashuai","jin" }) );
        set("long",
                "���˧��Ȼ�Ѿ�����ʮ���꣬վ������������Ȼ��ֱ���۾���Ȼ�й⣬
������Ȼ���ò�̫����ȴ��Ũ���ܺڡ���\n");

        set("attitude", "peaceful");
		set("age", 50);
        set("combat_exp", 1500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���˧��������������ͻȻ���������ʮ�����������ۻ����ҡ�\n",
        }) );
/*		set("inquiry", ([
            "����" : "�����Ǵ�����ͷ�����ﰡ���ţ�������ͷ��",
			"����" : "���Ѿ�ί�в�����������ˣ����������Ȥ���Ե����������������",
			"caishu" : "�����Ǵ�����ͷ�����ﰡ���ţ�������ͷ��",
			"mission" : "���Ѿ�ί�в�����������ˣ����������Ȥ���Ե����������������",
        ]) );*/
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("throwing",200);
		set_skill("meihua-biao",100);
		
		map_skill("parry","meihua-biao");
		map_skill("throwing", "meihua-biao");		
		
		setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/ball")->wield();
}


/*
void init()
{
        ::init();
		add_action("do_accept", "accept");
}

int accept_object(object me, object ob)
{
	object cart,obj;
	if(ob->query("name") == "�Ƽ���" && me->query_temp("marks/�Ƽ�") )
	{
		me->set_temp("marks/�õ�����",1);
		me->delete_temp("marks/�Ƽ�");
		me->start_busy(2);
		call_out("give_cart",2,me);
		return 1;
	}
	else
	{
	       	tell_object(me,"���˧˵�����ⲻ������Ҫ�ġ�\n");
        	return 0;  
        }    
}

void give_cart(object me)
{
	object jin,obj,cart,guard1,guard2;
	jin = this_object();
	command("spank " + me->query("id"));
	command("say �ðɣ��㽫�ڳ��͵�����ɽׯ�񷿣��Ի����˰��š�һ·С�ġ�");
	message_vision("$N��һ�У������𸮼Ҷ��Ӻ�Ժ�Ƴ�һ���ڳ���\n",jin);

	cart=new(__DIR__"cart");
	cart->move(environment());
	cart->set_owner(me);

	obj=new(SILVER_OB);
	obj->set_amount(4000);
	obj->set("name","���˧������");
	obj->move(cart);
	
	me->set_temp("dart_area","��");
	me->set_temp("dart_id","suanmei tang");
	me->set_temp("dart_name","��÷��");
	me->set_temp("protecting",cart);
}*/