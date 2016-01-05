//Tie
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
int tell_him();
int tell_him2();
int do_answer(string arg);

void create()
{
    	set_name("��ʯ��", ({ "wang", "shijiangfang" }) );
    	set("gender", "����" );
    	set("age", 49);
    	set("long", @LONG
��ʯ������Ѿ��Ĵ��ˣ���˵�������ʱ���и�����ˡ�������Ƕ��˵Ļ���
��ʯ���������Ѿ����˺����ˡ�
LONG
        );
    	
    	set("combat_exp", 20000);
    	set("attitude", "friendly");
    
    	set_skill("dodge", 50);
    	set_skill("parry", 50);
    
    	set("vendor_goods", ([
        	__DIR__"obj/stone1":60,
        	__DIR__"obj/stone2":70,
        	__DIR__"obj/stone3":80,
        	__DIR__"obj/stone4":90,
        ]) );
    	set("inquiry", ([
	        "�����":	(: tell_him2 :),
	        "����":	(: tell_him2 :),
	        "����" : (: tell_him :),
	        "yubotao" : (: tell_him :),
        ]));
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
    	object ob;

    	::init();
    	if( interactive(ob = this_player()) && !is_fighting() )
    	{
        	remove_call_out("greeting");
        	call_out("greeting", 1, ob);
    	}
    	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
    	if( !ob || environment(ob) != environment() ) return;
    	switch( random(10) )
    	{
    	case 0:
        	say( " ��ʯ��Ц�ŵ�����λ"+ RANK_D->query_respect(ob)
             		+ "����ʯʨ��ô�� \n");
        	break;
    	case 1:
        	say( " ��ʯ��Ц�ŵ�����λ"+ RANK_D->query_respect(ob)
             		+ "��������Ĵ���ʯ��������ˡ� \n");
        	break;
    	}
}


int tell_him2()
{
    	object me;
    	me=this_player();
    	tell_object(me,CYN"��ʯ��˵������ʶ�ҵĴ���ˣ������ܰɣ���˵����ʲô��\n"NOR);
    	me->set_temp("marks/wangshijiang",1);
    	add_action("do_answer","answer");
    	return 1;
}



int do_answer(string arg)
{
		object me;
    	me=this_player();
    	
    	if (!me->query_temp("marks/wangshijiang"))	return 0;
    	
    	if (me->query_temp("marks/wangshijiang")==1)
    	{
    		if (arg == "����" || arg == "kangqi") {
    			command("touch");
    			command("say ������������ţ���Ȼ������嶼�����ˣ�");
    			ccommand("dapp "+me->query("id"));
				return 1;
			}
    		
    		if (arg != "�ŷ�")	{
    			command("shake");
    			command("say ��Ȼ��ð��ġ�");
    			me->delete_temp("marks/wangshijiang");
    			return 1;
    		}
    		tell_object(me,CYN"��ʯ��˵���㾹Ȼ֪���Ҵ���˵����֣������������й�����\n"NOR);
    		
    		tell_object(me,CYN"
��ʯ��˵���������ٿ���һ��������˾������꣬�ҵ������Ǵ���˺�������
����֮�͵�һ�룬���ҵ��˴���˾�����������������ʱ�򣬴���˾�������
�ڵ������ˡ�����˽��꼸�ꣿ\n"NOR);
		   	me->set_temp("marks/wangshijiang",2);
    		return 1;
		}
		if (me->query_temp("marks/wangshijiang")==2)
    	{
    		if (arg != "30" && arg!="��ʮ")	{
    			command("shake");
    			command("say ��Ȼ��ð��ġ�");
    			me->delete_temp("marks/wangshijiang");
    			me->add_temp("timer/wangshijiang",1);
    			return 1;
    		}
    		tell_object(me,CYN"
��ʯ��˵����ͷ��������Ҫô������Ҫô��Ϲ�£��������˽��㡣��Ȼ��ˣ�
����ʲô��Ը�Ϻ�һ��������ɡ� \n"NOR);   		
		   	me->delete_temp("marks/wangshijiang");
    		me->set_temp("marks/��ʯ��",1);
    		return 1;
		}
		
}		


int tell_him()
{
    	object me;
    	me = this_player();
    	if(me->query_temp("marks/��ʯ��")) 
        	message_vision("$N��$n��������Ȼ�����ۻ����������Ҷ��˵����ѣ�"
                       "�������ҿ����ɣ�\n",this_object(),me);
    	else
        	message_vision("$N��$n�������Ѿ������ۻ������ܰ�������ôϸ�Ļ��ˣ�\n",
                       this_object(),me);
    	return 1;
}



int accept_object(object me, object obj)
{
    if(me->query_temp("marks/��ʯ��") && obj->query("id") == "round jade" &&
        obj->query("need_fix") && !obj->query("fixed"))
    {
        obj->set("fixed",1);
		obj->set("long","һ����������ĥ�ɵ��񻡣���Լ�а˴������֮һ԰��
������һ͹һ���������ۡ�\n");
		message_vision("$N��$n�ӹ�ȥ����$n�����˿̳�һ͹һ���������ۡ�\n",
                       this_object(),obj);
		notify_fail(name()+"���������ϵĳ����������񻡸������㡣\n");
    }

    return 0;
}

void reset(){
    	set("vendor_goods", ([
        	__DIR__"obj/stone1":60,
        	__DIR__"obj/stone2":70,
        	__DIR__"obj/stone3":80,
        	__DIR__"obj/stone4":90,
        ]) );	
	
}