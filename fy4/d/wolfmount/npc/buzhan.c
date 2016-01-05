inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��ս", ({ "master buzhan", "master" }) );
        set("nickname", HIW"ս����"NOR);
        set("long","�����Ź������Ȼ�������ƣ�ȴ������˵�������������š�\n");
        set("gender", "����" );
        set("apprentice_available", 5);
        
        set("age", 46);
        set("spi", 25);
        set("per", 40);
		set("attitude","heroism");
        set("combat_exp", 2200000);
               
        set("guard_msg",HIW"$N��$n�ȵ�����ɽ�ӵ�,ͬ����֦,�����������꣡\n"NOR);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��սһ�ֽ������ź���ǹ�����ǰ�ú���������ң�˭ɱ������ɱ�ǳ�\n���⣬�Ϸ���������ڡ�\n",
        }) );
        
        create_family("��ɽ", 3, "��ͷ��");
        set("rank_nogen",1); 
		    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
	set("ranks",({ "С���","�����","���ǵ�","ҹ�ǵ�","ս�ǵ�",
				"СͷĿ","��ͷĿ","Сͷ��","��ͷ��","���","����",
				"����",RED"��ʥ"NOR,RED"��˧"NOR,RED"����"NOR,HIR"����֮��"NOR}));
        set("class", "wolfmount");
        
        set("reward_npc", 1);
		set("difficulty", 2);
        
        set_skill("move", 150);
        set_skill("unarmed", 150);
        set_skill("perception", 150);    
        set_skill("foreknowledge",150);
        set_skill("parry", 150);
        set_skill("xueyeqianzong", 150);
        set_skill("wolf-strike", 160);
        set_skill("assassin-hammer", 160);
        set_skill("literate",100);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("chanting",100);
    	
    	set_skill("summonwolf", 200);
        set_skill("hammer",200);
		set_skill("wolf-force",160);
	
		
		map_skill("dodge","xueyeqianzong");
		map_skill("unarmed","wolf-strike");
		map_skill("parry","assassin-hammer");
		map_skill("hammer","assassin-hammer");
		map_skill("force","wolf-force");
     	map_skill("cursism", "wolf-curse");	
     	
     	setup();
     	carry_object(__DIR__"obj/silkcloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
       	carry_object(BOOKS"skill/wolf-curse_50");

}

void reset()
{
	set("apprentice_available", 5);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("say �Ϸ��Ѿ��չ��˵��ӣ����������ˡ�\n");
        }
}

void do_recruit(object me)
{
	if( (string)me->query("class") != "wolfmount" )
        {
        	command("say ��ֻ�ձ��ŵ��ӣ��㻹����ı�߾Ͱɣ�\n");
        }
        else if(!me->query_temp("marks/wolf_win_tiezhan"))
        {
        	switch ( random(2) )
		{
		  	case 0:
				command("say �ø����Ҳ�Т�ļһ��Ȼû�к���ս���к�����������\n����գ�\n");
				break;
			case 1:
		  		command("say ѧ��Ҫѭ�򽥽����㻹�Ǵ�û��������ɡ�\n");
		  		break;
		}
	}
	else if (!me->query_temp("marks/wolf_killed_wuyi"))
	{
                command("shake");
                command("say ��ɱ����������ƥ���Ϸ������ͽ��\n");
	}
	else
	{
		command("say ����ұ��˴���Ҿ�����Ϊͽ�ɣ�\n");
		command("recruit " + me->query("id") );
	}
}
		
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
}
