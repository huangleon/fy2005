#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("������", ({ "eagle gulina", "gulina","eagle" }) );
        set("long", "�ϳ��ӥ�����ȣ���ɽ��һɱ�֡�\n");
	set("nickname",HIY "�ϳ��ӥ"NOR);
        set("attitude", "heroism");
//        set("vendetta_mark", "authority");
//	set("vendetta_mark","pker");

	set("reward_npc", 1);
	set("difficulty", 25);
	set("combat_exp", 8000000);

        set("gender", "Ů��");
               
        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :)
        }) );
        
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	        
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","mapo",2);
        setup();
        carry_object(__DIR__"obj/kacloth",([	"name": "������˿Ͳȹ",
    						"long": "һ��������˿Ͳȹ��\n",
    						"value": 2,
    						 ]))->wear();    
}