inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("����",({"bilian"}));
    	set("title",YEL"����¥"NOR);
    	set("long","
�������󣬱����֬��������ʵ�������������������Ӵ�С������������¥��
û����֪����Ҳû���˹��Ĺ����������֡�����ԭ��ֻ�Ǹ�����Щ��ƶ���
���ӣ����������ˣ������������ҡǮ���ˡ�\n");
    	set("gender","Ů��");
    	set("age",15);
    	set("no_arrest",1);
    	set("per",60);
    	
    	set("combat_exp",250000);  
    	set("attitude", "friendly");
    
   	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	]) ); 
    	
    	set("chat_chance",1);
    	set("chat_msg",({
//		"��������ͨ�죬����ͷһ�����ԡ���\n",	
    	}) );
    	setup();    
	carry_object(__DIR__"obj/ladycloth2")->wear();
}


void init()	{
	::init();
	add_action("do_enjoy","enjoy");
}


int 	do_enjoy(){
	message_vision(CYN"$N˵����Ҫ�һ�ͣ����Ǽ����������衣��������ʱ������ʹ�á���\n"NOR,this_object());
	return 1;
}
