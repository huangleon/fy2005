//QCed and Modified by Tie
#include <ansi.h>
inherit NPC;  
inherit F_VENDOR;
int tell_test();

void create()
{
        set_name("С��", ({ "xiaofan" }) );
        set("gender", "����");
        set("age", 22);
	set("long",
		"��С���������Ÿ����ӣ��������Ÿ��ƺ��������οͶ���ʳƷ��\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		"/obj/food_item/wineskin":10,
		"/obj/food_item/dumpling":10,
		"/obj/food_item/chicken_leg":10,
	]) ); 
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :),
	}));
    	setup(); 
	carry_object("/obj/armor/cloth")->wear();
	
}

void init()
{
       ::init();
	if(interactive(this_player()) && !is_fighting()) {
		call_out("greeting", 1, this_player());
	}
	add_action("do_vendor_list", "list");
}      


int greeting(object me)
{
	message_vision("\nС�������������Ⱥ��Ŀ����ȼ����ơ�\n", this_object());
	return 1;
}

