#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Ѫ��", ({"xueshou"}) );
        set("gender", "����" );
        set("nickname", HIR"������"NOR);
        set("long", "����һ����Ѫ�������׺ݲ��̵�ʳ���ǵ��ӡ�\n");
 	set("attitude", "friendly");
/*	set("max_gin", 600);
	set("max_kee", 600);
	set("max_sen", 600);  */
	set("age", 20+random(10));

        set("combat_exp", random(500000)+600000);

        create_family("��ɽ", 4, "����");
        set_skill("blade", 70+random(10));
        set_skill("parry", 70+random(10));
        set_skill("dodge", 70+random(10));
        set_skill("move", 70+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
		"Ѫ���������촽���ü��춼û�Ե����ʵ������ˣ�\n",
        }) );

        setup();
     	carry_object(__DIR__"obj/pifeng")->wear();
	carry_object(__DIR__"obj/wolfblade")->wield(); 
        add_money("silver", random(5));
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
	if (!ob || environment(ob)!= environment(this_object()))	return;
	if(ob->query("class") != "wolfmount")
	{
		message_vision("$N���ſ�ˮ���������һ����գ�һ������������ζ�϶����ɽС���\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
      	}
      	return;
}
