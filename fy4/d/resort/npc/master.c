inherit F_MASTER;
inherit SMART_NPC;

#include <ansi.h>
int leave();
int smart_fight();
int task1();

void create()
{
    	set_name("����", ({ "master tieshao", "master","tieshao" }) );
    	set("gender", "����" );
    	set("nickname", HIG "���鵶��"NOR);
    	set("long","
���ٴ�ʮ���꿪ʼ�ͺͰ���ѩ������������������ϱڣ������޵С�
��������������ʢ֮ʱ����Ȼ�˳������������ڴˡ�\n");

    	set("marry","master xuerui");
    	set("group","legend");
 		set("couple","tiexue");	
    	set("boss", 1);
    	set("age", 25);
    	set("combat_exp", 20000000);
    	set("score", 90000);
    	set("reward_npc", 1);
    	set("difficulty", 40);
    	set("fly_target",1);
    		
    	set("class","legend");	
    	set("apprentice_available", 50);
    	create_family("��ѩɽׯ", 1, "ׯ��");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"��ͯ","��ͯ","��ͯ","С��","����","����",
    		"����","����","����","����","��ʥ","����",WHT"����"NOR,
    		WHT"����"NOR,WHT"���ڴ���"NOR,HIW"��������"NOR}));
    	
   		set("inquiry", ([    	
        	"�������":	(: task1 :),
        	"����":		(: task1 :),	
        	"leave" : (: leave :),
    		]));
    
    
    	set_temp("pfm/qidaoforce_juqi",200+random(200));
    	
    	set_skill("force", 200);
    	set_skill("chanting", 180);
    	set_skill("parry", 170);
    	set_skill("dodge", 170);
    	
    	set_skill("perception", 150);
    	set_skill("move",150);
    	set_skill("unarmed", 160);
    	set_skill("blade", 250);
    	set_skill("literate", 100);
    	set_skill("foreknowledge",100);    	
    	set_skill("meihua-shou", 150);
    	set_skill("qidaoforce", 150);
    	set_skill("fall-steps", 150);
    	set_skill("dormancy",300);
    	set_skill("six-sense",300);
    	set_skill("shortsong-blade", 200);
    	

    	map_skill("unarmed", "qidaoforce");
    	map_skill("blade", "shortsong-blade");
    	map_skill("force", "qidaoforce");
    	map_skill("parry", "shortsong-blade");
    	map_skill("dodge", "fall-steps");

     	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
	}) );

    	setup();
    	carry_object(__DIR__"obj/whitecloth")->wear();
    	carry_object(__DIR__"obj/mblade")->wield();
}


void reset()
{
    	set("apprentice_available", 20);
}


void attempt_apprentice(object ob)
{
    	if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            	command("say ������һ��һ������");
        else
            	call_out("do_recruit", 2, ob);
    	} else {
        	command("say ��ׯ�������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
    	}
}


void do_recruit(object ob)
{
    	if( (string)ob->query("gender") != "����" )
    	{      	
    		command("say ��ֻ���е��ӣ��㻹��ȥ���ҵ����˰ɣ�");
    	}
    	else 
    	{
        	command("smile");
        	command("say ���պ���д�ɣ�");
        	command("pat "+ ob->query("id"));
        	command("recruit " + ob->query("id") );
    	}
}


int recruit_apprentice(object ob)
{
    		if( ::recruit_apprentice(ob) )
        		ob->set("class", "legend");
    		add("apprentice_availavble", -1);
}


int accept_fight(object me)
{
    	object xiaocui;
    	if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    	{	
        	command("smile");
        	command("say ������С�����ɡ�");
        	return 0;
    	}
    	else
        	command("sigh");
    		command("���������ĴӴ������վ���������������е���ɰ����");
    		command("say �룡");
    		call_out("do_unwie", 3);
    		return 1;
}


int do_unwie()
{
    	if( !this_object()->is_fighting())
    	{
        	message_vision("$N����豭ǳ�һ�ڣ���������������ѩ���һ�ۣ�����������ϡ�\n", this_object());
        	command("smile");
        	return 1;
    	}
    	else
        	call_out("do_unwie", 3);
}

void init()
{	
	object me;
	add_action("do_killing", "kill");
    	::init();
 
}

int task1() {
	
	object me = this_player();
	
	if ( me->query("class")!= "legend") {
		command("say ��ѩ��֮�£��������޹ء�");
		return 1;
	}
	
	if ( me->query_skill("six-sense",1) < 150)	{
		command("say ��ѧ��δ�ɣ��мɷ�������");
		tell_object(me, WHT"�����ܴ˿�����150�����鰵ʶ��\n"NOR);
		return 1;
	}
	
	if (REWARD_D->check_m_success( me, "��������")) {
		command("say �ú��ӣ����Ѿ�ͨ����������顣");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"��������") == 1) {
		command("say ��ȥ��ȥ��Ϊʦ���������");
		return 1;
	}
	
	command("say ����ǰС��·����ɽ����������ɮ��ɽ�����ƣ��������˼����������ˡ�
��˵�⼸��ɮ�˺ųơ�������𡻣��������š����Ҵ�Ϊʦ��һ�ˣ�������"YEL"�ϻ���
��"CYN"��Ҳ�����ǴӴ˲�����С����ԭ���֣�\n"NOR);
    
    REWARD_D->riddle_set(me,"��������",1);	
    return 1;
}


int leave() {
	if (this_player()->query("class")!="legend") return 0;
	message_vision(CYN"$N�����˸���־���Ҳ���ǿ�����¡�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵��ֻ�Ǿ����ķ��ǵ��Ӳ���ʹ�ã��̸赶���ľ�������Ҳ��᲻���ˡ�\n"NOR,this_object(),this_player());
	return 1;
}

int smart_fight(){
	object *enemy, me, ob;
	int i;	
	ob = this_object(); 
	enemy = ob->query_enemy();
	for (i=0;i<sizeof(enemy);i++){
		if (userp(enemy[i])) {
			switch (random(3)) {
				case 0: ccommand("perform dodge.luoyeqiufeng "+ enemy[i]->get_id()); break;
				case 1: ccommand("perform duangechangmeng "+ enemy[i]->get_id()); break;
				case 2: ccommand("perform duangechangmeng "+ enemy[i]->get_id()); break;
			}
			break;
		}
	}
	return 1;
	
}	
	
	
