inherit SMART_NPC;
void create()
{
        set_name("��Ѫ�̿�", ({ "hitman", "man" }) );
        set("gender", "����");
        set("age", 34+random(20));
        set("long","����һ����Ŀ����Ĵ̿ͣ�����\n" ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        
        set("chat_chance", 10);
        set("chat_msg", ({
                "�̿��������ô������ ��ؿ�Ҫ��ͷ�������ˣ�\n",
		(: random_move :)
        }) );
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
               (: random_move :), 
               (: auto_smart_fight(99) :),
        }) );

        set("arrive_msg", "��ಣ���һ�����˹���");
        set("leave_msg", "��ಣ���һ������ʧ��");
        
        auto_npc_setup("wang",100,150,0,"/obj/weapon/","fighter_w","lefthand-sword",1);
        setup();
	carry_object(__DIR__"obj/kcloth")->wear();
	carry_object(__DIR__"obj/ksword")->wield();
}

void init()
{
        remove_call_out("hunting");
        call_out("hunting",1);
}

void hunting()

{
 	object tar;
	if(objectp(tar=present("master ximen",environment())))
	{
		command("say �����ű�½С�����ˣ��������ֽ�����ɱ���㣬���Ϳ��Ժ�������
���������ˣ���������\n");
		kill_ob(tar);
	}

}
