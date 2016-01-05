#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        string *name = ({BLU"��",MAG"��",HIR"��",HIG"��"});
        set_name(name[random(sizeof(name))]+"Ы��"NOR, ({"evil scorpion","scorpion"}) );

        set("maze","jq1");
        set("gender", "Ů��" );
        set("title", "��Ǯ�� Ů��");
        set("long", "
�����Ϲٽ��İ�Ů�Ϲ�С�ɵ�����Ů�£���Ȼֻ��Ů�ӣ��������׺ݶ�������
֮��ɫ���ˣ����������µĽ���������ʤ���������Ц���£�˭�ֻ��뵽��ɱ��
����Ѫ�Ĵ���Ů��\n");

 	set("attitude", "friendly");
	set("age", 18+random(10));
	
	set("target_name","Ы��");
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
     }) );
		
    set("combat_exp", 700000);
    setup();
	auto_npc_setup("liaoyin",100,140,1,"/obj/weapon/","fighter_w","nine-moon-sword",1);
	delete_temp("nine-moon-force_poison");
	carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
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
	object *inv;
	int i;
	if (!ob || environment(ob)!=environment(this_object()))	return;
		
	if ((string)ob->query("gender") == "����")
	{
        message_vision("$N������˿����$n����׷��۵���Ħ����������ӣ���߽�������ѽ���ҵ��㡣���þ��ˡ�����\n", this_object(),ob );
// here should add to cause ppl be poisoned, which not very lethom.
        if ((int)ob->query_cps()<random(25) && !ob->query_condition("no_shadow") ){
   			message_vision("$N����һ�������Ժ�����ֻ��������һ�飬��������������\n", ob);
   			ob->apply_condition("no_shadow",random(5)+5);
	  		return;
	  	}
	  	else
	  	{
	  		message_vision("$N��Цһ�������С�����������ң�\n", ob);
	  		return;
	  	}
	  }
	  return;
}

