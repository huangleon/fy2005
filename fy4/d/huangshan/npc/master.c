// taolord.c

inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name( "����Ϫ" , ({ "yu lanxi",  "yu" }) );
    	set("gender", "Ů��");
    	set("title", "�ɹ��� ����");
    	set("nickname", HIC"�չ��ľ�"NOR);
    	set("age", 46);
    	set("long", "һ��С���ֵ����֣�\n");
    	set("reward_npc", 1);
		set("difficulty", 5);

    	set("combat_exp", 6500000);
       	set("score", 200000);
    	set("class", "taoist");

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"����Ϫ����̾�˿������ƺ�˵���������ˡ���������\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",250,200,1,"/obj/weapon/","fighter_w","necromancy",1);
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "��������",
    						"long": "һ���������ۣ�ϴ���Ѿ���Щ�����ˡ�\n",
    						 ]))->wear();    
    	
}
