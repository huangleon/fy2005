#include <ansi.h>
inherit NPC;

int answer();

void create()
{
        set_name("С��", ({ "xiao pan","xiaopan" }) );
        set("title","�����Ʊ�");
        set("gender", "����" );
        set("age", 42);
	set("long","
��С����ʵ���Ѳ���С���ӣ�����������ʮ���꣬��ȴ������һ������
����û˵������Ц��˵���˻���Ц�����κ���Ҳû���Ӷ�����Ƣ����\n");
	set("combat_exp", 500000);

	set("inquiry",([
		"ɳĮ": (: answer() :),
		"desert": (: answer() :),		
		"camel": (: answer() :),
		"����": (: answer() :),
		"���ն�": (: answer() :),
	]));

	set("chat_chance", 1);
        set("chat_msg", ({
                "С������Ц������С�˵ı��£�����ʲ�ᶼ���ᣬʲ�ᶼ������һ���˻�
����ʮ�࣬����һ�㱾��Ҳû�У���Ҳ���Ǽ������£���˵���᣿��\n",
		"С��˵����Ҫ��̫̫ƽƽ�ع�ɳĮ���͵ù����ǵ����նӣ���\n",
        }) );
      
	set("attitude", "friendly");
	set("class","baiyun");
	
    	set_skill("unarmed", 100);
    	set_skill("force", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("calligraphy", 120);
    	set_skill("chessism", 150);
    	set_skill("feixian-steps", 80);
	set_skill("move",120);
	
    	map_skill("unarmed", "calligraphy");
    	map_skill("force", "chessism");
    	map_skill("dodge", "feixian-steps");
    	map_skill("move","feixian-steps");

        setup();
        carry_object(__DIR__"obj/scloth")->wear();

}


int answer(){
	message_vision("
С��˵����Ҫ��ɳĮ�����ҾͶ��ˣ���\n",this_object());
	if (!environment(this_object())->query("route_clear")) {
		message_vision("
С�˰���̾����˵�������������·�ϲ�̫ƽ���Ҹ�̫ƽ�����վʧ����ϵ��
�����նӵ�����Ҳ�������ˡ���������ܵ�̫ƽ���Ƕ�ȥ�����ͺ��ˡ���\n",this_object());
		return 1;
	}
	message_vision("
С��˵����ʯ���������õĳ���ʽ����ֻҪ�������ӣ��������ֿ��ְ�
ȫ�������ɳĮ����\n",this_object());
	return 1;
}


int accept_object(object who, object item){
	object ob, gold;
	
	ob = this_object();
	
	if (!environment(ob)->query("route_clear")) {
		message_vision("
С�˰���̾����˵����û�ã����·�ϲ�̫ƽ���Ҹ�̫ƽ�����վʧ����ϵ��
�����նӵ�����Ҳ�������ˡ���������ܵ�̫ƽ���Ƕ�ȥ�����ͺ��ˡ���\n",this_object());
		return 0;
	}
	if ((item->query("value")<300 && !who->query("ʯ����/desert_route"))
		|| item->query("value")<300) {
		message_vision("
С��Ϊ�ѵ�ҡҡͷ�������Ǯ�����������ղݶ�����������\n",ob);
		return 0;
	}
	if (who->is_busy()) {
		message_vision("С��˵�����͹��ƺ������¶�û�˰ɣ���\n",ob);
		return 0;
	}
		
	message_vision("С��������Ц��˵�����͹٣����������·����\n",ob);
	message_vision("
ʯ�մӺ���ǣ��һͷ�ִ���׳�����գ�$Nһ����������ȥ��\n",who);
	message_vision("$N����ߺ�ȣ������նӳ���ඣ���\n",ob);
	who->set_temp("ride","����");
	who->start_busy(16);
	environment()->go_out_1(who, 0);
	return 1;
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		if (environment()->query("route_clear")) return;
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob) {
	
	object gold;
	
	if (!ob || environment() != environment(ob))	return;
			
	if (interactive(ob) && ob->query_temp("quicksand/route_notice")) {
		ob->delete_temp("quicksand/route_notice");
		command("touch "+ob->query("id"));
		command("say ��л������ĺ���Ϣ��·������̫ƽ�ˡ�");
		command("say ���С��˼������°ɡ�");
		
		gold = new("/obj/money/gold");
		gold ->set_amount(5);
		if (!gold ->move(ob))	{
	    	tell_object(ob, HIR"���������ϵĶ�������̫�࣬������û���ˡ�����\n"NOR);
	    	destruct (gold);
	    } 
	    		
		REWARD_D->riddle_done(ob,"ɳĮ����", 20, 1);
			
		environment()->set("route_clear",1);
		CHANNEL_D->do_sys_channel("info","����ɳĮ�����ն��ֿ�ʼ�����ˣ�");
		return;
	}
}