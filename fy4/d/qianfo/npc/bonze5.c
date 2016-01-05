// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SMART_NPC;
int give_qin();
void create()
{
        set_name("����", ({ "yunliu" }) );
        set("gender", "����" );
        set("class", "bonze");
		set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);

        set("long", "�����˹��������������������ֱ���ʦ��\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
               
        set_skill("dabei-strike",100);
        set_skill("notracesnow",100);
        set_skill("unarmed", 100);
    	set_skill("force", 100);
    	set_skill("dodge", 100);
	    set_skill("parry", 100);
	    set_skill("cloudstaff", 170);
	    set_skill("lotusforce", 150);
	    set_skill("notracesnow",120);
	    set_skill("dabei-strike",120);
	    set_skill("move",120);
	
	    map_skill("staff", "cloudstaff");
	    map_skill("parry", "cloudstaff");
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
	 
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        
                
        set("chat_chance", 1);
        set("chat_msg", ({
                "����������һ�ۣ�����ȫ�����¿���һ������
����ǧ��������������ģ���
����˵���Ϸ��Ĵ�ç����һ��ɽׯ����һ"YEL"����"NOR"�����ȥ����Ϊʦ����\n",
        }) );
        set("inquiry", ([
             "����" : "����˵Ҫ������ˣ������"YEL"����"NOR"����\n",
             "yiren" : "����˵Ҫ������ˣ������"YEL"����"NOR"����\n",
			 "����" :  (: give_qin :),
			 "tanqin" : (: give_qin :),
			 "qin" : (: give_qin :),
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
        object obj,ob;
		if(query("given")<2)
        {
			command("say ��ѹ�������ȥ���ɣ���\n");
			obj = new(__DIR__"obj/qin");
			if (!obj->move(this_player()))
				destruct(obj);
			add("given",1);
			set("give_to", this_player());
        }
		else
		{
			if (objectp(ob=query("give_to")))
				command("say �ҵĹ������͸�"+ob->query("name")+"�ˣ�\n");
			else
				command("say �������ˣ��ҵ����Ѿ������ˡ�\n");
		}
		return 1;
}


void reset()
{
		delete("given");
}

