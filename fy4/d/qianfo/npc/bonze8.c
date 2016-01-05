// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
int give_qin();
void create()
{
        set_name("�ƺ�", ({ "yunhai" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);

        set("long", "�����˹��������������������ֱ���ʦ��\n");
        set("combat_exp", 2300000);
        set("attitude", "friendly");
    
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ƺ�˵�����������������\n",
        }) );
        set("inquiry", ([
		"�������" : (: give_qin :),
		"fomen" : (: give_qin :),
		]));
                    
        set_skill("dabei-strike",200);
        set_skill("notracesnow",200);
        set_skill("unarmed", 200);
    	set_skill("force", 200);
    	set_skill("dodge", 200);
	    set_skill("parry", 120);
	    set_skill("lotusforce", 150);
	    set_skill("notracesnow",120);
	    set_skill("dabei-strike",120);
	    set_skill("move",120);
	    
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
	 
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );

        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}


int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}

int give_qin()
{
        object obj;
		if( !query("given"))
        {
			command("say �Ұﲻ����ܶ࣬���Ҳ��������˭����������������ȥ�ɣ�\n");
			obj = new(__DIR__"obj/shoe2");
			command("give shoes to "+this_player()->get_id());
			set("given",1);
	        }
		else
			command("say ��Ҳ�ﲻ���㣡\n");
        return 1;
}

void reset()
{
		delete("given");
}

