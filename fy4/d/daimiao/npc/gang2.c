#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("���Ƹ�", ({ "zhang sigang","zhang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "������������Ĵ���֮һ��\n");
        set("group", "demon");
        set("vendetta_mark","demon");
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        
		set("title",YEL"������� Ǭ������"NOR);

		
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        set("smartnpc_busy", 1);
    	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","dimo",1);
	set_skill("iron-cloth",150);
	set_skill("jin-gang",180);
	map_skill("iron-cloth","jin-gang");
    	setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  "Ǭ�ַ�",
    						"long": "�������Ǭ�������ķ��Ρ�\n",
    						 ]))->wear();
        if (!random(3)) carry_object(__DIR__"obj/yaopai");
}