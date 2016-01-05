inherit NPC;
#include <ansi.h>
int talk_show();

void create()
{
	set_name("ϴ�¸�", ({ "laundry woman","woman" }) );
	set("gender", "Ů��" );
	set("cor",20);
	set("age", 42);
	set("long","
�����ĺ�ɫ���������ɫ�������ֱۻ�Բ����ɫ��ͭ������ͭ�ζ�����
���شֱ�������ɳ�͹��ĺ��몲��۴�����ֱ׹�ű���\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	set("chat_msg",({
		(:  talk_show() :),
    	}) );  
	
    		
	set_skill("hammer",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("unarmed",200);
		
	setup();
	carry_object(__DIR__"obj/tcloth")->wear();
	carry_object(__DIR__"obj/l_hammer")->wield();
}


int talk_show() {
	object ob,girl;
	ob=this_object();
	
	if (ob->query_temp("talking")) return 1;
	if (random(3)) {
		message_vision("\nϴ�¸��Ѽ�������Χȹƽ���ڴ�ʯ�ϣ�����ϴ�´������ô�������\n\n"NOR,ob);
		return 1;
	}
	
	girl=present("laundry girl",environment(ob));
	if (!girl || girl->is_fighting()) return 1;
	call_out("event1",1,this_player(),0);
	ob->set_temp("talking",1);
	return 1;
}
	
	
	
string *event1_msg=	({
	CYN"\n    ϴ�¸�Ц������˵�������꣬�������ֳ��������ˣ���\n"NOR,
	
	CYN"    ��Ů˵�����裬����˵�Ķ�ȥ�ˣ�����ȥ�ݶ�����ѧ��������\n"NOR,

 	CYN"    ��Ů�Ȼ��˸����ƣ���ˢ��һ���׹����ͷ������������������\n"NOR,

    	CYN"    ϴ�¸����ȵذ���һ����\n"NOR,
	
	CYN"    �����꣬�����������Ժ��û�������ˣ����ʿ��ڵ���ѽ����\n"NOR,

	CYN"    ��Ů��ڵ��һЦ�����裬�Ҵ���ѧ�����ٻ��ס���\n"NOR,

    	CYN"    ��Ů�յ�ϴ�¸����������˵��������˵�ˣ���Ҳ������ô��������ȥѧ�ա���\n"NOR,

	CYN"    ϴ�¸�����ԥԥ��˵�������ô����˾��������´�����ʮ�꣬���ڿ���ɽ���ء���\n"NOR,


});


void event1(object me, int count)
{
	object ob,girl;
	ob=this_object();
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	
	girl=present("laundry girl",environment(ob));
	if (!girl || girl->is_fighting()) return;
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    ��������������\n\n"NOR,me);
		ob->delete_temp("talking");
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}
	