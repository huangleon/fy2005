inherit NPC;
inherit F_VENDOR;

#include <ansi.h>

int show_me();

int annie_drug()
{
	object me = this_player();

	if (me->query_temp("annie/find_herb/����") 
		&& me->query_temp("annie/find_herb/������") 
		&& me->query_temp("annie/find_herb/��С��") 
		&& me->query_temp("annie/find_herb/����") 
		&& me->query_temp("annie/find_herb/����ѩ") 
		&& me->query_temp("annie/find_herb/Ҷ��ʿ")	)
	{
		message_vision(query("name")+"�ɵ�����Ҷ���֪�����ǡ����ǡ���\n",me);
		message_vision(query("name")+"ͻ��һ��ͷЦ�����㿴������ԣ���������÷��������\n",me);
		return 1;
	}

	if (me->query_temp("annie/find_herb/����"))
	{
		message_vision(query("name")+"ҡͷ������ίʵ����������\n",me);
		return 1;
	}
	message_vision(query("name")+"��ü˼���˰��Σ����̲ݣ���ˡ������֪������������\n",me);

	message_vision(query("name")+"˵����"+"��˵ҽ��Ҷ��ʿ�ð��Ƴ�����ȥ��������������ȥ���Ƶ����ʡ�\n",me);
	me->set_temp("annie/find_herb/����",1);
	return 1;
}

void create()
{
	set_name("����", ({ "pu sheng","sheng" }) );
	set("gender", "����" );
	set("age", 31);
	set("title", GRN "������"NOR);
	set("long",
		"��λ�������ϰ��书��ҽ����տ����������������\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	
	set("inquiry", ([
        	"����" : 	(: show_me :),
        	"���̲�" : 	(: annie_drug :),
        	"�ձ����ʽ" : 	(: show_me :),
             	"ҩ��" :	"��ÿ�쿪��ҩ���ɰ���ǧ�����ʵ�����һ�ţ�\n",
             	"������" :	(: show_me :),
             	"ҩ����" :	"��ÿ�쿪��ҩ���ɰ���ǧ�����ʵ�����һ�ţ�\n",
   	]));
	
	
	set("vendor_goods", ([
                __DIR__"obj/sendrug":200,
                __DIR__"obj/keedrug":200,
                __DIR__"obj/gindrug":200,

	]) );
	set_skill("unarmed",100);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("changquan",150);
	set_skill("move",150);
	map_skill("unarmed", "changquan");
	
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
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
	switch( random(20) ) {
		case 0:
message_vision("$N����$nһ�ۣ�����˵��������Ƽ��ݣ���ˮ���գ��Ƿ񣮣������ȣ�\n",this_object(),ob);
			break;
	}
}


int show_me() {
	command("say Ŷ�����ʵ���������ǰ�����Ǹ��հ�ʽ��ҩ���ɣ�������ʮ�ֺ�����ֻ������ز��С�");
	command("say ������һ���˲����������㣬���ǽ���Ϊ�������㡱��");
	return 1;
}

void reset()
{
	set("vendor_goods", ([
                __DIR__"obj/sendrug":12,
                __DIR__"obj/keedrug":22,
                __DIR__"obj/gindrug":12,
	]) );
}

