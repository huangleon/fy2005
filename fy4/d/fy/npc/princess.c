// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

inherit NPC;
// inherit F_ANNIE;
#include <ansi.h>

string quest();
int give_me_it_ling(object me);

void create()
{
	object weapon;
        set_name("������", ({ "youngman" }) );
        set("gender", "����" );
        set("long","
�������Ź�������һ˫�������������ˣ�ȴ�����ֲ�ŭ���������ơ�
"
	);

			set("title","�����");
			set("nickname",CYN"��̿����������"NOR);
	
      set("age", 21);
			set("per",40);
			set("str",1);
      set("attitude","friendly");
        
      set("combat_exp", 0);
        
      set("score", 20000);

			set("no_arrest",1);

				set("inquiry", ([
	       	"��ʹ": 	(: quest :),
	       	"����": 	(: quest :),
	       	"chashi": (: quest :),
	       	"chaishi": (: quest :),
	       	"cha shi": (: quest :),
	       	"chai shi": (: quest :),
         ]) );
		

        setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�ۻƷ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->set("armor_worn","���������ż�");
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name(HIY"�ƻ�����"NOR, ({ "feather" }) );
		weapon->set("value",0);
		weapon->set("armor_worn","����б����һ��");
		weapon->wear();

}




void init(){
	::init();
	add_action("do_look", "apprentice");
}


string *cishi= ({
"��","��","��","��","��","��","��","��","��","��","�","ʯ","�","��","��",
"��","Ǭ","��","��","ԭ","��","μ","��","��","��","̩","��","�","��","��","ͨ","��","��",
"��","��","��","��","��","̫ƽ","��","Ԭ","��","��","��","�","Ͽ","��","��","��","��","ȫ",
"��","��","��","��","��","̨","��","��","��","�Ͻ�","͡","��","��","��","��","��","��","��",
"��","��","��","ά","ï","��","��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","ʩ","��","��","��","��","��","��","ѭ","��","��","÷","Ӣ","��","��","����",
"��","��","��","��","��","��","��","��","��","��","��","�","��","��","��","��","��","�",
"��","��","����","��","����","��","��","��","��","��"
});

string *tuanlian= ({
"��","�","Ϋ","��","��",
"��","��","��","��","��","��","��"
});

string *fangyu= ({
"��","��","��","��","��","֣",
"��","��","�","��","۫","��","��","��","��","��","�","��","�","��","��","Ī","��","�",
"��","��","��","ޭ","��","��","ü","��","½","��"
});

string *guancha= ({
"��","��","��","��","۩","��","��","��","��","��","��","֣","��","��","��","��","�","��",
"��","��","��","��","��","��","��","��","º","��","��","ͬ","��","ҫ","��","�~","��","ߓ","��","��","μ","��","��","��",
"����","��","Խ","��","��","��","��","��","��","��","��","��","��","®","��","��","��","��","��","��",
"��","��","��","̶","��","��","Ȫ","��","��","��","��","��","��","��","��","��","��","��","ǭ"
});

string *jiedu= ({
"̩��","����","����","��","��ƽ","����","���","����","��","��������",
"ɽ�϶���","��ʤ","����","�ѻ�","����","����","�ɵ�","����","�õ�","����","����",
"����","����","�û�","����","����","����","����","����","����","����","����","����",
"����","����","����","����","���","��Զ","�䰲","��","ƽ��","��","����","����",
"����","����","����","����","����","����","ɽ������","����","����","�䶨","����","����",
"�俵","�庣","����","��Զ","����","����","����","����","����","��˳","�ù�","����",
"����","����","���","����","��ͬ"
});

int do_look(string arg)
{
	object me=this_player(),student;
	int exp;
	string g;
	student=me;
    exp = (int) student->query("combat_exp");
	if (!arg)
		return 0;
	if(present(arg,environment()) == this_object())
	{
		if (me->query("class") != "official")
		{
			ccommand("emote ����"+me->name()+"һ�ۣ���Ц������ȷǹټ����£��������ң�");
			return 1;
		}
		if (me->query("family/master_name") != "��ʤ����")
		{
			ccommand("emote ����"+me->name()+"һ�ۣ�����üë΢Ц�����������̫ǳ�ģ�����");
			return 1;
		}

		g=me->query("title");

		if (exp<= 1024000 && strsrch(g,"�ݴ�ʷ")!=-1)
		{
			ccommand("emote ����"+me->name()+"һ�ۣ�ҡͷ��������ʸ񻹲����ӷ�İ���");
			return 1;
		}
		else if (exp<= 2048000 && strsrch(g,"������ʹ")!=-1)
		{
			ccommand("emote ����"+me->name()+"һ�ۣ�ҡͷ��������ʸ񻹲����ӷ�İ���");
			return 1;
		}

		else if (exp<= 3315000 && strsrch(g,"�ݷ���ʹ")!=-1)
		{
			ccommand("emote ����"+me->name()+"һ�ۣ�ҡͷ��������ʸ񻹲����ӷ�İ���");
			return 1;
		}

		else if (exp<= 5312000 && strsrch(g,"�ݹ۲�ʹ")!=-1)
		{
			ccommand("emote ����"+me->name()+"һ�ۣ�ҡͷ��������ʸ񻹲����ӷ�İ���");
			return 1;
		}

		else if (exp<= 8800000 && strsrch(g,"�ڶȹ۲�����")!=-1)
		{
			ccommand("emote ����"+me->name()+"һ�ۣ�ҡͷ��������ʸ񻹲����ӷ�İ���");
			return 1;
		}
		else if (strsrch(g,"�ڶ�ʹ")!=-1)
		{
			ccommand("emote ����"+me->name()+"һ�ۣ���Ц�����������λ���˳������û���˲�֪�㣿");
			return 1;
		}

		        if( exp <= 1024000 ) 
					g=cishi[random(sizeof(cishi))]+"�ݴ�ʷ";
				else if ( exp <= 2048000 ) 
					g=tuanlian[random(sizeof(tuanlian))]+"������ʹ";
				else if ( exp <= 3315000 ) 
					g=fangyu[random(sizeof(fangyu))]+"�ݷ���ʹ";
				else if ( exp <= 5312000 )
					g=guancha[random(sizeof(guancha))]+"�ݹ۲�ʹ";
				else if ( exp <= 8800000 ) 
					g=jiedu[random(sizeof(jiedu))]+"�ڶȹ۲�����";
				else               
					g=jiedu[random(sizeof(jiedu))]+"�ڶ�ʹ";

			ccommand("emote ����"+me->name()+"һ�ۣ�ƫͷ������ô���������������������"+HIG+g+NOR+CYN+"�ա�");
			g="��͢���� "+g;
			me->set("title",g);

		return 1;
	}
	return 0;
}


