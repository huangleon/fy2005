inherit NPC;
void call_for_help();

void create()
{
        set_name("С���", ({ "xiao louluo","louluo" }) );
        set("gender", "����");
        set("age", 26);
        set("long",
                "һ�����ö��ӿ���կ�ŵĶ�����ǿ������\n");
        set("combat_exp", 420000);
        set("no_arrest",1);
        set("score", 80);
        set("max_kee",3000000);
        set("kee",3000000);
        set("max_sen",1000000);
        set("sen",1000000);
        set("max_gin",1000000);
        set("gin",1000000);
	set("cor",30);
	set("str",60);
	set("con", 30);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                "\nС���ƲƲ���������������ǿ����������������֪����������е�Ҫ���ġ���\n",
                "\nС������ﲻͣ�ص���������\n",
                
        }) );
        set_skill("blade", 90);
	set_skill("unarmed",80);
        set_skill("parry", 100);
        set_skill("dodge", 100);
	set_skill("demon-blade",70);
	map_skill("blade","demon-blade");
        setup();
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object me)
{
        command("say ����������Ұ��");
        command("kao");
        kill_ob(me);
        return 1;
}

int accept_object(object me, object obj)
{
        if(obj->query("id")=="meat")
	{
		me->set_temp("yuehu",1);
		say( "С���˫�۷Ź⣬���¼һ������ʳ������������������\n");
		return 1;
	}
	else 
	{
		command("shake");
       		return 0;
        }
	return 0;
}
