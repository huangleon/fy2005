inherit SMART_NPC;
#include <ansi.h>

void create()
{
	object armor;
	set_name("�۴�ʦ", ({ "hui dashi","hui"}) );
	set("gender", "Ů��" );
	set("title",HIW"��������"NOR);
	set("nickname",HIR"С����"NOR);
	set("age", 370+random(10));
	set("class","lama");        
	set("long",		"һ����������֮ɫ�����ᡣ\n");
	set("class","shaolin");
        set("combat_exp", 10000000);
        set("score", random(90000));
        set("reward_npc", 1);
	set("difficulty",10);
	
	set("attitude","friendly");
	
	set("fly_target",1);
	
	set("no_busy",8);
	
	set("chat_chance", 1);
    set("chat_msg", ({
                "�۴�ʦ��Ȼ��˫��һ�裬�߳����������徵ġ�ڵĦ�񲽡�����ʮ��
�ֲ���ʩ�꣬����һ�Σ�������ʮ�ɡ�\n",
                }) );
        
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","huidashi",1);
    setup();
    armor=new("/obj/armor/cloth");
	armor->set_name("˿֯�ĵ���",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}

