#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

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


	if (me->query_temp("annie/find_herb/����ѩ"))
	{
		message_vision(query("name")+"ҡͷ��������Ĳ��ǵ��ˡ�\n",me);
		return 1;
	}
	message_vision(query("name")+"�ü���������֣�������������������������\n",me);
	message_vision(query("name")+"ҡͷ�����������ǲ����ˣ���ȥ����������ɡ�\n",me);
	me->set_temp("annie/find_herb/����ѩ",1);
	return 1;
}

int tell_him();
void create()
{
    set_name("����ѩ", ({ "baili snow","baili" }) );
    set("gender", "Ů��" );
    set("title","��ũ�� С�ϰ�");  
    set("nick",HIW"��ѩ����"NOR);
    set("age", 22);
    set("long", "�������Զ��ֶŮ���������°�Ψһ�Ĳ���������ũ�ӡ�\n");
    set("combat_exp", 100000);
    set("attitude", "friendly");
    set("chat_chance", 1);
    set("chat_msg", ({
	"����ѩС��������Ų�ҩ���ƺ���û��ע����ĵ�����\n",
      }) );

	  	set("inquiry", ([
        	"���̲�" : 	(: annie_drug :),
   	]));
	

    set("vendor_goods", ([
//	"/obj/medicine/herb_annie_resurrect1" : 10,
//	"/obj/medicine/herb_annie_resurrect2" : 10,
//	"/obj/medicine/herb_annie_resurrect3" : 10,
//	"/obj/medicine/herb_annie_resurrect4" : 10,
//	"/obj/medicine/herb_annie_resurrect5" : 10,
	"/obj/medicine/herb_a1" : 50,
	"/obj/medicine/herb_a2" : 50,
	"/obj/medicine/herb_a3" : 50,
	"/obj/medicine/herb_a4" : 50,
	"/obj/medicine/herb_a5" : 50,
	"/obj/medicine/herb_b1" : 50,
	"/obj/medicine/herb_b2" : 50,
	"/obj/medicine/herb_b3" : 50,
	"/obj/medicine/lotus"	: 50,

      ]) );
    setup();
    carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
    ::init();
    add_action("do_vendor_list", "list");
}


void reset(){
	    set("vendor_goods", ([	
	"/obj/medicine/herb_a1" : 50,
	"/obj/medicine/herb_a2" : 50,
	"/obj/medicine/herb_a3" : 50,
	"/obj/medicine/herb_a4" : 50,
	"/obj/medicine/herb_a5" : 50,
	"/obj/medicine/herb_b1" : 50,
	"/obj/medicine/herb_b2" : 50,
	"/obj/medicine/herb_b3" : 50,
	"/obj/medicine/lotus"	: 50,
	
      ]) );
}