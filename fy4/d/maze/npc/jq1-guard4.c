#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name(HIY"��������"NOR, ({ "jinqian tiewei","tiewei"}) );
        set("gender", "����" );
        set("title","��Ǯ�� ");
        set("age", 22);
        set("class","official");
	set("long", "
���������ǽ�Ǯ�����ý�����������Ϲٽ����ѡ���ĳ������֮����
�����ֵ׹���Ҫ�ݣ�Ϊ��ҲҪ���ݲ��С�\n");
        
        set("combat_exp", 2000000);
                    
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������ȵ���ʲô�ˣ�\n",
        }) );
	
		set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	       	(: perform_action("spear.zonghengtianxia") :),    
        }) );
	
		auto_npc_setup("liaoyin",150,150,1,"/obj/weapon/","fighter_w","yue-spear",1);
		delete_skill("iron-cloth");
		setup();
		carry_object("/d/fy/npc/obj/tangfu")->wear();  
    	
}