// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
int do_pfm();

void create()
{
        string *name = ({"��","��","��","ȥ","��","��","��","��","��","��","��","λ"});
        set_name("Բ"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("class","shaolin");
        set("age",random(20)+ 32);
		create_family("������", 22, "����");
        set("long", "���������µĺ���\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+100000);
        set("attitude", "friendly");
        set("shaolin_blade",1);
        set("npc_team","shaolin_blade");
        
        set("inquiry", ([
        	"ʩ��":		"��ʮ�����ӣ����ֹ۹�һ���Σ�������\n",
        	"���":		"��ʮ�����ӣ����ֹ۹�һ���Σ�������\n",
        	"��ɽ��":	"��ʮ�����ӣ����ֹ۹�һ���Σ�������\n",
        ]));	
        
        set_skill("blade", 60+random(100));
        set_skill("dodge", 60+random(60));
        set_skill("puti-steps",60);
		set_skill("dabei-strike",60);
		set_skill("lianxin-blade",random(100)+50);
		set_skill("move",80);
		set_skill("force",200);
		set_skill("parry",80);
		map_skill("parry", "lianxin-blade");
		map_skill("unarmed","dabei-strike");
		map_skill("dodge","puti-steps");	
        map_skill("blade", "lianxin-blade");
        
      	set("chat_chance", 2);
        set("chat_msg", ({
                name()+"˵���������������������ʩ���Ƿ��ܹ�"YEL"ʩ��"NOR"Щ��\n",
        }) );
	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: do_pfm() :),
        }) );
        
        setup();
		carry_object(__DIR__"obj/monk22_cloth")->wear();
		carry_object(__DIR__"obj/jiblade")->wield();
}


int accept_object(object who, object ob)
{
            if( (int)ob->value() >= 2000 ) {
                say( name()+"���˵����е�"+ob->name()+"��΢Ц������������������������\n");
				say( name()+"˳�ֽ�"+ob->name()+"�����˻��С�\n");
                tell_object(who,name()+"���ĵ�˵�����Ų�̫���㣬�߱��Űɡ�\n");
                who->set_temp("shaolin", 1);
                return 1;
            } else {
				command("shake");
                return 0;
            }
        return 0;
} 

int do_pfm(){
	object *env, ob;
	
	int i;
	ob = this_object();
	env = all_inventory(environment(this_object()));
	for (i=0; i<sizeof(env);i++)
	{
		if (env[i]!= this_object() && env[i]->query("npc_team") == "shaolin_blade")
		{
			ob->ccommand("perform yipianlianxin with "+ env[i]->query("id")+" 2");
			return 1;
		}
	}
	return 1;
}
