inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("�ֻ����Ϻ���", ({ "old monk", "monk" }) );
	set("nickname",HIW"һ����Ⱦ"NOR);
	set("gender", "����" );
	set("age", 62);
    set("vendetta_mark","shaolin");

	set("class","shaolin");
    set("long",
		"�����������ֻ�����ɮ����˵��������ز�¶�ĸ��֡�\n"
		);
    set("chat_chance", 1);
    set("chat_msg", ({
		(: random_move :)
    }) );
	set("combat_exp", 3500000);
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/ironfist")->wield();

}

