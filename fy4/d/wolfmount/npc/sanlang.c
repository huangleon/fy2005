#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("������", ({"liu sanlang","sanlang"}) );
        set("gender", "����" );
        set("nickname", HIM"ɫ��"NOR);
        set("long", "����һ����������ĳ������꣬�۾���ɢ�����������������\n");
	 	set("attitude", "friendly");
		set("age", 18+random(10));

        set("combat_exp", random(600000)+200000);
        create_family("��ɽ", 4, "����");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        set("chat_chance", 1);
        set("chat_msg", ({
        	"�����������˵����ֻҪ��Ů�ˣ������Ҿͻ�����������С��Ը�����ҹ�����ɽô��\n",
        }) );
        setup();
        carry_object(__DIR__"obj/silk_cloth")->wear();
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
}

void greeting(object ob)
{
	object *inv;
	int i;
	if (!ob || environment(ob)!=environment(this_object()))	return;
	if ((string)ob->query("gender") == "Ů��")
	{
        message_vision(MAG"$Nɫ���Զ���$n����Ħ��$n�����أ�߽���������˶���
˯�ɣ�˯�ɣ�������ܵ��˼伫�ֵĸо���\n"NOR, this_object(),ob );
        if ((int)ob->query_cps()<random(15)&& !ob->query_temp("sleeped") ){
   			message_vision("$N��������ģ���������Ϳ������ȥ����������˯��������\n", ob);
   			tell_object(ob, "�ܿ���ͽ��������硣\n");
			ob->set_temp("sleeped",1);
			ob->set_temp("disable_inputs",1);
			ob->add_temp("block_msg/all",1);
			ob->set_temp("is_unconcious",1);
			ob->set("disable_type",HIG "<˯����>"NOR);

			inv = all_inventory(ob);
			if(sizeof(inv)) {
				for(i=0; i<sizeof(inv); i++) {
					inv -= ({ 0 });
					if(sizeof(inv)) {
						if(inv[i]->query("equipped")) {
							inv[i]->unequip();
						}
					}
				}
			}
	  		call_out("wake", 8, ob);
	  		return;
	  	}
	  	else
	  	{
	  		message_vision("$Nת����ȥ������������һ�ڣ��ò�Ҫ����\n", ob);
	  		return;
	  	}
	  }
	  return;
}

void wake(object ob)
{
	if (!ob)	return;
	ob->delete_temp("disable_inputs");
	ob->delete("disable_type");
	if (ob->query_temp("block_msg/all")>=1)
	    ob->add_temp("block_msg/all", -1);
	ob->delete_temp("is_unconcious");
	if(!ob->is_ghost())
	{
		message_vision(CYN"$N�������۾��������������ವģ�����һ���������������������\n", ob); 
   		message_vision("$N���Ծ��ţ�Ťͷһ����������������������Ҫ�����������������ñ�������
��˵���ð�����ƽʱ�Ǹ��θ�����Եܣ���˵ʲô��ô��ƫ���Ҿ��ѵó�ǽһ�Σ�
��û��ɣ��㡣����Ȼ���һ���������!��~~��~~\n"NOR,ob);  
		return;
	}
	return;
}
