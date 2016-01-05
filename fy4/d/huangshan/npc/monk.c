// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�չ�", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(10)+ 32);
        set("long", "���������³��⻯ի�ĺ��У����֮��������������ʿ�����ֵľ��ס�
��ʮ�����ӿɻ����ʮ��Թ����һ���ƽ�ɻ�������Թ����\n");
        create_family("������", 23, "����");
        set("combat_exp", random(10000)+10000);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
			"�չ⳪�˸���ŵ������ʩ�������������࣬������Ǯ�ɣ���\n",
        }) );    
        set_skill("unarmed", 5+random(40));
		set_skill("dabei-strike",random(40)+5);
		map_skill("unarmed","dabei-strike");
		set_skill("move",40);
		set_skill("force",20);
	
		set("NO_KILL","�չ�˵��ʩ����ô���������ˣ��������ա�\n");
		setup();

		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/bowl");
}



int accept_object(object who, object ob)
{
		int num;
		num=who->query("vendetta/shaolin");
		if( ob->value() >= 10000
			||(ob->value() >= 1000 && num<=20)) {
                        command( "say �������գ�������������ͷ�ǰ�...");
                        command( "say ƶɮ��Ϊʩ��ÿ�շ���һ�����о�����\n");
                        who->set("vendetta/shaolin", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                    	command("say ʩ���������أ�������ǡ�����\n");
                        return 0;
                }
        return 0;
} 
