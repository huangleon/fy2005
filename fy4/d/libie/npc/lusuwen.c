#include <ansi.h>
inherit NPC;
void dreamsay();
void create()
{
	set_name("������", ({ "lu suwen","lu" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 100);
	set("per", 50);
	
	set("inquiry", ([
                "����" : 	"��������������ͷ��Ů����\n",
                "lian gu" :  	"��������������ͷ��Ů����\n",
                "���" : 	"��������ӣ����ڵ���һ׮�ذ���\n",
                "yang" : 	"��������ӣ����ڵ���һ׮�ذ���\n",
                "yang zheng" : 	"��������ӣ����ڵ���һ׮�ذ���\n",
                "������":	"��������һ�����Ӵ��������֯���İ������������д���δ�й���
��������Ӵ����ܵ���֯�� \n",
        ]));
	set("long", @LONG
һ�����£����ĸɸɾ����������������һ�ű������㶯�˵�������
������Щ�������ƣ�롣
LONG
);	set("combat_exp", 10000);
	set("attitude", "friendly");

	setup();
	this_object()->disable_player( HIG "<˯����>"NOR);
//	this_object()->set_temp("is_unconcious",1);
//	set_temp("block_msg/all", 1);
//	COMBAT_D->announce(this_object(), "unconcious");

	carry_object(__DIR__"obj/white_cloth")->wear();
}

int accept_fight(object me)
{
	command("emote ˯�����㣬һ�㷴Ӧ��û�С�");
	return 0;
}


void init()
{
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer","answer");	
	if(!living(this_object()))
	if(!query("��ʼ˵�λ�"))
	{
		set("��ʼ˵�λ�",1);
        	call_out("dreamsay",10+random(100));
	}
	::init();
}

void dreamsay()

{	object room;

	if(!living(this_object()) &&this_object()->query("disable_type")==HIG"<˯����>"NOR)
	{
		room=environment(this_object());
                message("vision","�����ķ����������Ľ�ë�����Ҹ�����⣬˯�����૵������Ŷ��������ˣ�\n�������ˡ����������ȥ�ȡ���\n",room);
		call_out("dreamsay",10+random(100));
	}
	else
		delete("��ʼ˵�λ�");
	return;
}

void heart_beat()
{
	int msg;
	object me,lu,sheet;
	

	if(!living(this_object())&&this_object()->query("disable_type")==HIG"<˯����>"NOR)
	if(!query("��ʼ˵�λ�"))
	{
		set("��ʼ˵�λ�",1);
		call_out("dreamsay",10+random(10));
	}
	if(msg=query("dying_msg"))
	{
		me=environment()->query("���1����");
		lu=this_object();
		if(msg==4)
            		message_vision(YEL"$Nƽ�����ʣ��ҷ���ǲ����Ѿ����������ˣ�\n"NOR,lu);
		if(msg==3)
			me->ccommand("hmm");
		if(msg==2)
            		message_vision(YEL"\n$N���������룬������߽�������ɡ����������ˡ���\n
�����ĵ�����Խ��Խ΢��������\n"NOR,lu);
		if(msg==1)
		{
            message_vision(HIG"\n$N����˯���ˣ�ƣ�������¶�������΢Ц������
΢��������̾Ϣ������ɹ���ȸ���ڵ͵���ౣ�һ�й������š�����\n\n\n"NOR,lu);
			sheet = new(__DIR__"obj/sheet");
			sheet->move(environment(this_object()));
			REWARD_D->riddle_done(me,"���",200,1);
			me->delete("libie");
			me->delete_temp("libie");	// ��������ڿ������mark�������������ǽ������ǵ�һ�ε�
			me->set_temp("libie/���_β��",1);	// �����ץ������ͷ����
			lu->die();
		}
		add("dying_msg",-1);
	}
	::heart_beat();
}

void sleep()
{
	message("vision","�����Ĵ��˸���Ƿ������˯�˹�ȥ��\n",environment());
	this_object()->set_temp("is_unconcious",1);
	this_object()->disable_player(HIG "<˯����>"NOR);
}

void wake(object me)
{	string msg;
	object room;
		
	this_object()->delete_temp("is_unconcious");
	this_object()->enable_player();
	room=environment();
	if (present(me->query("id"),room)) 
		message_vision(HIG"����������˫��������һ��������$N��\n"NOR,me);
	else 
		message("vision",HIG"����������˫��������һ����\n"NOR,room);

}

int dying(object me)
{
	set("dying_msg",4);
	heart_beat();
	return 1;
}

void die()
{	object me,corpse,*inv,room;
	int i;

	room=environment();
	if(me=room->query("���1����"))
		me->delete_temp("libie/���_Ŀ�������");
	corpse=new("/d/libie/obj/lucorpse");
	corpse->move(room);
	message_vision("���������ˡ�\n",this_object());
	destruct(this_object());
		
}


int ask_question(object me)
{	
	if(environment(me)!=environment()) return 0;

    	message_vision(YEL "�����Ŀ��������������ķ��ˣ�������˼���������½���ɫ��������
��������������ʳ�İɣ�(answer yes or no)\n"NOR,me);
	me->set_temp("libie/answer_lu_1",1);
	return 1;
}

int do_answer(string arg)
{
    	object ob, me, book;
    	ob = this_object();
    	me= this_player();
    	
    	if (!me->query_temp("libie/answer_lu_1"))	return 0;
    	
    	if (arg == "yes" || arg == "no")
    	{
    	    	me->delete_temp("libie/answer_lu_1");
    		me->delete_temp("libie/���_׼���ͷ�");
    		if( arg == "yes" )
    		{
        		if(!REWARD_D->riddle_check(me, "���")){
        			REWARD_D->riddle_set(me, "���",1);
        			message("vision",YEL "
������΢Ц���ᶨ��˵��˳����¸�֪�������������������ģ�����ֻ
���ҷ��ɹ�����

��������ȼ����������������������ҷ򸾣������ҷ���ƻ�����ʧ��
һ�����׷��鰸֮�գ������ҷ��ž�֮ʱ��

�������ֵ����������ҵ��ģ���Ը�Ҷ�֪�����飬������������������
������ѯ�ʣ���Ȼ�������ɵĳ��ˣ�ȴҲ�����ĺ��ӡ�

������̾�˿�������Ŀ���\n"NOR,me);
			} else 
				message_vision(HIY "�����ĵ�����������Ѿ��������벻�ض��ԡ�\n"NOR,me);
    		 } else if( arg == "no" ) 
	 	       	message_vision(HIG"������΢̾һ������Ŀ���\n"NOR, me);
	 	return 1;
    	}
    	return 0;
}

int give_sword(object me)
{
	
	object sword,ob = this_object();
	if(environment(me)!=environment()) return 0;
	
	if (me->query_temp("libie/lu_sword"))
	{
		message_vision(YEL"�����Ŀ��˿�������ʧ����̾�˿�����\n"NOR, me);
		return 1;
	}
	
	tell_object(me,"�����������ļ򵥽����˵��������������������\n");
	tell_object(me, YEL"
�����ĵ��촽��Ȼ��ñ������������ȴ������ǿѹ�����Լ��� 
�����������ỹ���̲�ס����������

�����ķ������ϵ�һ��ľ�壬��ľ���µĵض��������������������ӡ� 
�������Ȼ�и������ӡ� 
�����Ĵ����˻��ۣ���Ϳ�����һ����δ������������

"WHT"һ����״����ı��У�������һ������---��𹳣�"YEL"

������������Ȼ�������������Ψһ������������������˵����
��������ͷ���ǵ������ܶ�������������˵������˵��������Ϊ�����
���۹�סʲô������������

������˵���������������������˵���ڵ���������

������΢̾һ����ת���ݺ�\n"NOR);

	sword = new(__DIR__"obj/leavehook");
	if (sword)	
	if (!sword->move(me))	sword->move(environment(me));
	sword->set("hook_owner",me);
	me->set_temp("libie/lu_sword",1);
	remove_call_out("sleep");
	destruct(this_object());	// At most 15 mins a sword bah :D
	return 1;
}
	


