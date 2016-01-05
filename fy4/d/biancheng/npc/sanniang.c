#include <ansi.h>
inherit SMART_NPC;

int area_chat();
void create()
{
    	set_name("������",({"shen sanniang","shen","sanniang"}));
	set("title",WHT"������ ������"NOR);
   	set("long","
�⸾�˳�����������ͷ�㷢��ڣ�һ�Ź�����ȴѩ����������������������
һ���������Ů����һ��һ���䶼������һ�ֳ���ĸ������ϡ�����ʲô����
���ˣ�ֻҪ���������̾ͻ�֪�����㲻�������������ϵõ���ο�����㣬Ҳ��
�Եõ��˽��ͬ�顣\n");

     	set("gender","Ů��");
    	set("age",32);
    	set("group","guo");    	
    	set("per",40);
    	
    	set("combat_exp",9000000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	

    	set("chat_chance",1);
    	set("chat_msg",({
		(: area_chat() :),
    	}) );    	    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
		setup();
    	carry_object("/obj/armor/cloth",([	"name": RED"��籰�"NOR,
    						"long": "һ����籰���\n",
    						 ]))->wear();    
    
}

int area_chat(){
	if (environment(this_object())->query("discussion_shen")) {
		if (random(2)) message_vision("�����︩������ȥ���ϵļ����Ӳݡ�\n",this_object());
			else message_vision("����������������Ĺ����һ�ﲻ����\n",this_object());
	}else {
		if (random(2))message_vision(name()+"����̾Ϣ��һ����������Ҳ���Ҹ����������ġ���\n",this_object());
			else message_vision(name()+"Ц�ˣ��������������Ҫ���ң�Ӧ����û���˵�ʱ��������\n",this_object());
	}
	return 1;
}


void init()
{	
	object me;

	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
	add_action("do_answer","answer");
}

void greeting(object me)
{
	object ob, huzi;
	ob=this_object();
	if (environment(ob)->query("discussion_shen")){
		message_vision(YEL"
�������ߵ��رߣ���ʯ��ǰ�����������������ã���վ������ת������
�Ϲ�������ۣ�ÿһ����ۡ�����֪����Ŷ���������ʹ�����¡�\n\n"NOR,ob);
		message_vision(CYN"�����ﻺ���ض�$N˵������֪����һ�������ġ���\n"NOR,me);
		call_out("event2",3,me,0);
		return;
	}
	if( !me || environment(me) != environment() || me->is_fighting()) return;
	if (me->query("marks/wanma/׼��ɱͬ��_ma")) {
		command("say �����������ĺ����ˣ�����������ϲ�������˴����ҵ�������㻹�ǿ��ȥ�ɡ�");
		return;
	}
	if (!me->query("marks/wanma/��¥")) {
		command("say ����뿪��������������������Ҳ�߲����ˡ�");
		return;
	}
	huzi=present("xiao huzi",environment(ob));
	if (huzi) {
		message_vision("������̧��ͷ�����ƺ�����ʹ�˸���ɫ��\n",ob);
		call_out("event1",10,me);
	}
	return;	
}

int event1(object me) {
	object huzi,ob;
	ob=this_object();
	if( !me || environment(me) != environment() || me->is_fighting()) 
		return 1;
	huzi=present("xiao huzi",environment(ob));
	if (huzi && !huzi->is_fighting()) {
		command("say ���ӣ���ȥ���㹫��������һ��");
		huzi->ccommand("jump");
		huzi->ccommand("south");
		destruct(huzi);
	}
	command("close door");
	message_vision(CYN"
������˵������֪�����������������£�������Ҳ�������㡣�������ܶ�
�¶���������濴������ô�򵥡���ϣ������μ�������ǰ�ܺú���һ�롣
�˴���ǽ�ж���ÿ���糿�Ҷ���ȥ�⸽����Сɽ�£��������ˣ����ȥ��
�����ҡ���\n"NOR,ob);
	return 1;
}


string *event2_msg=	({
	CYN"
�������������㣬��Ȼ�������㿴����ʲô����

�������һ���ء���\n"NOR,

CYN"�������������֪������˭�ķأ���

������������𡢰����¡�������\n"NOR,

CYN"��������ͷ����˵�����Ҳ������ջ����������������й�һ�����
֪�����׷�����ҵ��׽�㡣ʮ����ǰ��÷�����⣬һ�������ѩ����
�ϣ������𣬰�����������̤ѩʱͻ����ʮ����Χ���������ѩ�µúܴ�
����һƬ���ף�����ս������������һƬ����ɫ�Ĵ�أ���������ѪȾ
���ˡ�������\n"NOR,

YEL"������Խ˵Խ��������Խ��Խ�ͳ���ÿ��һ���ֶ�����ô��ʹ�ࡣ\n"NOR,

CYN"�׼ҵ�����ŮŮ���������٣�����һս���������������ֽ��Ժڲ����棬
�������书��ǿ����������ս����������Ҳֻ���߸����������������
�����������й�ϵ���˶��⵽׷ɱ�����������þͿ��ˡ�\n"NOR,

CYN"�Һͽ�㶫�����أ���ʱ��������°�����Ķ��ӣ���Ȼ�����ֵ����ж���
�ҿ�����ħ�̹������ڽ��ڵ��ڻ��²��������ѡ������Ӵ������䣬
���ղ��ֻ�б���һ�\n"NOR,

CYN"������ʮ��ǰ�����Ǵ�̽������������ڣ���Ȼ���а�����Ľ���ֵ���
��Ⱥ����������ǰ�Ҹ��ջ����������ã�����Ϊ��֤ʵ���£�����������
�����ֵ����䡣\n"NOR,

CYN"ʮ�����������һ��һ�⽫���Ӹ�������ָ����Ϊ������û�ϵ���û
�ϵ�������Ӹ���ѩ��Ȼ���ǰ�����Ķ��ӣ����������������Ź�Ҷ��ȴ
��Ըȥɱ���ˣ�����\n"NOR,

CYN"�����ֻ֣������©��ɱ�������������һ��Ҫ�������Ⱥ����Щ����һ
��Ҫ���������ֵ����ѵ���һ��Ҫ����\n"NOR,

	
});


void event2(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event2_msg[count]+"\n");
	if(++count==sizeof(event2_msg))	{
		tell_object(me,HIR"����Ը��Ϊ�����𱨳�����ܳ�Ϊ���ŵĴ��ˡ�\n\n"NOR);
		tell_object(me,HIY"���������򡡣���󣯣� \n"NOR);
		me->set_temp("marks/wanma/answer_shen",1);
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}

int do_answer(string arg)
{
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if(me->query_temp("marks/wanma/answer_shen")==1) {
		if(arg=="yes") {
			message_vision("\n$N�ᶨ�ص��˵�ͷ˵������˲���֮�£��������书��΢��Ը������������\n"NOR,me);
			message_vision(CYN"������˵�����ã��д������������Ⱥ����ͬ�����ָ�տɴ����ҽ���
����Ǳ������������������������Ǣ����\n",ob);
			tell_object(me,CYN"�����︩���������˵��������������ö���������ïʢ���ҵ�������
֮����\n"NOR);
			me->delete_temp("marks/wanma/answer_shen");
			me->set("marks/wanma/Ѱ�ض�",1);
			return 1;	
		}
		if(arg=="no"){
			message_vision("\n$N�Ͻ�ҡ��ҡͷ˵�����������յ�΢���㻹����������ɡ���\n"NOR,me);
			message_vision(CYN"��������Ȼ����������׷�����Ⱥ���ٻ�������Ҳ���谭�㡣ֻ�����
������һ���ᱨ����ʱ�򸲳�֮�£��������ѡ����㽫����й©�����Ⱥ
����Ҳ����Ź���ġ���\n"NOR,ob);
			message_vision(YEL"������ת��ͷȥ�����������ȥ���ϵĸ��������ٿ��㡣\n"NOR,ob);
			me->delete_temp("marks/wanma/answer_shen");
			me->set("marks/wanma/�ܾ���",1);
			return 1;
		}
		tell_object(me,"��ֻ�ܻش�������\n");
		return 1;
	}
	return 0;
}