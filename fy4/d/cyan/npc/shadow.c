// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("����֦Ҷ�еĺ�Ӱ", ({ "hidden shadow","shadow" }) );
        set("gender", "����" );

		set("age",47);

	set("chat_chance",2);
	set("chat_msg", ({
		"һ��ϤϤ������������������֪������֦Ҷ�еĺ�Ӱ�ڲ�Ūʲô��\n",
	}) );

        set("combat_exp", 4000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );

		set("death_msg",CYN"\n$N�鴤�˼��£�ֱͦͦ�ز����ˡ�\n"NOR);

		auto_npc_setup("ouyang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike-jg",1);
		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����İ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���Ƶİ���", ({ "cloth" }) );
		weapon->set("value",0);
    	
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
		write(MAG"��Ӱ����֦Ҷ֮�У���ʲôҲ�����塣"NOR"\n");
		return 1;
	}
	return 0;
}