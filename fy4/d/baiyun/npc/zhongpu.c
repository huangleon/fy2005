#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("���ٸ�", ({ "liu zhongpu","liu" }) );
        set("gender", "����" );
        set("title","�������");
        set("nickname",HIY"������������"NOR);
        set("age", 42);
        set("long", "��ʱ�������ҵ�һ�����֣��ഫ����ɽ��һ������������һ�ٶ�ʮ�ţ�
��ɱ�ô�ܣ���ʱŻѪ������\n");
        set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        	"���ٸ���ü��չ�����˿��������ף���ҡ��ҡͷ����̾�˿�����\n",
        }) );
        set("attitude", "friendly");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object(AREA_RESORT"npc/obj/wqi");
        carry_object("/d/fugui/npc/obj/m_cloth2")->wear();
}


int accept_fight(object me)
{
        command("say �𡣡�����֮�ˣ��ο����š�\n");
        return 0;
}