#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("½ôÄÇÂÞ²¿ÖÚ", ({ "disciple" }) );
	set("title",YEL"´ó¹âÃ÷½Ì"NOR);
	set("gender", "ÄÐÐÔ" );
	set("nickname",HIR"†† °È Âï ßä ßè"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(40) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$NµÍÉùµÀ£ºÉúÒàºÎ»¶£¬ËÀÒàºÎ¾å£¿ÄªÈô¹éÈ¥£¬ÄªÈô¹éÈ¥¡­¡­\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_u","kwan-yin-spells",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("ÂÞººôÂôÄ", ({ "monk cloth","cloth" }) );
	weapon->set("long","Ò»¼þ»æÓÐ¾ÅÌìÄ§ÏñµÄÆæÒìôÂôÄ¡£\n");
	weapon->set("value",0);
	weapon->wear();

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
