// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("��ɽ��", ({ "climber" }) );
        set("gender", "����" );
        set("age", 52);
        set("long", "һ���۵ò����˵ĵ�ɽ�ߣ�����Ъ�ţ�\n");
        set("combat_exp", 2600);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object me)
{
        command("say ���ž��أ����ɷ�����\n");
        return 0;
}
