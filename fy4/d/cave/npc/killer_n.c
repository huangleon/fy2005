inherit NPC;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();


void create()
{
	set_name("��ľ��", ({ "killer n","killer" }) );
	set("title",HIC"����ɱ��"NOR);
	set("gender", "����" );
	set("age", 42);
	set("long",
		"���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
	set("attitude", "friendly");
	set("combat_exp", 1600000);
    set("attitude", "friendly");
    set("class","legend");
    set("cave_killer",1);    
        
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",100);
	set_skill("shortsong-blade",100);
	set_skill("fall-steps",110);
	set_skill("move",200);
	set_skill("blade",150);
	set_skill("qidaoforce",150);
	
	map_skill("dodge","fall-steps");
	map_skill("move","fall-steps");
	map_skill("blade","shortsong-blade");
	map_skill("parry","shortsong-blade");
	map_skill("unarmed","qidaoforce");
	
	set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
      	(: ccommand("perform duangechangmeng") :),    
    }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/blade")->wield();
}

void die(){
	environment()->set("cave_mine",time());
	::die();
}


int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIW + name() + "һ�����ںڰ�����ʧ�ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
