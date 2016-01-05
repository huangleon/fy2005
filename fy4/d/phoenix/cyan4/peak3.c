// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";

void tell_team(object who,string what)
{
	object *team;
	int i; 
	object ob,me=who;
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			tell_object(team[i],what);
		}
	}
	return ;
	
}

void create()
{
	set("short", YEL"������"NOR);
    set("long", @LONG
������խ��ɽ�죬ӭ�������һƬ���ص����֡���δ�����ĸ��ֲ����ľ
��������ں�����������Ų��þ�Ȼ����ԶԶ��ȥ������ī���ϻ�δ������
ľ�塣��ͷ������������������ľҶ����һƬ�Ա̣���������ǳǳ�Ķ�ƣ�
֦����ƽ�ߣ�����Ϊһ��������ܵ�������
    ��֪���ļ��ڣ�΢�硣
    ��ɫ�Ĺ��ߴ�������ǳǳ��͸��������
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "peak3",
  		"westup" : "peak3",
	]) );

	set("stat",1);
	set("free_cmds",1);

	set("area","cyan4");


	set("item_desc", ([

	"eastdown": "���ܴ������ɣ���ʲôҲ���������\n",
	"westup": "���ܴ������ɣ���ʲôҲ���������\n",

	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
	setup();
}





int do_start(object me)
{
	set("commencer",time());
	set("apres_vague",time() + 30);
	set("owner_ob",me->query("id"));

	me->set_temp("annie_quest/cyan4",0);
	me->set_temp("annie_quest/cyan42",0);

	tell_room(this_object(),WHT"\n���ܴ������أ�һƬ������������г�����Ω��һ����ϸ��ĺ�������\n\n���������µĽŲ�����ңԶ�ı˷��������޴�����\n\n"NOR);

	
	call_out("attacks",30,me,1,1);

	return 1;

}




void failedd()
{
	object here = this_object();
	object r,*inv;
	int i;
	r=find_object("/d/cyan/path5");
	if (!r)
		r=load_object("/d/cyan/path5");


	inv = all_inventory(here);
	i = sizeof(inv);
		while(i--) 
				if(userp(inv[i])|| inv[i]->query("possessed")|| inv[i]->query("player")==1) 
					inv[i]->move(r);
				else
					destruct(inv[i]);

	"/d/phoenix/base/alive.c"->destruct_area(query("owner_ob"));
}

void finished(object me)
{
	tell_room(this_object(),HIC"\nһ�����������ĸ�����Զ����������������ƽ�ߵ�Լ�����Ҵ���������ⱼȥ��\n\n"NOR);



	me->set("quest/short", WHT"��ȥ��ƽ�ߴ���"CYN"�������"NOR);
	me->set("quest/duration",120);
	me->set("quest_time",time());
	tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);



	failedd();

	return;

}

void attacks(object me,int w,int n)
{

	object here = this_object();
	object o;
	int i,j;

	if (w==5)
		j=2+random(2);
	else
		j=3+random(6);

	if (!me)	//player quit?
	{
		failedd();
		return;
	}

	if (wizardp(me))
		tell_object(me,HIG"wave="+w+" n="+n+NOR);

	if (w<5)
	{
		o = new(__DIR__"npc/r"+w);
		o->move(this_object());
		o->set("ol",me);
		o->go(me);
	}
	else
		for (i=0; i<j; i++)
		{
			o = new(__DIR__"npc/r"+w);
			o->move(this_object());
			o->set("ol",me);
			o->go(me);
		}
		


	if (random(3)+1 < n)
	{
		if (w<6)
			call_out("attacks",20+random(10),me,w+1,1);
		else
			call_out("finished",20+random(10),me);
	}
	else
		call_out("attacks",20+random(10),me,w,n+1);

	return;

}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	return notify_fail("ƽ��Ҫ�������ﾲ����������ǲ�Ҫ�Ҷ��������ݾ��ߡ�\n");
}


void init()
{
   	add_action("aa", "a");
	::init();
}

int aa()
{
	if (wizardp(this_player()))
		do_start(this_player());
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


