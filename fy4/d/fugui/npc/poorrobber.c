inherit NPC;
void checking();

void create()
{
        set_name("ɽҰë��", ({ "thief" }) );
        set("gender", "����" );
        set("age", 27);
        set("str", 20);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
���ë�����в�ɫ������������죬�·��������ã������еĵ�������ġ�
LONG
);
        set("attitude", "friendly");
        set("combat_exp", 10000);
        set("chat_chance", 3);
        set("chat_msg", ({
			(: checking :),
        }) );

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "ë����Ȼ�Ǹո����У�����ƫ��Ŀ�����ߡ�\n",
              "ë���ߺ��������Ӱ����������ź��Ӿ��з����ˡ�\n",
        }) );

        set("force",100);
        set_skill("unarmed", 80);
        set_skill("blade", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        setup();
        carry_object(__DIR__"obj/caidao")->wield();
        carry_object(__DIR__"obj/pocloth")->wear();
}

void checking()
{
        object robber,player,leader;
        robber = this_object();
        player = this_player();
        leader = present("thief leader", environment( this_object()));
           
        if (robber->is_fighting()) 
        {
                message_vision("\n$N�е����������֣��ӰѾ�����\n\n",robber);
                return;
        }
        
        if ( present("thief leader",environment(this_object())))
        {
        	if (leader->is_fighting())
        	{
        		command("addoil leader");
        		return;
        	}
        	else 
        	{
        		command("sigh");
        		command("say ���Ǹ�ʲô��������������������ʵ��ҲҪ��٣�\n\n");
        		return;
        	}
        }
        else
        {       	               	
        	message_vision("$N����ʧ�룺��ͷͷ�أ�ͷͷ�أ�....��\n",robber);
		command("sigh");
		message_vision("$N���˵�������䣬ת�����ˡ�\n",robber);
		destruct(robber);
		return;
	}
}