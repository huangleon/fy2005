// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("������", ({ "sun xiuqin","sun" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIR"��Ӣ����֮"NOR );
        set("long",
"���˴�Լ��һ���彣��������ȥ����Ӣ��������������ü��\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
                "Ҷ�³�" : "Ҷ�����ķ��ɽ�������ж�������֮����ʦ��Ҳ�����������\n",
                "master ye" : "Ҷ�����ķ��ɽ�������ж�������֮����ʦ��Ҳ�����������\n",
                  "���Ŵ�ѩ" :"�������Ź����ܷ�Ӯ����Ҷ���������Ͻ�֮ս�����˹һ�����\n",
                  "master ximen" :"�������Ź����ܷ�Ӯ����Ҷ���������Ͻ�֮ս�����˹һ�����\n",
        ])                      );
        set("chat_chance", 1);
        set("chat_msg", ({
                "������üͷ΢�壬�������������紵ɢ�ĳ�������\n",
                }) );

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(6) :),
     	}) ); 		

		auto_npc_setup("wang",80,60,0,"/obj/weapon/","fighter_w","diesword",1);               
        setup();

        carry_object(__DIR__"obj/emeisword3")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}


