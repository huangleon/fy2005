// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "dashi", "heshang" }));
        set("gender", "����" );
        set("class", "bonze");
		set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);
        
        set("long", "�����˹��������������������ֱ���ʦ\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("unarmed",100);
        set_skill("dabei-strike",100);
        set_skill("nodust-steps",80);
        set_skill("parry",100);
        set_skill("dodge",100);
        
        map_skill("dodge","nodust-steps");
        map_skill("unarmed","dabei-strike");
                
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}


int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}
