#include <ansi.h>
inherit SMART_NPC;

int do_answer1();
int do_answer2();

void create()
	{
        set_name("Ϲ�Ӱ���", ({ "xiazi aming","aming" }) );
        set("title",HIR"������"NOR);
		set("long","��ɫ�԰ף����۷��ף���˵�Ǽ��ϸ�һ��������������ʿ��\n");
		set("gender", "����" );
		set("age", 25);
		set("class","yinshi");
	
		set("attitude", "friendly");
    	set("combat_exp", 3500000);
        set("reward_npc", 1);
		set("difficulty", 5);
	 	
    	set("inquiry", ([
           	"��ʦ����" : (: do_answer1 :), 
//		   	"���½���" : (: do_answer2 :),
        ]) );
	
    	set("chat_chance", 2);
    	set("chat_msg", ({
            "Ϲ�Ӱ�����̾��һ����������һƬ�հף�ʲô���㲻����������\n",
            "Ϲ�Ӱ���Ц��˵������������õģ����Ұ����ƣ�����\n",
            "Ϲ�Ӱ����޺�˵�����Ǹ����ֶ��٣�ÿ���������Ҹ����������������Ƶġ�����\n",
            "Ϲ�Ӱ������ص�˵����֪���Լ���ʦ������\n",
        }) );
        
        set("chat_chance_combat", 100);
   	 	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
    	 }) ); 		

		auto_npc_setup("wang",180,180,0,"/obj/weapon/","fighter_w","celecurse1",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/music/erhu");
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
	{	remove_call_out("greeting");
		call_out("greeting", 1, ob);	
	}	

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
     	say( "Ϲ�Ӱ�����"+ob->query("name")+"΢Ц������λ" + RANK_D->query_respect(ob)
				+ "������üֱ��ͦ��һ����֪���Ǵ󸻴��֮�ࡣ\n");

}

int do_answer1()
{
	int betray;	
	string respect;

	if(!this_player()->query_temp("money_given") )
	{
    		say("Ϲ�Ӱ�����Ц��������������Ǻǡ������������ǵú���������������������ˮ�����ء�������\nϹ�Ӱ��������һֻ��ָ������һ�Ρ�\n");
		return 1;
	}
	betray=this_player()->query("betrayer");
	respect=RANK_D->query_respect(this_player());
	if(!betray)
		{
		ccommand("admire "+this_player()->name());
       say("Ϲ�Ӱ��������˵����������ͷ�����Ĳ��ţ���"+respect+"��ôרһ���������ѵ�ѽ����\n����ض����ꡣ����\n");
		}
	else if(betray==1)
		{
		ccommand("admire "+this_player()->name());
        say("Ϲ�Ӱ����������������ͷ�����Ĳ��ţ���"+respect+"����ֻ����һ�����ɵ���Ҳ��\n�ѵ��ˡ�������ض����ꡣ����\n");
		}
		
	else if(betray<6)
		{
		ccommand("pat "+this_player()->name());
         say("Ϲ�Ӱ����ֺõ�������Ų������Ų�"+respect+"��Ȼ��ʶ��������Ȼ����"+chinese_number(betray)+"�����ɣ�\n���ض����˺ܶ�ε����������ձ��ܳɾʹ�ҵ����\n");
		}
	else
		{
		ccommand("?");
		say("Ϲ�Ӱ�����æ���ҵİ�����ָ������\n");
		ccommand("faint "+this_player()->name());
        	say("Ϲ�Ӱ�������һ̯���ƣ���������ʵ�������������������\n");
		ccommand("cry");
		}
	this_player()->delete_temp("money_given");
	return 1;

}
	


int accept_object(object who, object ob)
{
	if(ob->name()=="�ƽ�")
	{
    say("Ϲ�Ӱ�������˵��������ô�С�������������ȴ�������Żƽ�����"+this_player()->name()+"�û�ȥ�����ӡ�\n");
	this_player()->add_temp("money_given",1);
	return 1;
	}
	
    return notify_fail("Ϲ�Ӱ���ڨЦ������������ã�ֻ��ˡ�ѽ����ˡ�����\n");
}


int do_answer2()
{
	object log;

    	say("Ϲ�Ӱ������¿�����ѹ������˵���������·�ͬС�ɣ����������ү֪���ˣ��ҿ��±����������������\n");
	if(this_player()->query("marks/task_TBA"))
		{
        say("Ϲ�Ӱ���˵������������!#$@$!@�ķ��ϣ��Ҿͻ��ȥ�ˣ�������������٣�ǧ�����õ������˿���������¡���\n");
        say("Ϲ�Ӱ����ݸ�"+this_player()->name()+"һ���ʲ�״�����¡�\n");;
		log=new("/obj/diary.c");
		log->move(this_player());
		}
	return 1;


}
