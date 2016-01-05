// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"ÃÎÒÅ","ÃÎ»Ã","ÃÎÊ§","ÃÎ¶ª","ÃÎÃÂ","ÃÎ¶¼","ÃÎÏç",
"ÃÎ³õ","ÃÎ¿Õ","ÃÎÔ°", "ÃÎÁ÷"});
        
        set_name("ÃÎÁ÷", ({ "shaolin monk", "monk"}));
        
        create_family("ÉÙÁÖËÂ", 20, "µÜ×Ó");
        set("class","shaolin");
        set("gender", "ÄÐÐÔ" );
        set("age",random(20)+ 32);
		set("nickname","¹÷É®");
        set("long", "ÕâÊÇÉÙÁÖËÂµÄ¹÷É®¡£\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 40000);
        set("attitude", "friendly");
		set("stickguy",	1);
		set("cps",80);
        set_skill("staff", 40+random(100));
		set_skill("xingyi-stick",random(100)+20);
		set_skill("move",400);
		set_skill("force",200);
		set_skill("parry",40);
		
		map_skill("staff", "xingyi-stick");
		map_skill("parry","xingyi-stick");
		
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "staff.powerjam" :),
        }) );

		setup();
		carry_object(__DIR__"obj/monk23_cloth")->wear();
		carry_object(__DIR__"obj/stick")->wield();
}

