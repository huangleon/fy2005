// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("Ҷ����", ({ "ye xiuzhu","ye" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIG"��Ӣ����֮"NOR );
        set("long","һ���������������Ů��խխ���·��ĵ����������Ӹ�����ȶ��ˡ�\n"
                );
        set("attitude", "peaceful");
        set("age", 22);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
               "Ҷ�³�" : "���Ƴ����ĵ����󣬼��ӵ���С�����Ƕ������� ���ˣ���Ҳû���Ӵ��ġ�\n",
               "master ye" : "���Ƴ����ĵ����󣬼��ӵ���С�����Ƕ������� ���ˣ���Ҳû���Ӵ��ġ�\n",
                 "���Ŵ�ѩ"  :"����ʦ����Щ���ӻлк��������Ǻ������Ѫɱ�֡���\n",
                 "master ximen"  :"����ʦ����Щ���ӻлк��������Ǻ������Ѫɱ�֡���\n",
        ])                      );
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ����޺޵���ʦ�����ǣ���ʮ���˶���ɽ������СС���Ƶ����ɡ���\n",
                }) );
		auto_npc_setup("wang",60,100,0,"/obj/weapon/","fighter_w","nine-moon-sword",1);   
		delete_temp("nine-moon-force_poison");     
        setup();
        carry_object(__DIR__"obj/emeisword2")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
}
