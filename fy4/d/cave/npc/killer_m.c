inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��ˮ�", ({ "killer m","killer" }) );
	set("title",HIC"����ɱ��"NOR);
	set("gender", "����" );
	set("age", 42);
	set("long",
		"���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
	set("attitude", "friendly");
	set("combat_exp", 1600000);
    set("attitude", "friendly");
    set("class","bonze");
    set("cave_killer",1);
        
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("cloudstaff",130);
	set_skill("iron-cloth",200);
	set_skill("move",200);
	set_skill("blade",150);
	set_skill("bloodystrike",150);
	set_skill("staff",150);
	
	map_skill("iron-cloth","jin-gang");
	map_skill("staff","cloudstaff");
	map_skill("parry","cloudstaff");
	map_skill("unarmed","bloodystrike");
	
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: ccommand("perform longxianyuye") :),    
        }) );

	setup();
	
	carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/staff")->wield();
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

