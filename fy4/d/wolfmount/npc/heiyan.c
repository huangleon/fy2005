#include <ansi.h>
inherit NPC;

void create()
{
    set_name("������", ({"heiyan wolf","heiyan"}) );
        set("gender", "����" );
        set("nickname", HIB"ҹ��"NOR);
        set("long", "���¡���Ь���ڽ����棬��ҹɫ���۾������������ɫ�Ĺ⡣��\n");
 	set("attitude", "friendly");
/*	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000); */
    set("age", 35);
    	set("agi", 10);
        set("combat_exp", 1000000);
    set_temp("apply/damage", 50);
    set_temp("apply/armor", 50);

        create_family("��ɽ", 1, "���Ĵ�����");
        set_skill("staff", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set("chat_chance", 1);
        set("chat_msg", ({
        "���������쳤������ɽ�书�����£�ҹ���书����ɽ��\n",
        }) );

        setup();
        carry_object(__DIR__"obj/langyabang")->wield();
        carry_object(__DIR__"obj/blkcloth")->wear();
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
	if( !ob || environment(ob) != environment() )
		return;
	if (ob->query("class") != "wolfmount")
	{
        	message_vision("$N����Ŀ����㣺��������ɽ����û�л����ˡ���\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}