inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("�廨��Ů��", ({ "sewing girl" }) );
        set("gender", "Ů��");
        set("age", 25);
        set("long","һ����ˮ������Ů,��������������ǰ�廨��\n"); 
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 2);
        
        set("combat_exp", 3000000);  
              
        set("chat_chance_combat",100);     
        set("chat_msg_combat", ({
		     	(: auto_smart_fight(30) :),
     	}) ); 		

		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object(__DIR__"obj/n_stone")->wield();
		carry_object("/obj/armor/cloth")->wear();
}
