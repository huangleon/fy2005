inherit SMART_NPC;
#include <ansi.h>

void create()
{
    	set_name("�˺�����", ({ "master ren", "ren","master"}) );
    	set("nickname", HIW "�˶����"NOR);
    	set("title","�������");
    	set("gender", "����" );
    	set("group", "demon");
        set("vendetta_mark","demon");
    	set("reward_npc", 1);
		set("difficulty", 2);
    	set("age", 62);
    	set("per", 3);
    
    	set("attitude","friendly");
    
    	set("long", "�˺���������������еĵ�λ�ǽ����ڵ������˵ģ�\n"
        	    "�˺�����ͳ������������е��˶档\n");
    
   		set("combat_exp", 7300000);
    	set("score", 200000);
    	set("smartnpc_busy",1);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
        
    	auto_npc_setup("wang",200,250,0,"/obj/weapon/","fighter_w","demon-strike",2);
    	setup();
    	carry_object(__DIR__"obj/duoyi3")->wear();

}
