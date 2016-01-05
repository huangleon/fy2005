// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *order=({"����", "ɨ��", "�շ�", "��ˮ", 
"����","����","����","�"});
        set_name((order[random(8)]) +"�ĺ���", ({ "monk", "heshang"}) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����˹����µĺ��У�����æ�š�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 5+random(100));
	set_skill("notracesnow",3);
	set_skill("dodge", 4);
	set_skill("force",4);
	map_skill("dodge","notracesnow");
        
        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :),
        }) );
	
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/needle");
	carry_object(__DIR__"obj/needle");
}

