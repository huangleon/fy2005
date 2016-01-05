inherit NPC;
#include <ansi.h>

int startit();
int do_answer(string arg);

void create()
{
        set_name("����ѩ", ({ "hongxue", "fu hongxue", "fu hong xue" }) );
        set("gender", "����" );
        set("age", 24);
        set("title","���ڵ�����");
		set("attitude","friendly");
        
        set("reward_npc", 1);
		set("difficulty", 5);
        
        set("long","����ѩ���������ŵ���һ����״�����صĵ���������ڣ�������ڡ�
����������ʲô��ʱ��û�зŹ��������\n");

        set("combat_exp",4000000);
        set("score", 1000);
	
	
		set("inquiry", ([
        	"��Ũ" :	(: startit() :),	
        	"cuinong" :	(: startit() :),	
        	"cui nong" :	(: startit() :),	
        	"*":		(: message_vision("����ѩһ��һ���غ��žƣ��ƺ�û��������Ļ���\n",this_object()) :),
   		]));
   		
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ѩ�ٺȣ������������ѣ������������ϡ�������������ȫ�����������С�\n",
                "����ѩ�յ��Ĳ԰׵��֣�ȴ������Щ������\n",
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("blade", 300);
        set_skill("shortsong-blade",160);
        set_skill("fengyu-piaoxiang",200);
        set_skill("meihua-shou",200);
        set_skill("unarmed",200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
		if (!random(10)) carry_object(__DIR__"obj/fbblade")->wield();
		else carry_object(__DIR__"obj/bblade")->wield();
}

void init(){
	::init();
	add_action("do_answer","answer");
}


int startit() {
	object me = this_player();
	int stage;
	
	stage = REWARD_D->riddle_check(me,"�����ƺ�");
	
	if (!stage || stage == 1)	{
		command("say �㡭���㡭����֪������������������");
		tell_object(me,"��answer ĳ���ݣ������Ƿ����н����г��õ�����\n");
		if (!REWARD_D->riddle_check(me,"�����ƺ�"))
			REWARD_D->riddle_set(me,"�����ƺ�",1);
		me->set_temp("marks/fuhong_ask",1);
		return 1;
	}
	
	if (stage == 2)
		command("say ��Ũ����Ũ˵��Щʲô��");
	else if (stage == 3)
		command("say ��ȥ����ȥ�Ҵ�Ũ��");
	
	return 1;
		
}


int do_answer(string arg){
	int stage;
	object me;
	
	me = this_player();
	stage = REWARD_D->riddle_check(me,"�����ƺ�");
	
	if (!me->query_temp("marks/fuhong_ask")) {
		message_vision("����ѩ�������$N�������������ĵ�������û�аγ�������ȴ�����¡�\n",me);
		command("say �㡭������˵�ˣ���֪�����������ˣ��Ǹ�����һ���ߵġ�");
		if (!REWARD_D->riddle_check(me,"�����ƺ�"))
			REWARD_D->riddle_set(me,"�����ƺ�",1);
//		me->delete_temp("marks/fuhong_ask");
		return 1;
	}
	
	switch (stage) {
		case 0:
		case 1:		tell_object(me,"����ѩһ��һ���غ��žƣ��ƺ�û��������Ļ���\n");
					break;
		case 2:		
		case 3:		if ( arg == "�������Ҷ����ˣ���Ҳ�������ȥ��" 
						|| arg == "�������Ҷ����ˣ���Ҳ�������ȥ") {
						message_vision(CYN"
һ˲�䣬����ѩ������ȫ���ˡ������ı��ǽ��������ŵģ�������һ�ű�
���������ĵ�ֽ�������������ѿ�չ������̬�Ⱥ�Ȼ�ֱ�ó��������ţ�
��Ϊ����֪�����������˲�û�б����������յ������ֱ�ó�����򶨡�"CYN"

����ѩ˵������ȥ����������������ô�������Ѿ��ǹ�ȥ�����ˣ�������
"YEL"����ȥ���������ǣ�\n"NOR,me);
						REWARD_D->riddle_set(me,"�����ƺ�",3);
					} else
						tell_object(me,"����ѩ��һ����ֵ��������㣬�ƺ��ڿ�һ�����ӡ�\n");
					break;
	}
	return 1;
}