#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
#include <dbase.h>

void create()
{
        set_name("����ֱ", ({ "bu gongzhi","bu" }) );
        set("gender", "����" );
        set("title", "�������");
        set("long","
���������۾��ǰ���ȥ�ģ�ȧ��ȴ�߸���������ͷ�����д��ƣ�������Щ��
�����۾�ȴ��Щ���̡������ż��ǻ����������������������𻷣�����ȴ����
����Ϊ���أ��������ϵ�Ц�ݣ�ȴ�Ǻ��Ƶġ�\n"  
                );
        set("attitude", "friendly");
	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(:perform_action,"unarmed.mukuha":),
              }));
	set("age", 45);
        
        set("combat_exp", 2700000);

        set("chat_chance", 1);
        set("chat_msg", ({
		"����ֱ�������������صĹ�â�����㡣\n",
                }) );

        set_skill("unarmed", 200);
        set_skill("enmeiryu", 150);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("ghosty-steps", 100);
        map_skill("dodge", "ghosty-steps");
        map_skill("unarmed", "enmeiryu");
        
        set("vendor_goods", ([
		"/obj/medicine/herb_a1" : 50,
		"/obj/medicine/herb_a2" : 50,
		"/obj/medicine/herb_a3" : 50,
		"/obj/medicine/herb_a4" : 50,
		"/obj/medicine/herb_a5" : 50,
		"/obj/medicine/herb_b1" : 50,
		"/obj/medicine/herb_b2" : 50,
		"/obj/medicine/herb_b3" : 50,
		"/obj/medicine/herb_d09" : 50,
		"/obj/medicine/herb_d1" : 50,
		"/obj/medicine/herb_d10" : 50,
		"/obj/medicine/herb_d11" : 50,
		"/obj/medicine/herb_d12" : 50,
		"/obj/medicine/herb_d2" : 50,
		"/obj/medicine/herb_d19" : 50,
		"/obj/medicine/herb_d20" : 50,
		"/obj/medicine/herb_d21" : 50,
		"/obj/medicine/herb_d22" : 50,
		"/obj/medicine/herb_d29" : 50,
		"/obj/medicine/herb_d30" : 50,
		"/obj/medicine/herb_d3" : 50,
		"/obj/medicine/herb_d31" : 50,
		"/obj/medicine/herb_d32" : 50,
//		"/obj/medicine/herb_r"	: 50,
		
  
	]) );
        
                
        setup();
	carry_object("obj/armor/cloth")->wear();

}

void init()
{	
	object ob;
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
		"/obj/medicine/herb_d09" : 50,
		"/obj/medicine/herb_d1" : 50,
		"/obj/medicine/herb_d10" : 50,
		"/obj/medicine/herb_d11" : 50,
		"/obj/medicine/herb_d12" : 50,
		"/obj/medicine/herb_d2" : 50,
		"/obj/medicine/herb_d19" : 50,
		"/obj/medicine/herb_d20" : 50,
		"/obj/medicine/herb_d21" : 50,
		"/obj/medicine/herb_d22" : 50,
		"/obj/medicine/herb_d29" : 50,
		"/obj/medicine/herb_d30" : 50,
		"/obj/medicine/herb_d3" : 50,
		"/obj/medicine/herb_d31" : 50,
		"/obj/medicine/herb_d32" : 50,
//		"/obj/medicine/herb_r"	: 50,
		
  
	]) );
	
}


int legit_buyer(){
	if (this_player()->query("class")!= "knight") {
		ccommand("say С��ֻ������ֹ˿͵����⡣");
		return 0;
	}
	return 1;
}