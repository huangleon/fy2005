// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"����","�λ�","��ʧ","�ζ�","����","�ζ�","����",
"�γ�","�ο�","��԰", "����"});
        
        set_name("����", ({ "shaolin monk", "monk"}));
        
        create_family("������", 20, "����");
        set("class","shaolin");
        set("gender", "����" );
        set("age",random(20)+ 32);
		set("nickname","��ɮ");
        set("long", "���������µĹ�ɮ��\n");
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

