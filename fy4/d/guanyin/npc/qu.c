#include <ansi.h>
inherit NPC;
int direct();
int event1();
int event2();

void create()
{
        set_name("������", ({ "wurong" }) );
        set("title",WHT"��ɫ����"NOR);
        set("gender", "Ů��" );
        set("age", 22);
		set("long","
��̬�����ӯ��������˴�Լ����ϧ����ȫ���ǹ���һϮ����֮�ڣ�
Ҳ��֪�����������һ��"YEL"��ɫ����"NOR"����ò��\n");
	
		set("combat_exp", 1800000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"�����������������Ҫ���ȥ�����Ǳ�̧��ȥ����\n",
        }) );
        
        set("inquiry", ([
                "ʯ����" : 	(: direct :),
                "shi guanyin" : (: direct :),
				"master guanyin": (:direct :),
				"master shi": 	(:direct :),
				"��ɫ����":	(: event1 :),
				"��ò":		(: event1 :),
				"��":		"action�����������˵��֪���ˣ�����Թ��ˡ�\b",
				"����":		(: event2 :),
				"�����":	(: event2 :),
				"�㲻��":	(: event2 :),
        ]));

    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.yaozhan" :),
        }) );

    	set_skill("unarmed", 150);
    	set_skill("force", 100);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("kongshoudao", 150);
    	set_skill("ghosty-force", 150);
    	set_skill("ghosty-steps", 150);

    	map_skill("unarmed", "kongshoudao");
    	map_skill("blade", "wind-blade");
    	map_skill("force", "ghosty-force");
    	map_skill("dodge", "ghosty-steps");

        
        setup();
        carry_object(__DIR__"obj/bcloth")->wear();

}


int direct(){
	
	object me, ob;
	object room;
	me = this_player();
	ob = this_object();
	
	message_vision(CYN"$N��$n��Цһ�����������ʦ����\n"NOR,ob, me);
	if ( !REWARD_D->check_m_success(me,"����֮��")
		&& !me->query_temp("zangbei/����_�����ͱ�",1) 
		&& REWARD_D->riddle_check( me,"���˵ı���")!=3) {
		message_vision(CYN"������ô���׵��¶�����Ȱ�㻹�ǲ�Ҫȥ�����˰ɡ�\n"NOR,ob);
		return 1;
	}

	message_vision(CYN"���Ҿͳ�ȫ�㣡��\n",ob);
	room = load_object(AREA_GUANYIN"mirror");
	message_vision(YEL"$N����һ�ɣ������˲����ˣ�\n"NOR,me);
	me->move(room);	
    return 1;
}


int event1(){
	tell_object(this_player(),CYN"
������������Ц�����������ɫ�����ã��Ҿ����������ҵ������ɫ����

��������������˿�����Ц�����̾�����ס��

���������˵��������ֱ��ħ�����ò��

����Ҳ�벻������̬�����ӯ��������˴�Լ����Ů��һ�����������������

��˿��¡�

ֻ��������Ц�������������Ƽ����᣿����۸����治ǳ��������Ҳһ��Ҫ��

ס������������������"YEL"��"CYN"��Ů�ˣ���û�б��˱ȵ��ϡ���\n\n"NOR);
	this_player()->set_temp("guanyin/qu_beauty",1);
	return 1;
}


void init()
{
	::init();
	add_action("do_whisper","answer");
}

int do_whisper(string msg)
{
	object me,qu;
	string dest;
	me = this_player();
	qu=this_object();

	if (msg == "��") {
		tell_object(me,"�����������˵��֪���ˣ�����Թ��ˡ�\n");
		return 1;
	}
		

	if (msg == "�㲻�������" || msg == "�㲻�������" || msg == "�㲻��" || msg =="�����"
		|| msg == "����" )
	{
		if (!me->query_temp("guanyin/qu_beauty")) {
			message_vision(CYN"����������߳��������ȥ����ȥ�����ﲻ����໰�ĵط�����\n"NOR,me);
			return 1;
		}
		
		message_vision(CYN"
���������Ӿ���΢΢һ�𣬵������㡭����˵ʲ�᣿��\n"NOR,qu);
		tell_object(me,CYN"
�����ݳ���������㣬������Į�羮ˮ����۲��������ѱ�Ͷ����һ��ʯ�ӣ�
��������ƬƬ������\n"NOR);
		if (me->query_condition("no_force")) {
			tell_object(me,HIG"\n����������΢չ��һ�����µĻ���ӭ������������\n"NOR);
			me->change_condition_duration("no_force",0);
		}
	}
	else
		message_vision(CYN"����������߳��������ȥ����ȥ�����ﲻ����໰�ĵط�����\n"NOR,me);
		return 1;
}

int event2(){
	object me,qu;
	string dest;
	me = this_player();
	qu=this_object();

	if (!me->query_temp("guanyin/qu_beauty")){
		message_vision("$N����Ⱥɽ���ƺ�û������$n��˵����\n", qu, me);
		return 1;
	}
			
		message_vision(CYN"
���������Ӿ���΢΢һ�𣬵������㡭����˵ʲ�᣿��\n"NOR,qu);
		tell_object(me,CYN"
�����ݳ���������㣬������Į�羮ˮ����۲��������ѱ�Ͷ����һ��ʯ�ӣ�
��������ƬƬ������\n"NOR);
		if (me->query_condition("no_force")) {
			tell_object(me,HIG"\n����������΢չ��һ�����µĻ���ӭ������������\n"NOR);
			me->change_condition_duration("no_force",0);
		}
	return 1;
}	

