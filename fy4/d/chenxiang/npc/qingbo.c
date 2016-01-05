// (C)1998-2000 Tie Yu

#include <ansi.h>

inherit NPC;
int tell_him();
int ass_come();
int ass_in(object me);

void create()
{
	set_name("�岨����", ({ "prince qingbo","qingbo" }) );
	set("gender", "����" );
	set("long","���Ǹ����˼ң�����Ϊ�������ң��Ѿ����ų�ն��Ψ���岨���ӵ������⡣\n");
	set("age", 25);
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("per",30);
    
    set("chat_chance", 1);
    set("chat_msg", ({
         "�岨�����૵���Ԭ��������Ԭ��������֪�������ˣ�������\n",
    }) );
    
    set("inquiry", ([
         "Ԭ��" : (: tell_him :),
         "yuanji" : (: tell_him:),
         "baohu": 	(: ass_come :),
         "����":		(: ass_come :),
         "����":		"����������Һ�Ԭ���žۣ���������ǵĴ���ˡ�\n",
         "�����":	"����������Һ�Ԭ���žۣ���������ǵĴ���ˡ�\n",
        ]));
	set("qingbo", 1);
	setup();
	carry_object(__DIR__"obj/scloth2")->wear();
}

int tell_him()
{
 	object me;
 	me =this_player();
 	tell_object(me,"�岨���ӵ���Ԭ�����Ǻ�����÷��������Ϊ�Ҽұ����ų�ն��\n");
 	tell_object(me,"���Ѿ����ڹ����׹���ѡ�У��ܿ��Ҫ������ˣ�\n");
 	tell_object(me,"�岨������ɥ��������Ԭ�����ˣ����ǿ�����Ҳ�������ˣ�\n");
 	return 1;
}

void init(){
	
	object me;
	
	::init();
}


int ass_come(){
	
	object me = this_player();
	object ass1;
	
	if (ass1= present("assassin"))
	{	
		command("point"); 
		command("shiver");
		return 1;
	}
	
	command("say ��������ʲô�ɱ����ģ�û��Ԭ�����һ��Ż���ʲô��˼��");
	
	if (REWARD_D->riddle_check(me,"���ȵ��") == 2) {
		if (REWARD_D->riddle_check(me,"���о�")==1)
			tell_object(me,WHT"\n�㰵����ĥ���������д̿ʹӺ����������˰ɣ�\n"NOR);	
		if (!query_temp("ass_in_work"))
		{
			call_out("ass_in", 10+random(10), me);
			set_temp("ass_in_work",1);
			
		}
	}
	return 1;
}	
	

int	ass_in (object me)	{
	
	object ass;
	
	if (!me || environment(me) != environment())	
	{
		delete_temp("ass_in_work");
		delete_temp("marks/protector");
		return 1;
	}
	
	set_temp("ass_in_work",1);
	set_temp("marks/protector",me);
	
	message_vision(BLU"��ˮ��Ȼһ�������ವ���������Ӱ������ɭɭ��ֱ���岨���ӡ�\n"NOR,me);
	ass = new(__DIR__"assassin");
	if (ass)	ass->move(environment());
	
	return 1;	
}		

void die(){
	
	object prot, ass1, ass2;
	command("say Ԭ����Ԭ����������һ���ˣ�");
	
	ass1 = present("assassin");
	
	prot = query_temp("marks/protector");
	
	if (objectp(prot))
	{
		if (environment(prot) == environment())
		if ( (ass1 && prot->is_fighting(ass1)))
		{
			if (REWARD_D->riddle_check( prot, "���ȵ��")==2)
				REWARD_D->riddle_set(prot,"���ȵ��", 4);
		
		}
	}
	
	::die();
}

		
		