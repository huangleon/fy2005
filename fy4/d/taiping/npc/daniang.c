#include <ansi.h>
// RIDDLE NPC, shouldn't be in Questlist.

#include <command.h>
inherit SMART_NPC;

void create()
{

		set_name("�����",({"li daniang","daniang","li"}));
    	set("long", "
����Ц���紺�����ţ������紺ݺ��ת����ı����ҵ�Ů�˸���������òҲ
������Ѫū���Ǻ��������ˣ���δ��������ȡ�������������������
�ѷ������֡�\n");
		set("age",47);
		set("combat_exp", 10000000);
        set("attitude", "friendly");	
	
		set("reward_npc",20);

		set("group","lidaniang");
	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
		auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","diesword",2);
		setup();
		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/lisword")->wield();
}


/*
void init() {
	
	object ob;
	::init();
	add_action("do_answer","answer");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	call_out("ask_question_1",1,ob);

}
*/

void die() {
	object me, ob, owner;
	ob=this_object();	
	message_vision(HIR"\n$N��Ȼ����һ��������Ц����ʮ����ħʮ��Ѫ��ħ�����ڣ����ǲ������ġ�\n"NOR,ob);
	message_vision(HIR"$N��Ȼ���ˣ������˶��������֮������֮������������ձڡ�$Nת��
������㲻�ٳ��֡�\n"NOR,ob);
	destruct(ob);
}

