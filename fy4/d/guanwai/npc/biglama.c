inherit SMART_NPC;
#include <ansi.h>

void create()
{
	object armor;
	set_name(RED"�������"NOR, ({ "red lama"}) );
	set("gender", "����" );
	set("age", 40+random(10));
	set("int", 30);
	set("long","��̸�ɮ���ܸ���֮����������������ʧ��֮�¡�\n");
	set("class","lama");
        set("combat_exp", 2500000);
        set("score", 900);

	set("class","lama");        
    set("chat_chance", 1);
    set("chat_msg", ({
    	"���������Ȼ˵��������һ�ղ��鲼�����������Ǿ�һ�ղ��ܰ�˯��\n",
        (: random_move :),
    }) );
    	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",180,160,0,"/obj/weapon/","fighter_w","kwan-yin-spells",1);
	
	setup();
    armor=new(__DIR__"obj/redclothh");
	armor->set_name(RED"�����ߺ���"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}

