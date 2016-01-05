inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("½£³Õ" , ({ "jian chi","jian" }) );
    	set("long", "Òò½£¶ø³Õ£¬Îª½£¶ø³Õ¡£\n");
		set("attitude", "friendly");
    	set("age", 62);
        set("gender", "ÄÐÐÔ" );
        create_family("°×ÔÆ³Ç",1, "½£¿Í");
    	set("per",4);
    	set("combat_exp", 4000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(80) :),
	     		CYN"½£³ÕÉµÐ¦µÀ£ººÇºÇºÇºÇ¡­¡­¹þ¹þ¹þ¹þ¡­¡­à¸ºôºôºô¡­¡­°¡ºÙºÙºÙ¡­¡­\n"NOR,
        }) );


		set("chat_chance", 1);
        set("chat_msg", ({
        	"½£³ÕÉµÐ¦µÀ£ººÇºÇºÇºÇ¡­¡­¹þ¹þ¹þ¹þ¡­¡­\n",
        	"½£³ÕÉµÐ¦µÀ£ºà¸ºôºôºô¡­¡­°¡ºÙºÙºÙ¡­¡­\n",
        
        }) );
    	auto_npc_setup("ouyang",200,180,0,"/obj/weapon/","fighter_w","feixian-sword",1);


		setup();
        carry_object(__DIR__"obj/mayi")->wear();
        carry_object(__DIR__"obj/chengyin")->wield();
}



/*
 
               (\~~~/)            
               ( £®£®)        

               (_____)~£®      
   
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 10.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/
