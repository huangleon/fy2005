#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

	set_name("���´�",({"white cloth man","man"}));
    	set("title",WHT"���ׯ"NOR);
    	set("long", "
���´�һ���Ƶƣ�һ���յ���׷Ѳ��ׯ�ڡ�ѩ�׵�����֮����Ѫ�߲�������ƻ�
ӳ������������Ѫ�⡣���ǵ���ͫ�������Ѫ�������������ƺ�����δ����\n");
	set("age",40);
	set("combat_exp", 8000000);
        	
	set_skill("iron-cloth",150);
	set_skill("xisui",100);
	map_skill("iron-cloth","xisui");
	
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
	
	
	auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","smallguy",1);
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
}
