inherit NPC;
#include <ansi.h>

void create()
{
	set_name("������", ({ "killer c","killer" }) );
	set("title",HIC"����ɱ��"NOR);
	set("gender", "����" );
	set("age", 42);
	set("long",
		"���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
		set("attitude", "friendly");
		set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("class","official");
        set("cave_killer",1);
        
		set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: ccommand("perform zonghengtianxia") :),
        }) );

		set_skill("flame-strike",120);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("spear", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("manjianghong", 100);
		set_skill("yue-spear",120);
		set_skill("puti-steps",160);
 
        map_skill("force", "manjianghong");
        map_skill("spear","yue-spear");
        map_skill("dodge","puti-steps");
        map_skill("parry","yue-spear");
        map_skill("move","puti-steps");
        map_skill("unarmed","flame-strike");

		setup();
	
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/spear")->wield();
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

void die(){
	environment()->set("cave_mine",time());
	::die();
}
