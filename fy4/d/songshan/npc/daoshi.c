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
        set("long", "���ǳ縣����С��ʿ������æ�š�\n");
        set("combat_exp", 12000);
        set("attitude", "friendly");
                
        set("chat_chance", 10);
        set("chat_msg", ({
                "С��ʿ�����̾�˿����������幬��ʲô�˲���ģ��Ҿ����������Ҳ��ȥ��\n",
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

