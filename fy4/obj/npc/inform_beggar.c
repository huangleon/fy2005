#include <ansi.h>
inherit SMART_NPC;

int talk_show();

void create()
{
        set_name("������˪������ؤ", ({ "beggar courier"}) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ��������˪֮ɫ������ؤ���������쿴����Χ���Ρ�\n");
        set("combat_exp", 4000000);
		set("altitude", "friendly");			
		set("title","ؤ��Ŵ�����");
		set("class","beggar");
        set("inform_target",1);
        
		set("chat_chance",1);
    	set("chat_msg",({
			"����ؤ�����ָ�ִ����С��壬�����û�������������"YEL"������"CYN"��\n"NOR,
    	}) );  
                
        set("inquiry", ([
        	"������":	(: talk_show() :),
        ]));
                      
        set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(20) :),
	     }) ); 		
	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object("obj/armor/cloth")->wear();
}

int talk_show() {
	object ob,girl;
	ob=this_object();
	if (!this_player())	return 1;
			
	if (ob->query_temp("talking")) return 1;
	message_vision("\n����ؤ�����ָ�ִ����С��壬�����û�������������\n\n"NOR,ob);
	call_out("event1",1,this_player(),0);
	ob->set_temp("talking",1);
	return 1;
}

string *event1_msg=	({
	CYN"\n    ����ણ�����ણ�����������ડ�\n"NOR,
	CYN"    һ������һ���壬��λ�������ҳ���\n"NOR,
 	CYN"    ������ɶ�����ѣ�һ����ˮһ��̾��\n"NOR,
	CYN"    �����֣������䣬��һ�䣬��һ�䡣\n"NOR,
    CYN"    ����������κ������죬���˱���欣���ôҲ���ɣ�\n"NOR,
	CYN"    ��Ů�����죬�а������ᣬ��Ҳû����������û��ů��\n"NOR,
 	CYN"    ��Ǯʱ����Ҳ�Ǹ߳������Ž��ۣ������徭��������\n"NOR,
	CYN"    ����ʱ����Ҳ�ܷ����������ķ����쵱�����ص�����\n"NOR,
    CYN"    ֻ��û�����˰飬��ҹ���������߰��������ߣ�\n"NOR,
});

	
void event1(object me, int count)
{
	object ob,girl;
	ob=this_object();
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	
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

    	
