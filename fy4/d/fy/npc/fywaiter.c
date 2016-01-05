// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�պ��", ({ "su honger","su" }) );
	set("gender", "Ů��" );
	set("age", 31);
	set("title", "�ϰ���");
	set("long",
		"��λ�ϰ�����б���ڹ�̨�ߣ�Ц����������㡣\n");
	set("combat_exp", 300000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/yxrs":50,
		__DIR__"obj/cddt":50,
	        __DIR__"obj/frsp":50,
                __DIR__"obj/ssqy":50,
                __DIR__"obj/ylzp":50,
                __DIR__"obj/pwym":50,
                __DIR__"obj/cwgp":50,
                __DIR__"obj/ychz":50,
                __DIR__"obj/jxyz":50,
                __DIR__"obj/zypg":50,
                __DIR__"obj/rxcy":50,
                __DIR__"obj/qcsh":50,
                __DIR__"obj/hyjp":50,
                __DIR__"obj/szpc":50,
                __DIR__"obj/glyc":50,
                __DIR__"obj/xcfs":50,
                __DIR__"obj/cpcy":50,
                __DIR__"obj/gzyq":50,
                __DIR__"obj/qcxr":50,
                __DIR__"obj/jymj":50,
                __DIR__"obj/glxj":50,
                __DIR__"obj/cpdx":50,
                __DIR__"obj/pxhy":50,
                __DIR__"obj/kzmt":50,
                __DIR__"obj/hhdq":50,

	]) );
	set_skill("unarmed",50);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
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
	switch( random(10) ) {
		case 0:
message_vision("$N�۽Ǻ�Ц��������������$nһ�ۡ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����΢�ڣ�¶����֬�����ۣ���$n�������֡�\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����$nһ�ۣ�����������ӣ��С����Ц������\n",this_object(),ob);
			break;
	}
}

int accept_object(object who, object ob)
{
	int damount;
	if(ob->query("id") == "painting")
	{
		message_vision("$N���$nһ�ۣ�������λ"+ RANK_D->query_respect(who) + "�����۹⡣������ҷǳ�ϲ������Ҫ���ˡ�Ǯ��ֱ�ӻ㵽����ʻ��ϡ�\n",this_object(),who);
		damount = (int)who->query("deposit");
		damount += ob->query("real_value");
		// to make life more realistic
		who->add("richness",ob->query("real_value"));
		who->set("deposit", damount);
		return 1;
	}
	return 1;
}


void reset(){
		set("vendor_goods", ([
				__DIR__"obj/yxrs":50,
				__DIR__"obj/cddt":50,
	        	__DIR__"obj/frsp":50,
                __DIR__"obj/ssqy":50,
                __DIR__"obj/ylzp":50,
                __DIR__"obj/pwym":50,
                __DIR__"obj/cwgp":50,
                __DIR__"obj/ychz":50,
                __DIR__"obj/jxyz":50,
                __DIR__"obj/zypg":50,
                __DIR__"obj/rxcy":50,
                __DIR__"obj/qcsh":50,
                __DIR__"obj/hyjp":50,
                __DIR__"obj/szpc":50,
                __DIR__"obj/glyc":50,
                __DIR__"obj/xcfs":50,
                __DIR__"obj/cpcy":50,
                __DIR__"obj/gzyq":50,
                __DIR__"obj/qcxr":50,
                __DIR__"obj/jymj":50,
                __DIR__"obj/glxj":50,
                __DIR__"obj/cpdx":50,
                __DIR__"obj/pxhy":50,
                __DIR__"obj/kzmt":50,
                __DIR__"obj/hhdq":50,

	]) );
}