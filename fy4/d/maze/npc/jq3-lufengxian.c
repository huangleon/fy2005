#include <ansi.h>
inherit MAZE_NPC;

void create()
{
    	set_name("������",({"lu fengxian","lu"}));
		set("title",HIR"������"NOR);
        set("nickname",HIC"����º�"NOR);
        set("long",WHT"���յ�����º����������ڵ�������ȴ�ƺ�����ǿ��\n"NOR);
     	set("gender","����");
    	set("class","fugui");
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
	
		auto_npc_setup("liaoyin",350,250,0,"/obj/weapon/","fighter_w","xuezhan-spear2",2);

		setup();
    	carry_object("/obj/armor/cloth")->wear();     
    	carry_object(__DIR__"obj/silver_spear")->wield();
}
