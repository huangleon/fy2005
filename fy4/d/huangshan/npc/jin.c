// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "jin fenghuang", "jin"}) );
        set("gender", "Ů��" );
        set("age",32);
        set("long", "
����Ȼ�ѽ����꣬�������������ᣬһ˫������������������˭�����Կ���
��һ���Ǹ��ܲ����ǵ�Ů�ˡ�\n");
        
        create_family("��ɽ��", 5, "����");
	set("pursuer",1);
        set("combat_exp", random(200000)+100000);
        
        set_skill("sword", 100);
	set_skill("siqi-sword",80);
	set_skill("parry",100);
	set_skill("move",40);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40);
	set_skill("unarmed",100);
	set_skill("yunwu-strike",80);
	
	map_skill("unarmed","yunwu-strike");
	map_skill("sword", "siqi-sword");
	map_skill("parry", "siqi-sword");
	map_skill("dodge","liuquan-steps");
        
        set("chat_chance", 5);
        set("chat_msg", ({
		"������Ц����ʧ��ʧ������Ǹ��Ǹ���ұ�������Ϊ����һ�����˾�ҧ�ķ蹷��\n",
        }) );
        
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
        }) );
        
	setup();
	carry_object(__DIR__"obj/cuiyi")->wear();
	carry_object(__DIR__"obj/bijian")->wield();
}


int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

