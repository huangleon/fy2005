#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("����", ({ "jin wei", "jin"}) );
        set("title",YEL"�������"NOR" �廤��֮ ");
        set("gender", "����" );
        set("age", 32);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("long", "
������̸��ֽ���������������ϣ��Ľ�գ�����ͭ�����廤����
����������������֮һ�Ľ�����������ΧѲ������\n");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������ȵ�������Ŀ����\n",
                "��������ȵ���վס����������ƣ� û���ƾ�����Ѫ��������\n",
        }) );
	
		setup();
		auto_npc_setup("wang",120,140,0,"/obj/weapon/","fighter_w","dragonwhip",4);
		carry_object(__DIR__"obj/blackrobe",([	
    						"name":  "������",
    						"long": "һ����ɫ�ĳ��ۣ���������һ�������֡�\n",
    						 ]))->wear();
		set_skill("moon-blade",70);

}

