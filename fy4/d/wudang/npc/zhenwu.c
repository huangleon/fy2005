inherit NPC;
#include <ansi.h>
inherit F_MASTER;

void create()
{
    	set_name(HIY "����۾�" NOR, ({ "master zhenwu", "master", "zhenwu" }) );

    	set("gender", "����");
    	set("age", 999);
    	set("long", "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ���\n");
    	set("attitude", "peaceful");
    
    	set("no_shown",1);
    	set("rank_nogen",1);
    	create_family("�䵱��", 1, "������ʦ");
    	set("ranks",({"����",YEL"����"NOR,YEL"����"NOR,HIY"�۾�"NOR}));
    	set("rank_levels",({320000,5187000,10000000}));
    	set("class", "wudang");
    	
    	set("reward_npc", 1);
    	set("difficulty", 40);
    
    	set("str", 600);

    	set("force", 2000);
    	set("max_force", 2000);
    	set("force_factor", 1000);
    
    	set("combat_exp", 20000000);
    	set("score", 20000);
    	set("class", "wudang");
    
    	set_skill("unarmed", 180);
    	set_skill("force", 190);
    	set_skill("sword", 300);
    	set_skill("foreknowledge", 200);
    	set_skill("parry",180);
       	
    	set_skill("chanting", 100);
    	set_skill("perception",100);
    	set_skill("move",160);
    	set_skill("dodge",160);
    	set_skill("literate",100);
    	set_skill("taijiforce", 200);
    	set_skill("incarnation",320);
    	
    	set_skill("taiji",180);
    	set_skill("taiji-sword",180);
    	set_skill("changelaw", 200);
    	set_skill("qixing",200);
    	set_skill("five-steps",200);
    	set_skill("spells",100);
    	
    	    
    	map_skill("spells","qixing");
    	map_skill("dodge","five-steps");
    	map_skill("move","five-steps");	
    	map_skill("force", "taijiforce");
    	map_skill("unarmed", "taiji");
    	
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object me)
{
	if(me->query("class")=="wudang"
		&& me->query_skill("changelaw",1)>=150
		&& me->query("marks/�䵱_ִ��")
		&& me->query("family/master_id", "master shi"))
    		{
    			command("recruit " + me->query("id") );
		}
}


void recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "wudang");
}


void init()
{
    	:: init();
    	add_action("do_look","look");
}

int do_look(string arg)
{
    	if (arg == "master zhenwu" || arg == "zhenwu" || arg =="master")
    	{
        	write(HIY "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ��񡣡�\n" NOR);
        	return 1;
    	}
    	return 0;
}
