// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("ʯ����", ({ "shi xiuyun","shi" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIM"��Ӣ����֮"NOR );
        set("long","һ������ȥ���ľ���Ů���ӣ��ƺ�ʲô�¶������죬ʲô�˶�����̧��ȥ����\n"
                );
        set("attitude", "peaceful");
        set("age", 22);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
                "Ҷ�³�" : "Ŷ��Ҷ�����Ľ�����������µ�һô����֪�������ű���ô����\n",
                "master ye" : "Ŷ��Ҷ�����Ľ�����������µ�һô����֪�������ű���ô����\n",
                  "���Ŵ�ѩ" :"�������ƺ�����������Ѫ�һ��\n",
                  "master ximen" :"�������ƺ�����������Ѫ�һ��\n",
                  "����¥" : "�ţ���ϣ�����ټ�������������\n",
                  "hua manlou" : "�ţ���ϣ�����ټ�������������\n",
        ])                      );

        set("chat_chance", 1);
        set("chat_msg", ({
                "ʯ�������ĵ�������������Ҳ�ڣ����ж�ð���\n",
                }) );

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",80,80,0,"/obj/weapon/","fighter_w","siqi-sword",1);        
        setup();

        carry_object(__DIR__"obj/emeisword4")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt4")->wear();
}
