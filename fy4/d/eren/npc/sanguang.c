#include <ansi.h>
inherit SMART_NPC;
inherit F_PAWNOWNER;
inherit INQUIRY_MSG;

void create()
{
	set_name("��ԯ����",({"san guang","san","guang"}));
	set("title",YEL"��⣬�ع⣬��Ҳ��"NOR);
	set("long", "
һ���ɰ˵ĺ������ڹ�̨�����Ŀ�������ȸ������ϡ���˫�����������
���滹�����˺����׵�ë�����ֱ��ϥ�ǡ�\n");
	set("age",40);
	set("gender","����");
	set("combat_exp", 7500000);

	set("reward_npc",10);
		
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("guardian",250,200,0,"/obj/weapon","fighter_w","shadowsteps+lingxi",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/armor/sandal",([	"name": "�Ʋ�Ь",
					"long": "һ˫�Ʋ�Ь��\n",
					 ]))->wear();    
}

void init()
{	
	::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");

}