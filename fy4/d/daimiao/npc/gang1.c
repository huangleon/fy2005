#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("������", ({ "wang ruogang","wang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "������������Ĵ���֮һ��\n");
        set("group", "demon");
        set("vendetta_mark","demon");
        set("combat_exp", 3500000);
        set("attitude", "friendly");
        
		set("title",YEL"������� ��������"NOR);

		set("smartnpc_busy", 1);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","renmo",1);
		set_skill("iron-cloth",150);
		set_skill("jin-gang",180);
		map_skill("iron-cloth","jin-gang");
    	setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  "���ַ�",
    						"long": "����������������ķ��Ρ�\n",
    						 ]))->wear();
        if (!random(4)) carry_object(__DIR__"obj/yaopai");
}

