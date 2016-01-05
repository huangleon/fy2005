#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("ÊÔÊÔ", ({"justdoit"}) );
        set("gender", "Å®ÐÔ" );
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
     	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

   
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("justdoit",300,220,1,"/obj/weapon/","random","random",5);
	setup();
}
/*
¨X[ ¡¡- FengYun -¡¡ ]©¨©¨©¨©¨¨[
©®[dancing_faery@hotmail.com]©À©¤©¤¨[
©®[ ¡¡annie 09.2003¡¡ ]©¨©¨©¨¨a    ©¦
©®[ ÀëÀëÂþÈÇÈýÇïÂ¶£¬ÂöÂöÊ±Äý¾ÅÔÂËª ©¦
¨^¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª-¨a
*/

/*
update /std/skill;update here;clone /d/bashan/npc/yawnboy;update /adm/daemons/smartd;update /std/char/npc_ann;update /d/bashan/npc/yawngirl3;clone;call sinny->ccommand(kill justdoit)
*/


