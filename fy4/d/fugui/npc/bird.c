inherit NPC;

void create()
{
    set_name("Ğ¡Ï²Èµ", ({ "bird" }) );
	set("race", "·ÉÇİ");
	set("age", 1);
    	set("long", "Ò»Ö»ÏóÕ÷ĞÒ¸£¼ªÏéµÄĞ¡Ï²Èµ£¬ß´ß´ÔûÔû²»Í£µØ½Ğ¡£\n");
	set("combat_exp",10000);

	set("chat_chance", 1);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"ßÒßÒ¡£\n",
		"ÔûÔû¡£\n",
	}));
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	setup();
}
