#include <ansi.h>
inherit MAZE_NPC;

void create()
{
//      string *name = ({HIC"����"NOR,HIW"�׻�"NOR,HIR"��ȸ"NOR,HIB"����"NOR});
	string *name = ({"����","�׻�","��ȸ","����"});
        set_name(name[random(sizeof(name))], ({"jinqian assassin","assassin"}) );

       set("gender", "����" );
        set("title","��Ǯ�� "HIB"��ɱ��֮"NOR);
        set("age", 30+random(30));
	set("class","assassin");
        set("long", "��Ǯ���Ĵ�ɱ��֮һ��\n");
        set("maze","jq3");
        set("combat_exp", 6200000);

        set("attitude", "aggressive");
        
        set("experience",200);
	set("potential",65);
	set("money",200);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽���ƽ�����\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","random","random",1);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}