#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("��ҹ��",({"sky yaksa", "yaksa"}));
    	set("title",BLU"ҹ���Ĵ�֮ "NOR);
    	set("long", "����������ͥ�Ķ��񣬲�֪Ϊ�γ�����������صĶ����С�\n");
	set("age",40);
	set("combat_exp", 1200000);
	
	set("attitude","aggressive");
	set("env/invisibility", 1);
	
	set("sq_guard",1);
	
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	
	auto_npc_setup("wang",100,120,1,"/obj/weapon/","fighter_w","fengbo-fork",1);
		
	setup();
	carry_object("/obj/armor/ghost_cloth")->wear();

}
