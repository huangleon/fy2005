#include <ansi.h>
inherit NPC;
int do_jie(string arg);
void create()
{
        set_name("��ʨ��", ({ "jin shizi", "jin" }) );
        set("long","��ʨ�����ڣ���ò��ª��������һֻ����ӣ�ռ�˰������ĵط�����
�˲����ÿֲ���ֻ���ÿ�Ц��\n");
    	set("chat_chance",1);
		set("chat_msg",	({
			"��ʨ���������´������㣬���������������ߣ���Щ�����������
û�޳���С�����ӻ��ǻؼҹԹԴ���ȥ����\n",
		})  );

        set("combat_exp", 300000);
	
		set_skill("dodge",100);
		set_skill("move",100);
		set_skill("shenji-steps",100);
		set_skill("unarmed",160);
		set_skill("changquan",160);
		set_skill("parry",100);
	
		map_skill("unarmed","changquan");
		map_skill("dodge","shenji-steps");
		map_skill("move","shenji-steps");
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
}

int do_jie(string arg){
	
	object ob, me, yaopai;
	me= this_player();
	
	if (arg == "gaoshi"&&  environment(this_object())->query("gaoshi")) {
		if (REWARD_D->check_m_success(me,"���ܴ��")) {
			command("say ������һ�����ƣ����������ɳ��룬���ؽҸ�ʾ�ˡ�");
			if (!ob=present("yao pai", me)) {
				ob = new(__DIR__"obj/yaopai");
				ob->move(me);
				write("��ʨ�Ӹ�"+me->query("name")+"һ�����ơ�\n");
			}
			me->set_temp("yaopai",1);
			return 1;
		}
		
		if (!ob=present("yao pai",me)) {
			if (this_player()->query_temp("yaopai"))
				{
				command("say ������������Լ���Ҫ���ƣ�Թ�����ң�����");
				return 1;
				}
									
			if( time()-(int) this_player()->query("marks/last_time_jiegaoshi") < 1200 ) {
				command("say ��ո��Թ�û��ã��Ȼ�������ɣ�");
			} else if(present("jia gun", environment())) {
				command("point jia gun");
				command("say ��Ҫ֤�����ʵ�����ͺ��������аɣ���ͬ�⣨�����������");
				this_player()->set_temp("jiegaoshi",1);
				this_player()->set("marks/last_time_jiegaoshi",time());
			} else {
				message_vision("$N��$n�����й����ڣ���Ȼ�������ɡ�\n", this_object(), this_player());
			}
		} else if (this_player()->query_temp("yaopai")) 
				command("say �����Ѿ���������������");	
		else 
			command("say ������������͵���ģ�����ʵ����������Ͱ���ץ����ȥ��");
		return 1;
	
	}
	return 0;
}

/*
void die()
{
	object ob;
	object *enemy;
	ob = query_temp("last_damage_from");
	if(!ob) { 
		enemy = this_object()->query_enemy();
		if(sizeof(enemy))
			ob=enemy[0];
	} else {
		if(userp(ob)) 	ob->set_temp("marks/killjin",1);
	}
	::die();

}				

*/