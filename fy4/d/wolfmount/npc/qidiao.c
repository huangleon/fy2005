#include <ansi.h>
inherit NPC;

void create()
{
    set_name("���ս", ({"qidiao zhan","qidiao"}) );
        set("gender", "����" );
        set("nickname", HIY"ս��"NOR);
        set("long", "����һλ�뺷���ͣ�����η����ս�ǵ��ӡ�\n");
 	set("attitude", "friendly");
/*	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500); */
	set("age", 18+random(10));

        set("combat_exp", random(200000)+300000);
        create_family("��ɽ", 1, "���Ĵ�����");
        set_skill("blade", 100+random(20));
        set_skill("parry", 100+random(20));
        set_skill("dodge", 100+random(20));
        set_skill("move", 100+random(20));
        set("chat_chance", 2);
        set("chat_msg", ({
        "���սӭ��������������裺�����˽������Ƕ����롣����\n",
        }) );

        setup();
     	carry_object(__DIR__"obj/pifeng")->wear();
	carry_object(__DIR__"obj/wolfblade")->wield();  
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

void win_enemy(object loser)
{
	command("laugh");
    message_vision("$N����$nҡҡͷ�������������ֻ������죬������Ц�����Ӵ����ˣ�\n", this_object(), loser);
	return;
}

void lose_enemy( object winner )
{
	command("admire");
    message_vision("$N����$n�ļ��������������Ǵ����ս����϶�һ����ʡ�\n", this_object(), winner);
}

int accept_fight(object me)
{
	command("say ��ѽ����ѽ�������������أ�\n");
	return 1;
}

void greeting(object ob)
{   
	if (random(100)>30)
	{	
        message_vision("$N������ļ�����û������������������ɽ���ȸ��ұȻ��Ȼ��ɡ�\n", this_object() );
      		return;
      	}
      	else if(ob->query("class")=="wolfmount")
      	{
            message_vision("$Nһ�������˷ܵ�ֱ���£��������˸����еİ�����\n", this_object() );
      		command("fight "+ob->query("id"));
		return;
	}
	return;
}
