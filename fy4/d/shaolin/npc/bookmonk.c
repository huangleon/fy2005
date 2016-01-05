// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("����", ({ "shaolin monk", "monk"}) );
        set("long", "���������´�����ר�������ر��ĺ��С�\n");
        set("gender", "����" );
        set("age",random(20)+ 32);
        
	create_family("������", 23, "����");
        
	set("vendetta_mark","shaolin");
        set("class","shaolin");
        set("combat_exp", 120000);
        
        set("attitude", "friendly");
             	
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"Ц������˵�ĳ��ϼ���ǰ��Ȼ��С��ɵ�����Ѱ����ѹ�˻�����\n",
        }) );
        
	set_skill("unarmed", 100);
	set_skill("dabei-strike",random(10)+70);
	set_skill("dodge",60);
	set_skill("puti-steps",60);
	set_skill("move",40);
	set_skill("force",20);
	
	map_skill("dodge","puti-steps");
	map_skill("unarmed", "dabei-strike");
        
        set("chat_chance_combat", 10);
		set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        
        set("vendor_goods", ([
                BOOKS"literate_50a" : 10,
        ]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
	{ add_action("do_vendor_list","list");}


void reset()
{
	set("vendor_goods", ([
		BOOKS"literate_50a" : 10,
	]) );
}
