inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("ִ����ʿ", ({ "soldier"}) );
	set("title","���ȹ�");
	set("gender", "����" );
	set("age", 30+random(20));
	set("long","ִ����������ʿ�������ɷһ�㣬�߶�ۣ�������ԭ���ϡ�\n");
	set("attitude", "friendly");
	set("combat_exp", 2500000);
	
        set("attitude", "friendly");
        set("class","fugui");
        set("group_1","guizi");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(40) :),
     	}) );
        
		auto_npc_setup("wang",160,200,0,"/obj/weapon/","fighter_w","xuezhan-spear2",1);
		setup();
		carry_object(__DIR__"obj/g_armor")->wear();
        carry_object(__DIR__"obj/g_spear")->wield();
}