string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object room, silver,room2;
	object me = this_player();
	string *list1=({
	"�ǻ���Թ��",
	"���ŵ�Թ��",
	"�ߺ޵�Թ��",
	"��Ĭ��Թ��",
	"���ҵ�Թ��",
	"��ʧ��Թ��",
	"�ε���Թ��",
	});

	if (me->query("quest/short") == "ȥ�����йݴ�������")
	{
		if (me->query("quest/duration") == 964)	// ��Ӱ��а
		{
				n=2+random(3);
				me->set("annie_quest/name","��˼�����Ӱ��а");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����˼��ɱXXX"+WHT"����Ӱ��а"NOR);
				me->set("annie_quest/target","��Ӱ��а");
				me->set("quest/short", WHT"����˼��ɱ"+n+WHT"����Ӱ��а"NOR);
				me->set("quest/location", "��˼��");
				me->set("quest/difficulty",n*50);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());

				arg="��˼������о����й�����Ӱ��а��û������ǰȥ����\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}


		if (me->query("quest/duration") == 963)	// ѩ������
		{
				n=2+random(3);
				me->set("annie_quest/name","��˼���ѩ������");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����˼��ɱXXX"+WHT"��ѩ������"NOR);
				me->set("annie_quest/target","ѩ������");
				me->set("quest/short", WHT"����˼��ɱ"+n+WHT"��ѩ������"NOR);
				me->set("quest/location", "��˼��");
				me->set("quest/difficulty",n*50);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());

				arg="��˼������о����й���ѩ�������û������ǰȥ����\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}
		if (me->query("quest/duration") == 962)	// һ�����
		{
				n=2+random(3);
				me->set("annie_quest/name","��˼���һ�����");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����˼��ɱXXX"+WHT"��һ�����"NOR);
				me->set("annie_quest/target","һ�����");
				me->set("quest/short", WHT"����˼��ɱ"+n+WHT"��һ�����"NOR);
				me->set("quest/location", "��˼��");
				me->set("quest/difficulty",n*50);	// ÿ��һ���Ͷ�50% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());

				arg="��˼������о����й���һ����׳�û������ǰȥ����\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 961)	// �������
		{
				i = random(7);
				n=2+random(3);
				me->set("annie_quest/name","��ϼɽɱ"+list1[i]);
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"����ϼɽ����XXX"+WHT"��"+list1[i]+NOR);
				me->set("annie_quest/target",list1[i]);
				me->set("quest/short", WHT"����ϼɽ����"+n+WHT"��"+list1[i]+NOR);
				me->set("quest/location", "��ϼɽ");
				me->set("quest/difficulty",n*50);	// ÿ��һ���Ͷ�50% reward
				me->set("quest/duration",900+n*180);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg="��ϼɽ�����ղ���̫ƽ������ǰȥ����֮�У��ɻ�����"+list1[i]+"��\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}


		return "�������ûʲô���飬�㲻��û�����ʦ���ݲ�ɡ�\n";	// error mark.
	}
	else
		return "action��������Цҡͷ����������̫ƽ�����޲�ʹ��";
	
	return " ";
}

int give_me_it_ling(object me)
{
	object x;
	x=new(__DIR__"obj/she_ling");
	if (!x->move(me))
		x->move(environment(me));
	message_vision("�������ú�����ɤ��˵����"CYN"���ޣ������Т�������丸����ȥ�ɡ���"NOR"\n�ι�����󽫻�������ݵ�$N�����С�\n",me);
	return 1;
}


int accept_object(object who, object ob)
{
	object me = who;
	if (ob->query("name") == HIW"����"NOR && REWARD_D->riddle_check(me,"Т�в���") == 5)
	{
		if (ob->query("lore"))
		{
			message_vision("�����˽ӹ�"+ ob->name() + "�����������ԩ�飬�ǳ����ӡ���\n",me);
			message_vision("�������������ۣ�ʮ��ͬ�����С����־�����˵���е���\n", ob, me);
			REWARD_D->riddle_set(me,"Т�в���",6);
			give_me_it_ling(me);
			return 1;
		}
	}
	return 0;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

//2;clone /d/cyan/npc/maze_guard5;call mingyue->stop_busy();kill ghost;3;4;smash ghost


