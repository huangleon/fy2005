inherit NPC;
inherit F_MASTER;
int leave();
#include <ansi.h>

void create()
{
    	set_name("������", ({ "hua zhenzhen", "zhenzhen", "hua"}) );
    	set("gender", "Ů��" );
    	set("long","��˹˹���ģ�����������ʼ�յʹ���ͷ���·��߼����ˡ� 
żȻ̧ͷʱ��һ˫�������ǹ������������ȴ�ֳ�΢΢�κ졣 \n");

    	set("age", 18);
    	set("per", 30);
    
    	set("reward_npc", 1);
    	set("difficulty", 30);
    
    	set("class","huashan");
    	set("apprentice_available", 50);
    	create_family("��ɽ��", 15, "����");
    	set("title", "��ɽ�� ��ʮ�ߴ�����");
		set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"Ůͯ","С��","����","Ů��","÷ʹ","��ʹ",
					"��ʹ","��ʹ","����Ů��","������Ů","��������",
					"�����ɼ�",CYN"��Ů"NOR,CYN"��ʥ"NOR,CYN"���ڴ���"NOR,HIC"��������"NOR}));
    	set("inquiry", ([
			"leave" : (: leave :),
	]));
    
       	set("no_busy",10);
    	    
    	set_temp("apply/haste",400);
    	set("guard_msg",HIW"$N̾�˿�����ɱ���ߣ���ɱ֮��\n"NOR);
    	set("score", 5000);
    	set("combat_exp", 10000000);

    	set_skill("perception", 200);
    	set_skill("move", 190);
    	set_skill("dodge", 200);
    	set_skill("iron-cloth", 180);
    	set_skill("sword", 200);
    	set_skill("throwing", 250);
    	set_skill("foreknowledge",100);
    	set_skill("unarmed",160);
    	set_skill("force", 160);
    	set_skill("literate", 100);
    	set_skill("parry", 160);
    	set_skill("chanting",100);
    	
    	set_skill("hanmei-force", 200);
    	set_skill("anxiang-steps", 180);
    	set_skill("cloud-dance", 200);
    	set_skill("spring-water", 120);
    	set_skill("qingfeng-sword", 200);
    	set_skill("tanzhi-shentong", 160);
    	set_skill("zhaixin-claw",180);
    
    	map_skill("unarmed", "zhaixin-claw");
    	map_skill("force", "hanmei-force");
    	map_skill("dodge", "cloud-dance");
    	map_skill("sword", "qingfeng-sword");
    	map_skill("parry", "qingfeng-sword");
    	map_skill("move", "anxiang-steps");
    	map_skill("iron-cloth", "spring-water");
    	map_skill("throwing", "tanzhi-shentong");
    
    	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                 (: exert_function, "chill" :),
        }) );
        
        
    	setup();
    	carry_object(__DIR__"obj/ycloth")->wear();
    	carry_object(__DIR__"obj/qingfeng")->wield();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } 
}

void do_recruit(object ob)
{
	if((string)ob->query("gender") == "Ů��" 
			&& ob->query("class")=="huashan" 
			&& REWARD_D->check_m_success(ob,"����ëŮ��")){      
		if ( ob->query("combat_exp")<1200000) {
			message_vision("$N̾�˿���˵����ɽ���ڶ���֮�ʦ�øö�Ŭ���������� Ҳ��
���㳤�����һ�죬���ǻ����ټ���ġ� \n",this_object());
			command("wave");
			message_vision("\n\n$N��Ӱһ�Σ���Ȼ�Ӿ��ڱ���ʧ�ˡ�\n", this_object());
			destruct(this_object());
			return;
		}
				
		if (ob->query("marks/�ҳ�")==1 
		        || (ob->query("marks/�ҳ�")== -1 && ob->query("marks/kill_kumei"))
			){
			message_vision("$N����$n����һ�����̾�˿���˵����Ҳ�������һ�죬���ܷ�����ɽ�ɡ��� \n",
				this_object(), ob);
			command("recruit " + ob->query("id") );
			message_vision("\n$Nת���ߵ����ڱߣ�������$nʾ���������\n", this_object(),ob); 
			message_vision("$N��Ӱһ�Σ���Ȼ�Ӿ��ڱ���ʧ�ˡ�\n", this_object());
			environment(ob)->go_cliff(ob);
			destruct(this_object());
		}
		else if (ob->query("marks/�ҳ�")== -1 && !ob->query("marks/kill_kumei")) {
			message_vision("$N����$n����һ�����̾�˿���˵����Ҳ��������ʵ�Ļ�ɽ���ӣ�
Ҫ֪���������е���Щ�������˵İ��಻��������ɽ�ɾ���Զ���ܷ����󡣡� \n",
				this_object(), ob);            
			command("wave");
			message_vision("\n\n$N��Ӱһ�Σ���Ȼ�Ӿ��ڱ���ʧ�ˡ�\n", this_object());
			destruct(this_object());
		}
		
		else {
			message_vision("$N̾�˿���˵������ɽ���ڶ���֮�ʦ�øö�Ϊʦ�ų��������� \n",
				this_object());
			command("wave");
			message_vision("\n\n$N��Ӱһ�Σ���Ȼ�Ӿ��ڱ���ʧ�ˡ�\n", this_object());
			destruct(this_object());
		}
		
	} 
	else {
		message_vision("��Ȼ�Ǻڰ���ҹɫ�£�$N���ǲ�����˼�ص���ͷ��С��˵���� �Ҳ���\n", this_object());
		message_vision("��û�����ĵ��ӣ���ô�������˵�ʦ���أ��� \n", this_object());
		message_vision("$N��Ӱһ������ʧ��ҹĻ�С�\n", this_object()); 
		destruct(this_object());
	} 
	return;
}

void init(){
	object ob;
	::init();
	call_out("do_leave", 30);

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_killing", "kill");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if (REWARD_D->riddle_check(ob,"����ëŮ��") == 4 
		&& (ob->query("marks/�ҳ�")!= -1 || ob->query("marks/kill_kumei")) )
	{
		message_vision(CYN"$NĿע��$n������һ̾��
$N����������Ҳ�����ˣ���ɽ������ֵ����֮�����
��������ô���ؿ�÷ʦ�㣬���ǣ����ǣ���������������
$N˵����ʦ����������ٹ��أ�������ɽ���û���㲻����ȥ������\n\n"NOR,this_object(),ob);
		REWARD_D->riddle_done(ob,"����ëŮ��",50,1);
	}
}


void do_leave(){
	if( find_call_out("do_recruit") != -1 ) {
		call_out("do_leave", 5);
	}
	environment(this_object())->do_leave();
}


int leave() {
	if (this_player()->query("class")!="huashan") return 0;
	message_vision(CYN"$N����ͷ˵�����ðɡ�\n"NOR, this_object());
	message_vision(CYN"$N˵��ֻ�ǻ�ɽ�Ź�ɭ�ϣ���ˮ������ժ�ĵ��ؾ����ܴ��ߡ�\n"NOR,this_object());
	return 1;
}