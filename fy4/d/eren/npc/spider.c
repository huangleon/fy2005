#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("��֩��",({"spiderman"}));
	
	set("long", "
һ�������С�ĺ����ˣ�����ȫ��һ����������Ľ����·�������ס��
һ����Ҳ������ڵ���ߣ�ֻʣ��һ˫�ڰ׷��������ӣ��ڵĵط����ᣬ
�׵ĵط���ѩ��\n");

	set("age",25);
	set("combat_exp", 3300000);
	
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );

	auto_npc_setup("guardian",200,180,1,"/obj/weapon/","fighter_w","lefthand-sword",1);
	
	setup();
	carry_object(__DIR__"obj/darkcloth")->wear();
}



