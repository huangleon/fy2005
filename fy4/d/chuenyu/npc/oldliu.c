// chuenyu.c
inherit NPC;

void create()
{
        set_name("����ũ", ({ "old liu", "liu" }) );
        set("gender", "����" );
        set("age", 57);
        set("no_arrest",1);
        set("per", 10);
        set("long", @LONG
����ũ�������ʮ�ˡ����ֽŻ������ں���ɽ��������һĶ���ֱ��أ�
��Ψһ����Ů��С������Ϊ����
LONG
);
        set("attitude", "peaceful");
        set("combat_exp", 10000);
        
        set("marks/��������", 1);
        
        set_skill("sword", 150);
        set_skill("unarmed", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("bai-quan", 70);
        set_skill("doomsword",150);
        set_skill("chaos-steps", 120);
        map_skill("unarmed","bai-quan");
        map_skill("dodge", "chaos-steps");
        map_skill("sword","doomsword");
        
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
	
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",8 , ob);
        }
}


void greeting(object ob)
{
        object book, juan;
        object sword;
		int bonus;
        if (!ob || environment(ob)!=environment(this_object()))	return;
        	
        if(ob->query_temp("marks/xiaojuan_murder") == 0)
        {
        	if( !ob->query("marks/����")) 
        		say( "����ũ˵��������λ"+ RANK_D->query_respect(ob) +"���ɷ����СŮ������� \n");
        	else   	
        	{
        		juan = present("xiao juan",environment(this_object()));
        		if (!juan || juan->query("id")!= "xiao juan") return;
        		say( "����ũ˵��������λ"+ RANK_D->query_respect(ob) +"����л���СŮ������� \n");
        		say( "����ũ˵��������ڽ����Ȿ��������"+ RANK_D->query_respect(ob) +"���� \n");
        		say( "����ũ˵�������˴��Ǿ���֮�أ��ҵ�ȥҲ���� \n");
        		say( "����ũ���ž���Ҵ���ȥ���� \n");
		        destruct(juan);
				ob->set("marks/����", 0);
	    	  	REWARD_D->riddle_done(ob,"���ɾ���",10,1);
	        	if (QUESTS_D->verify_quest(ob,"���ɾ���"))
					QUESTS_D->special_reward(ob,"���ɾ���");
        		sword = new(__DIR__"obj/hengbing");
        		book = new(BOOKS"parry_75");
        		if (!sword->move(ob))	destruct(sword);
        		if (!book->move(ob))	destruct(book); 
        		destruct(this_object());
        	}
        }
        else
                call_out("killhim",1,ob);
}

void killhim(object ob)
{
        ob->set_temp("marks/xiaojuan_murder", 0);
        ob->set("marks/����", 0);
        set("title", "��������");
        say("����ũ����������������㣮���㣮�����Ǿ�Ȼɱ����Ů������������\n");  
        
        set("chat_msg_combat", ({
			"����ũ����������������㣮���㣮�����Ǿ�Ȼɱ����Ů������������",      
        }) );
        
        set("chat_chance", 15);
        set("chat_msg", ({
		"����ũ����������������㣮���㣮�����Ǿ�Ȼɱ����Ů������������",            
        }) );
           
        carry_object(__DIR__"obj/hengbing")->wield();
        kill_ob(ob);
        ob->kill_ob(this_object());
}
 
