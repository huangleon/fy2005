#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("��ѩ����", ({ "prisoner"}) );
        set("gender", "Ů��" );
        set("title",WHT"��ʬ����"NOR);
        set("age", 52);
	set("class","assassin");
        set("long", "
������ʱ�����ǻ��ǽ�����ͷ�ɶϡ�Ѫ������־����û�����ӣ����ǵ�����
�������ĥ��ҩ��Ķ������Ѿ������Ǳ����û����־��û����а����Ѫ���ˡ�\n");
        set("maze","jq2");
        set("combat_exp", 3600000);
		if (!random(10))	set("attitude", "aggressive");
        
		set("target_name","��ʬ����");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"˻�Ƶغ�����������������\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(15) :),    
        }) );
	
	auto_npc_setup("liaoyin",200,150,1,"/obj/weapon/","fighter_w","diesword",1);
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "�ƾɲ���������",
						"long": "һ���ƾɲ��������£��Ѿ�������ԭ������ɫ���ʵ��ˡ�\n",
					 ]))->wear();    
}
