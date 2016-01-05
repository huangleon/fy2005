#include <ansi.h>
inherit MAZE_NPC;

void create()
{
//      string *name = ({HIC"ÇàÁú"NOR,HIW"°×»¢"NOR,HIR"ÖìÈ¸"NOR,HIB"ÐþÎä"NOR});
	string *name = ({"ÇàÁú","°×»¢","ÖìÈ¸","ÐþÎä"});
        set_name(name[random(sizeof(name))], ({"jinqian assassin","assassin"}) );

       set("gender", "ÄÐÐÔ" );
        set("title","½ðÇ®°ï "HIB"ËÄÉ±ÊÖÖ®"NOR);
        set("age", 30+random(30));
	set("class","assassin");
        set("long", "½ðÇ®°ïËÄ´óÉ±ÊÖÖ®Ò»¡£\n");
        set("maze","jq3");
        set("combat_exp", 6200000);

        set("attitude", "aggressive");
        
        set("experience",200);
	set("potential",65);
	set("money",200);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"ºÈµÀ£ºÊ²Ã´ÈË¸ÒË½´³»Æ½ðËþ£¡\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","random","random",1);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}