inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name(HIC"������ʿ"NOR, ({ "silver soldier","soldier"}) );
	set("title",RED"��������"NOR);
	set("gender", "����" );
	set("age", 30+random(20));
	set("long",
		"�ɰ˵ĺ��ӣ��ֳ���ꪣ������ں�ձ���ԣ��ƹ�ӳ��ꪣ����������⡣\n");
	set("combat_exp", 3500000);
    set("class","fugui");
    
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) ); 		

	auto_npc_setup("wang",180,200,0,"/obj/weapon/","fighter_w","xuezhan-spear",1);
	setup();
	carry_object(__DIR__"obj/s_armor")->wear();
    carry_object(__DIR__"obj/s_spear")->wield();
}
