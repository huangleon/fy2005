inherit NPC;
void create()
{
    	set_name("��ū", ({ "catty" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("gender", "����");
        set("long", "���������Ĳ�˹è\n");
    	set("combat_exp", 200000);
        set("attitude","peaceful");
        set_temp("apply/dodge", 200);
	setup();
}

/*
void init()
{       
        object ob;
        
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
               
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object *inv;
	int i;
        if( !ob || environment(ob) != environment() ) return;
      
        {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((string)(inv[i]->query("id")) == "leaf" && inv[i]->query("real"))
                        {
				command("cat");     
				say("��ū���������϶��һ���������ˡ�\n");
				ob->set_temp("mark/cat",1);
				destruct( this_object());
				return;
                        }
                }


        }
      
        return;
}
*/