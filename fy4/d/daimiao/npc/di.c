inherit SMART_NPC;
#include <ansi.h>

void create()
{
    	set_name("��������", ({ "master di", "master", "di"}) );
    	set("nickname", HIW "�ض����"NOR);
    	set("title","�������");	
    	set("gender", "����" );
	    	
    	set("reward_npc", 1);
		set("difficulty", 5);
    	set("age", 63);
    	set("per", 3);
    	set("attitude","friendly");

    	set("long",
        	"������������������еĵ�λ�ǽ�������ʱ���˵ģ�\n"
        	"��������ͳ������������еĵض档\n");
    	
    	set("combat_exp", 7500000);
    	set("score", 200000);
    	set("smartnpc_busy",1);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
        
    	auto_npc_setup("wang",200,250,0,"/obj/weapon/","fighter_w","demon-strike",2);
    	setup();
    	carry_object(__DIR__"obj/duoyi2")->wear();

}
