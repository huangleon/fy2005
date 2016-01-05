// mind_beast.c

inherit NPC;

void create()
{
	set_name("°×¶îÃÍ»¢", ({ "tiger", "big tiger" }) );
	set("race", "Ò°ÊŞ");
	set("gender", "ĞÛĞÔ");
	set("age", 20);
	set("long", "ÕâÊÇÒ»Ö»Ğ×ÃÍÎŞ±ÈµÄ°×¶îÃÍ»¢¡£\n");
	
	set("attitude", "aggressive");

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "°×¶îÃÍ»¢ÃÍµØÏòÄãÒ»ÆË£¡\n",
                "°×¶îÃÍ»¢ºİºİµØÓÃÎ²°ÍÏòÄãÉ¨À´£¡\n"
        }) );

	set("combat_exp", 800000);
	set("bellicosity", 3000 );
	set("agi", 10 );
	
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 20);

	setup();
}
