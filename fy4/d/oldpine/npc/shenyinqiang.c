#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name( "����ǹ", ({ "shen yinqiang", "shen" }) );
		set("long", "�ھ������ġ�������ǹ����һ�����룬һ�ֳ�һ������ɫ�ĳ�ǹ��\n");
		set("attitude", "friendly");
		set("title", HIY "������ǹ"NOR);
		set("age", 57);
        set("gender", "����" );
		set("per", 60);
		set("combat_exp", 2900000);
		set("class","fugui");
        set("reward_npc", 1);
		set("difficulty", 3);
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear3",1);
		setup();
        carry_object("obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/silver_spear")->wield();
//        add_money("gold", random(5));
}
