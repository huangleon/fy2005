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
		"��С���������Ÿ������ӣ�����ϵ��ͭ�壬��ס�������졣\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		"/obj/food_item/wineskin":10,
		"/obj/food_item/dumpling":10,
		"/obj/food_item/chicken_leg":10,
	]) ); 
        set("inquiry", ([
                "����" : (: tell_test :),
		"beauty" : (: tell_test :),
        ]) );
        set("chat_chance", 1);
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

int tell_test()
{
	object	me;

	me = this_player();
		
		command( "careful");
		command( "say ��ô�����˵���������û�����ˣ�");

	return 1;
}

int greeting(object me)
{

		message_vision(HIR "\nС��С���ֹ�����̯�ˣ���ô�����ˣ�����û�����ˡ�\n"NOR, this_object());

	return 1;
}

int accept_object(object me, object obj)
{
	object pai;
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"��С����������밲�ˡ�");
        return 1;
}
