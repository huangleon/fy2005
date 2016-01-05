// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *name = ({"��","��","��","ǩ","��","��","��"});
        set_name("��"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
	create_family("������", 23, "����");
        set("long", "���������µĺ���\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000)+100000);
        set("attitude", "friendly");
        set_skill("unarmed", 60+random(10));
	set_skill("dabei-strike",random(10)+70);
	set_skill("move",40);
	set_skill("force",20);
	
	map_skill("unarmed", "dabei-strike");
        set("chat_chance", 20);
        set("chat_msg", ({
                name()+"����һ�鲼���˲����ӣ�\n",
		name()+"������һ�ۣ��������ˣ�����ʱ��չ���\n",
		name()+"��ͷһ��ɨ��һ�ߵ�������Ҳû�У���û��ʱ���أ�\n"
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );

	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}

