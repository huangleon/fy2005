// waiter.c

inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("������", ({ "max" }) );
	set("gender", "����" );
	set("age", 62);
	set("long",	"��λ�������������ӡ�÷��ڣ�һ����·�������ոճ������һ����\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_temp("apply/astral_vision",1);
	set("rank_info/respect", "�ϵ��");
	set("vendor_goods", ([
        __DIR__"obj/pumpkin" : 80,
		__DIR__"obj/wineskin": 80,
	]) );
	setup();
	carry_object("/obj/armor/ghost_cloth")->wear();
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
	switch( random(3) ) {
		case 0:
			say( "�����ĵ�����λ" + RANK_D->query_respect(ob)
				+ "��Ͷ̥������ŶŶ������������Ͷ����\n");
			break;
		case 1:
			say( "�����ĵ���" + RANK_D->query_respect(ob)
				+ "��������,��Ͷ�ޣ���������\n");
			break;
		case 2:
			say( "�����Ŀȵ�����λ" + RANK_D->query_respect(ob)
				+ "�������ȼ���С��Ļ����ưɣ�\n");
			break;
	}
}

void reset(){
	set("vendor_goods", ([
        __DIR__"obj/pumpkin" : 80,
		__DIR__"obj/wineskin": 80,
	]) );	
	
}