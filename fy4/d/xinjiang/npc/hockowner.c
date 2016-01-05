#include <ansi.h>
inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("ľ����", ({ "mulati" }) );
	set("gender", "����" );
	set("age", 69);
	set("richness",1000000);
	set("combat_exp", 2000);
	set("no_arrest",1);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
message_vision("$N˵������λ"+RANK_D->query_respect(ob)+
"���ǿ���ķ��˹��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N˵������λ"+RANK_D->query_respect(ob)+
"���ǿ���ķ��˹��\n",this_object(),ob);
			break;
		case 2:
message_vision("$Ņͷ����һ�ۣ�����\n"
,this_object(),ob);
			break;
				}
}
