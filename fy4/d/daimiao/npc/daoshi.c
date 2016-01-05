// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *order=({"�ϲ�", "ɨ��", "�շ�", "��ˮ", "����","����"});
        set_name((order[random(5)]) +"�ĵ�ʿ", ({ "daoshi", "dao"}) );
        set("gender", "����" );
        set("age", 22);
        set("long", "��������С��ʿ������æ�š�\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
		set_skill("dodge", 30);
		set_skill("force",30);
		set_skill("demon-steps",30);
		set_skill("taiji", 50);
		map_skill("unarmed","taiji");
		map_skill("dodge","demon-steps");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��ʿ����ĵ��˵����ϵĳ���������\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/boom");
        carry_object("/obj/armor/cloth",([	"name": "�ֲ�����",
    						"long": "һ���ֲ����ۡ�\n",
    						 ]))->wear();    
}

