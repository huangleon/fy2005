#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

int show_me();
int ask_tie();

void create()
{

		set_name("�����ѵ�С����",({"redgirl","girl"}));
    	set("title","����¥");
    	set("long", "�����׺����ѵ�С���һ˫���Ӻ�����ᡣ\n");
		set("age",40);
		set("combat_exp", 7000000);
        	
	
		set("inquiry", ([
        	"Τ����" : 	(: show_me :),
           	"wei qiniang" : (: show_me :),
           	"tie hen" : 	(: ask_tie :),
           	"����" : 	(: ask_tie :),
   		]));
	
	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	
    	
		auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
		set_skill("tanzhi-shentong",160);
		setup();	
		carry_object(__DIR__"obj/redskirt")->wear();
		carry_object(__DIR__"obj/needle")->wield();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
	if(arg == "redgirl" || arg == "girl"){
		write("�����׺����ѵ�С���һ˫���Ӻ�����ᡣ\n");
		write("��������Լʮ���ꡣ\n");
		write("�����Ĳ��ֲ��ݣ��书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
		write("�����������������۷�״̬��\n");
		write("�������ȹ(Red skirt)\n");
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	if( ob->name()==HIG"����"NOR) {
    	if (REWARD_D->riddle_check(who,"�Ѫ����")==4
    		 && who->query_temp("marks/parrot/ask_wei")) {
            
            command("say ԭ����������ͷ�����ѣ��ղ�ʧ���ˡ��˵��˶��ӣ�����̸��֮�ء�");
            command("say ���������ȥ��������վ�İ��Ӻ�����˵���ҽ���ȥ�ġ�");
            REWARD_D->riddle_set(who,"�Ѫ����",5);
 //         who->set("marks/parrot/Τ����",1);
            return 1;
		}                 
        	command("say ��λ"+RANK_D->query_respect(who)+"�����������͸������ǰɡ�");
        	return 0;
        }        
        return 0;
} 


int show_me()	{
	
	if (this_player()->query("marks/parrot/Τ����"))
		ccommand("say ���ޣ����Ӻ����Ҷ���׷��̫ƽ����ʧ���鱦�����䡣");
	else {
		command("ack "+this_player()->get_id());
		this_object()->set("name","Τ����");
		this_player()->set_temp("marks/parrot/ask_wei",1);
		command("say �㾹Ȼ֪���ҵ���������������ǰ���ڽ��������꣬��̫���ˡ�");
		command("say ������ֻ������¥һ�����ŵ�Ѿͷ��");
	}
	return 1;
}


int ask_tie()  {
	
	object who;
	who=this_player();
	if (REWARD_D->riddle_check(who,"�Ѫ����")>=5)
		ccommand("say ���ޣ����Ӻ����Ҷ���׷��̫ƽ����ʧ���鱦�����䡣");
		else
		ccommand("say ���ޣ��ǲ���������������Ҵ仨����λ��ү��");
	return 1;
}	

