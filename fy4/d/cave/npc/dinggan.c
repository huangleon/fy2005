#include <ansi.h>
inherit SMART_NPC;

void create()
{
    set_name("����", ({"ding gan","ding"}) );
    set("gender", "����" );
    set("nickname", CYN"������"NOR);
    set("title", "������ �̿�");
    set("long", "һ���ܸߴ���ˣ��ߴ����Щӷ�ף���һ˫��ȴ���ɵúܣ�˭�ֻ�֪��
��˫���ɵ��־�����˲Ϣ֮��˺��������ʺ���\n");
 		set("class","wolfmount");
 		set("attitude", "friendly");
    	set("age", 35);
    	set("per", 11);
    	
    	set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 3000000);
        
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        		(: auto_smart_fight(20) :),    
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"��������ϸϸ������ָ�ף�Ŀ��ͻȻ¶��һ�ֲп��Ц�ݡ�\n",
        }) );

        setup();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
        auto_npc_setup("guardian",150,150,0,"/obj/weapon/","fighter_w","wolf-strike",1);
        carry_object(__DIR__"obj/xiuzhiblade");
        carry_object("obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/waternut");
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
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	if (!ob->query("vendetta/authority")){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}
