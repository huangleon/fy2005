#include <ansi.h>

inherit SMART_NPC;
void fight_now();

void create()
{

	set_name("����",({"fighter"}));
   	set("title",YEL"������ʮ����"NOR);
	set("long", "����̽��¥�������ÿ��˵Ļ���һ��������ɵվ�ű���ɱ��\n");
	set("age",30+random(20));
	set("group","trainer");
	set("combat_exp", 6500000);
		
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
			(: fight_now :),  	
    }) );
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void die() {
	command("say ���ˣ��̱����ˣ�");
	destruct(this_object());
}

void fight_now(){
	int num;
	num = query("fight_chance");
	auto_smart_fight(num);    
	return;
}

