inherit NPC;
#include <ansi.h>

void create()
{
	set_name("ص����", ({ "killer p","killer" }) );
	set("title",HIC"����ɱ��"NOR);
	set("gender", "����" );
	set("age", 42);
	set("long",
		"���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
	set("attitude", "friendly");
	set("combat_exp", 1600000);
    set("attitude", "friendly");
    set("class","wudang");
    set("cave_killer",1);
        
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("taiji-sword",150);
	set_skill("five-steps",150);
	set_skill("move",150);
	set_skill("sword",150);
	set_skill("taiji",150);
	
	map_skill("dodge","five-steps");
	map_skill("move","five-steps");
	map_skill("sword","taiji-sword");
	map_skill("parry","taiji-sword");
	map_skill("unarmed","taiji");
	
	setup();
	
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield();
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

