inherit NPC;
inherit F_VENDOR;

void create() { 	
	set_name("���ӻ�", ({ "xinghua" }) );
	set("gender", "Ů��" );
	set("age", 67);	
	set("title", "�ϰ���");
	set("long","���컨ȹ������Ĩ�ź���֬��ָ����Ϳ�ŷ��ɻ�֭��һλ�����ϸ��ˡ�\n");
	set("chat_chance", 1);
	set("chat_msg", ({
		"���ӻ������һ��Ц�� ����λ������ү����������������������\nǹ��С���������Ǻ���˲���......\n",
		"���ӻ�̾��������һֱ�õȵ���ʮ���Ժ��Ҳ���ϰ��һ����˯��\n",
	}) );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",20);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	
	set("vendor_goods", ([
		__DIR__"obj/sxqj":12,
		__DIR__"obj/gaoskin":12,
		__DIR__"obj/gaoliang":6,
		__DIR__"obj/hsnr":6,
		__DIR__"obj/pill":50,
		]) );
	
	setup();
	carry_object("/obj/armor/cloth")->wear();

}

	

void init(){
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
	switch( random(3) ) 
	{
		case 0:
            message_vision("$Nһ��$n������æ����ǰ��һ������Ĩ��Ĩ��������������
��λ"+RANK_D->query_respect(ob)+"�þ�û���ˣ��Ҷ�������ġ�����\n",this_object(),ob);
			break;
		case 1:
            message_vision("$Nҡҡͷ̾�����������ϲ��С���˵���Ҳ��֪������ȥ�ˡ�
�Դ�������������Ѿͷ�󣬾Ͱ��������ӵ�һ��ȥ�ˡ�\n",this_object(),ob);
			break;
		case 2:
			message_vision("$N����$nһ�ۣ�����������ӣ��С����Ц������\n",this_object(),ob);

			break;
	}
}

void reset ()
{
	set("vendor_goods", ([
		__DIR__"obj/sxqj":12,
        	__DIR__"obj/gaoskin":12,
        	__DIR__"obj/gaoliang":6,
		__DIR__"obj/hsnr":6,
		__DIR__"obj/pill":50,
		]) );
}

