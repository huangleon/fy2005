#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int recruit();
int diqi();

void create()
{
    	set_name("���㴨",({"lv xiangchuan","lv"}));
	set("title",WHT"���ʱ��"NOR);
	set("long","
���㴨�Ǹ���ɫ�԰ף����ʱ����ˡ����Ա���������͹�������������
��Ϊ����û��ʲô�˲������ִ��󲻵���Ц�����ҿ��¡����㴨����
����������������֣�Ҳ��������������ڰ�������֮һ��������
���ڻ���һ��İ�����������Ҳû���κ����ܱȵ���������\n");
   	
     	set("gender","����");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",9500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
		"���ϴ�":  	(: recruit() :), 
		"gao":  	(: recruit() :), 
		"����": 		(: diqi() :),
		"laobo":	"�ϲ��������񲮣�û��������֪���������Ǹ���ô�����ˡ�
���԰�����ϲ��ľӴ�����ݲ������ˣ������ǲ��������ġ�\n",
		"�ϲ�":		"�ϲ��������񲮣�û��������֪���������Ǹ���ô�����ˡ�
���԰�����ϲ��ľӴ�����ݲ������ˣ������ǲ��������ġ�\n",

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
    	carry_object("obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/throwing/qixing")->wield();
 
}

int recruit(){
	object me,ob = this_object();
	me = this_player();

	if (me->query("timer/��԰ʧ��") + 1440 > time()) {
		command("say �㻹����������\n");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"��԰����")) {
		command("say ���ϴ��ǿ���ֵ�Ů���ˣ��п������ȥ��������");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"��԰����")!=1) {
		command("say �úøɣ��ϲ����������ġ�\n");
		return 1;
	}
	
	message_vision(CYN"
���㴨��ζ���һЦ���������Ծ�԰�����Ѿã��ϲ���������֮�ʡ���
Ȼ�Ǹ��ϴ�����Ƽ��㣬����������ɡ�����������ھ�԰���Ĵ�Ѳ�ӣ�
�緢�ֿ��ɵ����£�����˳�����ϲ��ˮ��ʯ���ٻر����ҡ�

���㴨˵����Щ����԰�������ϳ�������Ӱ�㿣����������غ򿴸����ס�
\n"NOR,ob);
	REWARD_D->riddle_set(me,"��԰����",2);

	return 1;
}
	
void init()
{       
        object ob;

        ::init();
        if (environment(this_object())->query("home"))
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
	object me, chick;
	int stage;
        
    if( !ob || environment(ob) != environment() ) return;
	
	if (REWARD_D->check_m_success(ob,"��԰����"))	return;
		
	stage = REWARD_D->riddle_check(ob,"��԰����");
	
	switch (stage) {
		case 0:		command("say ����ʲô�ˣ���Ȼ��˽�Ի����԰������ȥ�ɣ�");
					return;
					
		case 1:		message_vision(CYN"
���㴨������˫Ŀ�����㣬�ƺ�һ�ۿ�����������⡣\n"NOR,ob);
					return;
		
		case 2:
		case 3:
		case 5: 		
		case 8:
					command("say "+ ob->name(1)+ "������԰����ɻ���ʲô����֮�£�\n");			
					return;
					
		case 4: 	message_vision(CYN"
���㴨��ζ���˵����������԰�й������ϲ��ҳ��˴̿ͣ��ܺã��ܺá�\n"NOR,ob);
					tell_object(ob,WHT"\n���ϲ���������γ̶�����ˣ���\n"NOR);
					REWARD_D->riddle_set(ob,"��԰����",5);	
					return;
					
		case 6: 	message_vision(CYN"
���㴨��ζ���˵�����ĵ�����֪���ˣ��������⣬��������Ťת��
������ְ�أ����ĺܺã��ܺá�\n"NOR,ob);
					tell_object(ob,WHT"\n���ϲ���������γ̶�����ˣ���\n"NOR);
					REWARD_D->riddle_set(ob,"��԰����",8);
					return;
		
		case 7: 	message_vision(CYN"
���㴨��ζ���˵�����ĵ�����֪���ˣ��������⣬��������Ťת��
����ϲ��İ�ȫ�͸��������ˡ�\n"NOR,ob);
					tell_object(ob,WHT"\n���ϲ���������γ̶�����ˣ���\n"NOR);
					REWARD_D->riddle_set(ob,"��԰����",8);
					return;
						
		case 9:		message_vision(CYN"
���㴨��ɫ����½�����ѱ�һ�£������ϲ����֮�£����㾹�������һ����
ʵ������ʧ������԰���ݲ����㣬�㻹���߰ɡ�\n"NOR,ob);
					ob->delete_temp("zangbei/see_lv");
					ob->delete_temp("marks/kuaihuo");
					REWARD_D->riddle_clear(ob,"��԰����");
					ob->set("timer/��԰ʧ��",time());
					tell_object(ob,WHT"\n�㱻�ϳ��˾�԰������\n"NOR);
					ob->move("/d/zangbei/garden1");
					return;
		
		case 10: 	message_vision(CYN"
���㴨��ζ���˵��½�����ѱ�һ�£������ϲ����֮�£��������Ȼ����
��԰�Ķ���֮�š�\n"NOR,ob);
					command("hmm");
					command("say ��½���첻�������Ǿ�԰���ĸ��󻼣�");
					return;
		case 11:	message_vision(CYN"
���㴨��ζ���˵��½�����ѱ�һ�£������ϲ����֮�£��������Ȼ����
��԰�Ķ���֮�š�\n"NOR,ob);
					tell_object(ob,WHT"\n���ϲ���������γ̶�����ˣ���\n"NOR);
					REWARD_D->riddle_set(ob,"��԰����",12);
				
		case 12:	if (ob->query_temp("marks/kuaihuo/lv_cook")) {	
						command("say �ϲ����ڵ��㣬��ȥ�ɡ�");
						return;
					}
							
					message_vision(CYN"
���㴨���͵�˵����һ�����������ˣ��ϲ�����ȥ�Է���
���㴨����һ���ֵ�����ֻ�缦�����������ģ�������ȥ���ϲ��������Ͼ͵���\n"NOR,ob);
					ob->set_temp("marks/kuaihuo/lv_cook",1);
					chick = new(__DIR__"obj/chicken");
					chick->set("item_owner",ob);
					chick->move(ob);
					return;
		
		}
	
}


int diqi(){
	object me, ob, paper;
	ob = this_object();
	me = this_player();
	
	if (REWARD_D->riddle_check(me,"��԰����")!=13) {
		message_vision("$N˵���ϲ��ĵز����Ӳ�������\n"NOR,ob);
		return 1;
	}
	
	if (me->query_temp("marks/kuaihuo/get_diqi")) {
		message_vision(CYN"���㴨˵������ֵĵ����Ҳ��Ѿ�������ô��\n"NOR,ob);
		return 1;
	}
	
	paper = new(__DIR__"obj/diqi");
	if (paper->move(me)) {
		message_vision(CYN"���㴨ת���ó�һ�ŷ��Ƶ��ż�ֽ�ݸ��㣬�����ҹ�ϲ���ϴ�����Ը��ʵ���ˡ���\n"NOR,ob);
		paper->set("item_owner",me);
		me->set_temp("marks/kuaihuo/get_diqi",1);
		return 1;
	} else {
		destruct(paper);
		message_vision(CYN"
���㴨˵�����еط��ŵ���ô����\n",NOR,ob);
		return 1;
	}
}


	