#include <ansi.h>
inherit NPC;
void checking();

void create()
{
        set_name("ǿ��", ({ "robber" }) );
        set("gender", "����" );
        set("age", 30);
        set("str", 30);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
��ǿ�������˰̣�����������һ���׺ݶ��Ե������ӡ�
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 );
        set("combat_exp", 800000);
        set("chat_chance", 3);
        set("chat_msg", ({
		"ǿ���ߺ��������̸��ܣ�����ҪǮ��Ҫ���������˲����ա�\n",
		(: checking :),
        }) );

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
              "ǿ�������Խ�Ϊ����������Ҫ��������\n",
              "ǿ���ߺ��������˲����ա�\n",
        }) );

        set("force",1000);
        set("force_factor",20);
        set_skill("unarmed", 120);
        set_skill("blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("demon-blade",120);
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        setup();
        add_money("silver", 10); 
        carry_object(__DIR__"obj/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

void checking()
{
        object cart;
        object robber,player;
        robber = this_object();
        player = this_player();
        cart = present("silver cart",environment());
        
        if((int)robber->query("kee")* 100 / (int)robber->query("max_kee") <= 30)
        {
                if (!living(robber)) 
                	return;
                else 
                {
               		message_vision("\n$N�е����������֣�������\n\n$N�����ݶ��밵�ﲻ���ˡ�\n",robber);
                  	destruct(this_object());
                  	return;
                }
        }

        if (robber->is_fighting()) 
        {
                return;
        }
        else
        {
        	if ( !present(player->query("id"), environment(this_object())) && present("silver cart",environment(this_object())) )
           	{  
                	command("laugh");
                        message_vision("$N�����ڳ���Х��ȥ��\n", robber);
                        if( present("silver cart",environment(this_object())) )
                        	destruct(cart);
                	call_out("destroying",1,robber);
                	return;
        	}
	        else
          	{
        		message_vision("$N�㬵�˵���������ܵĿ죡��\n",robber);
			command("sigh");
			call_out("destroying",1,robber);
			message_vision("$N���μ�������ʧ�ڰ�����\n",robber);
			return;
		}
	}
             
}

void destroying(object me)
{
        destruct(me);
        return;
}