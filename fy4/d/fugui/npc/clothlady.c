#include <ansi.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("������", ({ "ji lingyan", "ji" }) );
        set("gender", "Ů��" );
        set("age", 18);
	set("title",WHT "������˫"NOR);
        set("long",
"���������羵�������볤�������裬һ�Ų԰׵������Լ�һ˫����
����ã���۾�������˫���������֣���������������˫�֣�����
�˷��Ƴ����������·���\n");
		set("combat_exp", 50000);
    	set("str", 20);
        set("attitude", "friendly");
		set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/m_cloth1":8,
                __DIR__"obj/g_gloves":8,
                __DIR__"obj/m_cloth2":10,
                __DIR__"obj/m_cloth3":10,
                __DIR__"obj/m_cloth4":10,
		__DIR__"obj/m_boots1":7,
		__DIR__"obj/m_boots2":8,
		__DIR__"obj/w_skirt1":8,
		__DIR__"obj/w_skirt2":8,
		__DIR__"obj/w_skirt3":8,
		__DIR__"obj/w_skirt4":10,
		__DIR__"obj/w_girth1":10,
		__DIR__"obj/w_girth2":10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void reset(){
        set("vendor_goods", ([
        __DIR__"obj/m_cloth1":8,
        __DIR__"obj/g_gloves":8,
        __DIR__"obj/m_cloth2":10,
        __DIR__"obj/m_cloth3":10,
        __DIR__"obj/m_cloth4":10,
		__DIR__"obj/m_boots1":7,
		__DIR__"obj/m_boots2":8,
		__DIR__"obj/w_skirt1":8,
		__DIR__"obj/w_skirt2":8,
		__DIR__"obj/w_skirt3":8,
		__DIR__"obj/w_skirt4":10,
		__DIR__"obj/w_girth1":10,
		__DIR__"obj/w_girth2":10,
        ]) );
	
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
                case 0:
                        say( " ������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����������¿�ʽ���·��ɡ� \n");
                        break;
                case 1:
                        say( " ������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "��������Щ�·����ֹ�����������˫�ģ������� \n");
                        break;
				case 2:
			say ( " ������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������Ķ����������������⡣���� \n");
                       break;
        }
}

				
