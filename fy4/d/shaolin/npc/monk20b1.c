
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("׳�����", ({ "shaolin monk", "monk"}) );
        create_family("������", 18, "����");
        set("gender", "����" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
		set("nickname",HIG"����ɮ"NOR);
        set("long", "���������»��µ�ɮ�ˡ�\n");
		set("vendetta_mark","shaolin");
        
        set("combat_exp", 5200000);
        set("attitude", "friendly");
                       
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"���������ļ�ʦ���ڴ���ڣ����˲������ڡ�\n"
        }) );
	
		set("group", "shaolin");
		
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(40) :),
	     }) ); 		
	
		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fumostaff",1);
		setup();
		carry_object(__DIR__"obj/monk20b_cloth")->wear();
		carry_object(__DIR__"obj/stick")->wield();
}
