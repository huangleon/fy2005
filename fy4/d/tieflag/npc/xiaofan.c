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
		"��С���������Ÿ����ӣ��������Ÿ��ƺ�������ϵ��ͭ�壬��ס�������졣\n");
		set("combat_exp", 5);
		set("attitude", "friendly");
		set("rank_info/respect", "С����");
		set("vendor_goods", ([
			"/obj/food_item/wineskin":	99,
			"/d/tieflag/npc/obj/beefmeat":	99,
			"/d/tieflag/npc/obj/dongskin":	99,
	          	"/obj/food_item/dumpling":	99,
			"/obj/food_item/chicken_leg":	99,
		]) ); 
        set("inquiry", ([
                "����" : (: tell_test :),
				"beauty" : (: tell_test :),
				"leaf" : (: tell_test :),
				"��Ҷ" : (: tell_test :)
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��������˵���ղ���λ���˸���һƬ"YEL"��Ҷ"NOR"��������\n"
        }) ); 
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
		
		if (!me->query_temp("mark/����")){
			command("consider");
			command("say ���¶�����û��ϵ�ɡ�");
			return 1;
		}
			
		command( "say ����������Ϊ���������������߹���");
		command( "say ����һλ����˵Ҫ�ҵ���·�ϣ�");
		command( "say ����������������û���Ƽ�·��һ�����ǰ�����߹�");
		command( "say �ҾͿ���Ƭ��Ҷ������ֻ����ʮ�����ӣ�һ�ֲ��ܶ�Ҫ��");
		command( "cry");
	return 1;
}

int greeting(object me)
{

		message_vision(HIR "\nС����������:ţ�⣬���ơ�\n"NOR, this_object());
		return 1;
}

int accept_object(object me, object obj)
{
	object pai;
	if( (int) obj->value() >= (1000) && me->query_temp("mark/����") )
	{
        command("smile");
		pai = new("/d/tieflag/npc/obj/shuye");
		if(pai)
		pai->move(me);
        message_vision("$N�ó���Ҷ��$n��\n",this_object(),me);
        me->set_temp("mark/����", 0);
		me->set("annie/����",1);
		return 1;	
	}

else
        {
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"��С����������밲�ˡ�");
        return 1;
        }
}

void reset(){
		set("vendor_goods", ([
			"/obj/food_item/wineskin":	99,
			"/d/tieflag/npc/obj/beefmeat":	99,
			"/d/tieflag/npc/obj/dongskin":	99,
	          	"/obj/food_item/dumpling":	99,
			"/obj/food_item/chicken_leg":	99,
		]) ); 
		
}