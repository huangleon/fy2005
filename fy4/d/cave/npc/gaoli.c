#include <ansi.h>
inherit NPC;

void create()
{
    set_name("����", ({"gao li","gao"}) );
    set("gender", "����" );
    set("nickname", HIC"����ǹ"NOR);
    set("title", "������ �̿�");
    set("long", "
���������·���Զ����������Ӱ������ϴ��ż������������ۣ��ǳ����
��Ϊ�������ڵ����²������ǶԳ��ض��ַ�������ǹ��\n");
 	set("attitude", "friendly");
    	set("age", 25);
    	   	
    	set("combat_exp", 4000000);
    	set("class","officer");
	
		set("reward_npc", 1);
        set("difficulty", 5);
	
		set_skill("spear", 200);
		set_skill("parry", 150);
		set_skill("yue-spear", 160);
		set_skill("dodge", 150);
		set_skill("move", 150);
		set_skill("dragonstrike",150);
		set_skill("unarmed",150);
		set_skill("puti-steps",200);
		set_skill("force",100);
		set_skill("manjianghong",120);
	
	map_skill("force","manjianghong");
	map_skill("unarmed","dragonstrike");
	map_skill("parry","yue-spear");
	map_skill("spear", "yue-spear");
	map_skill("dodge","puti-steps");
	map_skill("move","puti-steps");
	
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: command("perform zonghengtianxia") :),    
        }) );	
        
	set("chat_chance", 1);
    	set("chat_msg", ({
        HIR "��������Ѫ֮����Ŭ������˫˫��˻������˫����˫���������ҵ���\nҲϹ�ˣ��������У��㡣������Զ���������ġ���\n"NOR,
        HIR"�������˿�Ѫ����ΡΡ�ӻ����ͳ�һ����Ѫ��õ���С�����ޣ�\nһ��һ��Ŭ��������˫˫��\n"NOR,
    	}) );

    	setup();
    	carry_object(__DIR__"obj/taocloth")->wear();
    	carry_object(__DIR__"obj/bravespear")->wield();
    	carry_object(__DIR__"obj/bloodrose");
    	carry_object(__DIR__"obj/doll");
}

int accept_object(object who, object ob){
	object xi, box;
	
	if (this_object()->is_fighting())	return 0;
		
	if(ob->query("id") == "jadebox" && ob->name() == "ȸ�����"){
		message_vision("$N�������Ѫ���е�$n����ȸ������������$n���У��������������һ������\n", 
				who, this_object()); 
		who->start_busy(3);
		if(!present("ximen yu", environment())){
			return 0;
		}
		if(present("ximen yu", environment()) && present("shuang shuang", environment())){
			xi = present("ximen yu", environment());
			call_out("kill_xi", 2, who, xi);
		} else if (present("ximen yu", environment()) && !present("shuang shuang", environment())){
			message_vision("$N��̾һ�������ˣ�̫���ˡ���\n", this_object());
			message_vision("$N���г�ǹ��ת�����Լ��Ŀڡ�������\n", this_object());
			box = new(__DIR__"obj/jadebox");
			if(objectp(box)){
				box->move();
			}
			call_out("dead", 1);
			return 1;
		}
		return 1;
	}
	return 0;
}

int kill_xi(object me, object xi){
	if(!interactive(me) || environment(me) != environment()){
		return 0;
	}
	message_vision(RED"\n$N������������ȭͷ�����˲���ǵ���Ѫ��ͻȻŭ��һ������ֱ��������ǹ���֡�\n"NOR,
			this_object()); 
	message_vision("$NĬĬ�����ۻ����е�˫˫��������������ȵ������ţ���ǹ��\n",
			this_object()); 
	message_vision(HIW"\n$N������ǹ�·𼲵�����֡�������\n", this_object()); 
	message_vision(HIW"        ��ǹ�������������� ���ۡ���һ�������ѹᴩ����������ʺ�\n\n"NOR,
			this_object()); 
	xi->killed(me);	
}


void dead(){
	this_object()->die();
}

void do_leave(object me){
	call_out("leave", 1, me);
}

void leave(object me){
	object shuang;
	
	if(!interactive(me) || environment(me) != environment()){
		if(present("shuang shuang", environment())){
			shuang = present("shuang shuang", environment());
			message_vision("$N�����ű���˫˫����ʧ�ںڰ�֮�С����� \n", this_object());
			destruct(shuang);
			destruct(this_object());
		}
		return;
	}
	if(present("shuang shuang", environment())){
		shuang = present("shuang shuang", environment());	
		message_vision("$N����$n���˵�ͷ��Ȼ�������ű���˫˫����ʧ�ںڰ�֮�С�����\n",
				this_object(), me); 
		REWARD_D->riddle_done( me, "�Ǿȸ���", 10, 1);
		destruct(shuang);
		destruct(this_object());
	}
	return;
}