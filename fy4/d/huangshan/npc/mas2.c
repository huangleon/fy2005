inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();

void create()
{
    	set_name("����ü", ({ "master liu", "master","liu" }) );
    	set("gender", "Ů��" );
    	set("nickname", HIG"ӵ��ɽׯ�ٷ���"NOR);
    	set("apprentice_available", 50);
    	set("attitude", "friendly");
    	create_family("��ɽ��", 3, "����");
    	set("long",  "����ü��ɽ�����ŷ��ˡ�\n");
    
    	set("age", 26);
    	set("reward_npc", 1);
    	set("difficulty", 30);  
       
    	set("chat_chance", 1);
    	set("chat_msg", ({
        		name()+"�ֹ������森���ҵ�������ô�����ˣ�\n",
            }) );
    
    	  set("inquiry", ([
                "�����" : "������˻�ɽ��������������ִ�ƣ�������ѯ�ʡ�\n",
                "����":"��ū�ҵ���˼�أ�������ñ���ȥ̽����ʵ�źã�����С���󰡡�\n",
        				"��":"��ū�ҵ���˼�أ�������ñ���ȥ̽����ʵ�źã�����С���󰡡�\n",
        ]) );
        
    	set("combat_exp", 12000000);
    
    	set_skill("unarmed", 200);
    	set_skill("sword", 250);
    	set_skill("force", 180);
    	set_skill("move", 160);
    
    	set_skill("dodge", 200);
    	set_skill("perception", 200);
    	set_skill("parry",160);
    
    	set_skill("siqi-sword", 200);
    	set_skill("xianjing", 150);
    	set_skill("liuquan-steps", 200);

    	map_skill("unarmed", "meihua-shou");
    	map_skill("sword", "siqi-sword");
    	map_skill("force", "xianjing");
    	map_skill("dodge", "liuquan-steps");
    	map_skill("move","liuquan-steps");
    	map_skill("parry","siqi-sword");
	
    	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//             (: smart_fight() :),
        }) );
    
    	set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    	setup();
    	carry_object(__DIR__"obj/yellowcloth")->wear();
    	carry_object(__DIR__"obj/yusword")->wield();
}



void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

void init()
{

        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}

void attempt_apprentice(object ob)
{
		command("shake");
		command("say �������,��Ͼ��ͽ");
}


int accept_object(object who, object ob)
{
	if(ob->query("id") == "old jade")
	{
		command("smile");
		command("thank "+who->query("id"));
		if((int)ob->query("max_cure") < 5)
			call_out("give_pena",3,who);
			return 1;
	}
	return 0;
}

int give_pena(object who)
{
	if (!who) return 1;
	if(environment() != environment(who)) return 1;
	command("say �㾹Ȼ��͵�ñ����˵���ʯ������\n");
	kill_ob(who);
	who->kill_ob(this_object());
	return 1;
}
