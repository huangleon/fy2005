#include <ansi.h>
#include <command.h>
inherit INQUIRY_MSG;
inherit SMART_NPC;

void create()
{

		set_name("�ƴ�",({"tang da","tang"}));
    	set("title",RED"����ӧñ�Ĺٲ�"NOR);
    	set("long", "�ƴ�������ţ��ǳ�Ц���¾���ҩ���������֮һ������ʲô����ֻҪ����������
�����֣������ܹ��ֱ�ó���\n");
		set("age",47);
		set("combat_exp", 6000000);
	        set("attitude", "friendly");	
	
		set("reward_npc",5);
		set("inquiry", ([
        	"������" : "������ԭ������˫���콶���䣬����ѪҺ����������������һ����ҩ��
ȴ���Բ��Ƕ�ҩ��",
		"red bat" : "������ԭ������˫���콶���䣬����ѪҺ����������������һ����ҩ��
ȴ���Բ��Ƕ�ҩ��",
		"bat" : "������ԭ������˫���콶���䣬����ѪҺ����������������һ����ҩ��
ȴ���Բ��Ƕ�ҩ��",
        	 "�۵���" : "�۵������������־��ǲɻ���ඣ������ֻ֣������©���������ˡ�",
           	 "����": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
           	 "tie hen": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
           	 "tiehen": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
   		]));
	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	
        ]) );    	
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) ); 		

		auto_npc_setup("wang",250,200,1,"/obj/weapon/","fighter_w","herb",1);
	
		set_skill("iron-cloth",150);
		set_skill("xisui",100);
		map_skill("iron-cloth","xisui");
		
	setup();
	carry_object(__DIR__"obj/o_cloth3")->wear();
	carry_object(__DIR__"obj/redhat")->wear();
}

int accept_object(object who, object ob)
{
	if( ob->name()==HIR"��ʯ"NOR) {
                command("hmm");
		who->set("marks/parrot/��ʯ������",1);                 
        	call_out("event1",1,who,0);
        	return 1;
        }     
        if (ob->is_corpse())
     		command("say ��ʬ���ֶ������ֺ�Ϸ��");   
        return 0;
} 

string *event1_msg=	({
	
	CYN"\n  �ƴ�˵����������Ĳ��Ƕ�ҩ������\n",
	
	CYN"  ������ʯ����ͨ��ʯͷ��ֻ��Ϊ��"NOR+HIR"������"NOR+CYN"��ѪҺ�н����൱ʱ�����Բű��
��Ѫ�����ɫ��\n"NOR,

    	CYN"    Ҫ��ʯͷ�������ɫ��������Ҫʱ�䣬���������ѪҺ��������ʯͷ��ֱ����
��"+HIR"������"NOR+CYN"�Ľᾧ���ͷ���ˮ��Ƭ�̣�����ˮ���µ������Ů�ˣ���ʹ��������ҵ�
Ů�ˣ�ֻ��Ҳ�����Լ�������˵�����\n"NOR,
	
	CYN"    ������ҩ�������������֣���Ψһ�ǵþ�ֻ�С�ǧ��̤����"+HIM"�۵���"NOR+CYN"����֮�Ա�
���ϱ���������Ҹ�Ů������\n"NOR,

});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) 
		|| this_object()->is_fighting()) 	return;
	message_vision(event1_msg[count]+"\n",me);
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    ���ǣ�"+HIM"�۵���"NOR+CYN"���ڶ���ǰ������"+WHT"����"+CYN"���¡���\n"NOR,this_object(),me);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}