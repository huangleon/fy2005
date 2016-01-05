// hu.c

inherit NPC;
#include <ansi.h>
 
void create()
{
	set_name("�ֹ���", ({ "fat man","man"}) );
	set("gender", "����" );
	set("age", 32);
	    	
    	set("long",
"���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����
�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������
�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ�� \n"
    );

	set("combat_exp", 7000000);
	set("attitude", "friendly");
	
	set_skill("dodge",200);
	set_skill("move",200);
	set_skill("unarmed",200);
	set_skill("parry",200);
	set_skill("tigerstrike",400);
	set_skill("throwing",200);
	set_skill("meihua-biao",180);
    set_skill("fall-steps", 200);

    map_skill("parry","meihua-biao");
	map_skill("throwing", "meihua-biao");
	map_skill("dodge", "fall-steps");
	map_skill("unarmed","tigerstrike");
		
	set("chat_chance", 1);
	set("chat_msg", ({
		"�ֹ��ӳ�ü������̾����������������ô������ȥ����ô�����أ���\n",
		"�ֹ��Ӻ�Ȼ����̾�˿�������������֪�������һ�������ˣ��������˲��١���\n",  
		"�ֹ�����һ˫�ְ����ۣ������ü��õ��֣�����һ����ͷ�������ֳ�������
�ı��飬������ͷ����ŵ��廨�⣬Ȼ��һ��ҧ��ȥ��\n",
		"�ֹ�����������������֪��ô�ģ�һֻ�ɹ��Ĳ�Ӭ���ڵ��ϡ�\n",
	}));
	
	setup();
	carry_object(__DIR__"obj/fatcloth")->wear();
	carry_object(__DIR__"obj/chickbone")->wield();
	carry_object("/obj/armor/boots")->wear();
	carry_object(__DIR__"obj/mantou");
}

void init(){
	::init();
	add_action("do_look", "look");
	add_action("do_kill", "kill");
}

int do_look(string arg) {
	
	
	if(arg && (arg[0..6] == "fat man" || arg[0..2]=="man")){
		if (!present(arg))	return 0;
		write("���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����\n");
		write("�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������\n");
		write("�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ��\n");
		write("��������Լ��ʮ���ꡣ\n");
		write("������"+WHT"�Ŀ�����"NOR+"���书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
		write("�����������������۷�״̬��\n");
		write("����"+BLU"�����"NOR+"(Silk cloth)\n");
		return 1;
	}
	return 0;
}

int accept_object(object me, object ob){
	if(ob->query("food_remaining")){
		message_vision("$N�ӹ�" + ob->name()+"��ϸ�ĳ��˽�ȥ��Ȼ�������̾�˿�����\n", this_object());
		if(ob->query("name") == YEL"�л��Ӽ�"NOR){
			message_vision("$N���ĵ�̾�˿����������ٺ٣����δ����\n", this_object());
		}
		return 1;
	}
	return 0;
}

int do_kill(string arg) {
	if(arg == "fat man" || arg == "man"){
		message_vision("$Nͬ��ؿ���$nһ��˵������������һ������˭�ˡ�\n",this_object(),this_player());
		message_vision("$N֣�صظ���$n�����ҽ�"+HIW"����"NOR+"������Ѽ��"+HIW"��"NOR+"�����ӵ�"+HIW"��"NOR+"��������\n"NOR,this_object(),this_player());
		message_vision("���������ʼ�,��֪�Ķ�����һ������ͷ��ž���ش���$N�ļ羮Ѩ�ϡ�\n",this_player());
		this_player()->perform_busy(1);
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());	
		return 1;
	}
	return 0;
}
