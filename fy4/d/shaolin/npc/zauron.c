inherit SMART_NPC;
#include <ansi.h>
 

void create()
{
        set_name("����", ({ "lianrong" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
������ʮ��Ư����ȫ����㣬�����̲�ס���������ۣ���������
���ŵ����������������ŵĶ�������ӯ�Ĳ���������Ŷ!
TEXT
);
        set("class", "swordsman");
        set("combat_exp", 4500000);
		set("no_arrest",1);
	
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	
    	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","softsword",1);
        setup();
        carry_object(__DIR__"obj/clasp")->wear();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt2")->wear();
        carry_object(__DIR__"obj/bamboo_sword")->wield();

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
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "���ض���΢Ц�����ƵĶ���˵������ʮ���������ĵ�һ�����ˡ�\n");
                        break;
                case 1:
                  say( "���ض���΢Ц������ػζ��Ŵӱ�ɴ��¶���İ������ \n ˵������λ" +
RANK_D->query_respect(ob)
                   + "����ã���ӭ����ۡ԰��\n");
        }
}

