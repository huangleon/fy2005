
inherit NPC;
void create()
{
	set_name("Ϲ�ϵ�", ({ "laodie", "lao die" }) );
	set("gender", "����" );
	set("age", 55);
	set("title", "ä��ʦ");
	set("long","
û����֪��Ϲ�ϵ���������Ҳû��ע��������һ�쵽����ģ���û����֪����
��һ�����ֻ��뿪������Ϲ�ϵ�������Ů�����������������ҳ�һ��֧С
������Ҳ������ǿı��������Ŀ�Բ�ɣ�����ƺ᲼��\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",15);
	set_skill("unarmed",50);
	set_skill("dodge",50);

	setup();
   	carry_object("obj/music/erhu")->wield();
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
}

void greeting(object ob)
{
   	object	lianer;

	if( !ob || environment(ob) != environment() ) return;
        lianer = present("lian er", environment(ob));
        if(!objectp(lianer)){
message_vision("$N˵������λ"+RANK_D->query_respect(ob)+"�����ҵ���������?��\n",this_object(),ob);
           return;
        }
        if(query_temp("marks/sing") == 1) {
           	return;
        }
	switch( random(2) ) {
		case 0:
message_vision("$N���˵����ң�˵���������������˳���С�����ɡ���\n",this_object(),ob);
			break;
		case 1:
message_vision("$N���˵����ң�˵������λ"+RANK_D->query_respect(ob)+
"Ҫ����С����? ��\n",this_object(),ob);
			break;
	}
        this_object()->set_temp("marks/sing", 1);
        lianer->do_sing(ob);
}
