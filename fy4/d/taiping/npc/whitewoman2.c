#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

	set_name("���¸���",({"white cloth woman","woman"}));
    	set("title",WHT"���ׯ"NOR);
    	set("long", "
���¸��˵�����Ѳ��ᣬȴӦ���Ǿ��ϻ� �������ѻ��ţ������̴档���ǵ����
Ҳ���񻣬�ܶ��ˡ�\n");
	set("age",40);
	set("combat_exp", 8000000);
        set("gender","Ů��");	

		set("group","lidaniang");
			
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );

	
	auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","smallguy",1);
	set("gender","Ů��");	
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
}
