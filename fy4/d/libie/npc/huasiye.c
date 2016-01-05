
#include <ansi.h>

inherit NPC;

int answer_self();
int answer_qinglong();
int answer_di();

void create()
{
        set_name("����ү", ({ "hua siye","hua","siye" }) );
        set("long","
����ү��ǰ�������׸������øߴ󡢷�׳�����ཱུ�һ������͸�ųϿҡ�
���ģ��ƺ���һ���թ��û�С����˿̣����Ĺ�������ȴ������������
���˸е�����������\n");

        set("attitude", "friendly");
        set("title", "��������");
	set("age",53);
        set("agi", 60);
	set("class","wudang");
	
        set("combat_exp", 4000000+random(500000));
	
	set_skill("unarmed",200);
	set_skill("taiji",200);
	set_skill("parry",400);
	set_skill("dodge",400);
	set_skill("five-steps",150);
	map_skill("unarmed","taiji");
	map_skill("dodge","five-steps");
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"����ү��ҵ�����������߻ص���....�һ������ĺòҰ�....\n"
	}) );

        set("inquiry", ([
                "���" : 	"���������Ĳ�ͷ����˵�������Ե���͵��һ�ٰ�ʮ����������\n",
                "yang" :  	"���������Ĳ�ͷ����˵�������Ե���͵��һ�ٰ�ʮ����������\n",
                "yang zheng" : 	"���������Ĳ�ͷ����˵�������Ե���͵��һ�ٰ�ʮ����������\n",
                "������" : 	(: answer_di :),
                "di qinglin" :  (: answer_di :),
                "������":	"��������һ�����Ӵ��������֯���İ������������д���δ�й���
��������Ӵ����ܵ���֯�� \n",
		"������ˮ":	(:answer_qinglong:), 
		"��������":	(:answer_qinglong:),
		"���³���":	(: answer_self :),
		"������ˮ����������":	(:answer_qinglong:),
		"������":	"�����㻹������һ�����򣬵�ððʧʧ�������������㣿\n",
		"������":	"�����㻹������һ�����򣬵�ððʧʧ�������������㣿\n",
        ]));

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: perform_action("unarmed.nianzijue") :),
        }) );


        setup();

        carry_object("/obj/armor/cloth")->wear();
}

int is_ghost() { return 1; }


int answer_qinglong(){
	object me= this_player();
	
	if (!me->query_temp("libie/friend_hua"))
		message_vision("����ү��ɫ������������ˮ���������죬�㡢�����ܶ��ʲô�ˣ�\n",me);
	else
		message_vision("����ү�޺޵�˵��һ��Ҫ���ұ�����Ѫ�����\n",me);
	me->set_temp("libie/qinglong_hua",1);
	return 1;
}


int answer_self(){
	
	object me = this_player();
	
	if (!me->query_temp("libie/qinglong_hua") || !me->query("libie/huzi"))
	{
		command("say ���³�������ʮ���أ��������ڹ�����û�·ݵ����ӣ�\n");
		return 1;
	}
	
	tell_object(me, "����ү�����ã���Ȼ��֪�Ҵ��ţ�Ӧ���ܶ�֮�ˣ�\n");
	tell_object(me,"����ү�޺޵�˵�������룬������������棬ǧ���ܷŹ�����\n");
	me->set_temp("libie/friend_hua",1);
	return 1;
}
		
	
	
int answer_di()
{
	object me;
	string msg;
	
	me=this_player();
    	if (!me->query_temp("libie/friend_hua"))
    	{
    		msg= "����үԹ����˵��������Ϊ�����ݣ��в��������������м��мǡ�\n";
    		tell_object(me, msg);
    		return 1;
    	}
    	msg = "
����ү�޺޵�˵������˵�������������롢�Һ����÷���ͷ֮����������������
����ϸ���ڹ����ܶ��С�ഫ��Ҫ���������˵����룬û�뵽��������С��
�ĺ������ֹ�ƶ�ˣ�����ɱ��С�࣬����Ҳ���ڷ�����������һ���ӵ�Ǯ����
ô���˲�����ѽ������\n";
	tell_object(me,msg);
    	me->set_temp("libie/di_2",1);
	return 1;
}
