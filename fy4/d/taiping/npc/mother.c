inherit NPC;
#include <ansi.h>
int talk_show();

void create()
{
    	set_name("��",({"mother"}));
    	set("title",YEL"����¥"NOR);
    	set("long","
����������ۣ�������ͷ���޻�����֬ŨĨ¶���������ٻ��綷������
����¥��һ����𱡣\n");
    	set("gender","Ů��");
    	set("age",55);
    	set("no_arrest",1);
    	
    	set("combat_exp",350000);  
    	set("attitude", "friendly");
    
	   	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		]) ); 
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		(:	talk_show() 	:),
    	}) );
    	setup();    
	carry_object(__DIR__"obj/ladycloth2")->wear();
}



int talk_show() {
	object ob,girl;
	ob=this_object();
	
	if (ob->query_temp("talking")) return 1;
	
	girl=present("bilian",environment(ob));
	if (!girl || girl->is_fighting()) return 1;
	call_out("event1",1,this_player(),0);
	ob->set_temp("talking",1);
	return 1;
}
	
	
	
string *event1_msg=	({
	
	
	
	CYN"\n    ������������������������Ż��е��о�ô����\n"NOR,
	
	CYN"    �����������о������ģ���\n"NOR,

 	CYN"    �������������Ż��˼ң�����Ů��������Ů���������ֵ�һ�������ģ�
�����Ǵ��˼�����һ�����������������Сʱ���Ͳ��÷紵�ô󣻵�����Ū
���󣬱���������죬����ָ�������������á�ǰ��ӭ�£������;ɣ�������
�ף������Ͳ��������֣����Ǹ�����������мҡ���\n"NOR,

    	CYN"    �����������ߴ���Ҳ��������£���\n"NOR,
	
	CYN"    �����Ц��һ�������������������£������ɵ���ģ�һ��֮�У�����
����������С�����������ѵ��������һ��Ƥ�ޣ�����㲻����������ʱ����
�㲻���ҵ�·������\n"NOR,

	CYN"    ���ֵ�������ʱ����Щʹ�಻����ֻ�ýӿͣ�ȴ����ǧ������Ū�õ�΢
�ˣ���Ҫ�������Ц��������˵����Ͱ��������������������ˡ�����ǧ��
��ϲ��������Ļ������Լ�����\n"NOR,


});



void event1(object me, int count)
{
	object ob,girl;
	ob=this_object();
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	
	girl=present("bilian",environment(ob));
	if (!girl || girl->is_fighting()) return;
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    ��������ͨ�죬����ͷһ�����ԡ�\n\n"NOR,me);
		ob->delete_temp("talking");
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}
	