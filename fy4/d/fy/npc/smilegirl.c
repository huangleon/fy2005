inherit SMART_NPC;

void create()
{
	set_name("����", ({ "chu chu","chu" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
		"һ��������а��δ�����µ�СѾ��\n");
	set("combat_exp", 900000);
	set("attitude", "friendly");
	set("per",30);
	
	auto_npc_setup("wang",100,120,0,"/obj/weapon/","fighter_u","stormdance",1);
	setup();
	carry_object(__DIR__"obj/green_cloth")->wear();
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
message_vision("$N����$nһ�ۣ�Ȼ����סС�����ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$n����һ�ۣ�Ȼ���ߵ�ת������ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 2:
			command("snicker");
	}
}
