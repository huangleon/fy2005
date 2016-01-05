inherit NPC;

void create()
{
        set_name("л����", ({ "xie" }) );
        set("gender", "����");
        set("age", 28);
        set("long",
		"�䵱�ɵ��ӣ���һ���ɫ�ĵ��ۡ�\n"
	);
        set("combat_exp", 70000);
        
        set("score", 200);
        set("class", "wudang");

        create_family("�䵱��", 58, "����");

        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("taijiforce", 50);
        set_skill("taiji", 40);
        set_skill("three-sword", 50);
        set_skill("five-steps", 40);

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
             
        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/gongxiang");

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 50000 ) {
                        say("л���ڰ�Ǯ�Ž�����˵������������ˡ�\n");
                        who->set_temp("marks/͵��", 0);
                        return 1;
                } else {
                    say("л��������˵�������ǲ�����ڻ�¸�ģ�\n");
                        return 0;
                }
        return 0;
} 

 
