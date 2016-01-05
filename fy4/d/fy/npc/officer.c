#include <ansi.h>
inherit NPC;

string *first_name = ({ 
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","����","����","����","����",	});
string *name_words = ({ "��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��", });

string send_mail();
string receive_mail();
string quest();
object find_env(object ob);

void create()
{
    	set_name("����", ({ "officer wang", "officer","wang" }) );
		set("title", "�������䳤");
		set("gender", "����" );
		set("NO_KILL",1);
		set("no_arrest",1);
		set("age", 43);
		set("long",	"���絣�η�������䳤�Ѿ��м����ˣ��˺ܺã���÷��Ƴ�
����ϲ������ʹû���ż������Ҳ��������վ�������졣\n");
		set("combat_exp", 800);
		set("attitude", "friendly");
		set("inquiry", ([
		"����" : (: quest() :),
		"find" : (: quest() :),
		"job" : (: quest() :),	
		"ʧ��" : (: quest() :),
		"��վ" : "�ǰ�... ������Ƿ����䣬��Ҫ���Ż�������",
		"����" : (: send_mail :),
		"��" : (: send_mail :),
		"����" : (: receive_mail :),
		"mail" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("unarmed", 400);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	add_action("do_rent","rent");
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ������е��Ŷ������档\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}

int do_rent(string arg)
{

	object ob, chefu;
	object me = this_player();
	object silver;
	if (arg != "carriage" && arg != "mache")
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}

	if (query("mark/rented"))
	{
		tell_object(me,"
����˵����ѽ�����Ѿ����ȥ�ˣ���λ�͹��ǲ��ǹ����������
����Ȳ������Ҹ���ָ��һ���ݾ��ɡ�����Help newbie������ѡ��
·��ָ�ϣ������м�����������·��˵����\n");
		return 1;
	}
	if (me->query_temp("marks/wangfeng")) 
		me->delete_temp("marks/wangfeng");
	else {
	    if (me->query("deposit")<800)
	    	return notify_fail("��������Ĵ���������ӡ�\n");
		me->add("deposit",-800);
		tell_object(me, "������վ������˻���ת���˰������ӡ�\n");
	}
	
	ob=new(__DIR__"obj/carriage");
    ob->move(environment());
	message_vision("$Nʻ�˹��� \n",ob);

	chefu=new(__DIR__"chefu");
	chefu->move(environment());
	chefu->get_quest("/d/fy/carriageway");
	chefu->set_carriage(ob);
	message_vision("$N���˹��� \n",chefu);

	set("mark/rented",1);
	message_vision("$N�����ţ��������� \n",me);
	me->move(ob);
	chefu->go_now();
	
	call_out("check_status",30,chefu);
	return 1;
}

int check_status(object ob)
{
	if (!ob)
	{
		set("mark/rented",0);
	}else
	{
		call_out("check_status",30,ob);
	}
}

object generate_it(int exp,string name)
{
	object mail,room,*ulist, place, ob;
	int i,m,flag,fdd,num;
	string file, where;
	ulist=objects();
	m=sizeof(ulist);
	flag=1;

	mail=new("/obj/specials/annie/mail");
	mail->invoke(name);

	while (flag)
	{
		i=random(m);

//		write ("attemp ------fdd = " + fdd + "\n");
//		write (sprintf("it is %O\n",ulist[i]));
		
		if (!ulist[i])
			continue;
		if (!environment(ulist[i]) && !ulist[i]->query("short"))	// not a room: something in the planar void
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/login#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// ��֪����ʲô����
			continue;
		
		if (!ulist[i]->query("short") && fdd < 3)		// ���������������������exp��ѭ��, and teach ppl hiding places.
		{
			fdd++;
			continue;
		}

		room=ulist[i];
		
		// ������ player����Ҳ������ playerЯ����������		
		if (userp(room))	continue;		
		if (objectp(environment(room)) && userp(environment(room)))	
			continue;						
		
		// �����������Ӧ�ô�����ĳһ���������棬ȥ����Щ�޻�����NPC					
		ob = find_env(room);				
		if (!ob)	continue;
			
		if (ob->query("no_fight"))			continue;
		if (ob->query("no_death_penalty"))	continue;
		if (ob->query("no_fly"))			continue;	
		if (ob->query("perma_exist"))		continue;
		if (ob->query("no_lu_letter")) 		continue;	// Some rooms are tricky, can't get
					
		where = file_name(ob);
    	if (   where[0..7]=="/d/death"
    		|| where[0..4]=="/d/fy"			// including fy,fycycle,fywall
    		|| where[0..7]=="/d/eren2"
			|| where[0..6]=="/d/maze"
			|| where[0..5]=="/d/wiz"
			|| where[0..9]=="/d/welcome"
			|| where[0..9]=="/d/phoenix"
			|| where[0..8]=="/d/bashan"
			|| where[0..8]=="/d/zhaoze"
			|| where[0..9]=="/d/taoyuan"
			|| where[0..9]=="/d/shanliu"
			|| where[0..2]=="/p/"
			|| where[0..4]=="/obj"
			)
			continue;
								
		// ������ط���һ��NPCʱ
		if (room->query("combat_exp"))
		{
			if (room->query("NO_KILL"))					continue;
			if (room->query("vendetta_mark/authority"))	continue;
			if (room->query("possessed"))				continue;
			if (room->query("no_lu_letter"))			continue;
			if (room->query("combat_exp")> 10050000)	continue;	// capped around 10M				
			if (room->query("combat_exp") > exp/10*12 && fdd < 20)
			{
				fdd++;
				continue;
			}

			if (room->query("combat_exp") < exp/10*8 && fdd < 10)
			{
				fdd++;
				continue;
			}
		}
	
		if (room->query("id") == "skeleton" || room->query("id") == "corpse")
			continue;
			
		if (mail->move(room))
		{
//			CHANNEL_D->do_sys_channel("sys","move to " + file_name(room) + "\n");
//			write("move to "+ file_name(room)+"\n");	
			flag=0;
		}
	}
	return mail;

}

object find_env(object ob)
{
	while(ob)
	{
		if(ob->query("coor")) return ob;
		else 
			ob=environment(ob);	
	}
	return ob;
}

string quest()
{
	string arg, name;
	int i, n, m, size, reward, exp;
	object room, silver,room2;
	
	object me = this_player();
	
	if (me->query("quest/short") == "��������վѰ��ʧ��")
	{

		name = first_name[random(sizeof(first_name))];
		name += name_words[random(sizeof(name_words))];
		if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

//		write(sprintf("me is %O\n",me));
		me->set("annie_questx/mail",generate_it(me->query("combat_exp"),name));
		me->set("annie_questx/index", name);
		me->set("quest/short", WHT"Ѱ���͸�"+name+WHT"����"NOR);
		me->set("quest/location", "δ֪");
		me->set("quest/duration",900);	
		me->set("quest_time",time());
		arg="action����һ����ɫ���������Ѹ�"+name+"����Ū���ˣ���ﰳѰһѰ(locate quest)��\n";
		tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
		return arg;

	}
	else
		return "action���紵���ӵ��۵�����������վ�������ôӲ����ţ�";
	
	return " ";
}

int accept_object(object me,object ob)
{
	if (ob->query("desc_ext") != "�������")
		return 0;
	
	if (ob->query("marks") != me->query("annie_questx/index"))
		return 0;
	
	if (ob!= me->query("annie_questx/mail"))
		return 0;
	
	me->delete("annie_questx");

	if ( QUESTS_D->verify_quest(me,"Ѱ��ʧ��" ))
		QUESTS_D->special_reward(me,"Ѱ��ʧ��");
	
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/




