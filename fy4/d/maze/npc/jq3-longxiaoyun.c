#include <ansi.h>
inherit MAZE_NPC;

void create()
{
    	set_name("��Х��",({"long xiaoyun","long"}));
	set("title",HIR"������"NOR);
        set("nickname",HIY"����ׯ��"NOR);
        set("long",WHT"
��Х�Ʊ���������˭���뵽���ֻ��ˣ�׼ȷ��˵���ǻ��ˣ�ֻ�Ǵӵ����б�
�ٻ��������ѡ�\n"NOR);
     	set("gender","����");
        set("combat_exp", 8000000);
	set("boss",1);
	
        set("attitude", "aggressive");
        set("zombie-killer",1);
        
        set("experience",1000);
	set("potential",1000);
	set("money",2000);
	set("toughness",300);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽���ƽ�����\n",
        }) );

	set("officer-killer",1);		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("liaoyin",350,200,0,"/obj/weapon/","fighter_w","taiji",2);

	setup();
    	carry_object("/obj/armor/ghost_cloth")->wear();     
}