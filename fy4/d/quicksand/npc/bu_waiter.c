#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int shen();
void create()
{
    	set_name("��С��", ({ "sun xiaohong","sun" }) );
	set("gender", "Ů��" );
	set("age", 22);
    	set("title", "���ӹ���" );
	set("long", "������˵���Ů��,�ִֵı���,�����۾�,�ɰ����ˡ�\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϰ���");
	
	set("inquiry", ([
      		"�ϰ���":  (: shen() :),	
        	"��赾�" : (: shen() :),
        	"������": (: shen() :),	
        	"Ů�����": (: shen() :),		
   	]));
	set("vendor_goods", ([
		__DIR__"obj/bu1" : 10,
		__DIR__"obj/bu2" : 30,
		__DIR__"obj/bu3" : 10,
		__DIR__"obj/bu4" : 5,
	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
            say( "��С����˸��򸣣�Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "��Ҫ��ʲô��\n");
			break;
		case 1:
            say( "��С���ƺ��������������λ" + RANK_D->query_respect(ob)
                + "�������û������������Ѱ��������Ϣ��\n");
			break;
		case 2:
            say( "��С�������ʵ�����λ" + RANK_D->query_respect(ob)
                + "����֪��������Ϲٽ��һս������ô����\n");

			break;
	}
}

int shen() {
	message_vision(CYN"
��С��˦��˦�ֺ������Ĵ���ӣ�����Ц������˵�����˰�������ǰ����Ҳ���
�̸��Һ󣬾ͻ��޹�ɽׯ�˰ɣ�����Ů�����������������ҵ����������������
֮����ʵ�ڼ�����Ҳ�޲����ĸ�������\n\n"NOR, this_object());
	return 1;
}

int	accept_object( object who, object what) {
	
	if (what->query("name") == HIG"׺��÷����ɴ��"NOR) 
	{
		message_vision(CYN"
��С��˵����ɴ�������������ȥ�ģ�����������ǰ�������������ǰ���ϰ�
������������Ҳ��̫�����\n\n"NOR,who);
	}
	return 0;
}
