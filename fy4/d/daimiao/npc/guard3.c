#include <ansi.h>
inherit SMART_NPC;
void restrict_move();
 
void create()
{
        set_name("��Ȯ����", ({ "huangquan dizi", "dizi"}) );
        set("title",WHT"������� "NOR);
        set("gender", "����" );
        set("group", "demon");
        set("age", 22);
        set("long", "
������̸��ֽ���������������ϣ��Ľ�գ�����ͭ�����廤����
�ְַ׸롢���ǡ���Ȯ�������ֶ档����Ȯ������׷�٣������ǡ�
����ɱ�����׸롱�����񣬾��Ǹ����̽���ݸ�·����Ϣ��\n");
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
		set("chat_chance", 1);
		set("chat_msg", ({
			"��Ȯ���Ӿ���ز쿴�����ܵĶ�����\n",
			(: random_move :)
		}) );
		
		setup();
		auto_npc_setup("wang",200,150,1,"/obj/weapon/","fighter_w","fumostaff",1);
		carry_object("/obj/armor/cloth",([	
	   				"name":  "��ɫ�̷�",
    				"long": "������̽��ڵķ��Ρ�\n",
    	]))->wear();
}
