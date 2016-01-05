#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ÊØ±¸Ê¿±ø", ({ "wulapo garrison", "garrison" }) );
        set("title","ÎÚÀ­²´");
        set("long","
ÕâÊÇ¸öÕıÔÚÖ´ĞĞÊØ³ÇÈÎÎñµÄÖµÇÚ±ø£¬ËäÈ»ºÍĞí¶àÎäÁÖÈËÎï±ÈÆğÀ´£¬ÖµÇÚ±øÃÇµÄ
Îä¹¦ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓĞ×éÖ¯¡¢ÓĞ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕĞÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕĞÈÇËûÃÇ¡£ [32m\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("cor", 40);
        set("combat_exp", 5000000+random(2000000));
        
        set("max_kee",30000);
        set("max_sen",30000);
        set("max_gin",30000);
        set("boss",1);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "ÖµÇÚ±øºÈµÀ£º»¹²»¿ì·ÅÏÂÎäÆ÷ÊøÊÖ¾Í¸¿£¿\n",
                "ÖµÇÚ±øºÈµÀ£º´óµ¨µóÃñ¾¹¸Ò¾Ü²¶£¿·´ÁË£¡·´ÁË£¡\n",
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

        setup();
        carry_object(AREA_FYWALL"npc/obj/longdagger")->wield();
        carry_object(AREA_FYWALL"npc/obj/kiujia")->wear();
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


