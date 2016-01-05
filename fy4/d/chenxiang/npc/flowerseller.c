// waiter.c
inherit NPC;
inherit F_VENDOR;
inherit F_FLOWERSELLER;

#include <ansi.h>
void create()
{
	set_name("����", ({ "huagu" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("title", HIM "��ĵ��"NOR);
	set("long","��������������Ц���ÿɰ�����\n");
	set("combat_exp", 15000);
	set("attitude", "friendly");
	set("per",30);
	set("NO_KILL","��ô�ɰ���СŮ���ӣ�����ô�µ����֣�\n");
	set("vendor_goods", ([
                AREA_FY"npc/obj/purple_flower":30,
                AREA_FY"npc/obj/red_flower":25,
                AREA_FY"npc/obj/yellow_flower":33,
                AREA_FY"npc/obj/blue_flower":44,
                AREA_FY"npc/obj/white_flower":14,
                AREA_FY"npc/obj/black_flower":10,
	]) );
		set("inquiry",([
        	"Ѻ��" : 	(: give_deposit :),
        	"deposit" : (: give_deposit :),
        	"�ͻ�":		"�ͻ��ķ������뿴����ĸ�ʾ��sign����\n",
        	"delivery":	"�ͻ��ķ������뿴����ĸ�ʾ��sign����\n",	
    	]) );
    	
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
	add_action("do_vendor_list", "list");
	add_action("assign_delivery","delivery");
	add_action("cancel_delivery","cancel");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
message_vision("$NЦ��˵�����ղ������Ļ����ϣ���ɡ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$NЦ�����˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô������\n",this_object(),ob);
			break;
	}
}
