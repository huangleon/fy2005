#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("ׯ����" , ({ "guard" }) );
	set("long", "һ������ͨͨ�ĺ��ӣ��Ǹ������ɽׯѲ�Ӻͷ����ġ�\n");
	
	set("attitude", "friendly");
	set("title",WHT"����ɽׯ"NOR);
	set("age", 18+random(10));
        set("gender", "����" );
	set("group","baiyunzhuang");
	        
	set("combat_exp", 1500000+random(500000));
	
		set("chat_chance", 1);
    set("chat_msg", ({
        	"ׯ��������˵��ϲ�����Ͼ�Ҫ��ʼ�ˣ���ô���Ķӻ�û����\n",
        }) );
	
	set("inquiry", ([
             "ϲ��" : "�����Ǵ���ү��ϲ��֮�գ�ֻ�������Ĳ�����ϯ��\n",
             "���" : "�����Ǵ���ү��ϲ��֮�գ�ֻ�������Ĳ�����ϯ��\n",
             "feast": "�����Ǵ���ү��ϲ��֮�գ�ֻ�������Ĳ�����ϯ��\n",
             "wedding": "�����Ǵ���ү��ϲ��֮�գ�ֻ�������Ĳ�����ϯ��\n",
             "���Ķ�":	"��ү�صش��ڵ������ã������õ��˰ɣ��ǲ���·�ϳ���ʲô�¶���\n",
       	]));
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );

	
	auto_npc_setup("wang",150,150,1,"/obj/weapon/","fighter_w","fumostaff",1);

	setup();
   	carry_object("/obj/armor/cloth",([	"name": "��ɫ������",
    						"long": "����ɽׯ�Ҷ������·���\n",
    						 ]))->wear();    
}


	
	