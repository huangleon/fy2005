inherit MAZE_NPC;
#include <ansi.h>

void create()
{
	set_name("��ϲŮ����", ({ "huanxi bodhisattva", "bodhisattva","pusa" }) );
	set("gender", "Ů��" );
	set("title", HIR"��ϲ�� Ů����"NOR);
        set("age", 39);
	
        set("long","
���ֱ�Ͳ����ˣ�����һ��ɽ����ɽ�����۾�����С������ȴ�����ϵķ��⼷��
��һ���ߣ������ӱ���Ҳ�����̣�����ȴ�ѱ�һ�����ķ��������ˡ� \n"
		);
	set("inquiry", ([
		"����": "�������ϼһ�ߣ�����һ�컶ϲ�̻�һͳ�ر���\n",
	]) );
        set("combat_exp", 8000000);

        set("attitude", "aggressive");
        set("zombie-killer",1);
        
        set("experience",250);
	set("potential",60);
	set("money",250);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽���ƽ�����\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("liaoyin",300,250,1,"/obj/weapon/","fighter_w","kwan-yin-spells",2);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}