inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
	set_name("СѾ��", ({ "little yahuan","yahuan" }) );
	set("gender", "Ů��" );
	set("age", 14);
	set("title", "�绨����");
	set("long",
		"һ��������а��СѾ��\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/white_towel":100,
	]) );
    	set("inquiry", ([
        	"fatman" : (: tell_him :),
        	"������" : (: tell_him:),
        ]));
	set_skill("unarmed",5);
	set_skill("tenderzhi",5);
	set_skill("dodge",5);
	set_skill("stormdance",5);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
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
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
message_vision("$N�ڰ�æ��̧��ͷ����$nһ�ۡ�\n",this_object(),ob);
			break;
	}
}
int tell_him()
{
    object me;
    me =this_player();
    tell_object(me,"СѾ�ߵ��������춼��������Ҳ�������ո��ߣ�\n");
    
    if (REWARD_D->riddle_check(me,"ʧ���粨")==3 
    	|| REWARD_D->riddle_check(me,"ʧ���粨")==4 ) {
		tell_object(me,"�����Ƕ������ĵģ����ȥ����(search)˵���������Է��������µĶ�����\n");
		REWARD_D->riddle_set(me,"ʧ���粨",4);
	}
    
    return 1;
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/white_towel":100,
	]) );	
}