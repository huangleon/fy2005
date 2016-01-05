#include <ansi.h>
inherit NPC;
#include <ansi.h>

int ask_for();
void create()
{
	set_name("�����", ({ "song tianer","song" }) );
 	set("title", "��������");
 	set("gender", "Ů��" );
 	set("age", 21);
 	set("per", 100);
 	set("long",
"���ż����ɫ�Ŀ�����ѣ�¶��һ˫����ɫ�ģ�����������������͵����ȡ�
����ɫ�Ĺ���������˫�ڰ׷����Ĵ��۾����Ե��ֽ��ģ�����Ƥ��\n");
 	set("combat_exp", 1500000);
 	set("chat_chance", 1);
 	set("chat_msg", ({
"���������һЦ������ˮ�����������ண��ܵع��������ҵ��ض�����׹�����
�������С��Ը��ܡ� \n",
"�����Ŀ����Թ���ð�������Ĺٻ���������綼���˿������ˡ�������Ҫ����
�ó������������ǵ�"RED"��б���д�����С�"NOR"�ͺ��ˡ��� \n",
        }) );
 	
 	set("attitude", "friendly");
 	set("inquiry", ([
        	"food" : (: ask_for :),
        	"б���д������" : (: ask_for :),

        ]));
 	setup();
    	carry_object(__DIR__"obj/yelskirt")->wear();
    	carry_object(__DIR__"obj/zhulan");
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	object basket,food;
	
	if(!me->query("food_carrier")) return ;
	if(me->query("food_carrier")+60>time())
	{
		message_vision(CYN"�����������һ�ۣ�˵��������ʹ������Ҫ�ȶ��󡣡� \n"NOR,me);
		remove_call_out("make_food");
		call_out("make_food",60+me->query("food_carrier")-time(),me);
		return ;
	}
    	message_vision(CYN "��ϵ����ȥ��߶Ȱ����Ĳ˶���ɹ���� \n"NOR,me);
	basket=present("bamboo basket",this_object());
	if(!basket) 
	{
		basket=new(__DIR__"obj/zhulan");
		basket->move(this_object());
	}

    	message_vision(YEL "�����������"RED"��б���д�����С�"YEL"���ڴ������У�С���������㡣 
\n�����ƲƲ��͵͵Ц�����������ʾ��鷳�������ҳ������������ǧ�����͵��ม�\n"NOR,me);
	food=new(__DIR__"obj/food");
	food->move(basket);			
	if (!basket->move(me))
		basket->move(environment(me));
	me->set_temp("song_food_carrier",1);
	me->delete("food_carrier");
	return ;
}



int ask_for()
{
	object me;
	
	me=this_player();	

	if (me->query_temp("song_food_carrier")) {
		message_vision("�����˵��������ȥ���³��������\n", me);
		return 1;
	}
	
/*	if(me->query("marks/master_chu_food")) 
	{
		message_vision("���������һЦ���ð�������Ĺٻ���������л���ϴΰ����Ͳ˸�����硣��\n",me);
		return 1;
	}*/
	
	if(me->query_temp("search_song_food"))
	{
        message_vision(CYN "�������������һ�����������������ȥ�h���ϣ� ������\n"NOR,me);
		return 1;
	}

      	message_vision(YEL "���������Ц������λ"+RANK_D->query_respect(me)+"Ը���������" RED "��б���д�����С�" YEL "����̫���ˣ� 
�ţ��������ˣ�����Ҫ��Щ����" GRN "�����С�㡹�������⸬����������Ů���졹��
��ˮ���ҡ�������ź�������л��������ٺϻ�����" YEL "�ţ����б�����ͻȪ��Ȫˮ 
����Ͳ���������ˡ�\n"NOR, me);
    	message_vision(CYN "\n�������������ͷ�����˸�����������ȥ��ȥ��\n"NOR,me);
	me->set_temp("search_song_food",1);
	return 1;
}

string *material_names=({
    "���С��",YEL"���⸬"NOR,"����Ů����","ˮ����","��ź","�л�",HIC"�ٺϻ�"NOR
	});

int accept_object(object me, object ob)
{
	string ob_name;
	int i,success,food_ok;
	
	if(!me->query_temp("search_song_food")) 
		return 0;
		
	ob_name=ob->query("name");
	success=1;
	food_ok=0;
	for(i=0;i<7;i++)
	{
		if(ob_name==material_names[i])
		{
			if(me->query_temp("song/"+ob_name))
			{
				message_vision("�������ȻһЦ��˵�������ظ��Ѿ���ɹ������\n",me);
				return 0;
			}
			me->set_temp("song/"+ob_name,1);
			message_vision("�������ȻһЦ��˵��������л��λ"+RANK_D->query_respect(me)+"�h��"+ob_name+"���ҡ���\n",me);
			food_ok=1;
		}
		success = success*me->query_temp("song/"+material_names[i]);
	}
	if(!success) return food_ok;
	command("jump "+me->query("id"));
    	message_vision(GRN "�����Ц�������������������ҵġ� \n"NOR,me);
    	message_vision(YEL"�������ź���������棬�ۻ����Ұ��Ū���������������� \n"NOR,me);
    	me->delete_temp("song");
    	me->set("food_carrier",time());
	call_out("make_food",60,me);
	return 1;
}


void make_food(object me)
{
	object food,basket;

	if(!present(me,environment()))
		return ;		
	basket = present("bamboo basket",this_object());
	if(!basket) 
	{
		basket=new(__DIR__"obj/zhulan");
		basket->move(this_object());
	}

    	message_vision( YEL "һ����Ĺ��������������" RED "��б���д�����С�" YEL "���ڴ������У�С������ 
�����㡣\n\n�����ƲƲ��͵͵Ц�������ˣ��Ǿ��鷳���͸��ҳ���磬��ǧ���͵���ϣ� \n"NOR,me);
	food=new(__DIR__"obj/food");
	food->move(basket);			
	basket->move(me);
	me->set_temp("song_food_carrier",1);
    me->delete("food_carrier");
	return ;
}
		
