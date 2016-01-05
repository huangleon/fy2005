#include <ansi.h>
inherit MAZE_NPC;

void create()
{
//      string *name = ({HIC"����",HIY"����",HIR"����",HIG"����",CYN"����",YEL"����",GRN"ϲ��"});
	string *name = ({"����","����","����","����","����","����","ϲ��"});
        set_name(name[random(sizeof(name))]+"ʹ", ({"jinqian herald","herald"}) );

        set("gender", "����" );
        set("title","��Ǯ�� ��ʹ��֮");
        set("age", 30+random(30));
	set("class","assassin");
        set("long", "��Ǯ���ߴ󻤷�ʹ��֮һ��\n");
        
        set("combat_exp", 7800000);
	set("pursuer",1);
        set("attitude", "aggressive");
        set("maze","jq3");
        set("experience",160);
	set("potential",90);
	set("money",300);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽���ƽ�����\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","random","random",2);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}