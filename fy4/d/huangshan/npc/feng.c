// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;

void create()
{
        set_name("������", ({ "feng siniang", "feng"}) );
        set("gender", "Ů��" );
        set("age",32);
        set("long", "
��ϲ�����ָ����Ĵ̼���ϲ��������������ߵ�ɽ���������Ĳˣ�
�����ҵľƣ��������ĵ���ɱ��ݵ��ˡ�\n");
        set("combat_exp", random(100000)+200000);

	set_skill("move",70);
	set_skill("unarmed",250);
	set_skill("force",50);
	set_skill("dodge",200);
	set_skill("liuquan-steps",100);
        set_skill("yunwu-strike",100);
        
        map_skill("unarmed","yunwu-strike");
        map_skill("dodge","liuquan-steps");

       	set("chat_chance_combat",50);
       	set("chat_msg_combat",({
                      (:perform_action,"unarmed.miwu":),
	}));
        
        set("chat_chance", 1);
        set("chat_msg", ({
"������գ����Ц����ʧ��ʧ������Ǹ��Ǹ���ұ�������Ϊ�������������أ�\n",
        
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

