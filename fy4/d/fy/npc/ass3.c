// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("¶À±ÛÈË", ({ "one-armed man","man" }) );
        set("gender", "ÄÐÐÔ" );
		set("class","swordsman");

		set("age",35);
		set("annie/duxin",1);

        set("long","ÕâÈËÉí²ÄËäÊÝÈçÖñ¸Í£¬¼ç°òÈ´¿íµÃ³öÆæ¡£±³ºóÐ±±³ÖøÒ»¸ùºÚ\nÖñ¸Í£¬°ÑÒ»¶¥ÆÆ¾ÉµÄÖñóÒµÍµÍµÄÑ¹ÔÚÃ¼ÏÂ£¬Ö»Â¶³ö×ó±ß°ëÖ»\nÑÛ¾¦¡£\n");

        set("combat_exp", 1200000);


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: ccommand("perform muyufeihong") :),
             }) );
        set_skill("sword", 200);
        set_skill("softsword", 150);
        map_skill("sword", "softsword");


		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(BLK"ºÚÖñ¸Í"NOR, ({ "bamboo stick","stick" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("ÆÆ¶·óÒ", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();
}
