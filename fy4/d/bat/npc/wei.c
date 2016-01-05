//All Rights Reserved 1998 Apstone, Inc.

inherit NPC;
#include <ansi.h>
int give_book();

void create()
{
 	set_name("κ����", ({ "wei xing long" }) );
 	set("title", MAG "����ɷ��" NOR);
 	set("gender", "����" );
 	set("age", 35);
 	set("long",
		"�������۾���һ�����̣������������۽�һֱ�����������䳤����̫�
������������������Ѫ������ָ�������˺��ѷ����������̡�\n");
 	
 	set_skill("unarmed", 100);
 	set_skill("shuaibei", 200);
 	set_skill("move", 100);
 	set_skill("dodge",100);
 	set_skill("parry",100);
 	set_skill("qingfeng-sword",100);
 	set_skill("five-steps",80);
 	set_skill("sword",100);
 	
 	map_skill("sword","qingfeng-sword");
 	map_skill("unarmed", "shuaibei");
 	map_skill("dodge","five-steps");
 	
 	set("combat_exp", 500000);
 	set("chat_chance", 2);
 	 set("chat_msg", ({
"κ���������������ֻҪ�����ˡ����ʮ��ʽ���������Ƕ�����̫���Ҷ����¡�\n ",
"κ��������üͷ�ֹ��ţ�����һ���������ʵ��������ʵ���飬���߶������У�\n",
 }) );
 	set("inquiry",([
  	"���ʮ��ʽ" : (: give_book:),
 	 "book" : (: give_book:)
 	]) );
 	
 	
 	
 	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();

}

int give_book()
{
	command("say �����������б������������ɣ������ȱȻ��Ȼ���");
	if (this_player()->query_temp("marks/wei_win")) 
		this_player()->delete_temp("marks/wei_win");
	this_player()->set_temp("marks/wei",1);
	return 1;
}


void win_enemy(object loser)
{
    	message_vision("$N��м�ض�$n����һ����Ҫ�����Ϸ��������飬��������������ˡ�\n",this_object(),loser);
}

void lose_enemy(object winner)		//modified by jusdoit at Dec 17,2001
{					
    	object book;
    	if (winner->query_temp("marks/wei")) {
    		book = new(BOOKS"sword_50a");
    		message_vision("$N��ü�����ض�$n˵�����¹�Ȼ�������������ܼ�������Ҳ����ס�ˡ�\n",this_object(),winner);
    		if (!book->move(winner)){
    			message_vision("$N˵���������ò���Ҳ�ֲ����ҡ�\n",this_object());
    			destruct(book);
    			return;
    		}
    		message_vision("$N�޿��κεشӻ����ͳ�һ����ݸ�$n��\n",this_object(),winner);
    		winner->delete_temp("marks/wei");
			winner->set_temp("marks/wei_win",1);
		} else 
			message_vision("$N��ü�����ض�$n˵�����¹�Ȼ������\n",this_object(),winner);
	
}



void init() {
	object ob;
	::init();
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
}

void greeting(object ob) {
	
	string where;
	if(!ob || environment(ob) != environment()) {
		return;
	}
	
	switch( random(5)){
		case 0:
			say("κ���������������ֻҪ�����ˡ����ʮ��ʽ���������Ƕ�����̫���Ҷ����¡�\n");
			break;
		case 1:
			say("κ��������üͷ�ֹ��ţ�����һ���������ʵ��������ʵ���飬���߶������У�\n");
			break;
		}

}


int accept_fight(object me)
{
       if (!this_object()->is_fighting()) {
        		command("grin");
        		command("say �ã�����������ι�У�\n");
        		return 1;
		} else command ("say ��æ��æ��һ��һ������������ȱ���֡�");
			return 0;
}			


