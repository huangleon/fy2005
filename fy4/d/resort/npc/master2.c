
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();

void create()
{
    	set_name("ѩ���", ({ "master xuerui", "master","xuerui" }) );
    	
    	set("gender", "Ů��" );
    	set("nickname", HIG "���齣��"NOR);
    	set("long","
���ٴ�ʮ���꿪ʼ�ͺͰ���ѩ������������������ϱڣ������޵С�
��������������ʢ֮ʱ����Ȼ�˳������������ڴˡ�\n");

    	set("reward_npc", 1);
    	set("difficulty", 40);
    	set("combat_exp", 20000000);
    	set("score", 90000);
    	set("boss", 1);
    	set("age", 26);
    	set("per", 30);
    	
 	set("group","legend");
 	set("couple","tiexue");
    	set("marry","master tieshao");
    
    	set("class","legend");	
    	set("apprentice_available", 50);
    	create_family("��ѩɽׯ", 1, "ׯ������");
    	set("rank_nogen",1);
    	    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"��ͯ","��ͯ","��ͯ","С��","����","����",
    		"����","����","����","����","��ʥ","����",WHT"����"NOR,
    		WHT"����"NOR,WHT"���ڴ���"NOR,HIW"��������"NOR}));
    	
    	set("inquiry", ([
        "leave" : (: leave :),
    	]));    
       
    	set_skill("force", 200);
    	set_skill("chanting", 180);
    	set_skill("parry", 170);
    	set_skill("dodge", 170);
    	
    	set_skill("perception", 150);
    	set_skill("move",150);
    	set_skill("unarmed", 160);
    	set_skill("sword", 250);
    	set_skill("literate", 100);
    	
    	set_skill("foreknowledge",100);      	
    	set_skill("six-sense",300);
    	set_skill("dormancy",300);
    	set_skill("meihua-shou", 150);
    	set_skill("diesword",200);
    	set_skill("qidaoforce", 150);
    	set_skill("fall-steps", 150);
    
    	map_skill("unarmed", "meihua-shou");
    	map_skill("sword","diesword");
    	map_skill("force", "qidaoforce");
    	map_skill("parry", "diesword");
    	map_skill("dodge", "fall-steps");

    	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
				(: perform_action, "sword.caidiekuangwu" :),	
        }) );

    	setup();
    	carry_object(__DIR__"obj/yellowcloth")->wear();
    	carry_object(__DIR__"obj/msword")->wield();
}


void reset()
{
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
        	command("say ��ׯ�������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
    	}
}

void do_recruit(object ob)
{
    	if( (string)ob->query("gender") != "Ů��" )
    	{      	
    		command("say ��ֻ��Ů���ӣ��㻹��ȥ�����Ӱɣ�");
    	}
    	else 
    	{
        	command("smile");
        	command("say ���պ���д�ɣ�");
        	command("smile "+ ob->query("id"));
        	command("recruit " + ob->query("id") );
    	}
}


int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "legend");
    	add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
    	object xiaocui;
    	if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    	{
        	command("smile");
        	command("say ������С�����ɡ�");
        	return 0;
    	}
    	else
        	command("sigh");
    		command("ѩ��������ĴӴ������վ���������������е���ɰ����");
    		command("say �룡");
    		remove_call_out("do_unwie");
    		call_out("do_unwie", 3);
    		return 1;
}

int do_unwie()
{
    	if( !this_object()->is_fighting()) 
    	{	
	        message_vision("$N����豭ǳ�һ�ڣ�������������������һ�ۣ�����������ϡ�\n", this_object());
        	command("smile");
        	return 1;
    	}
    	else
        	call_out("do_unwie", 3);
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="legend") return 0;
	message_vision(CYN"$N�����˸���־���Ҳ���ǿ�����¡�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵��ֻ�Ǿ����ķ��ǵ��Ӳ���ʹ�ã������������ľ�������Ҳ��᲻���ˡ�\n"NOR,this_object(),this_player());
	return 1;
}