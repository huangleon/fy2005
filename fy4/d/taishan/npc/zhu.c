#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("��Ҷ��", ({ "zhuyeqing","zhu" }) );
        set("gender", "����");
        set("combat_exp", 4000000);
		set("age",47);
		set("long","��Ҷ����һ���ҾƵ����֣�����ȥ���������ܲ���ģ���Ҷ��Ҳ���ֶ��ߣ�����Ҫ����\n");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	(: auto_smart_fight(40) :),
		}) );
	
        setup();
		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","herb",1);
		carry_object("/obj/armor/cloth")->wear();
		carry_object("/obj/armor/bracelet",	([	"name": "������",
    						"long": "һֻ����ͨ������\n",
    						 ]))->wear(); 
}
