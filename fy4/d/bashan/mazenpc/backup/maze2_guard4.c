#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("Ç¬´ïÆÅ²¿ÖÚ", ({ "disciple" }) );
	set("title",YEL"´ó¹âÃ÷½Ì"NOR);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("gender", "ÄÐÐÔ" );

		set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 6000000);

	set("death_msg",CYN"\n$NµÍÉùµÀ£ºÉúÒàºÎ»¶£¬ËÀÒàºÎ¾å£¿ÄªÈô¹éÈ¥£¬ÄªÈô¹éÈ¥¡­¡­\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","divineforce2",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("ÏÊºìÎ§ÒÂ", ({ "scarlet scarf","scarf" }) );
	weapon->set("long","ÏÊºìÎ§ÒÂ(Scarlet scarf)¡£\n");
	weapon->set("value",0);
	weapon->wear();

}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}

/*

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨X¨Y
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦©¦©¦
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨^¨k¨k¨k¨_

¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 08.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/
