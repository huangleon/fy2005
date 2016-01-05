
inherit NPC;
inherit F_MASTER;

void create()
{
    	object armor;
    	set_name("�պ�", ({ "master queen", "master","queen" }) );
    	set("gender", "Ů��" );
    	set("class","tieflag");
    	set("age", 46);
    	
    	set("cor",50);
    	set("apprentice_available", 50);
    	set("rank_nogen",1);
    	create_family("������", 1, "����");
    	set("ranks",({"����","С��Ů","��Ů","����Ů","��Ů","��Ů","ʥŮ",
                      "������"}));

    	set("long",
        	"�պ�����Ѫ�����ŵ��ߴ�����������֮�ޣ��򿴲�����Ѫ�������˶���\n"
        	"���ӵ����飬����������һ�ɣ�������������������Ů�ӡ�\n"
        	);
		set("fly_target",1);
    	
    	set("reward_npc", 1);
    	set("difficulty", 15);
    	set("no_busy",6);
    	set("attitude", "peaceful");
    
    	set("combat_exp", 6500000);
    	set("score", random(90000));
            
    	set_skill("unarmed", 300);
    	set_skill("sword", 200);
    	set_skill("force", 200);
    	set_skill("parry", 200);
    	set_skill("dodge", 200);
    	set_skill("ill-quan", 200);
    	set_skill("jiayiforce", 150);
    	set_skill("tie-steps", 200);
    	set_skill("perception", 250);
    		
    	map_skill("unarmed", "ill-quan");
    	map_skill("force", "jiayiforce");
    	map_skill("dodge", "tie-steps");

    	setup();
    	armor=new(__DIR__"obj/corclot");
    	armor->set_name("����˿��",({"cloth"}) );
    	armor->move(this_object());
    	armor->wear();

}

void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
    }
}

void do_recruit(object ob)
{
/*    if( (string)ob->query("gender") != "Ů��" )
    {      command("say ��ֻ��Ů���ӣ�");
    }
    else {

        command("smile");
        command("say �����ҳ�������ѧ�������书���������������˾������壡");
        command("smile");
        command("recruit " + ob->query("id") );
    } */
    command("shake");
    command("say ����չ��������ݲ���ͽ");
}

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "tieflag");
    add("apprentice_availavble", -1);
}
/*
void init()
{
    object me;
    me = this_player();
    if(userp(me) && interactive(me) && me->query("class") == "tieflag" 
       &&  me->query("marry"))
    {
        command("say �󵨣����Ҵ����Ź棡");
	this_object()->kill_ob(me);
    }
    ::init();
}

*/