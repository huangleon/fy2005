#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("����������",({"young man","man"}));
    	set("long", "һ���߸����ݵ������ˣ���������ү���µĸɽ���\n");
		set("age",20);
		set("combat_exp", 3000000);
        
        set("sanye",1);
        
        
		set("max_kee", 6000);
		set("max_gin", 6000);
		set("max_sen", 6000);
        	
		set("inquiry", ([
        	"����":	"�ҿɲ����������������ˡ�\n",
        	"mission":	"�ҿɲ����������������ˡ�\n",
        	"��ү":	"��ү��������ү��������̫ƽ���һ�оͶ�����ү���ˡ�\n",
   		]));        	
		
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
	
		set("chat_chance",1);
    	set("chat_msg",({
				"����������Ħȭ���ƣ��ƺ��ܲ��ͷ������ӣ�\n",
    	}) );   
	
		auto_npc_setup("xuebin",170,170,1,"/obj/weapon/","random","random",1);
		setup();
		carry_object(__DIR__"obj/whitecloth")->wear();
}
