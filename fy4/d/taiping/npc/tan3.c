#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("̷�챪",({"tan tianbao","tan"}));
    	set("title",YEL"̷�������� ����"NOR);
    	set("long", "
̷�������쵱Ȼ��̷��Ҳ�����ǲ����Ǳ���̷�ȵĵ�ϵ�����������Լ�Ҫ��ô˵��
��û���˸һ��ɣ�Ҳû���˷��ϡ�ƴ��ʮ�������������˴�С���ٶ��ԡѪ��ս��
��̷�������족ȷʵ���ڽ���������վס�˽ţ����Ƶ����ǵ��ˣ�������ѱ���
��һ����������\n");

	set("age",40);
	set("combat_exp", 7500000);
	set("class","swordsman");        	
	set("attitude","friendly");
		
	set("reward_npc",5);
	
	set("death_msg",CYN"\n$N˵���ϴ��Ϊ�ұ���ġ������������� \n"NOR);		   
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"̷�챪˵�����㻹�ǿ���ɣ��ϴ������޶��������ˡ���\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps+lingxi",1);
		
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object(__DIR__"obj/lan_cloth3")->wear();
	if (!random(20)) carry_object(__DIR__"obj/redstone");
}



	
	