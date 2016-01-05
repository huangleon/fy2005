inherit SMART_NPC;
inherit F_MASTER;

void create()
{
    	set_name("������", ({ "master tie", "master","tie" }) );
    	set("gender", "����" );
    	set("age", 26);
   
    	set("apprentice_available", 50);
    	create_family("��Ѫ������", 8, "����");
    	set("rank_nogen",1);
    	set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));

    	set("long","����������Ѫ�����ŵĴ��ˡ�\n" );

    	set("no_busy",10);
    	set("reward_npc", 1);
    	set("difficulty", 10);
    	set("attitude", "peaceful");
    
    	set("combat_exp", 7800000);
    	set("score", random(90000));
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(60) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","fy-sword",1);
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void reset()
{
    set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
	command("shake");
	command("say ѧ����ʲô��˼��������ú�ȥ����");
}

void do_recruit(object ob)
{
    if (ob->query_temp("mark/can_apprentice_master_tie"))
        if( (string)ob->query("gender") != "����" )
        {      command("say ��ֻ���е��ӣ�");
        }
        else {

            command("smile");
            command("say ���պ���д�ɣ�");
            command("smile");
            command("recruit " + ob->query("id") );
        }
}
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "tieflag");
    add("apprentice_availavble", -1);
}

int accept_object(object me, object obj)
{
    if(obj->query("id")=="silk book" && me->query_temp("mark/silkbook"))
    {
        me->set_temp("mark/can_apprentice_master_tie",1);
        me->delete_temp("mark/silkbook");
        command("say ��⣬�����������\n");
        return 1;
    }
    if(obj->query("id")=="flag" && obj->query("fake"))
    {
	command("say �󵨣����Ķ�Ū��һ����������Ū�Ϸ�\n");
	kill_ob(me);
	return 1;
    }
    return 0;
}

