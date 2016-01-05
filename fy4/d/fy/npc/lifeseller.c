
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("Ѧ����", ({ "hunchback xue","xue" }) );
	set("nickname","���˲�����");
	set("gender", "����" );
	set("age", 69);
	set("long",	"��λ�������ð׶���ٵ�˫�۶����㣬������������֮ɫ��
���̲�ס��ʩ��Щʲô������\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("inquiry", ([
		"ʩ��":		(: command("yao") :),
	]));
	set("per",30);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set("vendor_goods", ([
            __DIR__"obj/baozi1":30,
            __DIR__"obj/baozi2":30,
            __DIR__"obj/baozi3":30,
			__DIR__"obj/baozi4":30,
            __DIR__"obj/baozi5":30,

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
	switch( random(10) ) {
		case 0:
message_vision("$N�ð׶���ٵ��۾�����$nһ�ۣ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$N���˴��Լ����ӱ�˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô��\n",this_object(),ob);
			break;
		case 2:
message_vision("$N�ߵ�������ӻ����򣮣�����\n",this_object());
	}
}


int accept_object(object who, object ob)
{
        int val;
		object paper;

        who->add_temp("marks/xuetuozi",ob->value());
        
        if( who->query_temp("marks/xuetuozi") < 5000 ) {
        	command( "say ��л��λ" + RANK_D->query_respect(who) + "��������û�õ������ˣ�ֻ��ϧ����ˮ��н����\n");
            return 1;
        }

		paper = new(__DIR__"obj/baozhizhi");
		if( paper) {
			paper->set("targetprice", who->query_temp("marks/xuetuozi"));
			paper->move(who);
		}
		command("touch");
		tell_object(who,CYN"Ѧ����˵�������£�����Ϊл����
Ѧ�������ĵ�������һ�Ŷ���˵���ܾ���ǰ�������ȹ�һ���������ˣ�������ǰ����
���������˵����Ժ�����ʲô���£����߱����۸��ˣ�ֻҪ������ֽ��д���Լ�
�����ַŵ��������ĳһ���ط������ͻ���Լǰ����������һ������ͷ������ˣ�
�͸���ɡ�\n"NOR);
		who->delete_temp("marks/xuetuozi");
		return 1;		       
}

void reset()
{
	set("vendor_goods", ([
                __DIR__"obj/baozi1":30,
                __DIR__"obj/baozi2":30,
                __DIR__"obj/baozi3":30,
		__DIR__"obj/baozi4":30,
                __DIR__"obj/baozi5":30,

	]) );

}
