// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("������", ({ "ma xiuzhen","ma" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIC"��Ӣ����֮"NOR );
        set("long","��ĺܸߣ�ϸϸ������һ˫���ۣ���Ц��ʱ��·�Ҳ�����ֱ��˵�ɱ����\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
                "Ҷ�³�" : "�ߣ�ʲôһ��������������ɣ��ҿ�Ҳ������ˣ����������ʦ�������˼ң�\n�����������ó����µ�һ������ͷ��\n",
                "master ye" : "�ߣ�ʲôһ��������������ɣ��ҿ�Ҳ������ˣ����������ʦ�������˼ң�\n�����������ó����µ�һ������ͷ��\n",
                  "���Ŵ�ѩ" :" �����Ѫħͷ��ɱ����ʦ������Ӣ����Ѫ�����һ��Ҫ����\n",
                  "master ximen" : "�����Ѫħͷ��ɱ����ʦ������Ӣ����Ѫ�����һ��Ҫ����\n",
        ])                      );
        
        set("chat_chance", 1);
        set("chat_msg", ({
            "�����������������ۣ���м�������Ƶ�Ҳ������ˡ�\n",
        }) );

		auto_npc_setup("wang",70,100,0,"/obj/weapon/","fighter_w","qingfeng-sword",1);        
        delete_skill("spring-watter");
        delete_skill("iron-cloth");
        setup();

        carry_object(__DIR__"obj/emeisword1")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}
