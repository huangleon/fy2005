#include <ansi.h>
inherit NPC;

void create()
{
		set_name("Ѫͷ��", ({"xue toutuo","toutuo"}) );
        set("gender", "����" );
        set("nickname", HIR"������"NOR);
        set("long", "һ�����������Ǹ��ź��ʱ��Ұ���ˣ�����ƺ�������δ�ɵ�Ѫ����\n");
 		set("attitude", "friendly");

		set("age", 20+random(10));

        set("combat_exp", 800000);

        create_family("��ɽ", 4, "����");
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set_skill("lianxin-blade",100);
        set_skill("xueyeqianzong",100);
        
        map_skill("parry","lianxin-blade");
        map_skill("dodge","xueyeqianzong");
        map_skill("blade","lianxin-blade");
        
        set("chat_chance", 1);
        set("chat_msg", ({
			"Ѫͷ���������촽���ü��춼û�Ե����ʵ������ˣ�\n",
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
	else
	{
        	message_vision("$N����Ц�������ϵܣ�û��ʲô����Т��үү����\n",this_object());
			return;
	}
      	return;
}