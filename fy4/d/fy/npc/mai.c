// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("��ֻ�", ({ "mai jiahuo","mai" }) );
		// MARK' collection
        set("gender", "����" );
        set("age", 31);
        set("title", CYN"��ٰ���"NOR);
        set("long","��λ�ϰ��������мֻ������߼���һ��̯��̯����\n����̯�ϴ�����ȱ����ϣ��Źֵ����⣬ֻ�Ǽ۸�����է�ࡣ\n������ˣ���Ը�Ϲ��������Ȼ�ܶ࣬��˼ֻ�̯���������ﲻ����\n");
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([  
                __DIR__"obj/sp_rabbitmeat"    : 40,
//                __DIR__"obj/sp_pic"           : 40,
                __DIR__"obj/sp_leaf"          : 40,
                __DIR__"obj/sp_ting"          : 40,
                __DIR__"obj/sp_needlebag"     : 40,
                __DIR__"obj/sp_wine"		  : 40,
                __DIR__"obj/sp_map"			  : 40,
                __DIR__"obj/sp_conch"			  : 40,
//                __DIR__"obj/sp_carpet"		  : 40,
        ]) );
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set("inquiry", ([
                "�ٻ�" : "action��ֻ�ɴ���������ҡͷ��������������ֻ���������ٻ���",
               "���ٻ�" : "action��ֻ�ɴ���������ҡͷ��������������ֻ���������ٻ���",
        ]));
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		
		// ż��֪�����ֵط��ϰ�������ߺ��˵>"<

        return;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/sp_rabbitmeat"    : 40,
//                __DIR__"obj/sp_pic"           : 40,
                __DIR__"obj/sp_leaf"          : 40,
                __DIR__"obj/sp_ting"          : 40,
                __DIR__"obj/sp_needlebag"     : 40,
//                __DIR__"obj/sp_carpet"		  : 40,
                __DIR__"obj/sp_map"			  : 40,
                __DIR__"obj/sp_wine"		  : 40,
                __DIR__"obj/sp_conch"			  : 40,
        ]) );
}

