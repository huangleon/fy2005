// girlfi.c

#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("�����", ({ "fenger" }) );

        set("gender", "Ů��");
        set("age", 20);
        set("long",
                "����ɫ���㡡�������ס�����浾��������御\\n"
                "�����ݾ��������������������������ŵ�һ�����㡣\n");
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("combat_exp", 4400000);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	    	
    	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","shadowsteps",1);
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/boot")->wear();

}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�����˵����λ" + RANK_D->query_respect(ob)
                                + "������������\n");
                        break;
                case 1:
                        say( "����������ĳ����ƺ�û�в���������\n");
                        break;
        }
}
