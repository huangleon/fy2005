#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("������", ({ "yellow sentry","sentry"}) );
        set("gender", "����" );
        set("title","��Ǯ�� ��ʿ");
        set("age", 22);
        set("maze","jq1");
        set("target_name","������");
	set("long", "
���˴�ͷ���Ŷ������˻�����ֻ���۾������������ף���ʱ��¶���׺ݷ���
��ɫ�����������ǽ�Ǯ���ϵ���ӣ������Ϲٽ��Ӹ��������������׼���֮
ͽ���书����������֪��\n");
        
        set("combat_exp", 900000);
        
        set("attitude", "aggressive");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ц����˽�����ý���������\n",
        }) );
	
		auto_npc_setup("liaoyin",100,120,1,"/obj/weapon/","fighter_w","smallguy",1);
		delete_skill("iron-cloth");
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "����",
					"long": "һ��������\n",
					 ]))->wear();    
    	
}