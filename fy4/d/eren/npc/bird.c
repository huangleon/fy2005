inherit NPC;

void create()
{
	set_name("°ÙÁéÄñ", ({ "bird" }) );
	set("race", "·ÉÇİ");
	set("age", 1);
	set("long", "ßÒßÒÔûÔûµÄÒ»Ö»Ğ¡°ÙÁéÄñ¡£\n");
	
	set("combat_exp",2000);
	set("chat_chance", 2);
	set("chat_msg", ({
		"ßÒßÒ¡£\n",
		"ÔûÔû¡£\n",
	}));
	
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	setup();
	carry_object(AREA_TIEFLAG"npc/obj/tongue",(["name":"°ÙÁéÄñÉà"]));
}
