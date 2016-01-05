#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ÓÄÔ¹¸¾ÈË", ({ "sad woman","woman" }) );
        set("gender", "Å®ÐÔ" );
        set("long",
                "Ò»¸ö³îÃ¼¿àÁ³£¬ÓôÓô¹Ñ»¶µÄ¸¾ÈË¡£\n"
                );
        set("title", WHT"ÌìÑÄ¹ÂÂÃ"NOR);
        set("attitude", "peaceful");
    	set("age", 25);
        set("per", 20);
        set("combat_exp", 1200000);
        
        set_temp("apply/damage", 50);

        set("chat_chance", 1);
        set("chat_msg", ({
                "ÓÄÔ¹¸¾ÈËà«à«Ò÷µÀ£ºÖª·ñ,Öª·ñ£¬Ó¦ÊÇÂÌ·ÊºìÊÝ£¡\n",
                }) );

        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
    	set_skill("doomstrike", 100);
    	set_skill("doomsteps", 100);
    	
    	map_skill("unarmed", "doomstrike");
    	map_skill("dodge", "doomsteps");
        
        
        setup();
        carry_object("/d/qianfo/npc/obj/lady_dress")->wear();
}

