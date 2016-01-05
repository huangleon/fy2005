#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ÔÆ×ä", ({ "fengyun garrison", "garrison" }) );
        set("long","
ÕâÊÇ¸öÕıÔÚÖ´ĞĞÊØ³ÇÈÎÎñµÄÔÆ×ä£¬ËäÈ»ºÍĞí¶àÎäÁÖÈËÎï±ÈÆğÀ´£¬ÔÆ×äÃÇµÄ
Îä¹¦ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓĞ×éÖ¯¡¢ÓĞ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕĞÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕĞÈÇËûÃÇ¡£ [32m\n");
        set("attitude", "heroism");
	set("class", "shaolin");
        set("vendetta_mark", "authority");
        set("cor", 40);
        set("combat_exp", 5000000+random(2000000));
        
        set("max_kee",30000);
        set("max_sen",30000);
        set("max_gin",30000);
        set("boss",1);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "ÔÆ×äºÈµÀ£º»¹²»¿ì·ÅÏÂÎäÆ÷ÊøÊÖ¾Í¸¿£¿\n",
                "ÔÆ×äºÈµÀ£º´óµ¨µóÃñ¾¹¸Ò¾Ü²¶£¿·´ÁË£¡·´ÁË£¡\n",
		(: perform_action, "spear.suomengchanhun" :),
        }) );
        
        set_skill("unarmed", 300);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("duanhun-spear",200);
	set_skill("move",500);
	set_skill("puti-steps",200);
	set_skill("changquan",200);

	map_skill("spear","duanhun-spear");
	map_skill("parry","duanhun-spear");
	map_skill("move","puti-steps");
	map_skill("dodge","puti-steps");
	
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}

void init() {
	object ob;
	::init();
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_killing", "kill");
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) {
		return;
	}
	switch( random(10)){
		case 0:
			say("ÔÆ×äÉÏÉÏÏÂÏÂµØ´òÁ¿ÄãÒ»·¬£¬ÓÖºÍÇ½ÉÏÌûµÄ¹Ù¸®Í¨µı¶ÔÁË¶Ô£¬µÍÉùàÖ¹¾µÀ£ººÃÏó¾ÍÊÇÁË£®\n");
			break;
		case 1:
			say("ÔÆ×ä¿´ÁËÄãÒ»ÑÛ£¬µÍÉùàÖ¹¾µÀ£º°¦£¬ÓÖÊÇÒ»¸ö½­ºşÈËÎï£®\n");
			break;
		case 2:
			say("ÔÆ×äÏòÄãºÈµÀ£ºÕ¾×¡£¡°ÑÁ³¸øÎÒÌ§ÆğÀ´£¡\n");
			break;
	}
}

int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
		return notify_fail("ÕâÀïÃ»ÓĞÕâ¸öÈË¡£\n");
    if(living(victim))
    {
       	if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N¶ÔÖø$nºÈµÀ£º´óµ¨¿ñÍ½,¾¹¸ÒÔÚÄÖÊĞÉ±ÈË,»¹²»¿ì¿ìÊøÊÖ¾Í¸¿!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 100000 ) {
                        say("ÔÆ×äºÇºÇµÄĞ¦µÀ£ººÃËµ£¬ºÃËµ¡£¡£¡£¡£\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        this_object()->command("follow none");
                        return 1;
                } else {
                    say("ÔÆ×äËµµÀ£ºÕâµãÇ®»¹²»¹»´óÒ¯ºÈ¾ÆµÄÄØ£¡\n");
                        return 0;
                }
        return 0;
} 

