#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("��С��",({"tu xiaojiao","tu","xiaojiao"}));
	set("age",20);
	set("gender","Ů��");
	set("long", "
һ����������Ц��Ȼ��������Ů��û����֪��������ʵ��ݣ�����
˵�����������ĵ��ӣ�Ҳ����˵���������������ݡ�\n");
	set("attitude", "friendly");
	set("combat_exp",5200000);
			
	set("reward_npc",2);
	
	set("inquiry", ([
   	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
        	"��С��Ц�������͹�����¥ЪϢ����\n",
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(50) :),    
        }) );
	
	auto_npc_setup("guardian",200,200,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/blade",([	"name": "��Ҷ��",
    						"long": "һ����Ҷ�ε���������ϸ�ᣬû��һ���Ĺ������԰��ա���\n",
    						 ]))->wield();    
	
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	message_vision("$N�����˹������ﲨ��$nһ��򸣵��������ã���\n", this_object(),ob);
      	return;
}