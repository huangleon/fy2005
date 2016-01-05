inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��ľ��", ({ "killer f","killer" }) );
	set("title",HIC"����ɱ��"NOR);
	set("gender", "����" );
	set("age", 42);
	set("long",
		"���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
	set("attitude", "friendly");
	set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","yinshi");
        set("cave_killer",1);
        
	set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: ccommand("perform tianleiyiji") :),
        }) );

	set_skill("flame-strike",120);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
		set_skill("whip",100);
		set_skill("thunderwhip",150);
		set_skill("zuixian-steps",160);
        set_skill("cursism", 100);

        map_skill("whip","thunderwhip");
        map_skill("dodge","zuixian-steps");
        map_skill("parry","thunderwhip");
        map_skill("move","zuixian-steps");
        map_skill("unarmed","flame-strike");

		setup();
	
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/whip")->wield();
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
