#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("��������ʿ", ({ "guard"}) );
        set("gender", "����" );
        set("title","��Ǯ�� ");
        set("age", 22);
        set("maze","jq1");
        set("target_name","������");
        set("class","official");
	set("long", "
��������ʿ������������߼���Ľ�����������Ϲٽ����ѡ���ĳ������֮
���������ֵ׹���Ҫ�ݣ�Ϊ��ҲҪ���ݲ��С�\n");
        
        set("combat_exp", 900000);
               
        set("attitude", "aggressive");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������ʿ��Ц����˽�����ý���������\n",
        }) );
	
		set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	       	(: perform_action("spear.zonghengtianxia") :),    
        }) );
	
		auto_npc_setup("liaoyin",100,120,1,"/obj/weapon/","fighter_w","yue-spear",1);
		delete_skill("iron-cloth");
		setup();
		carry_object("/d/fy/npc/obj/tangfu")->wear();  
    	
}