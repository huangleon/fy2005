inherit SMART_NPC;

void create()
{
		set_name("��ͯ", ({ "jin tong","tong" }) );
		set("gender", "����" );
		set("age", 14);
		set("long",	"һ��������а��δ�����µ�С��ͯ��\n");
	
		set("combat_exp", 900000);
		set("attitude", "friendly");
		set("per",30);
		set("class", "moon");
		
		auto_npc_setup("wang",100,120,0,"/obj/weapon/","fighter_u","stormdance",1);
		setup();
		carry_object(__DIR__"obj/yellow_cloth")->wear();
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
	switch( random(3) ) {
		case 0:
message_vision("$N����$nһ�ۣ�Ȼ����ס�쿪ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$n����һ�ۣ�Ȼ���ߵ�ת������ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 2:
			command("snicker");
	}
}
