#include <ansi.h>

inherit NPC;
// inherit PURSURER;

void create()
{
        set_name("·ç±ø", ({ "fengyun garrison", "garrison" }) );
        set("long","
ÕâÊÇ¸öÕýÔÚÖ´ÐÐÊØ³ÇÈÎÎñµÄ·ç±ø£¬ËäÈ»ºÍÐí¶àÎäÁÖÈËÎï±ÈÆðÀ´£¬·ç±øÃÇµÄ
Îä¹¦ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓÐ×éÖ¯¡¢ÓÐ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕÐÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕÐÈÇËûÃÇ¡£ [32m\n");

        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "authority");
        set("combat_exp", 1000000+random(2000000));
        
        set("max_kee",30000);
        set("max_sen",30000);
        set("max_gin",30000);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "·ç±øºÈµÀ£º»¹²»¿ì·ÅÏÂÎäÆ÷ÊøÊÖ¾Í¸¿£¿\n",
                "·ç±øºÈµÀ£º´óµ¨µóÃñ¾¹¸Ò¾Ü²¶£¿·´ÁË£¡·´ÁË£¡\n",
                (: perform_action, "spear.suomengchanhun" :),
        }) );

        set_skill("unarmed", 150);
        set_skill("spear", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("duanhun-spear",160);
	set_skill("move",500);
	set_skill("puti-steps",150);
	set_skill("changquan",200);

	map_skill("spear","duanhun-spear");
	map_skill("parry","duanhun-spear");
	map_skill("move","puti-steps");
	map_skill("dodge","puti-steps");

        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

	set("resistance/kee",99);
	set("resistance/gin",99);
	set("resistance/sen",99);
	
        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 100000 ) {
                        say("·ç±øºÇºÇµÄÐ¦µÀ£ººÃËµ£¬ºÃËµ...\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        this_object()->command("follow none");
                        return 1;
                } else {
                    say("·ç±øËµµÀ£ºÕâµãÇ®»¹²»¹»´óÒ¯ºÈ¾ÆµÄÄØ£¡\n");
                        return 0;
                }
        return 0;
} 

int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
		return notify_fail("ÕâÀïÃ»ÓÐÕâ¸öÈË¡£\n");
    if(living(victim))
    {
       	if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N¶ÔÖø$nºÈµÀ£º´óµ¨¿ñÍ½,¾¹¸ÒÔÚÄÖÊÐÉ±ÈË,»¹²»¿ì¿ìÊøÊÖ¾Í¸¿!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}


void init()
{	
	::init();
//	add_action("do_killing", "kill");

}


int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

