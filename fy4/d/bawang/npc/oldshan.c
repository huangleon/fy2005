#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��ɽ��", ({ "old shandong","shandong" }) );
	set("gender", "����" );
	set("title","��ͷ���ϰ�");
	set("age", 46);
	set("long",
		"���˲���̫�ϣ������̰�����Ѭ���ˡ�ֻ��Ц������ʱ�򣬲Ż�¶��\nһ��ѩ�׵����ݡ�\n"
		"��˵��ϲ��С����һ������ڵĴ�Сǿ���Ƕ������ĳ��͡�\n");
	set("combat_exp", 540000);
	set("attitude", "friendly");
	set("per",5);
	set("vendor_goods", ([
        	__DIR__"obj/mantou":120,
			__DIR__"obj/shaoji":120,
	]) );
	set("inquiry",	([
			"��ϲ" : "��ɽ�������ۿ�������죬��ȻЦ������������ϲ�����Ѱ�����......\n��ͷ�ռ�ȫ���С����������ԣ���ҭ�š���",
			"С��" : "��ɽ�������ۿ�������죬��ȻЦ����������С������Ѱ�����......\n��ͷ�ռ�ȫ���С����������ԣ���ҭ�š���",
	]) );
	set_skill("unarmed",100);
	set_skill("dodge",100);
	
	setup();
	carry_object(__DIR__"obj/dirty_cloth")->wear();
	carry_object(__DIR__"obj/sd_skinmask");
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


void greeting(object ob){
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) 
	{
		case 0:
			message_vision("$N����$nһ�ۣ������������λ"+RANK_D->query_respect(ob)+"��С������ˡ�\n",this_object(),ob);

			break;
		case 1:
			message_vision("$N̾����С������ɽ����ϲ�����ڣ�ʮ�а˳�����ȥ�޻ذ���\n$N����ҡ��ͷ�����ȴ���ֳ�һ˿���ص�Ц�ݣ�����ϧѽ����ϧ....\n��ô�õ�����С����ѽ......��\n",this_object());

			break;
	}
}

void reset ()
{
	set("vendor_goods", ([
        	__DIR__"obj/mantou":120,
			__DIR__"obj/shaoji":120,
	]) );
}
