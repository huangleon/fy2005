// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
int give_qin();

void create()
{
        set_name("�ƿ�", ({ "yunkong" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);

        set("long", "�����˹��������������������ֱ���ʦ��\n");
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        		        
		set_skill("kwan-yin-spells",130);
        set_skill("spells", 150);
        map_skill("spells","kwan-yin-spells");  
        
        set_skill("dabei-strike",200);
        set_skill("notracesnow",200);
        set_skill("unarmed", 200);
    	set_skill("force", 200);
    	set_skill("dodge", 200);
		set_skill("parry", 200);
		set_skill("lotusforce", 150);
		set_skill("dabei-strike",120);
		set_skill("move",200);
		set_skill("essencemagic",150);
		set_skill("magic",200);
	
		map_skill("magic","essencemagic");
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
	    map_skill("move","notracesnow");
	      
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ƿ�˵��������ѧ������\n",
        }) );
        set("inquiry", ([
		"����" : (: give_qin :),
		"jigu" : (: give_qin :),
	]));
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
		command("say ��ѷ������ȥ���ɣ���\n");
		obj = new(__DIR__"obj/fegu");
		obj->move(this_player());
		set("given",1);
        }
	else
		command("say �ҵķ���������ˣ�\n");
        return 1;
}

void reset()
{
	delete("given");
}
