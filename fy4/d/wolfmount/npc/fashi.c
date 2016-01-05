#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("��ʦ", ({"da fashi","fashi"}) );
        set("gender", "����" );
  	set("class", "taoist");
        set("nickname", HIR"ʳ������"NOR);
        set("long", "
һ��̬�Ⱥ���������ˣ����Ŷ�Բ���Ķ�ǩ��һ��Ѫ������ĳ���
���أ�ѩ�׵ĺ���ʹ���������������𾴡�\n");

 	set("attitude", "friendly");
 	set("reward_npc", 1);
	set("difficulty", 10);
        set("combat_exp", random(800000)+2500000);
        
	set("fly_target",1);
	set("age", 54);

        set("chat_chance", 1);
        set("chat_msg", ({
        	"��ʦ�ٺ�Ц����С������ⲻ���óԣ������̲��úܡ�\n",
        }) );
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	
    	auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","necromancy",1);
        setup();
        carry_object(BOOKS"cursism_50")->wear();
        carry_object(__DIR__"obj/hat")->wear();
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
	if (ob->query("gender") == "Ů��")
	{
		message_vision("$N���ſ�ˮ������$n����ϸƤ����ģ��ظ�һ���ܺóԡ���\n", this_object(),ob );
		kill_ob(ob);
	}
	return;
}
