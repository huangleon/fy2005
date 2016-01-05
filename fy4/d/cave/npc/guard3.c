#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��������", ({ "prison guard", "guard" }) );
        set("long", "�������������д��εĽ������䡣\n");
        set("title","������ ����");
        set("attitude", "heroism");

	set("class","wudang");
        set("combat_exp", 2000000);

        set("chat_chance", 2);

        set("chat_msg", ({
        "��������̾�˿�������ʮָ���ģ���Ȼ�����ϻ��������ܵ�ס��ʮָ����֮�̡�����\n",
        }) );



        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("dragonstrike",150);
        set_skill("taiji-sword",150);
        set_skill("five-steps",140);
        
        map_skill("sword","taiji-sword");
        map_skill("parry","taiji-sword");
        map_skill("unarmed","dragonstrike");
        map_skill("dodge","five-steps");
        setup();

        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{   
	string where, location;
	if( !interactive(ob) || environment(ob) != environment() )
		return;
	if (!ob->query("vendetta/authority") ){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
   	return;
}