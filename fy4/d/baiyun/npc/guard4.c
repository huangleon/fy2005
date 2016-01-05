// XXDER@FY3
inherit SMART_NPC;

void create()
{
    set_name("Ò¶áç" , ({ "swords man","man" }) );
    set("long", "Ò»¸ö°×ÒÂÆ®Æ®£¬Ó¢Æø²ª·¢µÄ°×ÔÆ³Ç½£Ê¿¡£¡£\n");
	set("attitude", "friendly");
    set("age", 19);
        set("gender", "ÄĞĞÔ" );
        create_family("°×ÔÆ³Ç", 2, "½£Ê¿");
    set("combat_exp", 200000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",80,60,1,"/obj/weapon/","fighter_w","feixian-sword",1);
	setup();
    carry_object("/obj/armor/cloth")->wear();
}
