#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("��Ƽ��",({"tie pinggu","pinggu"}));
	set("age",18);
	set("gender","Ů��");
	set("long", "
һ��ʮ�߰������Ů����Ȼ����ũ�����Σ�ȴ�ڲ�ס����֮ɫ�����ǣ�
�����۽��ܴ��ŵ����İ��ˡ�\n");

	set("attitude", "friendly");
	set("combat_exp", 2000000);
	set("group","pinggu");		
	set("inquiry", ([
   		"�����": "�������ҵ����ҵ����Һܺã���������µ�̩ɽȥ�ˡ�",   		
   		"����": "�������ҵ����ҵ����Һܺã���������µ�̩ɽȥ�ˡ�",   
   	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
        	"��Ƽ��˵����������ҵ����ͽ�����ؼҰɡ���\n",
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("guardian",150,150,1,"/obj/weapon/","fighter_w","three-sword",1);
	
	setup();
	carry_object(__DIR__"obj/pgcloth")->wear();
	
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
	if (REWARD_D->riddle_check(ob,"С����ҽ")==1) {
		message_vision(CYN"$N˵��лл����˺�֩�룬������ת���㣬�˵������Ļ��ϲ⣬
Ψ��ҽ������������ʽ�������"YEL"����"CYN"��\n"NOR, this_object(),ob);
      		REWARD_D->riddle_set(ob,"С����ҽ",2);
    }
    return;
}
