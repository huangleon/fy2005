// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����С��" , ({ "girl", "qing yi" }) );
	set("long", "һλʮ�����Ѿͷ������æµ�š�\n");
	set("attitude", "friendly");
	set("class","shenshui");
	set_skill("unarmed",10);
	set_skill("nine-moon-claw",10);
	map_skill("unarmed","nine-moon-claw");
	set("age", 15);
        set("gender", "Ů��" );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(100));
	set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.weiwoduzun" :),
        }) );
	
	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
